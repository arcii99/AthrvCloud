//FormAI DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50], temp[50];
    int i, j, choice;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("Choose an operation to perform:\n");
    printf("1. Concatenate the two strings\n");
    printf("2. Copy the second string to the first\n");
    printf("3. Swap the two strings\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            strcat(str1, str2);
            printf("Concatenated string: %s", str1);
            break;

        case 2:
            strcpy(str1, str2);
            printf("Copied string: %s", str1);
            break;

        case 3:
            strcpy(temp, str1);
            strcpy(str1, str2);
            strcpy(str2, temp);
            printf("Swapped strings: %s %s", str1, str2);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}