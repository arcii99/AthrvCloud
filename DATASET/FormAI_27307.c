//FormAI DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
    char string1[50], string2[50];
    int choice, position, length;

    printf("Enter the first string: ");
    scanf("%s", string1);

    printf("Enter the second string: ");
    scanf("%s", string2);

    printf("Choose an operation to perform on the strings:\n");
    printf("1) Concatenate the strings\n");
    printf("2) Find the length of the strings\n");
    printf("3) Compare the strings\n");
    printf("4) Extract a substring from the first string\n");
    printf("5) Replace a substring in the first string\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Concatenation
            strcat(string1, string2);
            printf("The concatenated string is: %s\n", string1);
            break;
        case 2: // Find length
            printf("The length of string 1 is: %d\n", strlen(string1));
            printf("The length of string 2 is: %d\n", strlen(string2));
            break;
        case 3: // String comparison
            if (strcmp(string1, string2) == 0) {
                printf("The strings are the same!\n");
            }
            else {
                printf("The strings are different.\n");
            }
            break;
        case 4: // Substring extraction
            printf("Enter the starting position to extract from the first string: ");
            scanf("%d", &position);

            printf("Enter the length of the substring: ");
            scanf("%d", &length);

            printf("The extracted substring is: %.*s\n", length, &string1[position]);
            break;
        case 5: // Substring replacement
            char replace[50];
            printf("Enter the substring to be replaced: ");
            scanf("%s", replace);

            char with[50];
            printf("Enter the substring to replace with: ");
            scanf("%s", with);

            char *ptr = strstr(string1, replace);
            if (ptr != NULL) {
                strcpy(&ptr[0], with);
                printf("The new string is: %s\n", string1);
            }
            else {
                printf("%s not found in %s\n", replace, string1);
            }
            break;
        default: // Invalid option
            printf("Invalid option selected.");
            break;
    }

    return 0;
}