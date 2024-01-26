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
#include <iomanip>
#include "TimedEvents.h"
using namespace std;
namespace seneca
{
    int TimedEvents::numRecords = 0;
    TimedEvents::TimedEvents()
    {
        startTime = chrono::steady_clock::now();
        endTime = chrono::steady_clock::now();
    }
    // rule of 3
    TimedEvents::~TimedEvents()
    {
        delete[] event;
        event = nullptr;
    }
    TimedEvents::TimedEvents(const TimedEvents &other) = default;
    TimedEvents &TimedEvents::operator=(const TimedEvents &) = default;
    void TimedEvents::startClock()
    {
        startTime = chrono::steady_clock::now();
    }
    void TimedEvents::stopClock()
    {
        endTime = chrono::steady_clock::now();
    }

    void TimedEvents::addEvent(const char *event_name)
    {
        if (numRecords < MAX_RECORDS)
        {
            Event *temp = new Event;
            temp->eventName = event_name;
            temp->unitsOfTime = "nanoseconds";
            temp->eventDuration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
            event[numRecords] = *temp;
            numRecords++;
        }
        else
        {
            cout << "ERROR: Exceeded the maximum number of records ( " << MAX_RECORDS << " ) !\n";
        }
    }
    ostream &operator<<(ostream &os, const TimedEvents &timed_event)
    {
        os << "Execution Times:\n";
        os << "--------------------------\n";
        for (int i = 0; i < TimedEvents::numRecords; i++)
        {
            os << setw(21) << left << timed_event.event[i].eventName << ' ' << setw(12) << right << timed_event.event[i].eventDuration.count() << ' ' << timed_event.event[i].unitsOfTime << '\n';
        }
        os << "--------------------------\n";
        return os;
    }
}