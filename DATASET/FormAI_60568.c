//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    
    fp = fopen("example.csv", "r"); // Replace example.csv with your own CSV file
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // Print header row
    fgets(line, MAX_LINE_LENGTH, fp);
    printf("Header row: %s\n", line);
    
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        int col_num = 0;
        printf("Row %d: ", col_num + 1);
        
        token = strtok(line, ",");
        
        while (token != NULL) {
            // Remove newline character from last token
            if (token[strlen(token)-1] == '\n') {
                token[strlen(token)-1] = '\0';
            }
            
            printf("Column %d: %s, ", col_num + 1, token);
            col_num++;
            
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    
    fclose(fp);
    
    return 0;
}