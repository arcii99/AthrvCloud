//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct database {
    int id;
    char name[50];
    float salary;
};

int compare(const void *a, const void *b) {
    int l = ((struct database *)a)->id;
    int r = ((struct database *)b)->id;
    return (l - r);
}

int main() {
    struct database db[100];
    int n, i, search_id;
    printf("Enter the number of records: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the ID, Name and Salary of the employee: ");
        scanf("%d %s %f", &db[i].id, db[i].name, &db[i].salary);
    }
    qsort(db, n, sizeof(struct database), compare);
    printf("Enter the ID to search: ");
    scanf("%d", &search_id);
    int l = 0, r = n - 1, mid, found = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (db[mid].id == search_id) {
            printf("Record found:\nID: %d, Name: %s, Salary: %.2f", db[mid].id, db[mid].name, db[mid].salary);
            found = 1;
            break;
        }
        else if (db[mid].id < search_id)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (!found)
        printf("Record not found!");
    return 0;
}