
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
#include "Pair.h"
using namespace std;
namespace seneca
{
    Pair::Pair(const Pair &other)
    {
        m_key = other.m_key;
        m_value = other.m_value;
    }
    Pair &Pair::operator=(const Pair &other)
    {
        if (this != &other)
        {
            m_key = other.m_key;
            m_value = other.m_value;
        }
        return *this;
    }
    Pair::~Pair()
    {
        m_key = "";
        m_value = "";
    }
}
