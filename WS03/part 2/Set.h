/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Feb 4, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#ifndef SENECA_SET_H
#define SENECA_SET_H
#include <iostream>
#include <cmath>
#include "Pair.h"
#include "Collection.h"
namespace seneca
{
    template <typename T>
    class Set : public Collection<T, SPECIAL_CAPACITY>
    {
    public:
        Set(T *arr = nullptr, unsigned int size = 0) : Collection<T, SPECIAL_CAPACITY>(arr, size){};
        bool add(const T &item) override
        {
            for (auto i = 0u; i < Collection<T, SPECIAL_CAPACITY>::size(); i++)
            {
                if (Collection<T, SPECIAL_CAPACITY>::operator[](i) == item)
                {
                    return false;
                }
            }

            return Collection<T, SPECIAL_CAPACITY>::add(item);
        }
        ~Set() {}
    };

    template <>
    bool Set<double>::add(const double &item)
    {
        for (auto i = 0u; i < Collection<double, SPECIAL_CAPACITY>::size(); i++)
        {
            if ((std::fabs(operator[](i) - item) <= 0.01))
            {
                return false;
            }
        }

        return Collection<double, SPECIAL_CAPACITY>::add(item);
    }

}
#endif //! SENECA_SET_H