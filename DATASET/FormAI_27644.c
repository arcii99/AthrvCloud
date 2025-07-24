//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

/* function prototypes */
int get_next_line(FILE *file, char *line);
void parse_line(char *line, char **timestamp, char **log_level, char **message);
void print_log(char *timestamp, char *log_level, char *message);

int main(int argc, char **argv) {

    /* check for correct number of arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* open log file for reading */
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line[MAXLINE];
    char *timestamp, *log_level, *message;

    /* read log file line by line */
    while (get_next_line(file, line) == 0) {
        parse_line(line, &timestamp, &log_level, &message);
        print_log(timestamp, log_level, message);
    }

    /* close log file */
    fclose(file);

    return 0;
}

/* function to read next line from file */
int get_next_line(FILE *file, char *line) {
    if (fgets(line, MAXLINE, file) == NULL) {
        return 1;
    }
    return 0;
}

/* function to parse log line into its components */
void parse_line(char *line, char **timestamp, char **log_level, char **message) {
    *timestamp = strtok(line, " []");
    *log_level = strtok(NULL, " []");
    *message = strtok(NULL, "\n");
}

/* function to print log components */
void print_log(char *timestamp, char *log_level, char *message) {
    printf("[%s] %s: %s\n", timestamp, log_level, message);
}