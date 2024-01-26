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
            // move the pointer to the beginning
            file.seekg(0, ios::beg);
        }
    }

}