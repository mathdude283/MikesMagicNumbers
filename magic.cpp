#include "magic.h"
#include <iostream>
#include <climits>

const unsigned long long int valueFromLimits = ULLONG_MAX;
const unsigned long long int before = (valueFromLimits - 1)/3;

// Takes in two numbers, one recording the current overall value to be checked, and one recording the current position in the magic sequence
bool magic(long long unsigned int x, long long unsigned int loc, bool changed)
{
    // If the current value is less than x, it has previously been checked and found to be magic, so if it is reached, x must be magic, or if 1 has been reached, it is known to be magic.
    if (loc == 1)
    {
        return true;
    }
    // Checks if a loop has been found
    if (x == loc)
    {
        // Marks that the chain has started
        if (!changed)
        {
            changed = true;
        }
        // If x == loc and changed is true, then a loop has been found, so the number is not magic
        else
        {
            std::cout << x << " is not a magic number\n";
            return false;
        }
    }
    // If the current value is even, checks if it is less than twice the current oveall value to be checked. If it is, returns true, otherwise calls itself with loc set to half of its current value
    if (loc % 2 == 0)
    {
        if (loc < 2*x)
        {
            return true;
        }
        return magic(x, loc/2, changed);
    }
    if (loc < x)
    {
        return true;
    }
    // Makes sure multiplying by three and adding one won't overflow the data type
    if (loc >= before)
    {
        std::cout << "Capacity overflowed\n";
        return false;
    }
    // Calls magic with loc set to loc*3+1
    return magic(x, loc*3 + 1, changed);
}