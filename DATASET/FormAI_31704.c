//FormAI DATASET v1.0 Category: HTML beautifier ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define TAB_SIZE 4

bool is_tag(char* line);
void print_tabs(int count);

int main() {
    //open file for reading
    FILE* fp;
    char* filename = "example.html";
    char line[MAX_LINE_LENGTH];
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    //read lines and print formatted output
    int tab_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        if (is_tag(line)) {
            print_tabs(tab_count);
        }
        printf("%s", line);

        //increment/decrement tab count as needed
        if (strstr(line, "</") == NULL && strstr(line, "<meta") == NULL) {
            if (strstr(line, "<") != NULL && strstr(line, "/>") == NULL) {
                tab_count += 1;
            }
            if (strstr(line, "</") != NULL) {
                tab_count -= 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

//check if line is an HTML tag
bool is_tag(char* line) {
    if (strstr(line, "<") == NULL || strstr(line, ">") == NULL) {
        return false;
    }
    if (strstr(line, "</") != NULL) {
        return true;
    }
    if (strstr(line, "/>") != NULL) {
        return true;
    }
    if (strstr(line, "<meta") != NULL) {
        return true;
    }
    return false;
}

//print specified number of tabs to indent code
void print_tabs(int count) {
    int i;
    for (i = 0; i < count * TAB_SIZE; i++) {
        printf(" ");
    }
}