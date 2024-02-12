/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Feb 11, 2024
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
            if (toys != nullptr)
                delete[] toys; // delete the old array

            size = co.size;
            toys = new const Toy *[size]; // create a new array
            for (size_t i = 0; i < size; ++i)
            {
                toys[i] = co.toys[i]; // copy the pointers
            }
        }
        return *this;
    }
    ConfirmOrder &ConfirmOrder::operator=(ConfirmOrder &&co)
    {
        if (this != &co)
        {
            // delete[] toys;
            // toys = new const Toy *[co.size];
            toys = co.toys;
            size = co.size;
            // for (auto i = 0u; i < size; ++i)
            // {
            //     toys[i] = co.toys[i];
            // }
            // delete[] co.toys;
            co.toys = nullptr;
            co.size = 0;
        }
        return *this;
    }
    // ~ConfirmOrder(){};
    ConfirmOrder &ConfirmOrder::operator+=(const Toy &toy)
    {
        bool found = false;
        for (auto i = 0u; i < size; ++i)
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
        for (auto i = 0u; i < size; ++i)
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
                if (confirmOrder.toys[i] != nullptr)
                    os << *(confirmOrder.toys[i]);
            }
        }

        os << "--------------------------\n";

        return os;
    }
}