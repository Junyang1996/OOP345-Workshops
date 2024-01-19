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
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
namespace seneca
{
    extern unsigned int g_sysClock;
    class Event
    {
        char *des = nullptr;
        unsigned int event_starts = 0; // the time when the event starts, expressed in number of seconds that passed from midnight. The time must be an integer between 0 and 86400 (choose an appropriate type).
    public:
        Event();
        // rule of 3
        Event(const Event &other);
        Event &operator=(const Event &other);
        ~Event();
        Event(char *_des, int _sec_passed);
        void display(); // a query that displays to the screen the content of an Event instance in the following format:
        void set(const char arr[] = nullptr);
    };
    void alocpy(char *&destination, const char *source);
}
#endif //! SENECA_EVENT_H