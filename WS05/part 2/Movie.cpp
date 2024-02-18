#include <string>
#include <iostream>
#include <iomanip>
#include "Movie.h"
#include "Book.h"
using namespace std;
namespace seneca
{
    Movie::Movie(const std::string &strMovie)
    {
        if (strMovie[0] != '#')
        {
            string temp = strMovie;
            _title = extract_string(temp, ',');
            // delete the string up until the first ,;
            temp.erase(0, temp.find(',') + 1);
            _year = extract_string(temp, ',');
            // delete the string up until the first ,;
            temp.erase(0, temp.find(',') + 1);
            _title = temp;
        }
    }
    std::ostream &operator<<(std::ostream &os, const Movie &mv)
    {
        os << setw(40) << mv._title << " | " << setw(4) << mv._year << " | " << mv._description << endl;

        return os;
    }
}
