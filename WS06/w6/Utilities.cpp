#include <string>
#include "Utilities.h"
using namespace std;
namespace seneca
{
    Person *buildInstance(std::istream &in)
    {

        std::string line;
        if (!std::getline(in, line))
        {
            return nullptr;
        }

         std::stringstream strings(line);

        if (!line.starts_with('e') && !line.starts_with('E'))
        {
            return nullptr;
        }
        else
        {
            Person *person = new Employee(strings);

            return person;
        }
    }
    string trim(const string &str)
    {
        string output = str;
        // Find the index of the first non-whitespace character
        size_t firstNonWhitespace = output.find_first_not_of(" \\t");
        // Erase leading whitespace characters
        output.erase(0, firstNonWhitespace);
        // Find the index of the last non-whitespace character
        size_t lastNonWhitespace = output.find_last_not_of(" \\t");
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
