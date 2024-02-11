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
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H
#include <string>
#include "Toy.h"
namespace seneca
{
    class Child
    {
        std::string _name = "";
        int _age = 0;
        // An attribute of type const seneca::Toy** representing the dynamically allocated array of pointers--> aggregation, it does not control the creation of the array
        const Toy **_toys = nullptr;
        size_t _count = 0;

    public:
        Child(std::string name, int age, const Toy *toys[], size_t count);
        Child(const Child &other);
        Child(Child &&other);

        Child &operator=(const Child &other);
        Child &operator=(Child &&other);
        ~Child();
        size_t size() const;
        friend std::ostream &operator<<(std::ostream &os, Child &child);
    };
}
#endif //! SENECA_CHILD_H