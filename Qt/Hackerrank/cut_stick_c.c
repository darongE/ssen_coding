
#include <stdio.h>
#include <stdlib.h>

//5 4 4 2 2 8
int main()
{
    int n = 0, len = 0;
    scanf("%d", &n);

    //int *arr = (int*)calloc(1001, sizeof(int));

    int arr[6] = {};
    int max = 0, min  = 0;

    for(int arr_i = 0; arr_i < n; arr_i++)
    {
        scanf("%d",&len);

        if(!min || min > len)
            min = len;
        if(max < len)
            max = len;
        arr[len]++;

    }

    int num_arr = sizeof(arr)/ sizeof(arr[0]);

    for(int i = min; i <= max; i++) {


           if(arr[i] && i <= num_arr) {
               printf("%d\n", n);
               n -= arr[i];
           }
       }

    return 0;
}
