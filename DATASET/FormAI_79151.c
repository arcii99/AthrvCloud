//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char virusName[20];
    char fileName[30];
    int isInfected = 0;

    printf("My dear, please enter the name of the file you wish to scan: ");
    scanf("%s", fileName);

    printf("\nMy love, let me scan the file for you...\n");

    // Check if the file is infected with a known virus
    FILE *virusDB = fopen("virus_db.txt", "r");
    while (fscanf(virusDB, "%s", virusName) != EOF) {
        if (strstr(fileName, virusName) != NULL) {
            printf("\nOh no, my love, the file is infected with %s virus! Please delete it immediately and do not open it again.", virusName);
            isInfected = 1;
            break;
        }
    }

    if (!isInfected) {
        printf("\nMy sweet, the file is safe and free from viruses. You can open it without any worries.");
    }

    fclose(virusDB);

    return 0;
}