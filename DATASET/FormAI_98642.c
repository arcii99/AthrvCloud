//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>

/* Cyberpunk Style C Searching Algorithm Example Program */

int main() {
    int arr[10] = {234, 1233, 33, 65, 12, 654, 342, 88, 987, 321};
    int element, i, flag = 0;

    printf("Enter the element you want to search: ");
    scanf("%d", &element);

    for (i = 0; i < 10; i++) {
        if (arr[i] == element) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("Hacking into the System...\n");
        printf("%d Found at Position %d. Initiating Data Extraction...\n", element, i+1);
        printf("Data Extraction Completed. Deleting all the traces....\n");
    } else {
        printf("Initiating Hacker Mode....\n");
        printf("The Element could not be found. Erasing all traces...\n");
    }

    return 0;
}