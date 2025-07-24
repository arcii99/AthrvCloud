//FormAI DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100 // maximum number of records

struct Record {
    int key;
    char data[20];
};

struct Index {
    int key;
    int pos;
};

void createDataFile() {
    FILE *fp = fopen("data.txt", "w");
    struct Record r;
    for (int i = 0; i < MAX; i++) {
        r.key = i+1;
        sprintf(r.data, "Record %d", i+1);
        fwrite(&r, sizeof(r), 1, fp);
    }
    fclose(fp);
}

void createIndexFile() {
    FILE *fp = fopen("index.txt", "w");
    struct Index ind;
    for (int i = 0; i < MAX; i++) {
        ind.key = i+1;
        ind.pos = i*sizeof(struct Record);
        fwrite(&ind, sizeof(ind), 1, fp);
    }
    fclose(fp);
}

void searchRecord(int key) {
    FILE *fp = fopen("index.txt", "r");
    struct Index ind;
    bool found = false;
    while (fread(&ind, sizeof(ind), 1, fp)) {
        if (ind.key == key) {
            found = true;
            break;
        }
    }
    fclose(fp);
    if (found) {
        fp = fopen("data.txt", "r");
        struct Record r;
        fseek(fp, ind.pos, SEEK_SET);
        fread(&r, sizeof(r), 1, fp);
        printf("Record found:\n");
        printf("Key: %d\n", r.key);
        printf("Data: %s\n", r.data);
        fclose(fp);
    } else {
        printf("Record not found\n");
    }
}

int main() {
    createDataFile();
    createIndexFile();

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    searchRecord(key);

    return 0;
}