#include <iostream>
#include <string>
#include <vector>
#include <cctype>

Tree::Tree(const string& s) {
  init_value(s);
  parent = nullptr;
  left = nullptr;
  right = nullptr;
}

Tree::Tree(const std::string& s, int n, Tree* p) {
  init_value(s);
  parent = p;
  left = nullptr;
  right = nullptr;
}
  

void Tree::init_value(const std::string& s) {
  value = s;
}


void Formula::formula() {
  std::string s;
  std::cin >> s;
  new_tree();
  bool is_connective = ! (std::find(connecteivs.begin(), connectives.end()) ==
			  connectives.end())
  if ( s == "(" ) {
    formula();
  } else if ( is_connective ) {
  } else if ( 
    
}

void Formula::new_tree() {
  cur_tree = new Tree();
}
      
bool Formula::is_connective() {
  
