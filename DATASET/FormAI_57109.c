//FormAI DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int x = 5;
    int flag = 0;   // to check if element is present or not
    int pos = -1;   // to store position of element

    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            flag = 1;   // element is present in the array
            pos = i;    // store the position of element
            break;      // exit the loop
        }
    }

    if(flag == 1)
        printf("Element %d is present at position %d\n", x, pos+1);
    else
        printf("Element %d is not present in the array\n", x);

    return 0;
}