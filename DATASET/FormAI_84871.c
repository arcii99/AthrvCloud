//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 20
#define MAX_FIELDS 10

void read_csv(FILE* file) {
    char line[MAX_LINE_LENGTH];
    char* fields[MAX_FIELDS];
    int num_fields, field_index;
    
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        line[strcspn(line, "\r\n")] = 0; // remove newline character(s)
        
        num_fields = 0;
        field_index = 0;
        
        fields[num_fields] = strtok(line, ",");
        
        while (fields[num_fields] != NULL && num_fields < MAX_FIELDS) {
            num_fields++;
            fields[num_fields] = strtok(NULL, ",");
        }
        
        if (num_fields > 0) {
            printf("%s: ", fields[0]);
            
            for (field_index = 1; field_index < num_fields; field_index++) {
                printf("%s", fields[field_index]);
                
                if (field_index < (num_fields - 1)) {
                    printf(", ");
                }
            }
            
            printf("\n");
        }
    }
}

int main(int argc, char** argv) {
    FILE* file;
    
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }
    
    file = fopen(argv[1], "r");
    
    if (!file) {
        printf("Error opening file '%s'\n", argv[1]);
        return 1;
    }
    
    read_csv(file);
    
    fclose(file);
    
    return 0;
}