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
#define SENECA_Collection_H
#include <iostream>
namespace seneca
{

    // T: the type of any element in the collection
    // CAPACITY: the capacity of the collection (a non-type parameter; an integer without sign). This is the maximum number of elements that can be added to the collection
    template <typename T, int CAPACITY>
    class Collection
    // Your design keeps track of the current number of elements stored in the collection (which may differ from the capacity of the collection). Initially the collection has no elements.
    {
        // Class Members
        T arr[CAPACITY] = {};
        unsigned int num_elements;
        // An object of type T (a dummy object). This object will be returned by member-functions when the client requests an object that is not in the collection.
        T dummy;

    public:
        Collection(T * = nullptr, unsigned int num = 0u);
        Collection(Collection &other);
        Collection &operator=(Collection &other);
        ~Collection();
        // size(): a query that returns the current number of elements in the collection
        unsigned int size();
        // display(): a query that receives as the parameter an output stream (with default value std::cout) and inserts into the stream all items from the collection (see the sample output for formatting hints).
        std::ostream &display(std::ostream &os = std::cout);
        // bool add(const T& item): a mutator that adds a copy of the parameter to the collection if there still is capacity. If the item has been added, this function return true; false otherwise.
        bool add(const T &item);
        // operator[]: a query that receives an index as parameter and returns a copy of the element stored in the collection at the specified index. If the index is not valid (outside the boundaries of the collection), this query returns the dummy object.
        T &operator[int index];
        // Add any other private members that your design requires (without changing the specs above)!
    };

    // Specialize the dummy object when type T = Pair and CAPACITY = 100 so the key is "No Key" and the value is "No Value".
    template <>
    class Collection<Pair, 100>
    {
        Pair arr[100];
        Pair dummy{"No Key", "No Value"};
        unsigned int num_elements;

    public:
        Collection(Pair * = nullptr, unsigned int num = 0u);
        Collection(Collection &other);
        Collection &operator=(Collection &other);
        ~Collection();
        unsigned int size();
        std::ostream &display(std::ostream &os = std::cout);
        bool add(const Pair &item);
        Pair &operator[](int index);
    };

}

#endif //! collection_h