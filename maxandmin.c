#include <stdio.h>

int main() {
    int arr2[5] = {10, 3, 25, 4, 9};

    int min = arr2[0];
    int max = arr2[0];

    for (int i = 0; i < 5; i++) {
        if (arr2[i] < min) {
            min = arr2[i];
        }

        if (arr2[i] > max) {
            max = arr2[i];
        }
    }

    printf("\nMin = %d\n", min);
    printf("Max = %d\n", max);

    return 0;
}

