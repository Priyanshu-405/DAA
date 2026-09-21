#include <stdio.h>
int main() {
    int arr2[5]={1, 2, 3, 4, 5};
    int start = 0;
    int end = 5 - 1;
    
    while (start < end) {
    int temp = arr2[start];
    arr2[start] = arr2[end];
    arr2[end] = temp;

    start = start + 1;
    end = end - 1;
}
printf("\nReversed array:\n");
for (int i = 0; i < 5; i++) {
    printf("%d\n", arr2[i]);
}
return 0;
}