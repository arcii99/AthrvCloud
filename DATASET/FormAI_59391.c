//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

/* Define structure of each data record */
typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

/* Define structure of an index node */
typedef struct {
    char key[MAX_KEY_LENGTH];
    int offset;
} IndexNode;

/* Define structure of an index */
typedef struct {
    int num_nodes;
    IndexNode nodes[MAX_RECORDS];
} Index;

void insert_record(FILE *fptr, Index *index, Record *record);
void delete_record(FILE *fptr, Index *index, char *key);
int search_record(FILE *fptr, Index *index, char *key);

int main() {
    FILE *fptr;
    Record record;
    Index index;
    memset(&index, 0, sizeof(Index));

    /* Open database file in binary read-write mode */
    fptr = fopen("database.bin", "rb+");
    if (fptr == NULL) {
        /* Create database file if it doesn't exist */
        fptr = fopen("database.bin", "wb+");
        if (fptr == NULL) {
            printf("Error creating database file!\n");
            return -1;
        }
    }

    /* Read in all records from file into memory and build index */
    fseek(fptr, 0, SEEK_SET);
    while (fread(&record, sizeof(Record), 1, fptr) == 1) {
        insert_record(fptr, &index, &record);
    }

    /* Close and reopen file in binary read-only mode */
    fclose(fptr);
    fptr = fopen("database.bin", "rb");
    if (fptr == NULL) {
        printf("Error opening database file for reading!\n");
        return -1;
    }

    /* Example usage of database operations */
    char search_key[] = "John Doe";
    char delete_key[] = "Jane Doe";
    char new_record_key[] = "Jack Smith";
    char new_record_value[] = "1234 Main St, Anytown USA";

    /* Search for a record */
    int offset = search_record(fptr, &index, search_key);
    if (offset >= 0) {
        printf("Record found at offset %d:\n", offset);
        fseek(fptr, offset, SEEK_SET);
        if (fread(&record, sizeof(Record), 1, fptr) == 1) {
            printf("Key: %s\nValue: %s\n", record.key, record.value);
        }
    } else {
        printf("Record not found!\n");
    }

    /* Insert a new record */
    strcpy(record.key, new_record_key);
    strcpy(record.value, new_record_value);
    insert_record(fptr, &index, &record);

    /* Delete an existing record */
    delete_record(fptr, &index, delete_key);

    /* Close file and free memory */
    fclose(fptr);
    return 0;
}

/* Helper function to insert a record into file and index */
void insert_record(FILE *fptr, Index *index, Record *record) {
    int i, j;

    /* Write record to end of file */
    fseek(fptr, 0, SEEK_END);
    int offset = ftell(fptr);
    fwrite(record, sizeof(Record), 1, fptr);

    /* Insert index node into sorted position */
    for (i = 0; i < index->num_nodes; i++) {
        if (strcmp(record->key, index->nodes[i].key) < 0) {
            /* Shift nodes to right to make space */
            for (j = index->num_nodes - 1; j >= i; j--) {
                strcpy(index->nodes[j + 1].key, index->nodes[j].key);
                index->nodes[j + 1].offset = index->nodes[j].offset;
            }
            break;
        } else if (strcmp(record->key, index->nodes[i].key) == 0) {
            /* Key already exists in index */
            return;
        }
    }
    /* Insert new node into index */
    strcpy(index->nodes[i].key, record->key);
    index->nodes[i].offset = offset;
    index->num_nodes++;
}

/* Helper function to delete a record from file and index */
void delete_record(FILE *fptr, Index *index, char *key) {
    int i, j, found = 0;

    /* Find index node for this key */
    for (i = 0; i < index->num_nodes; i++) {
        if (strcmp(key, index->nodes[i].key) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        /* Shift nodes to left to fill gap */
        for (j = i; j < index->num_nodes - 1; j++) {
            strcpy(index->nodes[j].key, index->nodes[j + 1].key);
            index->nodes[j].offset = index->nodes[j + 1].offset;
        }
        index->num_nodes--;

        /* Overwrite record in file with last record in file */
        fseek(fptr, 0, SEEK_END);
        long file_size = ftell(fptr);
        long last_record_offset = index->nodes[index->num_nodes].offset;
        if (last_record_offset + sizeof(Record) <= file_size) {
            fseek(fptr, last_record_offset, SEEK_SET);
            if (fread(&index->nodes[i], sizeof(Record), 1, fptr) == 1) {
                fseek(fptr, index->nodes[i].offset, SEEK_SET);
                fwrite(&index->nodes[i], sizeof(Record), 1, fptr);
            }
        }

        /* Truncate file to remove deleted record */
        ftruncate(fileno(fptr), file_size - sizeof(Record));
    }
}

/* Helper function to search for a record in file and index */
int search_record(FILE *fptr, Index *index, char *key) {
    int i;

    /* Perform binary search on index */
    int left = 0;
    int right = index->num_nodes - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(key, index->nodes[mid].key);
        if (cmp < 0) {
            right = mid - 1;
        } else if (cmp > 0) {
            left = mid + 1;
        } else {
            /* Key found, return offset of record in file */
            return index->nodes[mid].offset;
        }
    }
    /* Key not found */
    return -1;
}