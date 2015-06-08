#ifndef OVERLOADEDOPERATORS_H
#define OVERLOADEDOPERATORS_H

#include <string>

bool operator>(const std::string& a, const std::string& b)
{
    unsigned int i = 0;
    while (a[i] == b[i])
    {
        i++;
        if (i == a.size()) return true;
        else if (i == b.size()) return false;
    }

    return a[i] > b[i];
}

bool operator>=(const std::string& a, const std::string& b)
{
    return (a > b || (a.compare(b) == 0));
}

bool operator<(const std::string& a, const std::string& b)
{
    return !(a >= b);
}

#endif // OVERLOADEDOPERATORS_H
