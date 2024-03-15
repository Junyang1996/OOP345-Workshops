#ifndef COLLEGE_H
#define COLLEGE_H
#include <vector>
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
    };

}
#endif //! COLLEGE_H