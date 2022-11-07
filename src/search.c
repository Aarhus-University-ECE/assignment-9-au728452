#include "search.h"
#include <stdbool.h>
#include <assert.h>

bool search(int a[], int n, int x) // A function that can be used to search for a specific element in an array
{
    if (n > 0 && a[n - 1] != x) // Recursive step, that will check to see if there still are elements to search in the array, and whether the current element is the one that is being searched for, if not, then it will call the function again, and search the next element in the array
    {
        search(a, n - 1, x);
    }
    else if (n > 0 && a[n - 1] == x) // Base case, where if the current element being checked is the one being searched for, the function is true, meaning that the integer exists in the array
    {
        return true;
    }
    else
    {
        return false; // Base case, if the function can't be run again because the array has been fully searched, or if the correct integer has been found, the function is false, as the element being searched for doesn't exist.
    }
}