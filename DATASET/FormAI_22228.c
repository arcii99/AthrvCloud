//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char file_name[50];
    printf("Enter the file name to scan: ");
    scanf("%s", file_name);

    FILE* file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL) {
        printf("Error: File not found.\n");
        return -1;
    }

    char line[256];
    int line_number = 0;
    int total_infected = 0;

    printf("Scanning...\n");

    while (fgets(line, sizeof(line), file_pointer)) {
        line_number++;
        if (strstr(line, "virus") != NULL || strstr(line, "malware") != NULL) {
            printf("Found virus/malware in line %d: %s", line_number, line);
            total_infected++;
        }
    }

    if (total_infected > 0) {
        printf("%d infections found in total.", total_infected);
    } else {
        printf("No infections were found.");
    }

    fclose(file_pointer);
    return 0;
}