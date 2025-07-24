//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing a record
typedef struct {
    int id;
    char name[20];
    float salary;
} Record;

// Structure for storing the index
typedef struct {
    int id;
    int offset;
} Index;

// Function to insert a record into the database
void insert(Record record, FILE * data_file, FILE * index_file) {
    // Position the file pointer at the end of the data file
    fseek(data_file, 0, SEEK_END);
    // Write the record to the data file
    fwrite(&record, sizeof(Record), 1, data_file);
    // Get the current location of the file pointer and subtract the size of the record
    int offset = ftell(data_file) - sizeof(Record);
    // Create an index record
    Index index = {record.id, offset};
    // Write the index record to the index file
    fwrite(&index, sizeof(Index), 1, index_file);
}

// Function to search for a record by ID
int search(int id, FILE * index_file, FILE * data_file, Record * result) {
    // Position the file pointer at the beginning of the index file
    rewind(index_file);
    // Loop through the index records
    while (!feof(index_file)) {
        // Read an index record
        Index index;
        fread(&index, sizeof(Index), 1, index_file);
        // If the ID matches, read the corresponding record from the data file
        if (id == index.id) {
            fseek(data_file, index.offset, SEEK_SET);
            fread(result, sizeof(Record), 1, data_file);
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    // Open the data file and index file for reading and writing
    FILE * data_file = fopen("data.bin", "wb+");
    FILE * index_file = fopen("index.bin", "wb+");
    
    // Insert some records into the database
    insert((Record){1, "John", 1000.0}, data_file, index_file);
    insert((Record){2, "Jane", 2000.0}, data_file, index_file);
    insert((Record){3, "Bob", 1500.0}, data_file, index_file);
    
    // Search for a record by ID
    Record result;
    if (search(2, index_file, data_file, &result)) {
        printf("Record found: %d %s %.2f\n", result.id, result.name, result.salary);
    } else {
        printf("Record not found.\n");
    }
    
    // Close the files
    fclose(data_file);
    fclose(index_file);
    
    return 0;
}