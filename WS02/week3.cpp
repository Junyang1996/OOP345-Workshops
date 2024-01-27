#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template <typename T>
class Foo
{
    T m_value{};
    static int m_cnt;

public:
    void display() const; // inline implementation is to implement the function here, not in cpp
    // so the definination has to be here, thats why template has to be in header, if it's in cpp, you can only use it in this cpp.
    Foo();
};

template <typename T>
int Foo<T>::m_cnt = 0;

template <typename T>
Foo<T>::Foo() : m_value{}
{
    Foo<T>::m_cnt++;
}
template <typename T>
void Foo<T>::display() const
{
    cout << "an instance of type Foo [ " << m_value << "]" << endl;
}
int main(int, char **)
{
    Foo<int> aFoo;
    aFoo.display();
}