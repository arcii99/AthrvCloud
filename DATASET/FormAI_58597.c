//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 1024
#define MAX_LINES 1000

int main(int argc, char* argv[]) {
    FILE *fp;
    char buf[BUFSIZE];
    char *filename, *regex;
    char *lines[MAX_LINES];
    int i, line_num, regex_found;

    if (argc != 3) {
        printf("USAGE: %s <filename> <regex>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    regex = argv[2];

    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Could not open file");
        return 1;
    }

    line_num = 0;

    while (fgets(buf, BUFSIZE, fp)) {
        lines[line_num++] = strdup(buf);
        if (line_num == MAX_LINES) {
            printf("Maximum number of lines reached!\n");
            break;
        }
    }

    if (line_num == 0) {
        printf("ERROR: No lines read from file\n");
        return 1;
    }

    regex_found = 0;

    for (i = 0; i < line_num; i++) {
        if (strstr(lines[i], regex)) {
            printf("Regex found on line %d: %s\n", i+1, lines[i]);
            regex_found = 1;
        }
    }

    if (!regex_found) {
        printf("Regex not found.\n");
    }

    for (i = 0; i < line_num; i++) {
        free(lines[i]);
    }

    fclose(fp);

    return 0;
}