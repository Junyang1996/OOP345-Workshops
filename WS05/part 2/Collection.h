#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <string>
namespace seneca
{
    template <typename T>
    class Collection
    {
        std::string _name{};
        T *obj;
        size_t _size{};
        void (*observer)(const Collection<T> &, const T &) = nullptr;

    public:
        Collection(const std::string &name)
        {
            _name = name;
            obj = {};
            _size = {};
        }
        // this class doesn't support any copy operations; delete all of them.
        Collection(const Collection &) = delete;
        Collection &operator=(Collection &) = delete;
        ~Collection()
        {
            for (auto i = 0u; i < _size; ++i)
            {
                obj[i] = T{};
            }
            delete[] obj;
            _size = {};
            _name = {};
            observer = {};
        }
        // a query that returns the name of the collection.
        const std::string &name() const { return _name; }
        // a query that returns the number of items in the collection.
        size_t size() const { return _size; }
        void setObserver(void (*observer)(const Collection<T> &, const T &));
        Collection<T> &operator+=(const T &item);
        T &operator[](size_t idx) const;
        T *operator[](const std::string &title) const;
    };

    // void setObserver(void (*observer)(const Collection<T>&, const T&)): stores the address of the callback function (observer) into an attribute. This parameter is a pointer to a function that returns void and accepts two parameters: a collection and an item that has just been added to the collection. This function is called when an item is added to the collection.
    template <typename T>
    void Collection<T>::setObserver(void (*observer)(const Collection<T> &c, const T &))
    {
        this->observer = observer;
    }
    // adds a copy of item to the collection, only if the collection doesn't contain an item with the same title. If item is already in the collection, this function does nothing. If the item is not yet in the collection, this function:
    template <typename T>
    Collection<T> &Collection<T>::operator+=(const T &item)
    {
        bool found = false;
        for (auto i = 0u; i < _size; ++i)
        {
            if (obj[i].title() == item.title())
            {
                // if the address of toy is already in the array, this operator does nothing
                found = true;
            }
        }
        if (!found)
        {
            // resizes the array to make room for toy if necessary
            T *newObj = new T[_size + 1];
            for (size_t i = 0; i < _size; ++i)
            {
                newObj[i] = obj[i];
            }
            for (auto i = 0u; i < _size; ++i)
            {
                obj[i] = T{};
            }

            delete[] obj;

            obj = newObj;

            // resizes the array of items to accommodate the new item
            obj[_size] = item;
            _size++;
            // if an observer has been registered, this operator calls the observer function passing the current object (*this) and the new item as arguments.
            //  ASSUMPTION: type T has a member function called title() that returns the title of the item (std::string).
            if (*this->observer != nullptr)
                (*observer)(*this, item);
        }

        return *this;
    }
    template <typename T>
    T &Collection<T>::operator[](size_t idx) const
    {
        if (idx < _size && _size != 0)
            return obj[idx];
        // if the index is out of range, this operator throws an exception of type std::out_of_range with the message Bad index [IDX]. Collection has [SIZE] items.. Use operator + to concatenate strings.
        else
        {
            throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(_size) + "] items.");
        }
    }
    // T* operator[](const std::string& title) const: returns the address of the item with the title title (type T has a member function called title() that returns the title of the item). If no such item exists, this function returns nullptr.
    template <typename T>
    T *Collection<T>::operator[](const std::string &title) const
    {
        for (auto i = 0u; i < _size; ++i)
        {
            if (obj[i].title() == title)
                return &obj[i];
        }
        return nullptr;
    }
    // overload the insertion operator to insert the content of a Collection object into an ostream object. Iterate over all elements in the collection and insert each one into the ostream object (do not add newlines).
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const Collection<T> &c)
    {
        for (auto i = 0u; i < c.size(); ++i)
            os << c[i];
        return os;
    }
}
#endif //! SENECA_COLLECTION_H