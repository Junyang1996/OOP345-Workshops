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
#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <string>
#include "Employee.h"
namespace seneca
{
    class Professor : public Employee
    {
        std::string m_department{};

    public:
        Professor(std::istream &in);
        void display(std::ostream &out) const;
        std::string status() const { return "Professor"; }
        std::string department() const { return m_department; }
    };
}
#endif //! PROFESSOR_H