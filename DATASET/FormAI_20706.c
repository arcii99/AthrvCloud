//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: realistic
#include <stdio.h>
#include <string.h>

// Function to convert C Cat language to English
void convertToEnglish(char *inputString) {
    char outputString[1000] = "";
    char word[100] = "";
    int i=0, j=0, k=0;
    while(inputString[i] != '\0') {
        if(inputString[i] != ' ') {
            word[j++] = inputString[i++];
        }
        else {
            word[j] = '\0';
            j = 0;
            if(strcmp(word, "meow") == 0) {
                strcat(outputString, "Hello");
            }
            else if(strcmp(word, "purr") == 0) {
                strcat(outputString, "Yes");
            }
            else if(strcmp(word, "hiss") == 0) {
                strcat(outputString, "No");
            }
            else if(strcmp(word, "scratching") == 0) {
                strcat(outputString, "I am busy");
            }
            else {
                strcat(outputString, word);
            }
            strcat(outputString, " ");
            i++;
        }
    }
    word[j] = '\0';
    if(strcmp(word, "meow") == 0) {
        strcat(outputString, "Hello");
    }
    else if(strcmp(word, "purr") == 0) {
        strcat(outputString, "Yes");
    }
    else if(strcmp(word, "hiss") == 0) {
        strcat(outputString, "No");
    }
    else if(strcmp(word, "scratching") == 0) {
        strcat(outputString, "I am busy");
    }
    else {
        strcat(outputString, word);
    }
    printf("%s", outputString);
}

int main() {
    char ccatInput[1000] = "";
    printf("Enter C Cat language: ");
    fgets(ccatInput, 1000, stdin);

    convertToEnglish(ccatInput);
    return 0;
}