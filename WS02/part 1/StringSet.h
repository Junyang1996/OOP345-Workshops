/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Jan 26, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H
#include <string>
namespace seneca
{
    class StringSet
    {
    private:
        size_t numOfstring = 0;
        std::string *str;

    public:
        StringSet();
        StringSet(const char *);
        ~StringSet();
        size_t size() const;
        std::string operator[](size_t) const;
    };

}
#endif