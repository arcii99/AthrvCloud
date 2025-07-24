//FormAI DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct index {
    char key[100];
    int code;
};

void createIndexFile(char* filename) {
    FILE *fp;
    fp = fopen(filename, "wb");
    fclose(fp);
}

void addRecordToIndexFile(char* filename, char* key, int code) {
    FILE *fp;
    struct index record;
    strcpy(record.key, key);
    record.code = code;
    fp = fopen(filename, "ab");
    fwrite(&record, sizeof(record), 1, fp);
    fclose(fp);
}

int searchRecordInIndexFile(char* filename, char* key) {
    FILE *fp;
    struct index record;
    fp = fopen(filename, "rb");
    while (fread(&record, sizeof(record), 1, fp) != 0) {
        if (strcmp(record.key, key) == 0) {
            fclose(fp);
            return record.code;
        }
    }
    fclose(fp);
    return -1;
}

int main() {
    createIndexFile("index.bin");
    addRecordToIndexFile("index.bin", "apple", 1);
    addRecordToIndexFile("index.bin", "banana", 2);
    addRecordToIndexFile("index.bin", "orange", 3);
    
    int code = searchRecordInIndexFile("index.bin", "banana");
    if (code != -1) {
        printf("Code for 'banana' is %d\n", code);
    } else {
        printf("Record not found\n");
    }
    
    return 0;
}