//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <string.h>

void sanitizeString(char *str){
    int length = strlen(str);
    char sanitizedString[length + 1];
    int sanitizedIndex = 0;
    
    for(int i = 0; i < length; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            sanitizedString[sanitizedIndex] = str[i] + 32; //convert to lower case
            sanitizedIndex++;
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            sanitizedString[sanitizedIndex] = str[i];
            sanitizedIndex++;
        }
    }
    sanitizedString[sanitizedIndex] = '\0';
    strcpy(str, sanitizedString);
}

int main(){
    char userInput[100];
    printf("Enter a string: ");
    fgets(userInput, 100, stdin);
    userInput[strcspn(userInput, "\n")] = 0; //remove newline character

    sanitizeString(userInput);
    printf("Sanitized String: %s", userInput);

    return 0;
}