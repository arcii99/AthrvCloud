//FormAI DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRIMARY_KEY_LEN 10
#define MAX_RECORD_LEN 100

typedef struct Record {
    char primary_key[MAX_PRIMARY_KEY_LEN];
    char data[MAX_RECORD_LEN];
} Record;

typedef struct Index {
    char primary_key[MAX_PRIMARY_KEY_LEN];
    long int offset;
} Index;

void create_index(char* filename){
    FILE *file = fopen(filename, "rb");
    FILE *index_file = fopen("index.dat", "wb");

    Record record;
    Index index;

    long int offset = 0;

    while(fread(&record, sizeof(record), 1, file)){
        // Create index record
        strncpy(index.primary_key, record.primary_key, MAX_PRIMARY_KEY_LEN);
        index.offset = offset;

        // Write index record to file
        fwrite(&index, sizeof(index), 1, index_file);

        // Update offset
        offset = ftell(file);
    }

    fclose(file);
    fclose(index_file);
}

int search_index(char* filename, char* primary_key){
    FILE *index_file = fopen("index.dat", "rb");

    Index index;

    while(fread(&index, sizeof(index), 1, index_file)){
        if(strncmp(index.primary_key, primary_key, MAX_PRIMARY_KEY_LEN) == 0) {
            fclose(index_file);

            FILE* file = fopen(filename, "rb");
            fseek(file, index.offset, SEEK_SET);

            Record record;
            fread(&record, sizeof(record), 1, file);

            printf("Found record: %s\n", record.data);
            fclose(file);

            return 1;
        }
    }

    fclose(index_file);

    printf("Record not found!\n");
    return 0;
}

int main(){
    char filename[] = "data.dat";

    // Create initial file
    Record records[] = {
        {"1", "Record 1 data"},
        {"2", "Record 2 data"},
        {"3", "Record 3 data"},
        {"4", "Record 4 data"}
    };
    FILE *file = fopen(filename, "wb");
    fwrite(records, sizeof(records), 1, file);
    fclose(file);

    // Create index
    create_index(filename);

    // Search for record
    search_index(filename, "3");

    return 0;
}