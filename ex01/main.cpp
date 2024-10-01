#include "Span.hpp"
#include <iostream>

int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  try {
    Span span = Span(20000);
    std::vector<int> tab;
    srand(time(NULL));
    for (int i = 0; i < 20000; i++) {
      int random = rand() % 100000;
      tab.push_back(random);
    }
    span.addNumber(tab);
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;

    span.addNumber(42);
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
