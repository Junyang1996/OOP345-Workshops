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
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
#include "Person.h"
namespace seneca
{
    class Employee : public Person
    {
        std::string m_name{};
        // according to guidence these 2 should be string
        std::string m_age{};
        std::string m_id{};

    public:
        Employee(std::istream &);
        std::string status() const { return "Employee"; }
        std::string name() const { return m_name; }
        std::string id() const { return m_id; }
        std::string age() const { return m_age; }
        void display(std::ostream &out) const;
    };

}
#endif //! EMPLOYEE_H