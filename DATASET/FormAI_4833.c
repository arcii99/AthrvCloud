//FormAI DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 32 // maximum length of name
#define MAX_RECORDS 10000 // maximum number of records in the database

// define the student struct
struct student
{
    int id;
    char name[MAX_NAME_LENGTH];
    float gpa;
};

// define the database struct
struct database
{
    int num_records;
    struct student records[MAX_RECORDS];
};

// function to add a new record to the database
void add_record(struct database *db, struct student new_record)
{
    db->records[db->num_records] = new_record;
    db->num_records++;
}

// function to search for a record by id
struct student *search_by_id(struct database *db, int id)
{
    for (int i = 0; i < db->num_records; i++)
    {
        if (db->records[i].id == id)
        {
            return &(db->records[i]);
        }
    }
    return NULL; // record not found
}

// function to search for a record by name
struct student **search_by_name(struct database *db, char *name)
{
    struct student **result_set = (struct student **) malloc(sizeof(struct student *) * MAX_RECORDS);
    int num_results = 0;

    for (int i = 0; i < db->num_records; i++)
    {
        if (strcmp(db->records[i].name, name) == 0)
        {
            result_set[num_results] = &(db->records[i]);
            num_results++;
        }
    }

    if (num_results == 0)
    {
        free(result_set);
        return NULL; // record not found
    }

    result_set = (struct student **) realloc(result_set, sizeof(struct student *) * (num_results + 1));
    result_set[num_results] = NULL;

    return result_set;
}

int main()
{
    struct database db = { 0 };

    struct student s1 = { 1, "Alice", 3.8 };
    struct student s2 = { 2, "Bob", 3.5 };
    struct student s3 = { 3, "Charlie", 3.2 };
    struct student s4 = { 4, "Alice", 2.9 };
    struct student s5 = { 5, "Eve", 3.7 };

    add_record(&db, s1);
    add_record(&db, s2);
    add_record(&db, s3);
    add_record(&db, s4);
    add_record(&db, s5);

    printf("Searching for student with id 3...\n");
    struct student *result = search_by_id(&db, 3);
    if (result != NULL) printf("Record found: id=%d name=%s gpa=%.1f\n", result->id, result->name, result->gpa);
    else printf("Record not found.\n");

    printf("Searching for students named Alice...\n");
    struct student **result_set = search_by_name(&db, "Alice");
    if (result_set != NULL)
    {
        for (int i = 0; result_set[i] != NULL; i++)
        {
            printf("Record found: id=%d name=%s gpa=%.1f\n", result_set[i]->id, result_set[i]->name, result_set[i]->gpa);
        }
    }
    else printf("Record not found.\n");

    free(result_set);

    return 0;
}