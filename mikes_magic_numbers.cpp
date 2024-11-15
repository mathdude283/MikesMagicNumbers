#include <iostream>
#include <string>
#include "magic.h"
const unsigned long long int ENDVALUE = 1000000000;
int main()
{
    long long unsigned int x = 0;

    // Keeps track of whether a nonmagic number has been found
    bool all_magic = true;
    // Starts from 1 and works up. Any even number if reached is guaranteed to be magic assuming it is less than or equal to x, because it can be divided in half to get a positive integer which has already been shown correct.
    while(x < ENDVALUE)
    {
        x++;
        // If a nonmagic value has been found, records that in all_magic and exits the loop
        if (!magic(x, x, false))
        {
            all_magic = false;
            break;
        }
    }
    if (all_magic)
    {
        std::cout << "All numbers from 1 to " << std::to_string(ENDVALUE) << " are magic.\n";
    }
    return 0;
}