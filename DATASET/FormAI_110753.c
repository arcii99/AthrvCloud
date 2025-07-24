//FormAI DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100000

// Define record structure
typedef struct {
    int id;
    char name[50];
    int age;
} record;

// Define index structure
typedef struct {
    int key;
    int offset;
} index_entry;

// Function to compare two index entries
int compare_entries(const void *a, const void *b) {
    index_entry *entry_a = (index_entry*) a;
    index_entry *entry_b = (index_entry*) b;
    return entry_a->key - entry_b->key;
}

int main() {
    // Open file for reading
    FILE *file = fopen("records.bin", "rb");
    if (!file) {
        printf("Error: failed to open file.\n");
        return 1;
    }
    
    // Read records and create index
    record records[MAX_RECORDS];
    index_entry index[MAX_RECORDS];
    int num_records = 0;
    while (fread(&records[num_records], sizeof(record), 1, file)) {
        index[num_records].key = records[num_records].id;
        index[num_records].offset = ftell(file) - sizeof(record);
        num_records++;
    }
    fclose(file);
    printf("%d records read.\n", num_records);
    
    // Sort index
    qsort(index, num_records, sizeof(index_entry), compare_entries);
    
    // Search for record with ID = 500
    int target_id = 500;
    int lo = 0, hi = num_records - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (index[mid].key < target_id) {
            lo = mid + 1;
        } else if (index[mid].key > target_id) {
            hi = mid - 1;
        } else {
            // Found record
            record r;
            file = fopen("records.bin", "rb");
            fseek(file, index[mid].offset, SEEK_SET);
            fread(&r, sizeof(record), 1, file);
            fclose(file);
            printf("Record found: %d %s %d\n", r.id, r.name, r.age);
            return 0;
        }
    }
    printf("Record not found.\n");
    return 0;
}