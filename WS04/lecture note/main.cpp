#include <iostream>
using namespace std;
// 1 1 2 3 5 8 13v 21 34

void display(double *arr, int cnt)
{
    for (int i = 0; i < cnt; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
bool asc(const double &a, const double &b) { return a > b; }
bool desc(const int &a, const int &b) { return b > a; }
bool posNeg(const double &a, const double &b)
{
    if (a > 0 && b < 0)
        return false;
    if (a > 0 && b > 0)
        return false;
    if (a < 0 && b < 0)
        return false;
    if (a < 0 && b > 0)
        return true;
}
void selectionSort(double *arr, int cnt, bool (*comp)(const double &, const double &))
{
    for (int i = 0; i < cnt - 1; ++i)
    {
        for (int j = i + 1; j < cnt; ++j) // Fixed the condition to iterate over the array indices.
        {
            if (comp(arr[i], arr[j])) // should i switch the numbers?
            {
                auto tmp = arr[j];
                arr[j] = arr[i]; // Fixed the assignment to swap the numbers.
                arr[i] = tmp;
            }
        }
    }
}

// create an alias for a function that return bool and receives 2 doubles
// typedef bool(comparator_f)(const double &, const double &);
// using comparator_f = bool (*)(const double &, const double &);

class Comparator
{
public:
    bool operator()(const double &a, const double &b)
    {
        asc(a, b);
    }
};

int main(int, char **)
{
    double arr[] = {3.5, 9.2, 4.1, 0.1, -4.33};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    char choice{};
    cout << "sort how? (a/s/p)";
    comparator_f *comp_f;
    comp_f = &asc;
    display(arr, size);               // Pass the correct size to the display function
    selectionSort(arr, size, comp_f); // Pass the correct size to the selectionSort function
    display(arr, size);               // Pass the correct size to the display function
}
