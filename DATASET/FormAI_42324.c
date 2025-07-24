//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scan_file(char *filename) { // function to scan a given file
    FILE *fp = fopen(filename, "r");
    char c, signature[] = "virus"; // tentative signature to detect virus

    if(fp == NULL) { // error when opening file
        printf("Error opening file %s", filename);
        return 0;
    }

    while((c = fgetc(fp)) != EOF) {
        if(c == signature[0]) { // if the current character match with the first character of signature
            for(int i=1; i<strlen(signature); i++) { // check next characters
                c = fgetc(fp);
                if(c != signature[i]) { // if it doesn't match, reset file pointer
                    fseek(fp, -i, SEEK_CUR);
                    break;
                }
                if(i == strlen(signature) - 1) { // if all characters match, it's a virus
                    printf("Virus detected in %s\n", filename);
                    fclose(fp);
                    return 1;
                }
            }
        }
    }

    fclose(fp); // no virus detected
    return 0;
}

int main() {
    char *files[] = {"file.txt", "virus.exe", "image.jpg"}; // list of files to be scanned
    int num_files = sizeof(files) / sizeof(files[0]); // get number of files to iterate 

    for(int i=0; i<num_files; i++) { // loop through files
        printf("Scanning file %s\n", files[i]);
        scan_file(files[i]); // call scan_file function
    }

    return 0; // end of program
}