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
namespace seneca
{
    class Pair
    {
        std::string m_key{};
        std::string m_value{};

    public:
        const std::string &getKey() { return m_key; }
        const std::string &getValue() { return m_value; }
        Pair(const std::string &key, const std::string &value) : m_key{key}, m_value{value} {};

        // TODO: Add here the missing prototypes for the members
        //           that are necessary if this class is to be used
        //           with the template classes described below.
        //       Implement them in the Pair.cpp file.
        };
}
#endif