#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
private:
  /* data */

public:
  MutantStack() : std::stack<T, Container>() {}
  MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy) {}
  MutantStack &operator=(const MutantStack &copy) {
    std::stack<T, Container>::operator=(copy);
    return *this;
  }
  virtual ~MutantStack() {}

  typedef typename Container::iterator iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  iterator rbegin() { return this->c.rbegin(); }
  iterator rend() { return this->c.rend(); }
};

#endif
