/*************************************************************************************
 *
 * Student Name : Junyang Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "event.h"
using namespace std;
namespace seneca
{
    static int counter = 0;
    unsigned int g_sysClock = 0;
    Event::Event()
    {
        set();
    }

    Event::Event(char *_des, int _sec_passed)
    {
        if (_des != nullptr && _sec_passed >= 0 && _sec_passed <= 86400)
        {

            alocpy(des, _des);
            event_starts = _sec_passed;
        }
        else
        {
            set();
        }
    }
    Event::Event(const Event &other)
    {
        set(other.des);
        event_starts = other.event_starts;
    }
    Event &Event::operator=(const Event &other)
    {
        if (this != &other)
        {
            set(other.des);
            event_starts = other.event_starts;
        }
        return *this;
    }
    Event::~Event()
    {
        set();
        // event_starts = 0;
    }
    // // If no description has been stored in the current object, this query should print:
    // COUNTER. | No Event |
    // where
    // COUNTER is a field of size 2, that holds the number of times that this function has been called (use a local-to-function variable that remains in memory for the lifetime of the program) Do not use global/member variables to store the counter!
    // HH:MM:SS represents the time when the event started, expressed in hours, minutes and seconds
    void Event::display()
    {
        // a query that displays to the screen the content of an Event instance in the following format:
        // COUNTER. HH:MM:SS => DESCRIPTION
        // int total_seconds = g_sysClock - event_starts;
        int hr = event_starts / 3600;
        event_starts %= 3600; // discard the hour
        int min = event_starts / 60;
        int sec = event_starts % 60;
        if (des == nullptr || des[0] == '\0')
        {
            cout << setw(2) << ++counter
                 << ". | No Event |" << endl;
        }
        else
        {
            cout << ++counter
                 << ". " << setw(2) << setfill('0') << hr << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec << " => " << des << endl;
        }
    }
    // set(): a modifier that receives the address of an array of characters (by default, the parameter is null).
    // If the address is not null and the array is not empty, this function starts a new event and stores the information about this event in the current instance.
    // If the address is null or the array is empty, this function resets the current instance to an empty state.

    void Event::set(const char arr[])
    {
        if (arr == nullptr || arr[0] == '\0')
        {
            alocpy(des, nullptr);
            event_starts = 0;
        }
        else
        {
            alocpy(des, arr);
            event_starts = g_sysClock;
        }
    }

    // Safely allocates memory in the destination argument and copies the source into it.
    void alocpy(char *&destination, const char *source)
    {
        if (destination != nullptr)
        {
            delete[] destination;
        }
        destination = nullptr;
        if (source != nullptr)
        {
            // Allocate memory for the new description
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }
}
