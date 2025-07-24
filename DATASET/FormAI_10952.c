//FormAI DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // maximum number of records
#define MAX_NAME_LEN 50 // maximum length of name

// define a struct to hold a record
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
} Record;

// define a struct to hold an index entry
typedef struct {
    char key[MAX_NAME_LEN];
    int offset;
} IndexEntry;

// define a struct to hold the index
typedef struct {
    int num_entries;
    IndexEntry entries[MAX_RECORDS];
} Index;

// function to compare two strings
int cmp_strings(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

// function to create an index from a data file
Index create_index(char *filename) {
    Index index = {0};
    FILE *fp = fopen(filename, "rb");
    if (fp) {
        Record record;
        while (fread(&record, sizeof(Record), 1, fp) == 1) {
            IndexEntry entry;
            strncpy(entry.key, record.name, MAX_NAME_LEN);
            entry.offset = ftell(fp) - sizeof(Record);
            index.entries[index.num_entries++] = entry;
        }
        fclose(fp);
        qsort(index.entries, index.num_entries, sizeof(IndexEntry), cmp_strings);
    }
    return index;
}

// function to print a record
void print_record(Record record) {
    printf("%d %s\n", record.id, record.name);
}

// function to search for a record by name
int search_by_name(char *name, Index index, char *filename) {
    int i = 0;
    int found = 0;
    while (i < index.num_entries && !found) {
        if (strcmp(index.entries[i].key, name) == 0) {
            found = 1;
        } else {
            i++;
        }
    }
    if (found) {
        FILE *fp = fopen(filename, "rb");
        if (fp) {
            fseek(fp, index.entries[i].offset, SEEK_SET);
            Record record;
            fread(&record, sizeof(Record), 1, fp);
            while (!feof(fp) && strcmp(record.name, name) == 0) {
                print_record(record);
                fread(&record, sizeof(Record), 1, fp);
            }
            fclose(fp);
        }
    }
    return found;
}

// function to insert a record into the data file and index
void insert_record(char *name, Index *index, char *filename) {
    FILE *fp = fopen(filename, "ab");
    if (fp) {
        Record record;
        record.id = index->num_entries + 1;
        strncpy(record.name, name, MAX_NAME_LEN);
        fwrite(&record, sizeof(Record), 1, fp);
        fclose(fp);
        IndexEntry entry;
        strncpy(entry.key, name, MAX_NAME_LEN);
        entry.offset = ftell(fp) - sizeof(Record);
        index->entries[index->num_entries++] = entry;
        qsort(index->entries, index->num_entries, sizeof(IndexEntry), cmp_strings);
    }
}

int main() {
    Index index = create_index("data.bin");
    insert_record("Alice", &index, "data.bin");
    search_by_name("Bob", index, "data.bin");
    return 0;
}