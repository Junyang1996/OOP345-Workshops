/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Mar 14, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/

#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H
#include <string>
#include <list>
#include <vector>
namespace seneca
{
    struct Song
    {
        std::string artist{};
        std::string title{};
        std::string album{};
        double m_price{};
        std::string releaseYear{};
        unsigned int lengthSong{};
    };
    class SongCollection
    {

        std::vector<Song> obj{};

    public:
        SongCollection(const char *fileName);
        void display(std::ostream &out) const;
        void sort(const std::string sortBy);
        void cleanAlbum();
        bool inCollection(const std::string p_artist) const;
        std::list<Song> getSongsForArtist(const std::string p_artist) const;
    };
    std::ostream &operator<<(std::ostream &out, const Song &theSong);
    std::string trim(const std::string &str);
}
#endif //! SENECA_SONGCOLLECTION_H