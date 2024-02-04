/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Jan 26, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include "Pair.h"
namespace seneca
{
    const int SPECIAL_CAPACITY = 100;

    // T: the type of any element in the collection
    // CAPACITY: the capacity of the collection (a non-type parameter; an integer without sign). This is the maximum number of elements that can be added to the collection
    template <typename T, int CAPACITY>
    class Collection
    // Your design keeps track of the current number of elements stored in the collection (which may differ from the capacity of the collection). Initially the collection has no elements.
    {
        // Class Members
        unsigned int num_elements = 0u;
        T arr[CAPACITY] = {};

        // An object of type T (a dummy object). This object will be returned by member-functions when the client requests an object that is not in the collection.
        T dummy = T{};

    public:
        Collection(T * = nullptr, unsigned int num = 0u);
        Collection(const Collection &other);
        Collection &operator=(const Collection &other);
        // ~Collection();
        virtual ~Collection()
        {
            for (int i = 0; i < CAPACITY; i++)
            {
                arr[i] = T{};
            }
            num_elements = 0u;
        }
        // size(): a query that returns the current number of elements in the collection
        // unsigned int size() const;
        unsigned int size() const { return num_elements; }
        // display(): a query that receives as the parameter an output stream (with default value std::cout) and inserts into the stream all items from the collection (see the sample output for formatting hints).
        std::ostream &display(std::ostream &os = std::cout) const;
        // bool add(const T& item): a mutator that adds a copy of the parameter to the collection if there still is capacity. If the item has been added, this function return true; false otherwise.
        virtual bool add(const T &item);
        // operator[]: a query that receives an index as parameter and returns a copy of the element stored in the collection at the specified index. If the index is not valid (outside the boundaries of the collection), this query returns the dummy object.
        T operator[](int index) const;
        // Add any other private members that your design requires (without changing the specs above)!
    };
    template <typename T, int CAPACITY>
    Collection<T, CAPACITY>::Collection(T _arr[], unsigned int _num) : dummy{}
    {
        for (auto i = 0u; i < _num && i < CAPACITY; ++i)
        {
            arr[i] = _arr[i];
        }
        num_elements = _num;
    }

    template <typename T, int CAPACITY>
    Collection<T, CAPACITY>::Collection(const Collection<T, CAPACITY> &other)
    {
        for (auto i = 0; i < other.num_elements && i < CAPACITY; ++i)
        {
            arr[i] = other.arr[i];
        }
        num_elements = other.num_elements;
    }

    template <typename T, int CAPACITY>
    Collection<T, CAPACITY> &Collection<T, CAPACITY>::operator=(const Collection<T, CAPACITY> &other)
    {
        if (this != &other)
        {
            for (auto i = 0; i < other.num_elements && i < CAPACITY; ++i)
            {
                arr[i] = other.arr[i];
            }
            num_elements = other.num_elements;
        }
        return *this;
    }

    // display(): a query that receives as the parameter an output stream (with default value std::cout) and inserts into the stream all items from the collection (see the sample output for formatting hints).
    template <typename T, int CAPACITY>
    std::ostream &Collection<T, CAPACITY>::display(std::ostream &os) const
    {
        os << "----------------------\n"
              "| Collection Content |\n"
              "----------------------\n";
        for (auto i = 0u; i < num_elements; i++)
        {
            os << arr[i] << std::endl;
        }
        os << "----------------------\n";
        return os;
    }
    // bool add(const T& item): a mutator that adds a copy of the parameter to the collection if there still is capacity. If the item has been added, this function return true; false otherwise.
    template <typename T, int CAPACITY>
    bool Collection<T, CAPACITY>::add(const T &item)
    {
        bool answer = false;
        for (const auto &element : arr)
        {
            if (element == item)
            {
                answer = false;
            }
        }
        // if the num of elem is larget than the capacity,
        //  it will return false,
        //  if its smaller add the item num of elem+1 if its the same sized,
        //  just add it up
        if (num_elements > CAPACITY)
        {
            answer = false;
        }
        else if (num_elements < CAPACITY)
        {
            arr[num_elements] = item;
            num_elements++;
            answer = true;
        }
        else
        {
            arr[num_elements] = item;
            answer = true;
        }

        return answer;
    }

    // operator[]: a query that receives an index as parameter and returns a copy of the element stored in the collection at the specified index. If the index is not valid (outside the boundaries of the collection), this query returns the dummy object.
    template <typename T, int CAPACITY>
    T Collection<T, CAPACITY>::operator[](int index) const
    {
        if (index > CAPACITY)
            return dummy;
        else
            return arr[index];
    }

    // Specialize the dummy object when type T = Pair and CAPACITY = 100 so the key is "No Key" and the value is "No Value".
    template <>
    class Collection<Pair, SPECIAL_CAPACITY>
    {
        Pair arr[SPECIAL_CAPACITY];
        Pair dummy{"No Key", "No Value"};
        unsigned int num_elements = 0;

    public:
        Collection(Pair *arr = nullptr, unsigned int num = 0u)
        {
            // If arr is not null, copy the elements to this collection
            if (arr != nullptr)
            {
                for (unsigned int i = 0; i < num && i < 100; ++i)
                {
                    this->arr[i] = arr[i];
                }
            }
            // Set the number of elements
            this->num_elements = num;
        }
        Collection(Collection &other)
        {
            for (auto i = 0u; i < other.num_elements && i < SPECIAL_CAPACITY; ++i)
            {
                arr[i] = other.arr[i];
            }
            num_elements = other.num_elements;
        }
        Collection &operator=(Collection &other)
        {
            if (this != &other)
            {
                for (auto i = 0; i < other.num_elements && i < SPECIAL_CAPACITY; ++i)
                {
                    arr[i] = other.arr[i];
                }
                num_elements = other.num_elements;
            }
            return *this;
        }

        virtual ~Collection()
        {
            for (int i = 0; i < SPECIAL_CAPACITY; i++)
            {
                arr[i] = Pair{};
            }
            num_elements = 0u;
        }

        unsigned int size() const { return num_elements; }
        std::ostream &display(std::ostream &os = std::cout) const
        {
            os << "----------------------\n"
                  "| Collection Content |\n"
                  "----------------------\n";
            for (auto i = 0u; i < num_elements; i++)
            {
                os << arr[i] << std::endl;
            }
            os << "----------------------\n";
            return os;
        }

        virtual bool add(const Pair &item)
        {
            bool answer = false;
            for (const auto &element : arr)
            {
                if (element == item)
                {
                    answer = false;
                }
            }
            // if the num of elem is larget than the capacity,
            //  it will return false,
            //  if its smaller add the item num of elem+1 if its the same sized,
            //  just add it up
            if (num_elements > SPECIAL_CAPACITY)
            {
                answer = false;
            }
            else if (num_elements < SPECIAL_CAPACITY)
            {
                arr[num_elements] = item;
                num_elements++;
                answer = true;
            }
            else
            {
                arr[num_elements] = item;
                answer = true;
            }

            return answer;
        }
        Pair operator[](int index) const
        {
            if (index > num_elements)
                return dummy;
            else
                return arr[index];
        }
    };
}

#endif //! COLLECTION_H