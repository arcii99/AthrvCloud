//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>
#include <string.h>

/* define maximum file size */
#define MAX_FILE_SIZE 10000

/* function to scan file for viruses */
void scan_file(char *filename) {
    /* open file */
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!");
        return;
    }
    /* read the file contents into buffer */
    char buffer[MAX_FILE_SIZE];
    int n = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);
    /* close the file */
    fclose(file);
    /* check the file contents for viruses */
    int virus_found = 0;
    if (n > 0) {
        /* scan for virus signature 1 */
        if (strstr(buffer, "virus_signature_1") != NULL) {
            printf("Virus signature 1 found in file %s!\n", filename);
            virus_found = 1;
        }
        /* scan for virus signature 2 */
        if (strstr(buffer, "virus_signature_2") != NULL) {
            printf("Virus signature 2 found in file %s!\n", filename);
            virus_found = 1;
        }
        /* scan for virus signature 3 */
        if (strstr(buffer, "virus_signature_3") != NULL) {
            printf("Virus signature 3 found in file %s!\n", filename);
            virus_found = 1;
        }
    }
    /* print the scan result */
    if (virus_found == 0) {
        printf("File %s is clean!\n", filename);
    }
}

/* main function */
int main() {
    /* scan multiple files */
    scan_file("file1.exe");
    scan_file("file2.doc");
    scan_file("file3.pdf");
    return 0;
}