//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printAscii(char *str);
//function signature

int main() {
    char input[1000];
    //declare variable

    printf("Enter text to convert it to ASCII art:\n");
    fgets(input, 1000, stdin);
    //get input from user

    printAscii(input);
    //function call
    return 0;
}

void printAscii(char *str) {
    char *line = strtok(str, "\n");
    //split input into lines for processing

    while (line != NULL) {
        for (int i = 0; i < strlen(line)-1; i++) { //decrement strlen by 1 to ignore '\n'
            printf("%c%c%c\n", line[i], line[i], line[i]);
            printf("%c%c%c\n", line[i], line[i], line[i]);
            printf("%c%c%c\n", line[i], line[i], line[i]);
            //print ASCII art for each character in the line
        }
        line = strtok(NULL, "\n");
        //move to the next line of input
    }
}