#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <string>

using namespace std;

class Person {    
    protected:
        string name;
        int age;
        string phone;

    public:
        Person(){};        
        Person(string name, int age, string phone):name(name), age(age), phone(phone){};

        // getters
        string getName() const{ return name; }
        int getAge() const{ return age; }
        string getPhone() const{ return phone; }

        //setters
        void setName(string name){ this->name = name; }
        void setAge(int age){ this->age = age; }
        void setPhone(string phone){ this->phone = phone; }
};

#endif
