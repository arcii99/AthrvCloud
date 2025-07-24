//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>

int main() {
    FILE* csv_file = fopen("data.csv", "r");
    if (!csv_file) {
        printf("Error: Could not open CSV file!");
        return 1;
    }

    int row = 0;
    char buffer[1024];
    while (fgets(buffer, 1024, csv_file)) {
        if (row == 0) {
            printf("Headers: %s", buffer);
        } else {
            char* ptr = buffer;
            int col = 0;
            while (*ptr) {
                if (*ptr == ',') {
                    *ptr = '\0';
                    printf("Row %d, Column %d: %s\n", row, col, buffer);
                    col++;
                    buffer[0] = '\0';
                } else if (*ptr == '\n') {
                    *ptr = '\0';
                    printf("Row %d, Column %d: %s\n", row, col, buffer);
                } else {
                    ptr++;
                }
            }
        }
        row++;
    }
    fclose(csv_file);
    return 0;
}