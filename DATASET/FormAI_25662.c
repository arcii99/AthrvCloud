//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256];
    printf("Loading CSV reader...\n");
    printf("Enter filename: ");
    fgets(filename, 256, stdin);
    
    //Remove newline character from filename
    int len = strlen(filename);
    if (len > 0 && filename[len-1] == '\n') {
        filename[len-1] = '\0';
    }
    
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening file, please try again.\n");
        return 0;
    }
    
    printf("File opened successfully! Reading file...\n");
    
    char line[256];
    int line_count = 0;

    while (fgets(line, 256, file)) {
        if (line_count == 0) {
            printf("Header: %s", line);
        } else {
            printf("Data: %s", line);
        }
        line_count++;
    }

    printf("Finished reading file!\n");
    fclose(file);

    return 0;
}