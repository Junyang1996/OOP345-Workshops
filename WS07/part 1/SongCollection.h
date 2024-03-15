#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H
#include <string>
namespace seneca
{
    struct Song
    {
        std::string artist{};
        std::string title{};
        std::string album{};
        double price{};
        unsigned int releaseYear{};
        unsigned int lengthSong{};
    };
    class SongCollection
    {
        Song *obj{};

    public:
        SongCollection(const char *fileName);
        void display(std::ostream &out) const;
    };
    std::ostream &operator<<(std::ostream &out, const Song &theSong);
}
#endif //! SONGCOLLECTION_H