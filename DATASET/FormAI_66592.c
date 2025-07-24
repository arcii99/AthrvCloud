//FormAI DATASET v1.0 Category: Database simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
struct person {
    int id;
    char name[50];
    int age;
};

int main() {
    int choice;
    int next_id = 1;
    struct person *database = (struct person*)malloc(sizeof(struct person)); // Allocate memory for database
    int db_size = 0; // Initially database is empty
    
    while(1) {
        // Display menu
        printf("\nDatabase Menu\n");
        printf("1. Add person\n");
        printf("2. Delete person\n");
        printf("3. Print database\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Add person
                struct person new_person;
                new_person.id = next_id;
                printf("\nEnter name: ");
                scanf("%s", new_person.name);
                printf("Enter age: ");
                scanf("%d", &new_person.age);
                next_id++; // Increment next ID
                database[db_size] = new_person; // Add person to database
                db_size++; // Increment database size
                database = (struct person*)realloc(database, (db_size+1)*sizeof(struct person)); // Reallocate memory for updated database
                printf("Person added successfully!");
                break;
            case 2:
                // Delete person
                int delete_id;
                printf("\nEnter ID of person to delete: ");
                scanf("%d", &delete_id);
                int i, delete_index = -1;
                for(i=0; i<db_size; i++) {
                    if(database[i].id == delete_id) {
                        delete_index = i;
                        break;
                    }
                }
                if(delete_index == -1) {
                    printf("Person with entered ID not found!");
                } else {
                    for(i=delete_index; i<db_size-1; i++) {
                        database[i] = database[i+1];
                    }
                    db_size--; // Decrement database size
                    database = (struct person*)realloc(database, (db_size+1)*sizeof(struct person)); // Reallocate memory for updated database
                    printf("Person deleted successfully!");
                }
                break;
            case 3:
                // Print database
                printf("\nDatabase:\n");
                for(i=0; i<db_size; i++) {
                    printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
                }
                break;
            case 4:
                // Exit
                printf("\nExiting...");
                free(database); // Free memory allocated for database
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}