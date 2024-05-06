#ifndef ABSTRACTDAO_HPP
#define ABSTRACTDAO_HPP
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;

template <typename T>
class AbstractDAO {
    /* protected:
    string nome;
    string id; */

    public:
    AbstractDAO() {}
    virtual void add(const T& tempObject) = 0;
    virtual void update(const T& tempObject) = 0;
    virtual void remove(string id) = 0;
    virtual const shared_ptr<T> searchId(string id) = 0;
};

#endif