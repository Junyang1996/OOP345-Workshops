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
#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>
#include <sstream>
#include "Person.h"
#include "Employee.h"
namespace seneca
{

    Person *buildInstance(std::istream &in);
    std::string trim(const std::string &str);
    std::string extract_string(const std::string &_str, const char delimiter);

}
#endif //! UTILITIES_H