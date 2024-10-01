#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span() : _N(0) {
  std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const unsigned int n) : _N(n) {
  std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &copy) {
  std::cout << "Span copy constructor called" << std::endl;
  *this = copy;
}

Span &Span::operator=(const Span &copy) {
  std::cout << "Span assignation operator called" << std::endl;
  if (this != &copy) {
    this->_N = copy._N;
    this->_tab = copy._tab;
  }
  return *this;
}

Span::~Span() { std::cout << "Span destructor called" << std::endl; }

void Span::addNumber(const int n) {
  if (this->_tab.size() == this->_N)
    throw Span::NotEnoughNumbersException();
  this->_tab.push_back(n);
}

void Span::addNumber(const std::vector<int> &tab) {
  if (this->_tab.size() + tab.size() > this->_N)
    throw Span::NotEnoughNumbersException();
  this->_tab.insert(this->_tab.end(), tab.begin(), tab.end());
}

int Span::shortestSpan() {
  if (this->_tab.size() <= 1)
    throw Span::NoSpanException();

  std::sort(this->_tab.begin(), this->_tab.end());
  std::vector<int>::iterator it = this->_tab.begin();
  int min = *(it + 1) - *it;
  for (; it != this->_tab.end() - 1; it++) {
    if (*(it + 1) - *it < min)
      min = *(it + 1) - *it;
  }
  return min;
}

int Span::longestSpan() {
  if (this->_tab.size() <= 1)
    throw Span::NoSpanException();

  std::sort(this->_tab.begin(), this->_tab.end());
  return this->_tab.back() - this->_tab.front();
}

const char *Span::NoSpanException::what() const throw() {
  return "No span to find";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
  return "Not enough numbers to add";
}
