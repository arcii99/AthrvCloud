//FormAI DATASET v1.0 Category: Database querying ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining maximum length of string in record as 30
#define MAX_LEN 30

// structure of the record to store data
struct Record {
    char name[MAX_LEN];
    char subject[MAX_LEN];
    int marks;
};

// function to create a new record
struct Record* createRecord(char name[], char subject[], int marks) {
    struct Record* newRecord = (struct Record*) malloc(sizeof(struct Record));
    strcpy(newRecord->name, name);
    strcpy(newRecord->subject, subject);
    newRecord->marks = marks;
    return newRecord;
}

int main() {
    // creating records of students
    struct Record* student1 = createRecord("John Doe", "C Programming", 90);
    struct Record* student2 = createRecord("Jane Doe", "Database Management", 85);
    struct Record* student3 = createRecord("Tom Smith", "Data Structures", 92);
    struct Record* student4 = createRecord("Sarah Lee", "Web Development", 88);
    struct Record* student5 = createRecord("Mike Johnson", "Operating Systems", 95);

    // creating array of records to store all the records
    struct Record* records[5];
    records[0] = student1;
    records[1] = student2;
    records[2] = student3;
    records[3] = student4;
    records[4] = student5;

    int option;
    printf("What kind of query would you like to run?\n");
    printf("1. Display records with marks greater than 90\n");
    printf("2. Display records with marks less than 75\n");
    printf("3. Display records with subject 'C Programming'\n");
    printf("Enter your option (1-3): ");
    scanf("%d", &option);

    printf("\n");
    // switch case for different options
    switch (option) {
        case 1:
            printf("Records with marks greater than 90:\n");
            for (int i=0; i<5; i++) {
                if (records[i]->marks > 90) {
                    printf("%s scored %d marks in %s\n", records[i]->name, records[i]->marks, records[i]->subject);
                }
            }
            break;
        case 2:
            printf("Records with marks less than 75:\n");
            for (int i=0; i<5; i++) {
                if (records[i]->marks < 75) {
                    printf("%s scored %d marks in %s\n", records[i]->name, records[i]->marks, records[i]->subject);
                }
            }
            break;
        case 3:
            printf("Records with subject 'C Programming':\n");
              for (int i=0; i<5; i++) {
                if (strcmp(records[i]->subject, "C Programming") == 0) {
                    printf("%s scored %d marks in %s\n", records[i]->name, records[i]->marks, records[i]->subject);
                }
            }
            break;
        default:
            printf("Invalid option. Please enter a number between 1-3\n");
            break;
    }

    // freeing memory allocated to records
    free(student1);
    free(student2);
    free(student3);
    free(student4);
    free(student5);

    return 0;
}