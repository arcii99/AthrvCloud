//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // Define the database schema
    struct student{
        int id;
        char name[50];
        int age;
        float gpa;
    } database[10];

    // Add records to database
    database[0].id = 1;
    strcpy(database[0].name, "John Doe");
    database[0].age = 20;
    database[0].gpa = 3.8;

    database[1].id = 2;
    strcpy(database[1].name, "Jane Smith");
    database[1].age = 21;
    database[1].gpa = 3.6;

    // Print out all records in database
    printf("ID\tName\t\tAge\tGPA\n");
    for(int i=0; i<2; i++){
        printf("%d\t%s\t%d\t%.1f\n", database[i].id, database[i].name, database[i].age, database[i].gpa);
    }

    // Update a record in database
    int id_to_update = 1;
    for(int i=0; i<2; i++){
        if(database[i].id == id_to_update){
            strcpy(database[i].name, "John Smith");
            database[i].age = 22;
            database[i].gpa = 3.9;
            break;
        }
    }

    // Print out updated record in database
    printf("\nRecord with ID %d updated.\n", id_to_update);
    printf("ID\tName\t\tAge\tGPA\n");
    for(int i=0; i<2; i++){
        printf("%d\t%s\t%d\t%.1f\n", database[i].id, database[i].name, database[i].age, database[i].gpa);
    }

    // Delete a record from database
    int id_to_delete = 1;
    for(int i=0; i<2; i++){
        if(database[i].id == id_to_delete){
            for(int j=i; j<(2-1); j++){
                database[j] = database[j+1];
            }
            break;
        }
    }

    // Print out updated database after record deletion
    printf("\nRecord with ID %d deleted.\n", id_to_delete);
    printf("ID\tName\t\tAge\tGPA\n");
    for(int i=0; i<(2-1); i++){
        printf("%d\t%s\t%d\t%.1f\n", database[i].id, database[i].name, database[i].age, database[i].gpa);
    }

    return 0;
}