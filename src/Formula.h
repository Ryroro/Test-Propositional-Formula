#ifndef FORMULA_H
#define FORMULA_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Test_Formula;
class Node;

class Test_Formula {
public:
  Test_Formula() = default;
  void start();
  void get_situation();
  void reformat();
  void analyze();
  bool evaluate(Node*);
  //void result();
  bool is_connective();
  // void reset_iter();
private:
  std::string::iterator iter;
  
  std::string input;
  std::vector<std::string> reformat_input;
  std::string buffer;
  const std::vector<std::string> connectives =
    { "\\not", "\\and", "\\or", "\\then", "\\iff" };
  const int max_connec_length = 5;
  Node* root;
  std::map<std::string, bool> environ;
  Node* pwalk;
  
  
};

class Node {
 public:
  Node();
  Node(std::string);
  std::string str;
  bool val;
  Node* left;
  Node* right;
  Node* parent;
};

/*
class Atom : public Node {
 public:
  Atom();
  Atom(std::string&);
};

class Formula : public Node {
 public:
  Formula();
};

class Connective : public Node {
 public:
  Connective();
  Connective(std::string&);
}
*/  

#endif
