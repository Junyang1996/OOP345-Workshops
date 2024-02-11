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
#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H
#include <string>
#include <iostream>
#include <iomanip>
namespace seneca
{
    class Pair
    {
        std::string m_key{};
        std::string m_value{};

    public:
        const std::string &getKey() { return m_key; }
        const std::string &getValue() { return m_value; }
        Pair(const std::string &key = "", const std::string &value = "") : m_key{key}, m_value{value} {};

        // TODO: Add here the missing prototypes for the members
        //           that are necessary if this class is to be used
        //           with the template classes described below.
        //       Implement them in the Pair.cpp file.
        Pair(const Pair &other);
        Pair &operator=(const Pair &other);
        ~Pair();

        bool operator==(const Pair &other) const
        {
            return (m_key == other.m_key && m_value == other.m_value);
        }

        friend std::ostream &operator<<(std::ostream &os, const Pair &pair)
        {
            os << std::setw(20) << std::right << pair.m_key << ": " << pair.m_value;
            return os;
        }
    };
}
#endif //! SENECA_PAIR_H