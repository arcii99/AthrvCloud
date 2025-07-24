//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a file is infected with a C virus
int check_virus(char *filename, char *signatures[], int num_signatures) {

    FILE *fp;
    char buffer[1024];

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    while (fgets(buffer, 1024, fp)) {
        for (int i = 0; i < num_signatures; i++) {
            if (strstr(buffer, signatures[i])) {
                printf("Virus signature '%s' found in file %s\n", signatures[i], filename);
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);

    printf("File %s is clean of C viruses.\n", filename);
    return 0;
}

int main() {

    char *signatures[] = {"rm -rf", "shutdown -h now", "fork bomb"};
    int num_signatures = sizeof(signatures)/sizeof(signatures[0]);

    char filename[100];

    printf("Welcome to the C Antivirus Scanner\n");
    printf("Enter a filename to scan: ");
    scanf("%s", filename);

    check_virus(filename, signatures, num_signatures);

    return 0;
}