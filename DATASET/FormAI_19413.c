//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Romeo and Juliet
// Act I: Scene I: Introduction
// A unique searching algorithm in C
// Written in the style of Romeo and Juliet

#include <stdio.h>

int main() {
    // Act I: Scene II: Variables
    int arr[] = {5, 20, 45, 87, 111, 225};
    int target = 87;
    int n = sizeof(arr)/sizeof(arr[0]);

    // Act II: Scene I: Searching Algorithm
    int low = 0, high = n-1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            printf("O blessed, blessed night! I am afeard.\n");
            break;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
     }

     // Act II: Scene II: Results
     if (low > high) {
         printf("What's in a name? That which we call a rose by any other name would smell as sweet.\n");
     }
     else {
         printf("Did my heart love till now? Forswear it, sight! For I ne'er saw true beauty till this night.\n");
     }

     return 0;
}