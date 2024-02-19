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

#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#define ERROR_WORD_LIST 6
#include <string>
namespace seneca
{

    // Add a SpellChecker module to your project. This module holds two parallel arrays of strings, both of size 6 (statically allocated):
    class SpellChecker
    {
    public:
        static int cnt[];
        static std::string m_badWords[ERROR_WORD_LIST];
        static std::string m_goodWords[ERROR_WORD_LIST];
        SpellChecker(const char *filename);
        void operator()(std::string &text);
        void showStatistics(std::ostream &out) const;
    };
}
#endif //! SENECA_SPELLCHECKER_H