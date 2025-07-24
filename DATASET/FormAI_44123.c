//FormAI DATASET v1.0 Category: Educational ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to the Happy Learning Program!\n");
    printf("Today we will be learning about arrays!\n\n");

    int arr[10];
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        printf("Enter a number: ");
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("\nYay, you filled up the array! Here it is:\n[ ");

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("]\n\n");

    printf("The sum of all the numbers in the array is: %d\n", sum);

    printf("\nHope you enjoyed the Happy Learning Program! Keep coding with joy!\n");

    return 0;
}