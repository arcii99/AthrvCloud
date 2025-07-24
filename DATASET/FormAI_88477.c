//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    char *keywords[] = { "system", "exec", "shell", "command", "io", "file", "network" };
    int n_keywords = sizeof(keywords) / sizeof(*keywords);
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s' for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int line_number = 1;
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        for (i = 0; i < n_keywords; i++) {
            if (strstr(buffer, keywords[i]) != NULL) {
                printf("Potential intrusion detected on line %d: '%s'\n", line_number, keywords[i]);
            }
        }
        line_number++;
    }
    
    fclose(fp);

    return 0;
}