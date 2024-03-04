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
            // early exit if there's no line to read
            return nullptr;
        }

        std::stringstream strings(line);

        if (line.starts_with('e') || line.starts_with('E'))
        {
            person = new Employee(strings);
        }
        else if (line.starts_with('s') || line.starts_with('S'))
        {
            person = new Student(strings);
        }
        else if (line.starts_with('p') || line.starts_with('P'))
        {
            person = new Professor(strings);
        }

        return person;
    }
    string trim(const string &str)
    {
        string output = str;
        // Find the index of the first non-whitespace character
        size_t firstNonWhitespace = output.find_first_not_of(" \\t");
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
