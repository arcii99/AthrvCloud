//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define the maximum number of records in the database
#define MAX_RECORDS 100

//define the structure to represent a record in the database
typedef struct {
    int id; //record id
    char name[50]; //record name
    float value; //record value
} Record;

//define the database as an array of records
Record database[MAX_RECORDS];

//define the number of records in the database
int number_of_records = 0;

//function to add a new record to the database
void add_record(int id, char name[], float value) {
    //check if the maximum number of records has not been reached yet
    if (number_of_records < MAX_RECORDS) {
        //create a new record
        Record record;
        record.id = id;
        strcpy(record.name, name);
        record.value = value;

        //add the record to the database
        database[number_of_records] = record;
        number_of_records++;
    }
}

//function to remove a record from the database
void remove_record(int id) {
    //find the record in the database
    int index = -1;
    int i;
    for (i = 0; i < number_of_records; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }

    //remove the record from the database
    if (index != -1) {
        int j;
        for (j = index; j < number_of_records - 1; j++) {
            database[j] = database[j+1];
        }
        number_of_records--;
    }
}

//function to print the records in the database
void print_records() {
    int i;
    for (i = 0; i < number_of_records; i++) {
        printf("Record id: %d\n", database[i].id);
        printf("Record name: %s\n", database[i].name);
        printf("Record value: %.2f\n", database[i].value);
    }
}

int main() {
    //add some records to the database
    add_record(1, "Record 1", 10.00);
    add_record(2, "Record 2", 20.00);
    add_record(3, "Record 3", 30.00);

    //print the records in the database
    printf("Records in the database:\n");
    print_records();

    //remove a record from the database
    printf("Removing record with id 2\n");
    remove_record(2);

    //print the records in the database
    printf("Records in the database after removing record with id 2:\n");
    print_records();

    return 0;
}