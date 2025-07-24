//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char filename[100];

    printf("Enter the filename you want to scan: ");
    scanf("%s", filename);

    // check if file exists
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error! File not found.\n");
        return 0;
    }

    // read the content of the file
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* content = malloc(size);
    fread(content, 1, size, fp);
    fclose(fp);

    // scan the content for virus signatures
    if (strstr(content, "virus_signature_1") != NULL) {
        printf("Virus Signature 1 Detected!\n");
    }

    if (strstr(content, "virus_signature_2") != NULL) {
        printf("Virus Signature 2 Detected!\n");
    }

    if (strstr(content, "virus_signature_3") != NULL) {
        printf("Virus Signature 3 Detected!\n");
    }

    free(content);

    printf("Scan complete! Your system is safe!\n");

    return 0;
}