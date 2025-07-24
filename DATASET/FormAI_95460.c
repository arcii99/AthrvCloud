//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 10000

char scan_path[100];
char virus_signature[] = "virus";

int main() {

    printf("Enter the path of the file to scan: ");
    scanf("%s", scan_path);
    
    FILE* file_to_scan = fopen(scan_path, "r");
    if (file_to_scan == NULL) {
        printf("Invalid file path\n");
        return 0;
    }

    char buffer[MAX_BUFFER_SIZE];
    int bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, file_to_scan);
    fclose(file_to_scan);

    if (bytes_read == 0) {
        printf("Empty file\n");
        return 0;
    }

    int virus_detected = 0;
    for (int i = 0; i < bytes_read - sizeof(virus_signature) + 1; i++) {
        if (memcmp(&buffer[i], virus_signature, sizeof(virus_signature)) == 0) {
            virus_detected = 1;
            break;
        }
    }

    if (virus_detected == 1) {
        printf("Virus detected!\n");
    }
    else {
        printf("No virus detected\n");
    }

    return 0;
}