#include <iostream>
#include <string>
#include <vector>
class Test_Formula {
public:
  Test_Formula() = default;
  void start();
  void reformat();
  void analyze();
  void result();
  void is_connectives();
  void reset_iter();
private:
  std::strig::iterator iter;
  
  std::string input;
  std::vector<std::string> reformat_input;
  std::string buffer;
  const std::vector<std::string&> connectives =
    { "\\not", "\\and", "\\or", "\\then", "\\iff" };x
  const int max_connec_length = 5;
  Tree tree;
  
};

class Node {
 public:
  Node();
  Node(std::string&);
  std::string str;
  bool val;
  Node* left;
  Node* right;
};

class Atom : public Node {
 public:
  Atom();
  Atom(std::string&);
};

class Formula : public Node {
 public:
  Formula();
  Node* 
  
  
class Tree {
 public:
  Tree();
  Node* root;
};

