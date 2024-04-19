#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
        int age;
        string phone;

    public:
        Person();
        
        Person(string name, int age, string phone):
        name(name), age(age), phone(phone){}

        // get
        string getNome(){
            return name;
        }

        int getAge(){
            return age;
        }

        string getPhone(){
            return phone;
        }

        //set
        void setNome(string name){
            this->name = name;
        }

        void setAge(int age){
            this->age = age;
        }

        void setPhone(string phone){
            this->phone = phone;
        }


};

#endif
