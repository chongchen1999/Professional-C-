#include <iostream>
#include <memory>
using namespace std;

class MyClass {
public:
    int value;

    // 构造函数
    MyClass(int v) : value(v) {
        cout << "Constructor called" << endl;
    }

    // 拷贝构造函数
    MyClass(const MyClass &obj) {
        value = obj.value;
        cout << "Copy Constructor called" << endl;
    }

    // Move Constructor
    MyClass(const MyClass&& other) {
        cout << "Move Constructor called" << endl;
    }

    ~MyClass() {
        cout << "Destructor called" << endl;
    }
};

// 1. 以值传递对象传入函数体
void passByValue(MyClass obj) {
    cout << "Function called with value: " << obj.value << endl;
}

// 2. 以值传递对象从函数返回
unique_ptr<MyClass> returnByValue() {
    auto obj = make_unique<MyClass>(20);
    cout<< obj.get() << endl;
    return obj;
}

int main() {
    MyClass obj1(10);

    // 调用拷贝构造函数：以值传递对象传入函数体
    passByValue(obj1);

    // 调用拷贝构造函数：以值传递对象从函数返回
    puts("Test 2:");
    auto obj2 = returnByValue();
    cout << obj2.get() << endl;
    puts("End test 2!");

    // 调用拷贝构造函数：通过另一个对象初始化对象
    MyClass obj3 = obj1;
    MyClass obj4(obj1);

    puts("Test 3:");
    {
        MyClass *obj5 = new MyClass(30);
        // delete obj5;
    }
    puts("End test 3!");

    return 0;
}