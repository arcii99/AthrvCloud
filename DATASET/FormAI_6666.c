//FormAI DATASET v1.0 Category: Text processing ; Style: futuristic
#include <stdio.h>
#include <string.h>

// futuristic text processing program

void runTextProcessor(char *input) {
    int length = strlen(input); // get length of input string
    char output[length+1]; // create output string with space for null terminator
    
    // loop through each character in input string
    for(int i=0; i<length; i++) {
        char c = input[i];
        
        // if character is a letter, shift it to the next alphabetical character
        if(c >= 'a' && c <= 'z') {
            c++;
            if(c > 'z') { // if character shifts past z, loop back to a
                c = 'a';
            }
        } else if(c >= 'A' && c <= 'Z') { // do the same for uppercase letters
            c++;
            if(c > 'Z') {
                c = 'A';
            }
        } else if(c == ' ') { // if character is a space, replace with a dash
            c = '-';
        } else if(c == '.') { // if character is a period, replace with an exclamation point
            c = '!';
        }
        // add modified character to output string
        output[i] = c;
    }
    output[length] = '\0'; // add null terminator to output string
    
    // print processed text
    printf("Your futuristic text: %s\n", output);
}

int main() {
    printf("Welcome to the Futuristic Text Processor!\n");
    printf("Enter your text: ");
    
    char input[1000];
    scanf("%[^\n]s", input); // read input until newline character
    
    runTextProcessor(input);
    
    return 0;
}