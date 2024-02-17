/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Feb 17, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#include <string>
#include <iostream>
#include <iomanip>
#include "Book.h"
using namespace std;
namespace seneca
{
    // a function that returns the price by reference, allowing the client code to update the price
    double &Book::price()
    {
        return _price;
    }
    string trim(const string &str)
    {
        string output = str;
        // Find the index of the first non-whitespace character
        size_t firstNonWhitespace = output.find_first_not_of(" \t");
        // Erase leading whitespace characters
        output.erase(0, firstNonWhitespace);
        // Find the index of the last non-whitespace character
        size_t lastNonWhitespace = output.find_last_not_of(" \t");
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

    Book::Book(const std::string &strBook)
    {
        string temp_book = strBook;
        _author = extract_string(temp_book, ',');
        // delete the string up until the first ,;
        temp_book.erase(0, temp_book.find(',') + 1);
        // store title
        _title = extract_string(temp_book, ',');
        // delete the string up until the first ,;
        temp_book.erase(0, temp_book.find(',') + 1);
        // store country
        _country = extract_string(temp_book, ',');
        temp_book.erase(0, temp_book.find(',') + 1);
        // store price
        _price = stod(extract_string(temp_book, ','));
        temp_book.erase(0, temp_book.find(',') + 1);
        // store year
        _year = stoi(extract_string(temp_book, ','));
        temp_book.erase(0, temp_book.find(',') + 1);
        // store description
        _description = trim(temp_book);
    }
    ostream &operator<<(ostream &os, const Book &book)
    {
        os << setw(20) << book._author << " | ";
        os << setw(22) << book.title() << " | ";
        os << setw(5) << book.country() << " | ";
        os << setw(4) << book.year() << " | ";
        os << setw(6) << std::fixed << std::setprecision(2) << book._price << " | ";
        os << book._description << endl;
        return os;
    }
}