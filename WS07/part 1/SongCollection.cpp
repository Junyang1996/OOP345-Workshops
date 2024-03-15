#pragma endregion
#include <fstream>
#include <iostream>
#include "SongCollection.h"
using namespace std;
namespace seneca
{
    SongCollection::SongCollection(const char *fileName)
    {
        ifstream file(fileName);
        if (!file)
        {
            std::cerr << "ERROR: Cannot open file [" << fileName << "].\n";
            return;
        }
        while (file)
        {
            // TODO: This code can throw errors to signal that something
            //         went wrong while extracting data. Write code to catch
            //         and handle the exceptions.
            try
            {
                Song *song = new Song;
                std::string temp{};
                std::getline(file, temp);

                if (temp.length() < 90) // Check if the line is shorter than expected
                    throw std::runtime_error("Line is too short");

                song->title = temp.substr(0, 25);
                song->artist = temp.substr(25, 25);
                song->album = temp.substr(50, 25);
                song->releaseYear = stoi(temp.substr(75, 5));
                song->lengthSong = stoi(temp.substr(80, 5));
                song->price = stod(temp.substr(85, 5));
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        }
    void SongCollection::display(std::ostream &out) const
    {
    }

    std::ostream &operator<<(std::ostream &out, const Song &theSong)
    {
    }
}