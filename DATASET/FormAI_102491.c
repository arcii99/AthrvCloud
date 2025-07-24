//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constants
#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 20
#define MAX_GRADE_LENGTH 2

// data structures
struct Record {
    char name[MAX_NAME_LENGTH];
    int id;
    char grade[MAX_GRADE_LENGTH];
};

struct Table {
    struct Record records[MAX_RECORDS];
    int record_count;
};

// function prototypes
void display_records(struct Table table);
void add_record(struct Table *table, struct Record record);
int search_record(struct Table table, int id);
void update_record(struct Table *table, int id, char new_grade[MAX_GRADE_LENGTH]);
void delete_record(struct Table *table, int id);

int main() {
    struct Table student_table = {0};

    // manually add some records for testing
    add_record(&student_table, (struct Record){.name = "Alice", .id = 1234, .grade = "A"});
    add_record(&student_table, (struct Record){.name = "Bob", .id = 5678, .grade = "B"});
    add_record(&student_table, (struct Record){.name = "Charlie", .id = 9012, .grade = "C"});

    display_records(student_table);

    add_record(&student_table, (struct Record){.name = "Daniel", .id = 3456, .grade = "A"});
    add_record(&student_table, (struct Record){.name = "Evelyn", .id = 7890, .grade = "B"});

    display_records(student_table);

    int id_to_search = 1234;
    printf("Search result for ID %d:\n", id_to_search);
    int index = search_record(student_table, id_to_search);
    if (index != -1) {
        printf("%s %d %s\n", student_table.records[index].name, student_table.records[index].id, student_table.records[index].grade);
    } else {
        printf("Record with ID %d not found.\n", id_to_search);
    }

    update_record(&student_table, 5678, "A");

    delete_record(&student_table, 9012);

    display_records(student_table);

    return 0;
}

// displays all records in the table
void display_records(struct Table table) {
    printf("Displaying all records:\n");
    for (int i = 0; i < table.record_count; i++) {
        printf("%s %d %s\n", table.records[i].name, table.records[i].id, table.records[i].grade);
    }
    printf("\n");
}

// adds a new record to the table
void add_record(struct Table *table, struct Record record) {
    if (table->record_count >= MAX_RECORDS) {
        printf("Table is full. Cannot add more records.\n");
        return;
    }
    table->records[table->record_count] = record;
    table->record_count++;
    printf("Record added.\n");
}

// searches for a record with the given ID and returns its index in the table
int search_record(struct Table table, int id) {
    for (int i = 0; i < table.record_count; i++) {
        if (table.records[i].id == id) {
            return i;
        }
    }
    return -1; // not found
}

// updates the grade of a record with the given ID
void update_record(struct Table *table, int id, char new_grade[MAX_GRADE_LENGTH]) {
    int index = search_record(*table, id);
    if (index == -1) {
        printf("Record with ID %d not found.\n", id);
        return;
    }
    strncpy(table->records[index].grade, new_grade, MAX_GRADE_LENGTH);
    printf("Record updated.\n");
}

// deletes a record with the given ID
void delete_record(struct Table *table, int id) {
    int index = search_record(*table, id);
    if (index == -1) {
        printf("Record with ID %d not found.\n", id);
        return;
    }
    for (int i = index; i < table->record_count - 1; i++) {
        table->records[i] = table->records[i + 1];
    }
    table->record_count--;
    printf("Record deleted.\n");
}