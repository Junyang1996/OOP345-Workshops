#include <vector>
#include <iomanip>
#include "Person.h"
#include "College.h"
using namespace std;
namespace seneca
{
    College::~College()
    {
        for (Person *person : m_persons)
            delete person;
        m_persons.clear();
    }
    College &College::operator+=(Person *thePerson)
    {
        m_persons.push_back(thePerson);
        return *this;
    }
    void College::display(std::ostream &out) const
    {
        vector<Person *>::const_iterator it;
        out << "-----------------------------------------\n"
               " Test #1 Persons in the college!        |\n"
               "-----------------------------------------\n";
        for (it = m_persons.begin(); it != m_persons.end(); it++)
        {
            (*it)->display(out);
            out << endl;
        }
        out << "-----------------------------------------\n";
        out << "-----------------------------------------\n"
               " Test #2 Persons in the college!        |\n"
               "-----------------------------------------\n";
        for (it = m_persons.begin(); it != m_persons.end(); it++)
        {
            out << "| " << left << setw(10) << (*it)->status() << " | " << setw(10) << (*it)->id() << " | " << setw(20) << (*it)->name() << " | " << setw(3) << (*it)->age() << endl;
        }
        out << "-----------------------------------------\n";
    }
}
