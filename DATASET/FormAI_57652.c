//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multivariable
#include <stdio.h>
#include <string.h>

//function to check if a file name contains the extension of a virus
int virusCheck(char fileName[]) {
    char virus[] = "virus";
    char *extension;
    int result = 0;
    
    extension = strchr(fileName, '.');
    if (extension != NULL) {
        if (strcmp(extension+1, virus) == 0) {
            result = 1;
        }
    }
    
    return result;
}

int main() {
    //initialize variables for file scanning
    char fileName[100];
    char fileContents[1000];
    FILE *fp;
    
    //prompt user for file name and attempt to open file
    printf("Enter file name: ");
    scanf("%s", fileName);
    fp = fopen(fileName, "r");
    
    //if file cannot be opened, print error and exit program
    if (fp == NULL) {
        printf("Error: File %s not found\n", fileName);
        return 1;
    }
    
    //otherwise, read file contents line by line and scan for viruses
    while (fgets(fileContents, 1000, fp) != NULL) {
        if (virusCheck(fileContents) == 1) {
            printf("Warning: Virus detected in file %s\n", fileName);
            break; //stop scanning file once a virus is detected
        }
    }
    
    //close file and terminate program
    fclose(fp);
    return 0;
}