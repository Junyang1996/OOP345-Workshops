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
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <string>
#include <iostream>
namespace seneca
{
    class Book
    {
        std::string _author{};
        std::string _title{};
        std::string _country{};
        size_t _year = 0;
        double _price = 0.0;
        std::string _description{};

    public:
        Book() = default;
        Book(const Book &other) = default;
        Book &operator=(const Book &other) = default;
        ~Book() = default;
        const std::string &title() const { return _title; }
        const std::string &country() const { return _country; }
        const size_t &year() const { return _year; }
        double &price();
        Book(const std::string &strBook);
        friend std::ostream &operator<<(std::ostream &os, const Book &book);
    };
    std::string trim(const std::string &str);
    std::string extract_string(const std::string &_str, const char delimiter);
}
#endif //! SENECA_BOOK_H