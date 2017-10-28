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

void Test_Formula::reformat() {
  iter = input.begin();
  auto end = input.end();
  while (iter != end) {

    if (*iter == '(') {

      reformat_input.push_back(std::string(*iter));

    } else if (*iter == '\\') {
// for now, the legal connectives all starts with \

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
  while (begin != end) {
if (*begin == '(') {
  


  

  
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
  }
  else {
    return false;

  }

}



Node::Node(): left(nullptr), right(nullptr) {}

Node:: Node(std::string& s): str(s), left(nullptr), right(nullptr) {}





