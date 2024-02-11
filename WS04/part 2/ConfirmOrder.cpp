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
#include "ConfirmOrder.h"
using namespace std;
namespace seneca
{
    ConfirmOrder::ConfirmOrder(const ConfirmOrder &co)
    {
        *this = co;
    }
    ConfirmOrder::ConfirmOrder(ConfirmOrder &&co)
    {
        *this = std::move(co);
    }
    ConfirmOrder &ConfirmOrder::operator=(const ConfirmOrder &co)
    {
        if (this != &co)
        {
            delete[] toys; // delete the old array

            // create a new array and copy the pointers
            toys = new const Toy *[co.size];
            size = co.size;
            for (size_t i = 0; i < size; ++i)
            {
                toys[i] = co.toys[i];
            }
        }
        return *this;
    }
    ConfirmOrder &ConfirmOrder::operator=(ConfirmOrder &&co)
    {
        if (this != &co)
        {
            delete[] toys;
            toys = new const Toy *[co.size];
            size = co.size;
            for (auto i = 0; i < size; ++i)
            {
                toys[i] = co.toys[i];
            }
            co.toys = nullptr;
            co.size = 0;
        }
        return *this;
    }
    // ~ConfirmOrder(){};
    ConfirmOrder &ConfirmOrder::operator+=(const Toy &toy)
    {
        bool found = false;
        for (auto i = 0; i < size; ++i)
        {
            if (&toy == toys[i])
            {
                // if the address of toy is already in the array, this operator does nothing
                found = true;
            }
        }
        if (!found)
        {
            // resizes the array to make room for toy if necessary
            const Toy **newToys = new const Toy *[size + 1];
            for (size_t i = 0; i < size; ++i)
            {
                newToys[i] = toys[i];
            }
            delete[] toys;
            toys = newToys;

            // stores the address of toy in the array (your function should not make copies of the toy itself)
            toys[size] = &toy;
            size++;
        }

        return *this;
    }
    ConfirmOrder &ConfirmOrder::operator-=(const Toy &toy)
    {
        for (auto i = 0; i < size; ++i)
        {
            if (&toy == toys[i])
            {
                toys[i] = nullptr;
            }
        }
        return *this;
    }
    std::ostream &operator<<(std::ostream &os, ConfirmOrder &confirmOrder)
    {
        os << "--------------------------\n";
        os << "Confirmations to Send\n";
        os << "--------------------------\n";

        if (confirmOrder.size == 0)
        {
            os << "There are no confirmations to send!\n";
        }
        else
        {
            for (size_t i = 0; i < confirmOrder.size; ++i)
            {
                os << *(confirmOrder.toys[i]) << "\n";
            }
        }

        os << "--------------------------\n";

        return os;
    }
}