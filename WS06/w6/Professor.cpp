/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Mar 7, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#include <string>
#include "Professor.h"
#include "Utilities.h"
using namespace std;
namespace seneca
{
    Professor::Professor(std::istream &in) : Employee(in)
    {
        string temp{};
        getline(in, temp);
        m_department = trim(temp);
    }
    void Professor::display(std::ostream &out) const
    {
        Employee::display(out);
        out << m_department << "| " << status();
    }
}
