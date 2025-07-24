//FormAI DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inputStr[1000];
    char buffer[1000];
    int i = 0, j = 0, len;

    printf("Enter a string: ");
    fgets(inputStr, sizeof(inputStr), stdin);

    len = strlen(inputStr);

    for(i = 0; i <= len; i++) {
        if(inputStr[i] == ' ') {
            for(j = i; j <= len; j++) {
                buffer[j-i] = inputStr[j];
            }
            strcat(buffer, " ");
            strcat(buffer, "is ");
            strcat(buffer, "not ");
            strcat(buffer, "a ");
            strcat(buffer, "valid ");
            strcat(buffer, "word.\n");
            printf("%s", buffer);
            break;
        }
    }

    if(i == len + 1) {
        printf("No spaces found. This is a valid string.\n");
    }

    return 0;
}