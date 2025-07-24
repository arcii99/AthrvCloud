//FormAI DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>

int main() {

    FILE *fp = fopen("myfile.txt", "r"); // Opening a file in read mode
    
    if(fp == NULL) { // Handling file opening error
        printf("Error opening file!\n");
        return 1;
    }
    
    char buffer[256]; // Declaring a buffer variable
    int num; // Declaring an integer variable
    
    if(fgets(buffer, 256, fp) == NULL) { // Error handling for reading from file
        printf("Error reading file!\n");
        fclose(fp); // Closing file before return
        return 1;
    }
    
    // Converting buffer string to integer
    if(sscanf(buffer, "%d", &num) != 1) { // Error handling for conversion
        printf("Error converting buffer to integer!\n");
        fclose(fp); // Closing file before return
        return 1;
    }
    
    printf("The number in file is: %d\n", num);
    
    if(fclose(fp) != 0) { // Handling file closing error
        printf("Error closing file!\n");
        return 1;
    }
    
    return 0; // Program executed successfully
}