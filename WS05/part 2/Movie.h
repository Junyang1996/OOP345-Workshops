#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <string>
namespace seneca
{
    class Movie
    {
        std::string _title{};
        std::string _year{};
        std::string _description{};

    public:
        Movie() = default;
        const std::string &title() const { return _title; }
        Movie(const std::string &strMovie);
        template <typename T>
        void fixSpelling(T &spellChecker);
        friend std::ostream &operator<<(std::ostream &os, const Movie &mv);
    };
    template <typename T>
    void Movie::fixSpelling(T &spellChecker)
    {
        spellChecker(_title);
        spellChecker(_description);
    }

}
#endif //! SENECA_MOVIE_H