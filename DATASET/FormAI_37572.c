//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: rigorous
#include<stdio.h>
#include<string.h>

int main() {
    char virus[] = "I am a virus!"; // define virus signature
    char filename[200]; // filename to be scanned
    int infected = 0; // counter for infected files
    
    printf("Enter the file name to be scanned: ");
    scanf("%s", filename);
    
    FILE *fp = fopen(filename, "r"); // open the file in read mode
    
    if(fp == NULL) { // if file not found
        printf("File not found!");
        return 1;
    }
    
    char buffer[200]; // buffer to read the file contents to
    int index = 0; // index to keep track of buffer position
    
    while(fscanf(fp, "%c", &buffer[index]) != EOF) { // read the file character by character
        if(index == 11) { // if the buffer size equals the virus signature size
            if(strcmp(virus, buffer) == 0) { // if a match is found
                infected++; // increment infected count
                printf("Found virus in file: %s\n", filename); // print infected file name
                break; // stop scanning the file
            } else {
                index--; // rollback the buffer position by one
            }
        }
        index++;
    }
    
    fclose(fp); // close the file
    
    if(infected == 0) { // if no viruses found
        printf("No viruses found in file: %s\n", filename);
    } else {
        printf("Total infected files: %d\n", infected);
    }
    
    return 0;
}