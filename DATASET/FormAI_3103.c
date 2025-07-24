//FormAI DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry {
    char key[20];
    int data;
};

struct index {
    char key[20];
    int offset;
};

void add_entry(struct entry *e, FILE *fp, FILE *idx) {
    // write entry to file
    int offset = ftell(fp);
    fwrite(e, sizeof(struct entry), 1, fp);
    
    // write key and offset to index file
    struct index idx_entry;
    strcpy(idx_entry.key, e->key);
    idx_entry.offset = offset;
    fwrite(&idx_entry, sizeof(struct index), 1, idx);
}

int find_entry(char *key, FILE *idx) {
    // search for key in index file
    struct index idx_entry;
    rewind(idx);
    while (fread(&idx_entry, sizeof(struct index), 1, idx)) {
        if (strcmp(key, idx_entry.key) == 0)
            return idx_entry.offset;
    }
    return -1;  // entry not found
}

void print_entry(struct entry *e) {
    printf("Key: %s, Data: %d\n", e->key, e->data);
}

int main() {
    FILE *data_file = fopen("data.dat", "wb");
    FILE *index_file = fopen("index.dat", "wb");
    
    // add entries to database
    struct entry e1 = {"key1", 100};
    add_entry(&e1, data_file, index_file);
    struct entry e2 = {"key2", 200};
    add_entry(&e2, data_file, index_file);
    struct entry e3 = {"key3", 300};
    add_entry(&e3, data_file, index_file);
    
    // search for entry
    char search_key[20] = "key2";
    int offset = find_entry(search_key, index_file);
    if (offset != -1) {
        // read entry from file
        struct entry e;
        fseek(data_file, offset, SEEK_SET);
        fread(&e, sizeof(struct entry), 1, data_file);
        print_entry(&e);
    } else {
        printf("Entry not found.\n");
    }
    
    // close files
    fclose(data_file);
    fclose(index_file);
    
    return 0;
}