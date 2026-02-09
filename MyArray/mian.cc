#include <iostream>
#include "MyArray.hpp"
#include "Person.hpp"
using namespace std;

template <class T>
void print_array(MyArray<T>& arr) {
    for (int i = 0; i < arr.get_size(); i++) {
        cout << arr[i] << endl;
    }
}

void test1() {
    MyArray<int> arr1(10);
    for (int i = 0; i < 5; i++) {
        arr1.push_back(i);
    }
    cout << "arr1的输出为: " << endl;
    print_array(arr1);
    cout << "arr1的容量为: " << arr1.get_capacity() << endl;
    cout << "arr1的大小为: " << arr1.get_size() << endl;
    MyArray<int> arr2(arr1);
    arr2.pop_back();
    cout << "arr2的输出为: " << endl;
    print_array(arr2);
    cout << "arr2的容量为: " << arr2.get_capacity() << endl;
    cout << "arr2的大小为: " << arr2.get_size() << endl;
}

void test2() {
    MyArray<Person> arr3(5);
    Person p1("张三", 18);
    Person p2("李四", 19);
    Person p3("王五", 20);
    arr3.push_back(p1);
    arr3.push_back(p2);
    arr3.push_back(p3);
    cout << "arr3的输出为: " << endl;
    print_array(arr3);
    cout << "arr3的容量为: " << arr3.get_capacity() << endl;
    cout << "arr3的大小为: " << arr3.get_size() << endl;
}

int main() {
    test1();
    test2();
    return 0;
}