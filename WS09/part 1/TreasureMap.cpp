// Name: Lawrence Wan
// Seneca Student ID: 105442230
// Seneca email:jwan27@myseneca.ca
// Date of completion: March 31, 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <fstream>
#include <thread>
#include <functional>
#include <future>
#include <vector>
#include <string>
#include "TreasureMap.h"

namespace seneca
{

    size_t digForTreasure(const std::string &str, char mark)
    {
        size_t cnt = 0;
        for (auto &x : str)
        {
            if (x == mark)
            {
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char *filename)
    {
        std::fstream fin(filename);
        if (fin)
        {
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while (fin)
            {
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else
        {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap()
    {
        delete[] map;
    }

    std::ostream &TreasureMap::display(std::ostream &os) const
    {
        if (map)
        {
            for (size_t i = 0; i < rows; ++i)
            {
                os << map[i] << std::endl;
            }
        }
        else
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char *filename)
    {
        // Binary write
        if (map)
        {

            // TODO: Open a binary file stream to the filename
            std::ofstream fin(filename, std::ios::out | std::ios::binary | std::ios::trunc);
            // and then write the row number to the binary file
            // then each of the rows of the map.
            if (fin)
            {
                // we have to cast the these 2 into char* and given a size when writing into a file.
                fin.write(reinterpret_cast<char *>(&rows), sizeof(rows));
                fin.write(reinterpret_cast<char *>(&colSize), sizeof(colSize));
                for (auto i = 0u; i < rows; i++)
                {
                    std::string &line = map[i];
                    std::string newLine;
                    for (char c : line)
                    {
                        if (c != '\0')
                        {
                            newLine += c;
                        }
                    }
                    fin.write(newLine.c_str(), colSize);
                }
            }
            else
            {
                // If the file cannot be open, raise an exception to
                // inform the client.

                // END TODO
                throw std::string("Failed to open file, please try again.");
            }
        }
        else
        {
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char *filename)
    {
        // Binary read

        std::ifstream ifs(filename, std::ios::in | std::ios::binary);
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        if (ifs)
        {
            ifs.read(reinterpret_cast<char *>(&rows), sizeof(rows));
            //         for the map followed another 4 bytes for the colSize
            //         of each row in the map.
            ifs.read(reinterpret_cast<char *>(&colSize), sizeof(colSize));
            //       Afterwards is each row of the map itself.-8
            //       If the file cannot be open, raise an exception to inform
            //         the client.
            // allocate map according to the number of rows
            map = new std::string[rows];
            for (auto i = 0u; i < rows; i++)
            {
                char c;
                for (auto j = 0u; j < colSize; j++)
                {
                    ifs.read(&c, 1);
                    if (c != '\0')
                    {
                        map[i] += c;
                    }
                    // else
                    // {
                    //     map[i] += '*';
                    // }
                }
            }
        }
        else
        {
            // If the file cannot be open, raise an exception to
            // inform the client.

            // END TODO
            throw std::string("Failed to open file, please try again.");
        }

        // END TODO
    }

    void TreasureMap::clear()
    {
        delete[] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark)
    {
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        // for (size_t i = 0; i < rows; ++i)
        // {
        //     count += digForTreasure(map[i], mark);
        // }
        constexpr int NT = 4; // number of threads
        std::vector<std::packaged_task<size_t(std::string)>> tasks(NT);
        std::vector<std::future<size_t>> futures(NT);
        std::vector<std::thread> threads(NT);

        // Create some packaged_tasks (the number should match the number of threads used) with the bound version of digForTreasure()
        for (int i = 0; i < NT; ++i)
        {
            // use bind to bind one argument with mark
            tasks[i] = std::packaged_task<size_t(std::string)>(std::bind(digForTreasure, std::placeholders::_1, mark));
            // Associate these packaged_tasks with some future objects to eventually retrieve the result of those tasks (ie the count of treasure)
            futures[i] = tasks[i].get_future();
        }

        for (int i = 0; i < NT; ++i)
        {
            // calculate start and end for this thread
            size_t start = i * rows / NT;
            size_t end = (i + 1) * rows / NT;

            // concatenate strings in assigned rows
            std::string data;
            for (size_t j = start; j < end; ++j)
            {
                data += map[j];
            }

            // Create some threads and provided them these packaged_tasks and the partitioned data to be processed
            threads[i] = std::thread(std::move(tasks[i]), std::move(data));
        }

        for (auto &thread : threads)
            thread.join();

        // Retrieve the data from the futures once the threads have completed their tasks

        for (auto &future : futures)
        {
            count += future.get();
        }

        return count;
    }
}