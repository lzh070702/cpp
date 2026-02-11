#pragma once
#include <iostream>
#include <string>
#include "MyArray.hpp"
using namespace std;

class Person {
   private:
    string m_name;
    int m_age;

   public:
    Person() {}
    Person(string name, int age) : m_name(name), m_age(age) {}
    Person(const Person& p) : Person(p.m_name, p.m_age) {}
    string get_name() { return this->m_name; }
    int get_age() { return this->m_age; }
};

ostream& operator<<(ostream& cout, Person p) {
    cout << "姓名:" << p.get_name() << "   年龄:" << p.get_age();
    return cout;
}