#ifndef ABSTRACT_HPP
#define ABSTRACT_HPP
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class AbstractDAO {
    protected:
    string nome;
    string id;
    public:
    AbstractDAO() {}
    virtual void add(const T& tempObject) = 0;
    virtual void update(const T& tempObject) = 0;
    virtual void remove(int id) = 0;
    virtual T searchId(int id) = 0;
};

#endif