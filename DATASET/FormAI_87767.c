//FormAI DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

/* This program takes in an array of integers and
 * determines whether it's a palindrome or not.
 */
int main(void) {
    int arr[10];    // array with maximum size of 10
    int len, i;
    bool is_palindrome = true;  // assume the array is a palindrome

    printf("Enter the length of the array (maximum is 10): ");
    scanf("%d", &len);

    printf("Enter %d integers: ", len);
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    /* Check whether the array is a palindrome */
    for (i = 0; i < len / 2; i++) {
        if (arr[i] != arr[len - i - 1]) {
            is_palindrome = false;
            break;  // exit the loop as soon as we find a mismatch
        }
    }

    /* Output whether the array is a palindrome or not */
    if (is_palindrome) {
        printf("The array is a palindrome.\n");
    } else {
        printf("The array is not a palindrome.\n");
    }

    return 0;
}