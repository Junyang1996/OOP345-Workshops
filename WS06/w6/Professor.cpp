#include <string>
#include "Professor.h"
#include "Utilities.h"
using namespace std;
namespace seneca
{
    Professor::Professor(std::istream &in) : Employee(in)
    {
        string temp{};
        getline(in, temp);
        m_department = trim(temp);
    }
    void Professor::display(std::ostream &out) const
    {
        Employee::display(out);
        out << m_department << "|" << status();
    }
}
