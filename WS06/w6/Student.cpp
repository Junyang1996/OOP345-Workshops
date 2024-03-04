#include <string>
#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Student.h"
using namespace std;
namespace seneca
{
    Student::Student(std::istream &is)
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
        try
        {
            // stoi will throw an error as std::invalid_argument &, so its better to do try and catch instead of if throw
            std::stoi(m_age);
        }
        catch (std::invalid_argument &)
        {
            string answer = m_name + "++Invalid record! wrong age";
            throw answer;
        }
        getline(is, temp, ',');
        temp = trim(temp);
        if (temp[0] != 's' && temp[0] != 'S')
        {
            throw m_name + "++Invalid record! invalid id";
        }
        else
        {
            m_id = extract_string(temp, ',');
        }
        getline(is, temp, ',');

        // remove white space and then check if it's a int
        // if (!std::stoi(trim(temp)))
        // {
        //     throw m_name + "++Invalid record!";;
        // }
        // else
        // {
        //     m_count = std::stoi(trim(temp));
        // }
        try
        {
            m_count = std::stoi(trim(temp));
        }
        catch (std::invalid_argument &)
        {
            throw m_name + "++Invalid record! invalid count";
        }
        // if (std::stoi(trim(temp)))
        //     m_count = std::stoi(trim(temp));

        m_courses = new string[m_count];
        for (auto i = 0u; i < m_count; ++i)
        {
            if (i != (m_count - 1))
            {
                getline(is, temp, ',');
                m_courses[i] = trim(temp);
            }
            else
            {
                getline(is, temp, '\0');
                m_courses[i] = trim(temp);
            }
        }
    }
    void Student::display(std::ostream &out) const
    {
        out << "| " << setw(10) << status() << " | " << setw(10) << id() << " | " << setw(20) << name() << " | " << setw(3) << age() << " |";
        for (auto i = 0u; i < m_count; i++)
        {
            out << m_courses[i];
            if (i != (m_count - 1))
                out << ", ";
        }
    }
    Student::~Student()
    {
        if (m_courses != nullptr)
            delete[] m_courses;
        m_courses = nullptr;
        m_count = 0;
    }
}
