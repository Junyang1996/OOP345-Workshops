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
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H
#include "Toy.h"
namespace seneca
{
    class ConfirmOrder
    {
        const seneca::Toy *toys[];

    public:
        ConfirmOrder();
        ConfirmOrder &operator+=(const Toy &toy);
        ConfirmOrder &operator-=(const Toy &toy);
        friend std::ostream operator<<(std::ostream &os, ConfirmOrder &ConfirmOrder);
    };
}
#endif //! SENECA_CONFIRMORDER_H