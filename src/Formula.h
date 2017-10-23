#include <iostream>
#include <string>
#include <vector>

class Tree {
public:
  
  Tree(, int);
  Tree(char*, int, Tree*, Tree*);
  void init_value(const std::string&);
  Tree* parent;
  Tree* left;
  Tree* right;
  std::string value;
  
};

class Formula {
 public:
  Formula();
  void formula();
  Tree* cur_tree;
  void match(char);
  void new_tree();
  bool is_connective();
  std::vector<std::string> connectives =
    { "/\\", "\\/", "->", "<->", "\not"}; 
}
  
  

