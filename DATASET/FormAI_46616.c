//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct to store XML tag information
typedef struct {
    char* name;
    int depth;
} XMLTag;

// Declare function to parse XML file
void parseXML(char* fileName) {
    FILE* fp = fopen(fileName, "r"); // open file
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    char line[1000]; // buffer to read in lines from file
    XMLTag* stack[100]; // stack to keep track of tags
    int top = -1; // initialize stack

    while(fgets(line, 1000, fp)) { // read in lines from file
        char* token = strtok(line, "<>"); // get first tag
        while(token != NULL) { // loop through all tags in line
            if(token[0] == '/') {
                // closing tag, pop from stack and compare names
                if(top == -1) {
                    printf("Error: stack underflow\n");
                    return;
                }
                else {
                    XMLTag* tag = stack[top--]; // pop tag from stack
                    if(strcmp(tag->name, token+1) != 0) { // compare tag names
                        printf("Error: tag mismatch\n");
                        return;
                    }
                    printf("%*c</%s>\n", tag->depth*4, ' ', tag->name); // print closing tag
                    free(tag->name); // free tag name memory
                    free(tag); // free tag memory
                }
            }
            else if(token[strlen(token)-1] == '/') {
                // empty tag, just print it
                printf("%*c<%s/>\n", (top+1)*4, ' ', token); // print tag
            }
            else {
                // opening tag, push onto stack and print it
                XMLTag* tag = malloc(sizeof(XMLTag)); // allocate memory for tag
                tag->name = strdup(token); // copy tag name to memory
                tag->depth = top+1; // set tag depth
                stack[++top] = tag; // push tag onto stack
                printf("%*c<%s>\n", tag->depth*4, ' ', tag->name); // print opening tag
            }
            token = strtok(NULL, "<>"); // get next tag
        }
    }

    fclose(fp); // close file

    // check if stack is empty
    if(top != -1) {
        printf("Error: stack not empty\n");
        return;
    }
}

int main() {
    parseXML("example.xml");
    return 0;
}