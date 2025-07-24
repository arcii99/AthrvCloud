//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[50];
    printf("Enter the filename to scan for viruses: ");
    scanf("%s", filename);

    // Open file
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Read contents of file
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), file)) {
        // Check for virus signatures
        if(strstr(buffer, "malware") != NULL || strstr(buffer, "virus") != NULL || strstr(buffer, "trojan") != NULL) {
            printf("Virus detected: %s\n", buffer);
        }
    }

    // Close file
    fclose(file);

    printf("Scan completed. Press any key to exit...");
    getchar();
    return 0;
}