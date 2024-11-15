# Mike's Magic Numbers

## Code logic
* The main logic of my code works by looping through all the numbers from 1 to ENDVALUE (In this case 1,000,000). For each of these numbers, it checks if it is magic. If the number is not magic, a variable is set which marks this and the loop exits. If the loop finishes and no non-magic numbers have been found, A message is printed to that effect.
* The function that checks if a specific number is magic is a recursive function that takes in 3 parameters: x, which is the current number to be checked in the loop, loc, which is the current number in the sequence for x, and changed, which is used to track whether loc is in a loop. First, it checks whether loc == 1, and if so returns true, because 1 is magic. Next, if loc == x, it checks whether this is the first iteration of the function, and if not, prints that x is not magic and returns false, because loc is in a loop. Otherwise, it sets changed to true, so future iterations know that it is no longer the first iteration. Then, it checks if loc is even, and if loc is less than twice x, returns true, because loc must be magic, as described below. If loc is even but greater than or equal to x, it returns the value of the function called with loc set to half of its current value. Then, if loc is less than x, it returns true, because that value of loc would have already been checked as an x value and found to be magic. Next, if the function is still running, it checks if there will be an overflow if the next step is run. If there will, this is printed, and the function returns false. Otherwise, it returns the function called on loc*3+1.

## Potential Speedups
* I started with concluding any even number less than twice the current number to be checked has to be magic, and the program ran in about 26-28 seconds. I kept this.
* I also tried checking if x was a power of two, because if so it was guaranteed to be magic. When paired with the previous speedup, however, there was not a noticeable speed increase, and potentially even slowed it down slightly. I did not keep this.
* I also added returning true if loc was less than x, because if it is then that value of loc has been checked as an x value, and must be magic if the program is still running. This did't make much of a difference when added on along with the first check, but it seemed to maybe give a slight speed boost, so I kept it.


Without any of the speedups, the program takes 27 and a half minutes, although I only tested this once so it probably varies some up and down.