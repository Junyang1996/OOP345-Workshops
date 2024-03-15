
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
#include <string>
#include "Student.h"
#include "Person.h"
#include "Professor.h"
#include "Utilities.h"
using namespace std;
namespace seneca
{
    Person *buildInstance(std::istream &in)
    {
        Person *person = nullptr;

        std::string line;
        if (!std::getline(in, line))
        {
            // early exit if there"s no line to read
            return nullptr;
        }

        std::stringstream strings(line);

        if (line.substr(0, 1) == "e" || line.substr(0, 1) == "E")
        {
            person = new Employee(strings);
        }
        else if (line.substr(0, 1) == "s" || line.substr(0, 1) == "S")
        {
            person = new Student(strings);
        }
        else if (line.substr(0, 1) == "p" || line.substr(0, 1) == "P")
        {
            person = new Professor(strings);
        }

        return person;
    }
    string trim(const string &str)
    {
        string output = str;
        // Find the index of the first non-whitespace character
        size_t firstNonWhitespace = output.find_first_not_of(' ');
        // Erase leading whitespace characters
        output.erase(0, firstNonWhitespace);
        // Find the index of the last non-whitespace character
        size_t lastNonWhitespace = output.find_last_not_of(" ");
        // Erase trailing whitespace characters
        if (lastNonWhitespace != string::npos)
            output.erase(lastNonWhitespace + 1);
        return output;
    }
    string extract_string(const string &_str, const char delimiter)
    {
        // find the index of the delimiter
        size_t index = _str.find(delimiter);
        // return the trimed string until the delimiter
        return trim(_str.substr(0, index));
    }
}
