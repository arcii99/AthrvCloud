//FormAI DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "example.txt" // define file name

int main() {
    int data[5] = {10, 20, 30, 40, 50}; // create data array
    int i;
    
    // write data to file
    FILE *fptr;
    fptr = fopen(FILENAME, "w"); // open file in write mode
    
    if(fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    for(i = 0; i < 5; i++) {
        fprintf(fptr, "%d\n", data[i]);
    }
    
    fclose(fptr);
    
    // read data from file
    fptr = fopen(FILENAME, "r"); // open file in read mode
    
    if(fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    int readData[5];
    i = 0;
    
    while(fscanf(fptr, "%d", &readData[i]) != EOF) { // read data from file
        i++;
    }
    
    fclose(fptr);
    
    // print data
    for(i = 0; i < 5; i++) {
        printf("%d\n", readData[i]);
    }
    
    return 0;
}