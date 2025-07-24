//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>

void sherlock_scan_file(char* filename) {
    printf("Scanning %s for viruses...\n", filename);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return;
    }
    int num_viruses = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, "virus") != NULL) {
            printf("Virus detected on line: %s\n", line);
            num_viruses++;
        }
    }
    fclose(file);
    if (num_viruses == 0) {
        printf("No viruses found in %s.\n", filename);
    } else {
        printf("%d viruses found in %s. Quarantining file...\n", num_viruses, filename);
        // TODO: implement quarantine feature
    }
}

int main() {
    printf("Welcome to the Sherlock Holmes antivirus scanner.\n");
    printf("Please enter the filename to scan: ");
    char filename[100];
    scanf("%s", filename);
    sherlock_scan_file(filename);
    return 0;
}