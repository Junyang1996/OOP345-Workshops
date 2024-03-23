#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "SongCollection.h"
using namespace std;
namespace seneca
{
    string trim(const string &str)
    {
        string output = str;
        // Find the index of the first non-whitespace character
        size_t firstNonWhitespace = output.find_first_not_of(' ');
        // Erase leading whitespace characters
        output.erase(0, firstNonWhitespace);
        // Find the index of the last non-whitespace character
        size_t lastNonWhitespace = output.find_last_not_of(' ');
        // Erase trailing whitespace characters
        if (lastNonWhitespace != string::npos)
            output.erase(lastNonWhitespace + 1);
        return output;
    }

    SongCollection::SongCollection(const char *fileName)
    {
        int count{};
        ifstream file(fileName);
        if (!file)
        {
            std::cerr << "ERROR: Cannot open file [" << fileName << "].\n";
            return;
        }
        while (file)
        {
            Song song;
            std::string temp{};
            std::getline(file, temp);

            // if (temp.length() < 90)
            // Check if the line is shorter than expected
            // {
            //     std::cerr << "ERROR: Line is too short.\n";
            //     continue;
            // }
            if (temp.length() > 0)
            {
                song.title = trim(temp.substr(0, 25));
                song.artist = trim(temp.substr(25, 25));
                song.album = trim(temp.substr(50, 25));
                song.releaseYear = trim(temp.substr(75, 5));
                try
                {
                    stoi(song.releaseYear);
                }
                catch (std::invalid_argument &)
                {
                    song.releaseYear = "";
                }

                song.lengthSong = stoi(trim(temp.substr(80, 5)));
                song.price = stod(trim(temp.substr(85, 5)));
                obj.push_back(song);
            }
            count++;
        }
    }

    void SongCollection::display(std::ostream &out) const
    {
        copy(obj.begin(), obj.end(), ostream_iterator<Song>(out, "\n"));
        int totalLength = accumulate(obj.begin(), obj.end(), 0, [](int sum, const Song &song)
                                     { return sum + song.lengthSong; });
        cout << totalLength;
    }

    std::ostream &operator<<(std::ostream &out, const Song &theSong)
    {
        out << "| " << left << setfill(' ') << setw(20) << theSong.title << " | " << setw(15) << theSong.artist << " | " << setw(20) << theSong.album << " | " << right << setw(6) << theSong.releaseYear << " | " << right << theSong.lengthSong / 60 << ":" << setw(2) << setfill('0') << theSong.lengthSong % 60 << " | " << right << theSong.price << " |";
        return out;
    }
}
