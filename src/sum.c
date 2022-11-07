#include "sum.h"
#include <assert.h>

int sum(int a[], int n) // Function that sums all elements in an array
{
    /*Pre condition*/
    assert(n >= 0);

    if (n > 0) // Recursive step, that will sum the current array element, and will call the sum function, for the next array element
    {
        return a[n - 1] + sum(a, n - 1);
    }
    else // Base case, that will return 0, as when n hits 0, it will make it so that a -1 index array won't be added to the sum, as it is not possible, thus ending the recursion
    {
        return 0;
    }
}