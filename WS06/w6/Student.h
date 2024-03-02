#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
namespace seneca
{
    class Student : public Person
    {
        std::string m_name{};
        int m_age{};
        std::string m_id{};
        std::string *m_courses{};
        size_t m_count{};

    public:
        Student(std::istream &);
        std::string status() const;
        std::string name() const;
        void display(std::ostream &out) const;
    };
} // namespace seneca

#endif //! STUDENT_H