/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Feb 9, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/

#include <string>
#include <iostream>
#include <iomanip>
#include "Toy.h"
using namespace std;
namespace seneca
{

    void Toy::set()
    {
        _m_order_id = 0;
        _m_name = "";
        _m_item_number = 0;
        _m_price = 0.0;
    }
    Toy::Toy()
    {
        set();
    }
    Toy::Toy(Toy &other)
    {
        _m_order_id = other._m_order_id;
        _m_name = other._m_name;
        _m_item_number = other._m_item_number;
        _m_price = other._m_price;
    }
    Toy &Toy::operator=(Toy &other)
    {
        if (this != &other)
        {
            _m_order_id = other._m_order_id;
            _m_name = other._m_name;
            _m_item_number = other._m_item_number;
            _m_price = other._m_price;
        }
        return *this;
    }
    Toy::~Toy()
    {
        set();
    }
    string trim(const string &str)
    {
        string output;
        for (char c : str)
        {
            if (c != ' ')
            {
                output += c;
            }
        }
        return output;
    }

    string extract_string(const string &_str, const char dilimiter)
    {
        string str = trim(_str);
        size_t index = str.find(dilimiter); // the id idex
        return str.substr(0, index);        // store the
    }
    // use find to find the first :, take it as a int using stoi() stod() for double, repeat it until the end of the string
    // size_t index = toy.find(':'); // the id idex
    Toy::Toy(const std::string &toy)
    {
        string sub_str_toy = toy;
        // get id
        _m_order_id = stoi(extract_string(sub_str_toy, ':'));
        // delete the id from the string, copied
        sub_str_toy.erase(0, sub_str_toy.find(':') + 1);
        // get name
        _m_name = extract_string(sub_str_toy, ':');
        // delete name from the string
        sub_str_toy.erase(0, sub_str_toy.find(':') + 1);
        // get _m_item_number
        _m_item_number = stoi(extract_string(sub_str_toy, ':'));
        // delete num from the string
        sub_str_toy.erase(0, sub_str_toy.find(':') + 1);
        // get _m_price, it's the last piece of string, just convert it to double and store it in the attribute
        _m_price = stod(sub_str_toy);
    }
    void Toy::update(int numItems)
    {
        _m_item_number = numItems;
    }

    ostream &operator<<(ostream &os, Toy &toy)
    {
        os << "Toy";
        os << setw(8) << toy._m_order_id << ":";
        os << setw(18) << right << toy._m_name;
        os << setw(3) << toy._m_item_number << " items";
        os << setw(8) << toy._m_price;
        os << " /item subtotal:";
        os << setw(7) << toy._m_price * toy._m_item_number;
        os << " tax:";
        os << setw(6) << std::fixed << std::setprecision(2) << toy._m_hst_percent * toy._m_price * toy._m_item_number;
        os << " total:";
        os << setw(7) << toy._m_hst_percent * toy._m_price * toy._m_item_number + toy._m_price * toy._m_item_number << endl;
        return os;
    }

}
