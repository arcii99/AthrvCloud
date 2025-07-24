//FormAI DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct Index {
    int id;
    int offset;
};

void createIndexFile(char* filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error: Could not create index file");
        return;
    }
    fclose(f);
}

void insertIndex(char* filename, struct Index new_index) {
    FILE *f = fopen(filename, "ab");
    if (f == NULL) {
        printf("Error: Could not open index file");
        return;
    }
    fwrite(&new_index, sizeof(struct Index), 1, f);
    fclose(f);
}

int searchIndex(char* filename, int id) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: Could not open index file");
        return -1;
    }
    int offset = -1;
    struct Index temp_index;
    while (fread(&temp_index, sizeof(struct Index), 1, f)) {
        if (temp_index.id == id) {
            offset = temp_index.offset;
            break;
        }
    }
    fclose(f);
    return offset;
}

int main() {
    struct Index new_index;
    new_index.id = 1;
    new_index.offset = 10;

    createIndexFile("index.bin");
    insertIndex("index.bin", new_index);

    int offset = searchIndex("index.bin", 1);
    if (offset == -1) {
        printf("Index not found!\n");
    } else {
        printf("Index found at offset %d\n", offset);
    }

    return 0;
}