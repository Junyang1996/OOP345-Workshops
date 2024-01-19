#include <iostream>
#include <utility>
using namespace std;

// void display(int &){
//     cout<<"l - value";
// }
// void display(int &&){
//     cout<<"r-value";
// }

// int main(int, char *reftoint *)
// {
//     int data = 10;
//     int &&reftoint = 10;

//     display(10);
//     display(data);
//     display(reftoint); // this will be rvalue
//     display(++data);   // it will give back the original
//     display(data++);   // it will give back the local value
//     display(data + 5); // r-value reference will be returned
//     reftoint = 30;
// }

class Numbers
{
    double *m_arr{};
    size_t m_cnt{};

public:
    Numbers(size_t len)
    {
        clog << "[" << this << "] Numbers (size_t)\n";
        m_arr = new double[len]{};
        for (auto i = 0; i < len; i++)
        {
            m_arr[i] = 0.5 * i;
        }
    }
    // rule of 3+2
    // TODO all attributes that are used in c=
    Numbers(const Numbers &other)
    {
        m_arr = nullptr;
        *this = other;
    }

    Numbers &operator=(const Numbers &other)
    {
        if (this != &other)
        {
            delete[] m_arr;
            m_cnt = other.m_cnt;

            // 4.deep copy
            if (m_cnt != 0)
            {
                m_arr = new double[m_cnt];
                for (int i = 0; i < m_cnt; i++)
                {
                    m_arr[i] = other.m_arr[i];
                }
            }
            else
            {
                m_arr = nullptr;
            }
        }
        return *this;
    }
    ~Numbers()
    {
        delete[] m_arr;
    }

    // move constructor
    Numbers(Numbers &&other) noexcept
    {
        // initialize all attributes used by M=
        *this = std::move(other);
    }
    // move assignment operator
    Numbers &operator=(Numbers &&other) noexcept
    {
        if (this != &other)
        {
            delete[] m_arr;
            m_cnt = other.m_cnt;

            m_arr = other.m_arr;
            other.m_arr = nullptr;
        }
        return *this;
    }
};
