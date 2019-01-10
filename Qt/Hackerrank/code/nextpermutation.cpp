#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/*
 * Computes the next lexicographical permutation of the specified vector
 * of values in place, returning whether a next permutation existed.
 * (Returns false when the argument is already the last possible permutation.)
 */

//0,1,2, 5,3,3,0
bool next_permutation(char array[], size_t length) {
    // Find non-increasing suffix
    if (length == 0)
        return false;
    size_t i = length - 1;
    while (i > 0 && array[i - 1] >= array[i])
        i--;
    if (i == 0)
        return false;

    // Find successor to pivot
    size_t j = length - 1;
    while (array[j] <= array[i - 1])
        j--;
    char temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;

    // Reverse suffix
    j = length - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    return true;
}


int main()
{
    char arr[] = {'d','k','h','c'};

    bool rflag = false;
    rflag = next_permutation(arr,sizeof(arr)/sizeof(arr[0]));

    cout << rflag << "\n";

    return 0;
}
