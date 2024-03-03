#ifndef COLLEGE_H
#define COLLEGE_H
#include <vector>
#include <list>
#include "Person.h"
namespace seneca
{
    class College
    {
        std::vector<Person *> m_persons{};

    public:
        ~College();
        College &operator=(College &) = delete;
        College &operator+=(Person *thePerson);
        void display(std::ostream &out) const;
        template <typename T>
        void select(const T &test, std::list<const Person *> &persons)
        {
            std::vector<Person *>::const_iterator it;
            // go over each person in m_persons
            for (it = m_persons.begin(); it != m_persons.end(); it++)
            {
                if (test)
                {
                    persons.push_back(*it);
                }
            }
        };
    };

}
#endif //! COLLEGE_H