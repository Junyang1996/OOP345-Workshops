#include <fstream>
#include <iomanip>
#include <vector>
#include "SpellChecker.h"
#include "Book.h"

using namespace std;
namespace seneca
{
    // to make these 2 statically available to the public
    string SpellChecker::m_badWords[ERROR_WORD_LIST];
    string SpellChecker::m_goodWords[ERROR_WORD_LIST];
    vector<int> SpellChecker::cnt{};

    // receives the address of a C-style null-terminated string that holds the name of the file that contains the misspelled words. If the file exists, this constructor loads its contents. If the file is missing, this constructor throws an exception of type const char*, with the message Bad file name!. Each line in the file has the format BAD_WORD  GOOD_WORD; the two fields can be separated by any number of spaces.
    SpellChecker::SpellChecker(const char *filename)
    {
        std::ifstream file(filename);
        if (!file)
        {
            throw "Bad file name!\n";
        }
        int count = 0;
        string strWord{};
        do
        {
            // load line by line
            getline(file, strWord);
            // get the bad words up until the first white space
            m_badWords[count] = extract_string(strWord, ' ');
            // delete everything before the first white space
            strWord.erase(0, strWord.find(' ') + 1);
            // trim the whitespace for the rest and store it in goodword
            m_goodWords[count] = trim(strWord);
            count++;

        } while (file && count < 6);
    }
    // this operator searches text and replaces any misspelled word with the correct version. It should also count how many times each misspelled word has been replaced.
    void SpellChecker::operator()(std::string &text)
    {
        // this is to count how many time it's been called to fix the misspelled

        for (auto i = 0; i < ERROR_WORD_LIST; ++i)
        {
            // if bad word is found in the string
            if (text.find(m_badWords[i]) != string::npos)
            { // replace the bad word with the good word in the same list.
                text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
                cnt[i]++;
            }
        }
    }
    // inserts into the parameter how many times each misspelled word has been replaced by the correct word using the current instance. The format of the output is:
    void SpellChecker::showStatistics(std::ostream &out) const
    {
        for (auto i = 0; i < ERROR_WORD_LIST; ++i)
        {
            out << setw(15) << right << m_badWords[i] << ": " << cnt[i] << " replacements" << endl;
        }
    }
}