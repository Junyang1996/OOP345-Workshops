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

        out << "------------------------------------------------------------------------------------------------------------------------\n"
               "|                                        Test #1 Persons in the college!                                               |\n"
               "------------------------------------------------------------------------------------------------------------------------\n";
        for (it = m_persons.begin(); it != m_persons.end(); it++)
        {
            (*it)->display(out);
            out << endl;
        }

        out << "------------------------------------------------------------------------------------------------------------------------\n"
               "|                                        Test #2 Persons in the college!                                               |\n"
               "------------------------------------------------------------------------------------------------------------------------\n";
        for (it = m_persons.begin(); it != m_persons.end(); it++)
        {
            out << "| " << left << setw(10) << (*it)->status() << "| " << setw(10) << (*it)->id() << "| " << setw(20) << (*it)->name() << " | " << setw(3) << (*it)->age() << " |" << endl;
        }
        out << "------------------------------------------------------------------------------------------------------------------------\n";
    }
}
