/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Jan 26, 2024
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
    class Set : public Collection<T, 100>
    {
    public:
        Set(T *arr = nullptr, unsigned int size = 0) : Collection<T, 100>(arr, size){};
        bool add(const T &item) override
        {
            for (auto i = 0u; i < Collection<T, 100>::size(); i++)
            {
                if (Collection<T, 100>::operator[](i) == item)
                {
                    return false;
                }
            }

            return Collection<T, 100>::add(item);
        }
        ~Set() {}
    };

    template <>
    bool Set<double>::add(const double &item)
    {
        for (auto i = 0u; i < Collection<double, 100>::size(); i++)
        {
            if ((std::fabs(operator[](i) - item) <= 0.01))
            {
                return false;
            }
        }

        return Collection<double, 100>::add(item);
    }

}
#endif //! SENECA_SET_H