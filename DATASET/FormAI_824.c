//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_LEN 256
#define MAX_FIELDS 20

/* CSV Reader example program */

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char field[MAX_FIELD_LEN];
    char *ptr;
    int field_count = 0;
    int row_count = 0;
    int i;
    
    // Check for correct number of arguments
    if (argc != 2) {
        printf("usage: %s filename.csv\n", argv[0]);
        exit(1);
    }

    // Open file for reading
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("error: can't open %s\n", argv[1]);
        exit(1);
    }
    
    // Read file line by line
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;
        
        // Parse fields in line
        ptr = line;
        field_count = 0;
        while ((ptr = strtok(ptr, ",")) != NULL) {
            strncpy(field, ptr, MAX_FIELD_LEN);
            printf("%s, ", field);
            ptr = NULL;
            field_count += 1;
        }
        printf("\n");
        
        // Check for too many fields in row
        if (field_count > MAX_FIELDS) {
            printf("error: too many fields in row %d\n", row_count + 1);
            exit(1);
        }
        row_count += 1;
    }

    // Close file
    fclose(fp);

    return 0;
}