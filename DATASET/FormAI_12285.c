//FormAI DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fptr;
    char filename[50], c;
    int count = 0;
    
    // User enters the log file to be read
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // Open file in read mode
    fptr = fopen(filename, "r");
    if (fptr == NULL){
        printf("Unable to open file.");
        exit(0);
    }
    
    // Read contents of the log file
    while((c = fgetc(fptr)) != EOF){
        // If a new line character is encountered, increment count
        if(c == '\n'){
            count++;
        }
    }
    
    // Close file
    fclose(fptr);
    
    // Print the number of log entries in the file
    printf("Number of log entries in file: %d\n", count);
    
    return 0;
}