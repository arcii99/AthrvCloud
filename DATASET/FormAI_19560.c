//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    printf("WOW! Have you ever heard of a C Database Indexing System? If not, you're in for a treat!\n");
    printf("This program will allow you to create an index for your database table, which will make it faster and easier to search for specific records. Amazing, right?\n");
    
    printf("Choose the table that you want to create an index for: ");
    char table_name[50];
    scanf("%s", table_name);
    
    printf("How many columns does the table have? ");
    int num_columns;
    scanf("%d", &num_columns);
    
    printf("Great! Now let's create the index. Please provide the name of the column that you want to index: ");
    char column_name[50];
    scanf("%s", column_name);
    
    printf("What type of data does the column contain? (integer, float, string, etc.) ");
    char data_type[50];
    scanf("%s", data_type);
    
    printf("Amazing job! Let's create the index...\n");
    
    // Create index file
    char index_file_name[50];
    sprintf(index_file_name, "%s_%s_index.dat", table_name, column_name);
    FILE* index_file = fopen(index_file_name, "wb+");
    if (index_file == NULL) {
        printf("Oops, something went wrong. Could not create the index file.\n");
        exit(1);
    }
    
    // Write index entries
    int num_entries;
    printf("How many entries do you want to add to the index? ");
    scanf("%d", &num_entries);
    
    for (int i = 0; i < num_entries; i++) {
        int record_id;
        printf("Enter the record ID for entry %d: ", i+1);
        scanf("%d", &record_id);
        
        // Calculate offset in data file
        int offset = record_id * sizeof(data_type);
        
        // Write index entry
        fwrite(&record_id, sizeof(record_id), 1, index_file);
        fwrite(&offset, sizeof(offset), 1, index_file);
    }
    
    printf("Woohoo! Your index has been created successfully. You can find the index file at %s.\n", index_file_name);
    
    // Cleanup
    fclose(index_file);
    
    return 0;
}