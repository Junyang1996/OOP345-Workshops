/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Jan 26, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H
#include <chrono>
#include <string>
namespace seneca
{
    typedef std::chrono::steady_clock::time_point time;
    constexpr int MAX_RECORDS = 10;
    struct Event
    {
        std::string eventName;
        std::string unitsOfTime;
        std::chrono::steady_clock::duration eventDuration;
    };
    class TimedEvents
    {
    private:
        static int numRecords;
        time startTime;
        time endTime;
        Event *event;

    public:
        TimedEvents();
        // rule of 3
        ~TimedEvents();
        TimedEvents(const TimedEvents &);
        TimedEvents &operator=(const TimedEvents &);
        void startClock();
        void stopClock();
        void addEvent(const char *);
        friend std::ostream &operator<<(std::ostream &, const TimedEvents &);
    };

}
#endif //! SENECA_TIMEDEVENTS_H