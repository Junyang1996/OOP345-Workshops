/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * Seneca Email: jwan27@myseneca.ca
 * Completion date: Jan 26, 2024
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <fstream>
#include "StringSet.h"
using namespace std;
namespace seneca
{
    StringSet::StringSet() = default;
    StringSet::StringSet(const char *file_name)
    {
        ifstream file(file_name);
        if (file.is_open())
        {
            string temp;
            while (getline(file, temp, ' '))
            {
                // increment the number of strings
                numOfstring++;
            }
            // allocate memory for the number of strings
            str = new string[numOfstring];
            // reset the file pointer
            file.clear();
            // re-reads the file and loads the strings into the array. Move the file pointer to the beginning of the file
            file.seekg(0, ios::beg);
            for (auto i = 0u; i < numOfstring; i++)
            {
                getline(file, str[i], ' ');
            }
        }
        else
        {
            cerr << "ERROR: Cannot open file [" << file_name << "].\n";
        }
    }
    StringSet::~StringSet()
    {
        if (str != nullptr)
            delete[] str;
        str = nullptr;
    }
    StringSet::StringSet(const StringSet &other)
    {
        *this = other;
    }
    StringSet &StringSet::operator=(const StringSet &other)
    {
        if (this != &other)
        {
            numOfstring = other.numOfstring;
            // delete the old array
            if (str != nullptr)
                delete[] str;
            // allocate memory for the new array
            str = new string[numOfstring];
            for (auto i = 0u; i < numOfstring; i++)
            {
                str[i] = other.str[i];
            }
        }
        return *this;
    }

    size_t StringSet::size() const
    {
        return numOfstring;
    }
    string StringSet::operator[](size_t index) const
    {
        if (index < numOfstring && index >= 0)
        {
            return str[index];
        }
        else
        {
            return "";
        }
    }

}
