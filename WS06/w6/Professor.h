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
        std::string status() const;
        std::string department() const;
    };
}
#endif //! PROFESSOR_H