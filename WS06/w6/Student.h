#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
namespace seneca
{
    class Student : public Person
    {
        std::string m_name{};
        std::string m_age{};
        std::string m_id{};
        std::string *m_courses{};
        size_t m_count{};

    public:
        Student(std::istream &);
        std::string status() const { return "Student"; }
        std::string name() const { return m_name; };
        std::string age() const { return m_age; }
        std::string id() const { return m_id; };
        void display(std::ostream &out) const;
        ~Student();
    };
} // namespace seneca

#endif //! STUDENT_H