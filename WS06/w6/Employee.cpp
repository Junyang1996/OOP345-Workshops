#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"
#include "Utilities.h"
using namespace std;
namespace seneca
{

    Employee::Employee(std::istream &is)
    {
        string temp{};
        // store the input into temp
        getline(is, temp, ',');
        // we don't need to store tag
//        trim(temp);
        // temp.erase(0, temp.find(',') + 1);
        // we don't need to store tag
        getline(is, temp, ',');
        m_name = extract_string(temp, ',');
        // temp.erase(0, temp.find(',') + 1);
        // get the age, if it's not a number throw error
        getline(is, temp, ',');
        m_age = extract_string(temp, ',');

        getline(is, temp, ',');
        temp = extract_string(temp, '\n');
        try
        {
            // stoi will throw an error as std::invalid_argument &, so its better to do try and catch instead of if throw
            std::stoi(m_age);
        }
        catch (std::invalid_argument &)
        {
            string answer = m_name + "++Invalid record!";
            throw answer;
        }
        temp.erase(0, temp.find(',') + 1);
        // get the id, if it start with E, it's valid otherwise throw error
        if (temp[0] != 'e' && temp[0] != 'E')
        {
            throw m_name + "++Invalid record!";
        }
        else
        {
            m_id = extract_string(temp, '\n');
        }
    }
    void Employee::display(std::ostream &out) const
    {
        out << "| " << left << setw(10) << status() << " | " << setw(10) << id() << " | " << setw(20) << name() << " | " << setw(3) << age();
    }

}
