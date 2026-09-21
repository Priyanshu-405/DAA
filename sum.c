#include <stdio.h>
int main() {
    int arr1[5]={14,9,7,15,4};
    int sum = 0;
    for (int i=0; i<5; i++){
        sum = sum + arr1[i];
    }
    printf("Sum = %d\n", sum);
    return 0;
}