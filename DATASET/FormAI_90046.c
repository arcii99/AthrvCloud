//FormAI DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>

/* Structure for database records */
struct Records {
    int id;
    char name[50];
    int age;
};

/* Structure for index records */
struct IndexRecords {
    int id;
    int offset;
};

/* Function to insert a record into the database */
void insertRecord(FILE *fp, struct Records record, struct IndexRecords *index, int *numIndexes) {
    /* Write the Record to the Database */
    fseek(fp, 0, SEEK_END);
    int offset = ftell(fp);
    fwrite(&record, sizeof(struct Records), 1, fp);

    /* Insert an Index Record */
    struct IndexRecords newRecord = {record.id, offset};
    index[*numIndexes] = newRecord;
    (*numIndexes)++;
}

/* Function to search for a record by ID */
struct Records searchByID(FILE *fp, struct IndexRecords *index, int numIndexes, int id) {
    for(int i = 0; i < numIndexes; i++) {
        if(index[i].id == id) {
            fseek(fp, index[i].offset, SEEK_SET);
            struct Records record;
            fread(&record, sizeof(struct Records), 1, fp);
            return record;
        }
    }
    printf("Record not found.\n");
    return (struct Records) {0, "", 0};
}

int main() {
    /* Create the Database File */
    FILE *fp = fopen("database.dat", "wb");

    /* Create the Index Array */
    struct IndexRecords index[100];
    int numIndexes = 0;

    /* Insert Some Records */
    struct Records record1 = {1, "Alice", 25};
    struct Records record2 = {2, "Bob", 30};
    struct Records record3 = {3, "Charlie", 35};
    struct Records record4 = {4, "David", 40};
    insertRecord(fp, record1, index, &numIndexes);
    insertRecord(fp, record2, index, &numIndexes);
    insertRecord(fp, record3, index, &numIndexes);
    insertRecord(fp, record4, index, &numIndexes);

    /* Search for a Record */
    struct Records foundRecord = searchByID(fp, index, numIndexes, 3);
    printf("Found Record: ID = %d, Name = %s, Age = %d\n", foundRecord.id, foundRecord.name, foundRecord.age);

    /* Close the Database File */
    fclose(fp);
    return 0;
}