#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span {
private:
  unsigned int _N;
  std::vector<int> _tab;

public:
  Span();
  Span(const unsigned int n);
  Span(const Span &copy);
  Span &operator=(const Span &copy);
  ~Span();

  void addNumber(const int n);
  void addNumber(const std::vector<int> &tab);
  int shortestSpan();
  int longestSpan();

  class NoSpanException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class NotEnoughNumbersException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

#endif // !SPAN_HPP
