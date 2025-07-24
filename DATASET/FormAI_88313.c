//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: portable
#include<stdio.h>
#include<string.h>

int main() {
    // Define the C-Cat dictionary
    char dictionary[10][2][20] = {
        {"meow", "printf"},
        {"purr", "scanf"},
        {"hiss", "return"},
        {"nip", "+"},
        {"scratch", "-"},
        {"bat", "*"},
        {"swat", "/"},
        {"stretch", "int"},
        {"curl", "char"}, 
        {"claws", ";"},
    };

    // Ask the user to enter a C-Cat program
    printf("Enter a C-Cat program:\n");
    char program[100];
    scanf("%[^\n]", program);

    // Tokenize the C-Cat program into individual words
    char *token = strtok(program, " ");
    while(token != NULL) {
        // Convert C-Cat words to C language equivalent
        for(int i = 0; i < 10; i++) {
            if(strcmp(token, dictionary[i][0]) == 0) {
                printf("%s ", dictionary[i][1]);
                break;
            }
            // If word is not found in dictionary, print it as it is
            if(i == 9) {
                printf("%s ", token);
            }
        }
        token = strtok(NULL, " ");
    }
    return 0;
}