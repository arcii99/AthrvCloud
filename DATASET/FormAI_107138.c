//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeLeadingSpaces(char *string){
    int length = strlen(string);
    int i, j = 0;
    for(i = 0; i < length; i++){
        if(string[i] != ' '){
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
}

void removeTrailingSpaces(char *string){
    int length = strlen(string);
    int i;
    for(i = length - 1; i >= 0; i--){
        if(string[i] != ' '){
            break;
        }
        string[i] = '\0';
    }
}

void removeExtraSpaces(char *string){
    int length = strlen(string);
    int i, j = 0;
    int spaceCount = 0;
    for(i = 0; string[i]; i++){
        if(string[i] != ' '){
            spaceCount = 0;
            string[j++] = string[i];
        }
        else {
            spaceCount++;
            if(spaceCount == 1){
                string[j++] = ' ';
            }
        }
    }
    string[j] = '\0';
    removeTrailingSpaces(string);
}

void sanitizeInput(char *string){
    removeLeadingSpaces(string);
    removeExtraSpaces(string);
}

int main(){
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    printf("Original string: %s\n", input);
    sanitizeInput(input);
    printf("Sanitized string: %s\n", input);
    return 0;
}