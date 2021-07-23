//
//  main.cpp
//  27_Inheritance_Practice_1
//
//  Created by 세광 on 2021/07/23.
//

#include <iostream>

using namespace std;

class A {
public:
    virtual int f() { return x; }
    virtual ~A() { }
    
private:
    int x = 10;
};

class B : public A {
public:
    int f() { return x; }
    virtual int g() { return A::f(); }
    
private:
    int x = 20;
};

class C : public B {
public:
    int f() { return x; }
    int g() { return B::f(); }
    virtual int h() { return B::g(); }
    
private:
    int x = 30;
};

int main() {
    A *a = new B;
    A *b = new C;
    B *c = new C;
    C *d = new C;
    cout << a->f() << endl;
    cout << static_cast<B*>(a)->g() << endl; // a의 포인터 타입은 A이므로 A의 멤버에만 접근할 수 있음 -> 형변환을 통해 B의 멤버에 접근할 수 있도록 함
    cout << b->f() << endl;
    if (C *t = dynamic_cast<C*>(b)) cout << t->g() << endl; // 정말로 C 타입의 객체를 가리키고 있는지 확인하고 싶을 경우 dynamic_cast 사용
    cout << c->f() << endl;
    cout << c->g() << endl;
    cout << d->g() << endl;
    cout << d->h() << endl;
    delete a;
    delete b;
    delete c;
    delete d;
}
