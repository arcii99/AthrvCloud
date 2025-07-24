//FormAI DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIN_LEN 200
#define MAX_TIME_LEN 20

void read_logs(FILE *f, int *info, int *warn, int *error);
void print_level_count(int level, int count);

int main() {
    int info = 0, warn = 0, error = 0;
    FILE *f_ptr;
    char file_name[MAX_LIN_LEN];
    printf("Enter the log file name: ");
    fgets(file_name, MAX_LIN_LEN, stdin);
    file_name[strcspn(file_name, "\n")] = '\0'; // remove trailing newline
    f_ptr = fopen(file_name, "r");

    if (f_ptr == NULL) {
        printf("Failed to open file. Please check if the file exists.\n");
        exit(EXIT_FAILURE);
    }

    read_logs(f_ptr, &info, &warn, &error);
    printf("\nTotal log entries: %d\n", info + warn + error);
    print_level_count(0, info);
    print_level_count(1, warn);
    print_level_count(2, error);

    fclose(f_ptr);
    return 0;
}

void read_logs(FILE *f, int *info, int *warn, int *error) {
    char line[MAX_LIN_LEN], time[MAX_TIME_LEN];
    int level;
    if (fgets(line, MAX_LIN_LEN, f) != NULL) {
        level = atoi(line);
       fgets(time, MAX_TIME_LEN, f); // skip next line
        switch(level) {
            case 0:
                *info += 1;
                break;
            case 1:
                *warn += 1;
                break;
            case 2:
                *error += 1;
                break;
        }
        read_logs(f, info, warn, error);
    }
}

void print_level_count(int level, int count) {
    char *level_name;
    switch(level) {
        case 0:
            level_name = "INFO";
            break;
        case 1:
            level_name = "WARN";
            break;
        case 2:
            level_name = "ERROR";
            break;
    }
    printf("%s: %d\n", level_name, count);
}