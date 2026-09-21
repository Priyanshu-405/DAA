#include <stdio.h>
#include <time.h>

void insertionsort(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr [i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int sizes[] = {10, 100, 1000};
    int arr[1000];
    int n, i, s;
    clock_t start, end;
    double time_taken;

    for (s = 0; s < 3; s++)
    {
        n = sizes[s];

        for (i = 0; i < n; i++)
            arr[i] = n - i;

        start = clock();

        insertionsort(arr, n);

        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("n = %d, Time = %f seconds\n", n, time_taken);
    }

    return 0;
}
