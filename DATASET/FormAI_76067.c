//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

void print_grid(int rows, int cols, char grid[rows][cols]) {
    printf("\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void monitor(char file_path[]) {
    FILE *log_file = fopen(file_path, "r");
    if (!log_file) {
        fprintf(stderr, "Error: Cannot access log file.\n");
        exit(1);
    }
    char current_line[1000];
    char grid[MAX_ROWS][MAX_COLS];
    memset(grid, ' ', sizeof(grid));
    int count = 0;
    while (fgets(current_line, sizeof(current_line), log_file)) {
        if (count < MAX_ROWS) {
            int len = strlen(current_line);
            if (len > MAX_COLS) {
                current_line[MAX_COLS - 1] = '\0';
                len = MAX_COLS - 1;
            }
            strncpy(grid[count], current_line, len);
            ++count;
        } else {
            break;
        }
    }
    fclose(log_file);
    print_grid(count, MAX_COLS, grid);
}

int main() {
    char file_path[] = "/var/log/auth.log";
    while (1) {
        monitor(file_path);
        sleep(10);
    }
    return 0;
}