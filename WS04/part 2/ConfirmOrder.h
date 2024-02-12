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
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H
#include "Toy.h"
namespace seneca
{
    class ConfirmOrder
    {
        const Toy **toys = nullptr;
        size_t size = 0;

    public:
        ConfirmOrder() : toys(nullptr), size(0){};
        ConfirmOrder(const ConfirmOrder &);
        ConfirmOrder(ConfirmOrder &&);
        ConfirmOrder &operator=(const ConfirmOrder &);
        ConfirmOrder &operator=(ConfirmOrder &&);
        ~ConfirmOrder()
        {
            // for (auto i = 0u; i < size; ++i)
            // {
            //     toys[i] = nullptr;
            // }
            delete[] toys;
            toys = nullptr;
            size = 0;
        };
        ConfirmOrder &operator+=(const Toy &toy);
        ConfirmOrder &operator-=(const Toy &toy);
        friend std::ostream &operator<<(std::ostream &os, ConfirmOrder &ConfirmOrder);
    };
}
#endif //! SENECA_CONFIRMORDER_H
