#include <iostream>
#include <string>
#include <cctype>
#include "Formula.h"


void Test_Formula::start() {
  std::cout << "Input formula to be Tested" << std::endl;
  std::getline(std::cin, input);
  reformat();
  analyze();
  result();
}

void Test_Formula::get_situation() {
  std::cout << "Input the current situation" << std::endl;
  std::string atom;
  std::string str_val;
  bool bool_val;

  while (std::cin >> atom >> tr_value) {
    if (str_value == "true" || str_value == "True") {

      bool_val = true;

    } else if (str_value == "false" || str_value == "False") {

      bool_val = false;

    } else {

      throw error("Unrecognized Input");

    }
    environ.insert(std::make_pair(atom, bool_val));
  }

}

  
// breaks the string into brackets, connectives and atoms
void Test_Formula::reformat() {
  iter = input.begin();
  auto end = input.end();

  while (iter != end) {
    if (*iter == '(') {

      reformat_input.push_back(std::string(*iter));

    } else if (*iter == '\\') {

        auto old_inter = iter;

        if (is_connective()) {

          reformat_input.push_back(buffer);
          buffer.clear();

        } else {

          throw error("Invalid connective");

        }
    } else if (isalpha(*iter)) {

      reformat_input.push_back(std::string(*iter));

    } else if (isspace(*iter)) {

      continue;

    } else {

      throw error("Input contains unrecognized symbol");

  }
}
      
void Test_Formula::analyze() {
  auto begin = reformat_input.begin();
  auto end = reformat_input.end();
  tree = new Tree();
  Node* cur = tree->root;

  while (begin != end) {
    if (*begin == "(") {

      cur = cur->left;

    } else if (*begin == ")") {

      cur = cur->parent;

    } else if (*begin.length() == 1 && isalpha(*begin[0])) {

      cur->val = *begin;

    } else if (std::find(connectives.begin(), connectives.end(), *begin) !=
	     connectives.end()) {

      cur->val = *begin;
      cur = cur->right;

    } else {

      throw error("Unrecognized input");

    }
    begin++;
  }
  
}

void Test_Formula::evaluate(Node* pwalk) {
// After parsing the formula into a tree
// Evaluate the formula to get the true false value of the root
// Do a post-order walk through the tree
  if (pwalk != nullptr) {
    bool lval = evaluate(pwalk->left);
    bool rval = evaluate(pwalk->right);
    bool result_val;
    std::string& connec = pwalk->str;
    
    if (str == "\\and") {
      
      result_val = lval && rval;
      
    } else if (str == "\\or") {
      
      result_val = lval || rval;
      
    } else if (str == "\\then") {
      
      if (lval == true && rval == false) {
	
	result_val = false;
	
      } else {
	
	result_val = true;
	
      }
    } else if (str == "\\iff") {
      if (lval == rval) {
	
	result_val = true;
	
      } else {
	
	result_val = false;
	
      }
    }
  }
}
  
bool Test_Formula::is_connectives() {
  int count = 0;
  while (!isspace(*iter) && count < max_connec_length) {
    buffer.push_back(*iter);
    iter++;
    count++;
  }
  if (std::find(connectives.begin(), connectives.end(), buffer) !=
      connectives.end()) {
    
    return true;
    
  } else {
    
    return false;

  }

}

Node::Node(): left(nullptr), right(nullptr) {}
Node:: Node(std::string& s): str(s), left(nullptr), right(nullptr) {}

Atom::Atom(): Node() {}
Atom::Atom(std::string& s) :Node(s) {}

Formula::Formula(): Node(){}

Connective::Connective(): Node() {}
Connective::Connective(std::string& s): Node(s) {}
 

