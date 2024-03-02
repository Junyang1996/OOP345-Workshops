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