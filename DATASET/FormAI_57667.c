//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_RECORDS 10000

//Struct to define a record
typedef struct{
    int id;
    char name[50];
    float salary;
} Record;

//Global list of records
Record records[MAX_RECORDS];

//Function to add a new record to the list
void addRecord(int id, char *name, float salary){
    int i;

    //Find empty spot in list
    for(i=0; i<MAX_RECORDS; i++){
        if(records[i].id == 0){
            //Found empty spot, add record
            records[i].id = id;
            strcpy(records[i].name, name);
            records[i].salary = salary;
            return;
        }
    }

    printf("ERROR: Maximum number of records reached!\n");
}

//Function to remove a record from the list
void removeRecord(int id){
    int i;

    //Find record with matching ID
    for(i=0; i<MAX_RECORDS; i++){
        if(records[i].id == id){
            //Found record, remove it
            records[i].id = 0;
            strcpy(records[i].name, "");
            records[i].salary = 0;
            return;
        }
    }

    printf("ERROR: Record with ID '%d' not found!\n", id);
}

//Function to retrieve a record by ID
Record getRecord(int id){
    int i;

    //Find record with matching ID
    for(i=0; i<MAX_RECORDS; i++){
        if(records[i].id == id){
            //Found record, return it
            return records[i];
        }
    }

    printf("ERROR: Record with ID '%d' not found!\n", id);

    //Return empty record
    Record empty;
    empty.id = 0;
    strcpy(empty.name, "");
    empty.salary = 0;

    return empty;
}

//Function to print all records in the list
void printRecords(){
    int i;

    printf("----------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-10s |\n", "ID", "Name", "Salary");
    printf("----------------------------------------------------------\n");

    //Print all non-empty records
    for(i=0; i<MAX_RECORDS; i++){
        if(records[i].id != 0){
            printf("| %-5d | %-20s | %-10.2f |\n", records[i].id, records[i].name, records[i].salary);
        }
    }

    printf("----------------------------------------------------------\n");
}

int main(){
    //Add some initial records
    addRecord(1, "John Smith", 10000.00);
    addRecord(2, "Jane Doe", 15000.00);
    addRecord(3, "Bob Johnson", 12000.00);

    //Print all records
    printf("Initial records:\n");
    printRecords();

    //Remove record with ID 2
    removeRecord(2);

    //Print all records again
    printf("Records after removing ID 2:\n");
    printRecords();

    //Get record with ID 3 and print it
    Record r = getRecord(3);
    printf("Record with ID 3:\n");
    printf("| %-5s | %-20s | %-10s |\n", "ID", "Name", "Salary");
    printf("----------------------------\n");
    printf("| %-5d | %-20s | %-10.2f |\n", r.id, r.name, r.salary);
    printf("----------------------------\n");

    //Add a new record and print all records again
    addRecord(4, "Alice Brown", 9000.00);
    printf("Records after adding new record:\n");
    printRecords();

    return 0;
}