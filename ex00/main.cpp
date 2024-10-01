#include "Easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> tab;

  tab.push_back(1);
  tab.push_back(2);
  tab.push_back(3);
  tab.push_back(4);
  tab.push_back(5);

  try {
    std::vector<int>::iterator it = easyfind(tab, 3);
    std::cout << "Value found: " << *it << std::endl;

    it = easyfind(tab, 6);
    std::cout << "Value found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "Value not found" << std::endl;
  }

  return 0;
}
