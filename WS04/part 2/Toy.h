/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Feb 11, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#ifndef SENECA_TOY_H
#define SENECA_TOY_H
#include <string>
#include <iostream>
namespace seneca
{
    class Toy
    {
        unsigned int _m_order_id = 0;
        std::string _m_name = "";
        int _m_item_number = 0;
        double _m_price = 0.0;
        const double _m_hst_percent = 0.13;
        void set();

    public:
        Toy();
        Toy(const Toy &other);
        Toy &operator=(const Toy &other);
        ~Toy();
        Toy(const std::string &toy);

        void update(int numItems);
        friend std::ostream &operator<<(std::ostream &os, const Toy &toy);
    };
    std::string trim(const std::string &str);
    std::string extract_string(const std::string &_str, const char dilimiter);
}
#endif //! SENECA_TOY_H