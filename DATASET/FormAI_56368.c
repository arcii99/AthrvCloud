//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[100], delimiter;
    int choice, len, i, j, k;
    printf("Enter a string with maximum length of 100: ");
    fgets(string, 100, stdin);
    printf("\nEnter a delimiter character: ");
    scanf("%c", &delimiter);
    printf("\nSelect an operation to perform on the string:\n1. Remove all occurrences of the delimiter.\n2. Replace all occurrences of the delimiter with a space.\n3. Count the number of occurrences of the delimiter.\nChoice: ");
    scanf("%d", &choice);
    len = strlen(string);
    switch(choice) {
        case 1:
            for(i = 0; i < len; i++) {
                if(string[i] != delimiter)
                    printf("%c", string[i]);
            }
            break;
        case 2:
            for(i = 0; i < len; i++) {
                if(string[i] == delimiter)
                    printf(" ");
                else
                    printf("%c", string[i]);
            }
            break;
        case 3:
            j = 0;
            for(i = 0; i < len; i++) {
                if(string[i] == delimiter)
                    j++;
            }
            printf("The number of occurrences of '%c' is: %d", delimiter, j);
            break;
        default:
            printf("\nInvalid input!");
            break;
    }
    printf("\n");
    return 0;
}