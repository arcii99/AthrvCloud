//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <threshold_value>\n", argv[0]);
        exit(1);
    }

    char *input_file = argv[1];
    int threshold_value = atoi(argv[2]);

    FILE *file = fopen(input_file, "r");
    if (!file) {
        printf("Could not open input file\n");
        exit(1);
    }

    char line[MAX_LINE];
    int line_num = 1;
    while (fgets(line, MAX_LINE, file) != NULL) {
        if (strstr(line, "intrusion detected") != NULL) {
            printf("Intrusion detected on line %d: %s\n", line_num, line);
            if (strlen(line) > threshold_value) {
                printf("Alert! Intrusion message exceeds threshold value\n");
            }
        }
        line_num++;
    }

    fclose(file);

    return 0;
}