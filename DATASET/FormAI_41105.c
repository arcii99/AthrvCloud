//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shape_shift(char* input, char* output) {
    int i=0, j=0;
    while(input[i] != '\0') {
        char current_char = input[i];
        if(current_char == 'a') {
            strcat(output, ".+");
        } else if(current_char == 'b'){
            strcat(output, "-*");
        } else if(current_char == 'c') {
            strcat(output, "_/");
        } else if(current_char == 'd') {
            strcat(output, "<>");
        } else if(current_char == 'e') {
            strcat(output, "o^");
        } else {
            strcat(output, "&$");
        }
        i++;
        j+=2;
    }
}

int main() {
    char input[50];
    printf("Enter the C Alien Language: ");
    fgets(input, 50, stdin);
    
    char output[100];
    output[0] = '\0';
    
    shape_shift(input, output);
    printf("The translated output is: %s", output);
    return 0;
}