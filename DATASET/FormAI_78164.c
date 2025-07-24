//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>
#include <string.h>

/* Function to scan a file for any potential viruses */
void scan_file(char *filename) {

    FILE *fp;
    char buffer[1024];
    const char *virus_signature = "malicious";

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    /* Scan each line for the virus signature */
    while(fgets(buffer, 1024, fp)) {
        if(strstr(buffer, virus_signature)) {
            printf("Virus found in the file %s\n", filename);
            return;
        }
    }

    printf("No virus found in the file %s\n", filename);

    fclose(fp);
}

int main() {

    char *files[] = {"file1.txt", "file2.txt", "file3.txt"};

    /* Scan each file for potential viruses */
    for(int i = 0; i < 3; i++) {
        scan_file(files[i]);
    }

    return 0;
}