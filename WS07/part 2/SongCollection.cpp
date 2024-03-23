/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Mar 15, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
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
                song.m_price = stod(trim(temp.substr(85, 5)));
                obj.push_back(song);
            }
            count++;
        }
    }
    void SongCollection::display(std::ostream &out) const
    {

        // Use std::copy to copy elements of obj to the output stream using outputIterator
        // std::copy(obj.begin(), obj.end(), std::ostream_iterator<Song>(out, "\n"));
        for_each(obj.begin(), obj.end(), [&out](const Song &a)
                 { out << a << endl; });

        // the value starts with 0, accumulate all the length into sum
        int totalLength = accumulate(obj.begin(), obj.end(), 0, [](int sum, const Song &song)
                                     { return sum + song.lengthSong; });
        out << "----------------------------------------------------------------------------------------" << endl;
        out << "| " << setfill(' ') << right << setw(77) << "Total Listening Time: " << totalLength / 3600 << ":" << (totalLength % 3600) / 60 << ':' << totalLength % 60 << " |\n";
    }

    std::ostream &operator<<(std::ostream &out, const Song &theSong)
    {
        out << "| " << left << setfill(' ') << setw(20) << theSong.title << " | " << setw(15) << theSong.artist << " | " << setw(20) << theSong.album << " | " << right << setw(6) << theSong.releaseYear << " | " << right << theSong.lengthSong / 60 << ":" << setw(2) << setfill('0') << theSong.lengthSong % 60 << " | " << right << theSong.m_price << " |";
        return out;
    }
    void SongCollection::sort(const std::string sortBy)
    {
        try
        {
            if (sortBy == "title")
            {
                std::sort(obj.begin(), obj.end(), [](const Song &a, const Song &b)
                          { return std::less<std::string>()(a.title, b.title); });
            }
            else if (sortBy == "album")
            {
                std::sort(obj.begin(), obj.end(), [](const Song &a, const Song &b)
                          { return std::less<std::string>()(a.album, b.album); });
            }
            else if (sortBy == "length")
            {
                std::sort(obj.begin(), obj.end(), [](const Song &a, const Song &b)
                          { return std::less<int>()(a.lengthSong, b.lengthSong); });
            }
            else
            {
                throw std::invalid_argument("wrong input.");
            }
        }
        catch (const std::invalid_argument& e)
        {
            cout <<endl<< e.what() << endl;
        }
    }
    void SongCollection::cleanAlbum()
    {
        transform(obj.begin(), obj.end(), obj.begin(), [](Song &a)
                  {
            if(a.album=="[None]")
                {a.album=""; }
                return a; });
    }
    bool SongCollection::inCollection(const std::string p_artist) const
    {
        return any_of(obj.begin(), obj.end(), [p_artist](Song a)
                      {
            if(a.artist==p_artist){
                return true;
            }
            return false; });
    }
    std::list<Song> SongCollection::getSongsForArtist(const std::string p_artist) const
    {

        // find out how many sia is there, make the list accordingly
        size_t size = count_if(obj.begin(), obj.end(), [p_artist](const Song &a)
                               { return a.artist == p_artist; });
        list<Song> list(size);
        copy_if(obj.begin(), obj.end(), list.begin(), [p_artist](const Song &a)
                { return a.artist == p_artist; });
        return list;
    }

}
