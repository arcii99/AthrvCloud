//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main(void) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char* token;
  
    fp = fopen("example.csv", "r");
 
    // Read headers
    fgets(line, MAX_LINE_SIZE, fp);
    // Process headers here
  
    // Read records
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        // Split line into tokens using comma as delimiter
        token = strtok(line, ",");
 
        while (token != NULL) {
            // Process token here
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
 
        printf("\n");
    }
 
    fclose(fp);
 
    return 0;
}