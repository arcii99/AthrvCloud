//FormAI DATASET v1.0 Category: Data mining ; Style: light-weight
#include <stdio.h>

int main() {
    int dataArray[10] = {2, 7, 3, 8, 9, 4, 5, 1, 6, 10};
    int userNumber, i, found = 0;

    printf("Enter a number: ");
    scanf("%d", &userNumber);

    for(i = 0; i < 10; i++) {
        if(dataArray[i] == userNumber) {
            found = 1;
            break;
        }
    }

    if(found == 1) {
        printf("The number %d was found at index %d in the array.\n", userNumber, i);
    } else {
        printf("The number %d was not found in the array.\n", userNumber);
    }

    return 0;
}