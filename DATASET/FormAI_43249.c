//FormAI DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 5000
#define MAX_OUTPUT_SIZE 10000
#define TAB_SIZE 4

char input[MAX_INPUT_SIZE];
char output[MAX_OUTPUT_SIZE];

void process_line(char* line) {
    char temp[MAX_INPUT_SIZE];
    int i = 0, j = 0, tab_count = 0;
    memset(temp, 0, MAX_INPUT_SIZE);
    while(line[i] != '\0') {
        if(line[i] == '{') {
            output[j] = '\n';
            j++;
            tab_count++;
            for(int k = 0; k < tab_count * TAB_SIZE; k++) {
                output[j] = ' ';
                j++;
            }
        }
        else if(line[i] == '}') {
            output[j] = '\n';
            j++;
            tab_count--;
            for(int k = 0; k < tab_count * TAB_SIZE; k++) {
                output[j] = ' ';
                j++;
            }
        }
        else if(line[i] == ';') {
            output[j] = ';';
            j++;
            output[j] = '\n';
            j++;
            for(int k = 0; k < tab_count * TAB_SIZE; k++) {
                output[j] = ' ';
                j++;
            }
        }
        else {
            temp[j] = line[i];
            j++;    
        }
        i++;
    }
    strcpy(line, temp);
}

int main() {
    printf("Enter your C code: \n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    char* token = strtok(input, "\n");
    while(token != NULL) {
        process_line(token);
        strcat(output, token);
        strcat(output, "\n");
        token = strtok(NULL, "\n");
    }
    printf("\n\nYour formatted C code is:\n");
    printf("%s", output);
    return 0;
}