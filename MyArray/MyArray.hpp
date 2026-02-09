#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray {
   private:
    int m_capacity, m_size;
    T* pm_address;

   public:
    MyArray(int capacity) {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pm_address = new T[this->m_capacity];
    }
    MyArray(const MyArray& arr) {
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // 深拷贝
        this->pm_address = new T[this->m_capacity];
        for (int i = 0; i < this->m_size; i++) {
            this->pm_address[i] = arr.pm_address[i];
        }
    }
    MyArray& operator=(const MyArray& arr) {
        // 清理原本数据
        if (this->pm_address != NULL) {
            delete[] this->pm_address;
            this->pm_address = NULL;
        }
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // 深拷贝
        this->pm_address = new T[this->m_capacity];
        for (int i = 0; i < this->m_size; i++) {
            this->pm_address[i] = arr.pm_address[i];
        }
        return *this;
    }
    T& operator[](int index) { return this->pm_address[index]; }
    int get_capacity() { return this->m_capacity; }
    int get_size() { return this->m_size; }
    void push_back(const T& data) {
        if (this->m_size == this->m_capacity) {
            cout << "数组容量已满，无法插入" << endl;
            return;
        }
        this->pm_address[this->m_size++] = data;
    }
    void pop_back(void) {
        if (this->m_size == 0) {
            cout << "数组容量已空，无法删除" << endl;
            return;
        }
        this->m_size--;
    }
    ~MyArray() {
        if (this->pm_address != NULL) {  
            delete[] this->pm_address;
            this->pm_address = NULL;
        }
    }
};