//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char virus_signature[] = "malware";
    char buffer[101] = {0};
    int virus_detected = 0;

    FILE *file = fopen("scan_file.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, virus_signature) != NULL) {
            virus_detected = 1;
            break;
        }
    }

    if (virus_detected == 1) {
        printf("Virus detected!\n");
    } else {
        printf("No virus found.\n");
    }

    fclose(file);

    return 0;
}