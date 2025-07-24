//FormAI DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

int main() {
    FILE *db_file;
    Person person;
    
    // Check if the database file exists
    if ((db_file = fopen("database.bin", "rb")) == NULL) {
        printf("Database file does not exist.\n");
        return 0;
    }
    
    // Read and display all records in the database
    while (fread(&person, sizeof(Person), 1, db_file) == 1) {
        printf("ID: %d\n", person.id);
        printf("Name: %s\n", person.name);
        printf("Age: %d\n", person.age);
        printf("\n");
    }
    
    // Close the database file
    fclose(db_file);
    
    // Create a new record and add it to the database
    printf("Enter a new record:\n");
    printf("ID: ");
    scanf("%d", &person.id);
    printf("Name: ");
    scanf("%s", person.name);
    printf("Age: ");
    scanf("%d", &person.age);
    
    db_file = fopen("database.bin", "ab");
    fwrite(&person, sizeof(Person), 1, db_file);
    fclose(db_file);
    
    return 0;
}