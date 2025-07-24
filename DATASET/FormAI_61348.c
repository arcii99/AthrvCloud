//FormAI DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_FILE "my_db.dat"
#define INDEX_FILE "my_db.idx"

typedef struct {
    int id;
    char name[30];
    int age;
} Record;

typedef struct {
    int id;
    long offset;
} Index;

void create_database() {
    FILE *fp_db = fopen(DB_FILE, "wb");
    fclose(fp_db);
}

void create_index() {
    FILE *fp_db = fopen(DB_FILE, "rb");
    FILE *fp_idx = fopen(INDEX_FILE, "wb");
    int i = 0;
    while (!feof(fp_db)) {
        Record r;
        fread(&r, sizeof(Record), 1, fp_db);
        if (!feof(fp_db)) {
            Index idx;
            idx.id = r.id;
            idx.offset = sizeof(Record) * i++;
            fwrite(&idx, sizeof(Index), 1, fp_idx);
        }
    }
    fclose(fp_db);
    fclose(fp_idx);
}

int search(int id) {
    FILE *fp_idx = fopen(INDEX_FILE, "rb");
    fseek(fp_idx, 0, SEEK_END);
    long size = ftell(fp_idx);
    fseek(fp_idx, 0, SEEK_SET);
    long low = 0, high = (size / sizeof(Index)) - 1;
    while (low <= high) {
        long mid = (low + high) / 2;
        Index idx;
        fseek(fp_idx, mid * sizeof(Index), SEEK_SET);
        fread(&idx, sizeof(Index), 1, fp_idx);
        if (idx.id == id) {
            fclose(fp_idx);
            return idx.offset / sizeof(Record);
        }
        else if (idx.id < id) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    fclose(fp_idx);
    return -1;
}

void insert(Record r) {
    FILE *fp_db = fopen(DB_FILE, "ab");
    fwrite(&r, sizeof(Record), 1, fp_db);
    fclose(fp_db);
    create_index();
}

void print_record(Record r) {
    printf("ID         : %d\n", r.id);
    printf("Name       : %s\n", r.name);
    printf("Age        : %d\n", r.age);
}

int main() {
    create_database();
    Record r1 = {1, "John Doe", 25};
    insert(r1);
    Record r2 = {2, "Jane Doe", 22};
    insert(r2);
    Record r3 = {3, "Bob Smith", 32};
    insert(r3);
    Record r4 = {4, "Mary Johnson", 46};
    insert(r4);
  
    int result = search(2);
    if (result == -1) {
        printf("Record not found.\n");  
    }
    else {
        FILE *fp_db = fopen(DB_FILE, "rb");
        fseek(fp_db, result * sizeof(Record), SEEK_SET);
        Record r;
        fread(&r, sizeof(Record), 1, fp_db);
        print_record(r);
        fclose(fp_db);
    }
    return 0;
}