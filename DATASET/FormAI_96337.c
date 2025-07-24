//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Global constants, macros and variables */
#define TAB_SIZE 4
#define MAX_LINE_LEN 1000
#define MAX_STACK_SIZE 1000
int line_count = 0; /* Tracks the number of lines in the input HTML file */
char input[MAX_LINE_LEN]; /* Stores the input HTML file */
char output[MAX_LINE_LEN]; /* Stores the output HTML file */
char *stack[MAX_STACK_SIZE]; /* Stack for storing tags */

/* Function declarations */
void beautify_html(char *input, char *output);
int get_line(char *input, char *line, int max_line_len);
void print_indentation(int depth);
int is_tag(char *line);
int parse_tag(char *line, char *tag);
void push(char *tag);
void pop();

/* Main function */
int main(int argc, char *argv[]) {
    /* Check command line arguments */
    if (argc != 3) {
        printf("Usage: ./beautify input.html output.html\n");
        exit(1);
    }
    /* Read input file */
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Error: Could not open input file '%s'\n", argv[1]);
        exit(1);
    }
    char line[MAX_LINE_LEN];
    while (get_line(f, line, MAX_LINE_LEN) != -1) {
        strncat(input, line, strlen(line));
    }
    fclose(f);
    /* Beautify HTML */
    beautify_html(input, output);
    /* Write output file */
    f = fopen(argv[2], "w");
    if (f == NULL) {
        printf("Error: Could not open output file '%s'\n", argv[2]);
        exit(1);
    }
    fprintf(f, "%s", output);
    fclose(f);
    printf("Beautification successful!\n");
    return 0;
}

/* Function to beautify HTML */
void beautify_html(char *input, char *output) {
    char line[MAX_LINE_LEN];
    char tag[MAX_LINE_LEN];
    int line_len, i, depth = 0;
    while ((line_len = get_line(input, line, MAX_LINE_LEN)) != -1) {
        line_count++;
        if (is_tag(line)) {
            parse_tag(line, tag);
            if (tag[0] == '/') { /* Closing tag */
                depth--;
                print_indentation(depth);
                sprintf(output + strlen(output), "%s\n", line);
                pop();
            } else if (tag[strlen(tag) - 1] == '/') { /* Self-closing tag */
                print_indentation(depth);
                sprintf(output + strlen(output), "%s\n", line);
            } else { /* Opening tag */
                push(tag);
                print_indentation(depth);
                sprintf(output + strlen(output), "%s\n", line);
                depth++;
            }
        } else { /* Text content */
            print_indentation(depth);
            sprintf(output + strlen(output), "%s\n", line);
        }
    }
}

/* Function to read a line from a file */
int get_line(char *input, char *line, int max_line_len) {
    int i = 0, c;
    while ((c = input[0])) {
        input++;
        if (c == '\n' || c == EOF || i == max_line_len - 1) {
            break;
        } else {
            line[i++] = c;
        }
    }
    line[i] = '\0';
    if (c == EOF && i == 0) {
        return -1;
    } else {
        return i;
    }
}

/* Function to print the indentation for a given depth */
void print_indentation(int depth) {
    int spaces = depth * TAB_SIZE;
    int i;
    for (i = 0; i < spaces; i++) {
        sprintf(output + strlen(output), " ");
    }
}

/* Function to check if a line contains a tag */
int is_tag(char *line) {
    return line[0] == '<';
}

/* Function to extract the tag from a line */
int parse_tag(char *line, char *tag) {
    int i = 0, j = 0;
    while (isspace(line[i]) || line[i] == '<') {
        i++;
    }
    while (!isspace(line[i]) && line[i] != '>') {
        tag[j++] = line[i++];
    }
    tag[j++] = line[i++];
    tag[j] = '\0';
    return i;
}

/* Function to push a tag onto the stack */
void push(char *tag) {
    stack[line_count] = (char *) malloc(strlen(tag) + 1);
    strcpy(stack[line_count], tag);
}

/* Function to pop a tag from the stack */
void pop() {
    free(stack[line_count--]);
}