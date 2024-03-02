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
        std::string status() const { return "EMPLOYEE"; }
        std::string name() const { return m_name; }
        std::string id() const { return m_id; }
        std::string age() const { return m_age; }
        void display(std::ostream &out) const;
    };

}
#endif //! EMPLOYEE_H