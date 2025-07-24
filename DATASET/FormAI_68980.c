//FormAI DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} record_t;

typedef struct {
    int id;
    int index;
} index_t;

typedef struct {
    index_t *index;
    int size;
} index_list_t;

void create_index(record_t records[], index_list_t *index_list, int num_records) {
    index_list->index = calloc(num_records, sizeof(index_t));
    index_list->size = num_records;

    for (int i = 0; i < num_records; i++) {
        index_list->index[i].id = records[i].id;
        index_list->index[i].index = i;
    }
}

int compare_index(const void *a, const void *b) {
    index_t *ia = (index_t *)a;
    index_t *ib = (index_t *)b;

    if (ia->id < ib->id) {
        return -1;
    } else if (ia->id > ib->id) {
        return 1;
    } else {
        return 0;
    }
}

int binary_search(index_t index[], int size, int id) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (index[mid].id < id) {
            left = mid + 1;
        } else if (index[mid].id > id) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    record_t records[MAX_RECORDS];
    int num_records = 0;

    // Add some records
    records[num_records].id = 1;
    strncpy(records[num_records].name, "Alice", MAX_NAME_LENGTH);
    num_records++;

    records[num_records].id = 2;
    strncpy(records[num_records].name, "Bob", MAX_NAME_LENGTH);
    num_records++;

    records[num_records].id = 3;
    strncpy(records[num_records].name, "Charlie", MAX_NAME_LENGTH);
    num_records++;

    // Create index
    index_list_t index_list;
    create_index(records, &index_list, num_records);

    // Search for a record
    int search_id = 2;
    int result = binary_search(index_list.index, index_list.size, search_id);

    if (result != -1) {
        printf("Record found: id=%d, name=%s\n", records[index_list.index[result].index].id, records[index_list.index[result].index].name);
    } else {
        printf("Record not found\n");
    }

    // Sort the index
    qsort(index_list.index, index_list.size, sizeof(index_t), compare_index);

    // Search for a record again
    search_id = 3;
    result = binary_search(index_list.index, index_list.size, search_id);

    if (result != -1) {
        printf("Record found: id=%d, name=%s\n", records[index_list.index[result].index].id, records[index_list.index[result].index].name);
    } else {
        printf("Record not found\n");
    }

    // Free the index
    free(index_list.index);

    return 0;
}