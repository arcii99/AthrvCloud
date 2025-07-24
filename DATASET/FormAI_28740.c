//FormAI DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[50], str2[50], temp[50]; // declare char arrays for strings
    int choice, length1, length2;
    printf("Enter the first string: ");
    scanf("%s", str1); // input the first string
    printf("Enter the second string: ");
    scanf("%s", str2); // input the second string
    length1 = strlen(str1);
    length2 = strlen(str2);
    while(1) {
        printf("\n1. Concatenate two strings\n2. Compare two strings\n3. Reverse the first string\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // concatenate two strings
                strcat(str1, str2); // str1 will now contain both strings
                printf("Concatenated string: %s\n", str1);
                break;
            case 2: // compare two strings
                if(strcmp(str1, str2) == 0)
                    printf("Strings are equal\n");
                else
                    printf("Strings are not equal\n");
                break;
            case 3: // reverse the first string
                for(int i = 0, j = length1-1; i < length1/2; i++, j--) {
                    temp[i] = str1[i];
                    str1[i] = str1[j];
                    str1[j] = temp[i];
                }
                printf("Reversed string: %s\n", str1);
                break;
            case 4: // exit program
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}