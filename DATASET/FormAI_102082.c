//FormAI DATASET v1.0 Category: Text processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 50
#define MAX_CHARS 100

int main() {
    char lines[MAX_LINES][MAX_CHARS];
    int num_lines = 0;

    printf("Enter up to 50 lines of text and type 'exit' to quit.\n");

    while(num_lines < MAX_LINES) {
        printf("Line %d: ", num_lines+1);
        fgets(lines[num_lines], MAX_CHARS, stdin);

        if(strcmp(lines[num_lines], "exit\n") == 0) {
            break;
        }

        num_lines++;
    }

    printf("\n\nYou entered %d lines of text:\n", num_lines);

    for(int i=0; i<num_lines; i++) {
        printf("Line %d: %s", i+1, lines[i]);
    }

    return 0;
}