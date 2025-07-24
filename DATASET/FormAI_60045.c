//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    // Open CSV file for reading
    FILE* fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file");
        return -1;
    }
    
    // Read CSV data line by line
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = 0;
        }
        
        // Split CSV data into fields
        char* ptr = strtok(buffer, ",");
        while (ptr != NULL) {
            printf("%s ", ptr);
            
            ptr = strtok(NULL, ",");
        }
        printf("\n");
    }
    
    // Close CSV file
    fclose(fp);
    
    return 0;
}