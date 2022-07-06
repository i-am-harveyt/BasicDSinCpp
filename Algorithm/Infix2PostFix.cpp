#include <iostream>
#include <set>
#include <string>
#include <vector>

int priority(char chr) {
  if (chr == '+' || chr == '-')
    return 1;
  else if (chr == '*' || chr == '/')
    return 2;
  else if (chr == '^')
    return 3;
  else if (chr == '(')
    return 4;
  return -1;
}

void Infix2PostFix(std::string str) {
  int index = 0, len = 0;
  char top;
  std::vector<char> stack;
  stack.push_back('!');
  std::set<char> charset;
  charset.insert('(');
  charset.insert(')');
  charset.insert('+');
  charset.insert('-');
  charset.insert('*');
  charset.insert('/');
  charset.insert('^');

  while (index < (int)str.size()) {
    // std::cout << str[index] << std::endl;
    if (charset.find(str[index]) == charset.cend()) {
      std::cout << str[index];
    } else if (str[index] == ')') {
      while (stack.back() != '(') {
        std::cout << stack.back();
        stack.pop_back();
      }
      stack.pop_back();
    } else {
      while (priority(stack.back()) >= priority(str[index]) &&
             stack.back() != '(') {
        std::cout << stack.back();
        stack.pop_back();
      }
      stack.push_back(str[index]);
    }
    index++;
  }

  while (stack.size() > 1) {
    std::cout << stack.back();
    stack.pop_back();
  }
}

int main(void) {
  Infix2PostFix("a+b*c-d^e/f");
  return 0;
}
