#include <iostream>
using namespace std;

bool asc(const double &a, const double &b) { return a > b; }
bool desc(const double &a, const double &b) { return b > a; }
bool postNeg(const double &a, const double &b)
{
    // if(a>0 && b<0)
    //     return false;
    // if(a>0 && b>0)
    //     return false;
    // if(a<0 && b<0)
    //     return false;
    if (a < 0 && b > 0)
        return true;
    return false;
}

class Comparator
{
public:
    // function object/functor
    bool operator()(const double &a, const double &b)
    {
        return asc(a, b);
    }
};

// // this will use a custom function as a parameter
// void selectionSort(double *arr, int cnt, bool (*comp)(const double &, const double &))
// {
//     for (int i = 0; i < cnt - 1; ++i)
//         for (int j = i + 1; j < cnt; ++j)
//             if (comp(arr[i], arr[j])) // should i switch the numbers?
//             {
//                 auto tmp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = tmp;
//             }
// }
template <typename Comp_T>
void selectionSort(double *arr, int cnt, Comp_T comp)
{
    for (int i = 0; i < cnt - 1; ++i)
        for (int j = i + 1; j < cnt; ++j)
            if (comp(arr[i], arr[j])) // should i switch the numbers?
            {
                auto tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
}

void display(double *arr, int cnt)
{
    for (int i = 0; i < cnt; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
// create an alias for "a function that return bool and receives as "
typedef bool(comparator_t)(const double &, const double &);
// //c++ style
// using comparator_t = bool(const double &, const double &);
int main(int, char **)
{
    // TODO: lamba expressions
    double arr[] = {3.5, -9.2, 4.1, 0.1, -4.33, 7.4, -8.1, 8.11};
    // define a function as a variable
    // bool (*comp_f)(const double &, const double &) = nullptr;
    // char choice;
    // cout << "sort how? (a/d/p)";
    // cin >> choice;

    // comparator_t *comp_f;

    // switch (choice)
    // {
    // case 'a':
    //     comp_f = asc;
    //     break;
    // case 'd':
    //     comp_f = desc;
    //     break;
    //     ;
    // default:
    //     comp_f = postNeg;
    //     break;
    // }
    Comparator comp_fo;
    comp_fo(1.2, 4.5);
    display(arr, 8);
    selectionSort(arr, 8, comp_fo);
    display(arr, 8);
}