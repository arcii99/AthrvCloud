//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // create a file pointer and open the file in write mode
    FILE *fp = fopen("sample.txt", "w");
    
    // check if the file was opened successfully
    if(fp == NULL) {
        printf("Could not open file");
        exit(1);
    }
    
    // write data to the file using fwrite
    char data[] = "Hello world!";
    fwrite(data, sizeof(char), sizeof(data), fp);
    
    // close the file
    fclose(fp);
    
    // open the file in read mode
    fp = fopen("sample.txt", "r");
    
    // check if the file was opened successfully
    if(fp == NULL) {
        printf("Could not open file");
        exit(1);
    }
    
    // read data from the file using fread
    char buffer[256];
    fread(buffer, sizeof(char), sizeof(data), fp);
    
    // display the data read from the file
    printf("%s\n", buffer);
    
    // close the file
    fclose(fp);
    
    return 0;
}