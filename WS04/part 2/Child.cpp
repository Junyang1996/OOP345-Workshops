/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Feb 9, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#include <utility>
#include "Child.h"
#include "Toy.h"
using namespace std;
namespace seneca
{
    Child::Child(std::string name, int age, const Toy **toys, size_t count)
    {
        _name = name;
        _age = age;
        _toys = toys;
        _count = count;
    }
    Child::Child(const Child &other)
    {
        // _name = other._name;
        // _age = other._age;
        // _toys = other._toys;
        // _count = other._count;
        *this = other;
    }
    Child::Child(Child &&other)
    {
        *this = std::move(other);
    }

    Child &Child::operator=(const Child &other)
    {
        if (this != &other)
        {
            _name = other._name;
            _age = other._age;
            _count = other._count;

            delete[] _toys;
            // create a new array
            _toys = new const Toy *[_count];
            for (size_t i = 0; i < _count; ++i)
            {
                // copy each pointer
                _toys[i] = other._toys[i];
            }
        }
        return *this;
    }
    Child &Child::operator=(Child &&other)
    {
        if (this != &other)
        {
            _name = std::move(other._name);
            _age = other._age;
            // delete the old array
            delete[] _toys;
            // take ownership of the other array
            _toys = other._toys;
            _count = other._count;
            // leave the other object in a safe state
            other._toys = nullptr;
            other._count = 0;
        }
        return *this;
    }
    Child::~Child() = default;
    size_t Child::size() const
    {
        return _count;
    }
    ostream &operator<<(ostream &os, Child &child)
    {
        static int CALL_CNT = 0;
        if (child.size() == 0)
        {
            os << "--------------------------" << endl
               << "Child " << ++CALL_CNT << ": " << child._name << " " << child._age << " years old:\n"
               << " --------------------------" << endl
               << "This child has no toys!" << endl
               << "-------------------------\n";
        }
        else
        {
            os << "--------------------------" << endl
               << "Child " << ++CALL_CNT << ": " << child._name << " " << child._age << " years old:\n"
               << " --------------------------" << endl;
            for (auto i = 0u; i < child._count; ++i)
            {
                os << *child._toys[i];
            }
        }
        return os;
    }
}
