//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>

// Function to remove whitespace from the beginning and end of the string
char* trim(char *str){
    char *end;
    while(isspace((unsigned char)*str)) str++;
    if(*str == '\0') return str;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

int main() {
    char catInput[100];
    char englishOutput[100];
    
    printf("Enter your cat language: ");
    fgets(catInput, 100, stdin);
    
    // Convert cat language to English
    if (strcmp(trim(catInput), "Meow") == 0) {
        strcpy(englishOutput, "Hello");
    } else if (strcmp(trim(catInput), "Purr") == 0) {
        strcpy(englishOutput, "I am happy");
    } else if (strcmp(trim(catInput), "Hiss") == 0) {
        strcpy(englishOutput, "I am angry");
    } else if (strcmp(trim(catInput), "Growl") == 0) {
        strcpy(englishOutput, "I am scared");
    } else {
        strcpy(englishOutput, "I don't understand what you are saying");
    }
    
    printf("English Translation: %s", englishOutput);
    
    return 0;
}