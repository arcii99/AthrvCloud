//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_RECORDS 1000

struct employee {
    int id;
    char name[20];
    float salary;
};

struct index_entry {
    int id;
    int offset;
};

struct index {
    struct index_entry entry[MAX_RECORDS];
    int num_entries;
};

int compare_records(const void *a, const void *b) {
    int id_a = ((struct index_entry*)a)->id;
    int id_b = ((struct index_entry*)b)->id;
    return id_a - id_b;
}

void build_index(FILE *fp, struct index *idx) {
    struct employee emp;
    int offset = 0;
    while (fread(&emp, sizeof(struct employee), 1, fp) == 1) {
        idx->entry[idx->num_entries].id = emp.id;
        idx->entry[idx->num_entries].offset = offset;
        idx->num_entries++;
        offset += sizeof(struct employee);
    }
    qsort(idx->entry, idx->num_entries, sizeof(struct index_entry), compare_records);
}

bool find_record(FILE *fp, struct index *idx, int id, struct employee *emp) {
    int i = 0;
    while (i < idx->num_entries && idx->entry[i].id != id) {
        i++;
    }
    if (i == idx->num_entries) {
        return false;
    }
    fseek(fp, idx->entry[i].offset, SEEK_SET);
    fread(emp, sizeof(struct employee), 1, fp);
    return true;
}

int main() {
    FILE *fp = fopen("employees.dat", "rb");
    if (!fp) {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }
    struct index idx = {0};
    build_index(fp, &idx);
    struct employee emp = {0};
    int id = 42;
    if (find_record(fp, &idx, id, &emp)) {
        printf("Employee ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
    } else {
        printf("Employee ID not found.\n");
    }
    fclose(fp);
    return EXIT_SUCCESS;
}