#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include "Formula.h"


void Test_Formula::start() {
  std::cout << "Input formula to be Tested" << std::endl;
  std::getline(std::cin, input);
  std::cout << "Input the situation" << std::endl;
  get_situation();
  reformat();
  analyze();
  evaluate(root);
  //result();
  if (root->val) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
}

void Test_Formula::get_situation() {
  std::cout << "Input the number of situation" << std::endl;
  int i;
  std::cin >> i;
  std::string atom;
  std::string str_val;
  bool bool_val;

  for (int j = 0; j < i; j++) {
    std::cin >> atom >> str_val;
    if (str_val == "true" || str_val == "True") {

      bool_val = true;

    } else if (str_val == "false" || str_val == "False") {

      bool_val = false;

    } /*else {

      throw std::error("Unrecognized Input");

      }*/
    environ.insert(std::make_pair(atom, bool_val));
    std::cout << "getting situation" << std::endl;
  }

}

  
// breaks the string into brackets, connectives and atoms
// Suppose the test_formula has the input ->
//       " (p \\and q ) \\and r"
// then the input in the buffer will be
//      ["(", "p", "\\and", ")", "\\and", "r"]

void Test_Formula::reformat() {
  iter = input.begin();
  auto end = input.end();
  std::cout << "in reformat " << std::endl;
  while (iter != end) {
    if (*iter == '(') {

      std::string temp;
      temp.push_back(*iter);

      reformat_input.push_back(temp);
      iter++;

    } else if (*iter == ')') {

      std::string temp;
      temp.push_back(*iter);

      reformat_input.push_back(temp);
      iter++;
      
    } else if (*iter == '\\') {

        auto old_inter = iter;

        if (is_connective()) {

          reformat_input.push_back(buffer);
          buffer.clear();

        }/* else {

          throw error("Invalid connective");

	  }*/
	iter++;
    } else if (isalpha(*iter)) {

      std::string temp;
      temp.push_back(*iter);

      reformat_input.push_back(temp);
      iter++;

    } else if (isspace(*iter)) {

      iter++;

    }/* else {

      throw std::error("Input contains unrecognized symbol");

      }*/
    else {
      iter++;
    }
  }
}

// create a tree from the reformat input

void Test_Formula::analyze() {
  auto begin = reformat_input.begin();
  auto end = reformat_input.end();
  root = new Node();
  Node* cur = root;
  std::cout << "analyzing" << std::endl;
  std::cout << "checking reformat result" << std::endl;
  auto b = reformat_input.begin();
  auto e = reformat_input.end();
  while (b != e) {
    std::cout << *b << " ";
    b++;
  }
  std::cout << std::endl;

  while (begin != end) {
    if (*begin == "(") {

      auto old_cur = cur;
      cur->left = new Node();
      cur->right = new Node();
      cur = cur->left;
      cur->parent = old_cur;
      std::cout << "in left bracket" << std::endl;

    } else if (*begin == ")") {

      
      cur = cur->parent;
      std::cout << "in right bracket" << std::endl;

    } else if ((*begin).length() == 1 && isalpha((*begin)[0])) {
      // if the input is an atom

      cur->str = *begin;
      cur->val = environ[*begin];
      cur = cur ->parent;
      std::cout << "get alpha" << std::endl;

    } else if (std::find(connectives.begin(), connectives.end(), *begin) !=
	     connectives.end()) {
      // if the input is a connective
      auto old_cur = cur;
      std::cout << "finding connective " << std::endl;
      std::cout << "value of pointer is " << *begin << std::endl;
      cur->str = *begin;
      std::cout << "check which line" << std::endl;
      cur = cur->right;
      cur->parent = old_cur;
      std::cout << "find connective" << std::endl;

    } /*else {

      throw std::error("Unrecognized input");

      }*/
    begin++;
  }
  
}

bool Test_Formula::evaluate(Node* pwalk) {
// After parsing the formula into a tree
// Evaluate the formula to get the true false value of the root
// Do a post-order walk through the tree
  std::cout << "in evaluate" << std::endl;
  if (pwalk != nullptr) {
    if (pwalk->left == nullptr && pwalk->right == nullptr) {
      return pwalk->val;
    }
    
    bool lval;
    bool rval;
    if (pwalk->left != nullptr) {
      evaluate(pwalk->left);
      lval = pwalk->left->val;
    }
    if (pwalk->right != nullptr) {
      evaluate(pwalk->right);
      rval = pwalk->right->val;
    }
   
    bool result_val;
    std::string& connec = pwalk->str;
    
    if (connec == "\\and") {
      
      result_val = lval && rval;
      
    } else if (connec == "\\or") {
      
      result_val = lval || rval;
      
    } else if (connec == "\\then") {
      
      if (lval == true && rval == false) {
	
	result_val = false;
	
      } else {
	
	result_val = true;
	
      }
    } else if (connec == "\\iff") {
      if (lval == rval) {
	
	result_val = true;
	
      } else {
	
	result_val = false;
	
      }
    }
    pwalk->val = result_val;
    return result_val;
  }
  
}

bool Test_Formula::is_connective() {
  int count = 0;

  // collect the word from the buffer
  // will test whether the word is a buffer
  while (!isspace(*iter) && count < max_connec_length) {
    buffer.push_back(*iter);
    iter++;
    count++;
  }

  // check if the word in the buffer is a connective
  if (std::find(connectives.begin(), connectives.end(), buffer) !=
      connectives.end()) {
    
    return true;
    
  } else {
    
    return false;

  }
  

}

Node::Node(): str(""),left(nullptr), right(nullptr) {}
Node::Node(std::string s): str(s), left(nullptr), right(nullptr) {}
/*
Atom::Atom(): Node() {}
Atom::Atom(std::string& s) :Node(s) {}

Formula::Formula(): Node(){}

Connective::Connective(): Node() {}
Connective::Connective(std::string& s): Node(s) {}
 
*/
