//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: secure
#include <stdio.h>
#include <string.h>

int main() {
    char virus[] = "infected";
    char file[100];
    int virus_found = 0;

    printf("Enter the name of the file to scan for viruses: ");
    scanf("%s", file);

    FILE *fptr = fopen(file, "r");

    if (fptr == NULL) {
        printf("Error opening file.");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fptr)) {
        if (strstr(line, virus)) {
            virus_found = 1;
            break;
        }
    }

    if (virus_found) {
        printf("Virus found in the file!");
    } else {
        printf("File is clean of viruses.");
    }

    fclose(fptr);
    return 0;
}