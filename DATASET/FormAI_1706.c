//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int arr[] = {2, 5, 7, 10, 15, 18, 22, 25, 30};
    int num, i, flag = 0;
    printf("Enter the number to search in the array: ");
    scanf("%d", &num);
    int low = 0, high = sizeof(arr)/sizeof(arr[0]) - 1, mid;

    // Sherlock Holmes inspired
    printf("\nI looked at the array in front of me and my eyes scanned the values carefully.\n");
    printf("I could sense there was something peculiar about this array.\n");
    printf("But my instinct told me that the number I am looking for is there somewhere.\n");
    printf("As I began my search, I kept a sharp eye on the values around me,\n");
    printf("eliminating sections one by one until I narrowed it down to the correct index.\n");

    // Binary search implementation
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == num) {
            flag = 1;
            break;
        }
        else if (arr[mid] > num) high = mid - 1;
        else low = mid + 1;
    }

    // Outcomes
    if (flag == 1) {
        printf("\nAh, I knew it. The number %d does exist in the array.\n", num);
        printf("I found it at index %d!\n", mid);
    }
    else {
        printf("\nSadly, I couldn't find the number %d in the array.\n", num);
        printf("Perhaps, my instincts were wrong this time.\n");
    }
    return 0;
}