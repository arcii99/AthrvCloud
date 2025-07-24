//FormAI DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct record {
    int id;
    char name[20];
    int age;
} Record;

int main()
{
    srand(time(NULL));
    
    printf("Welcome to the Surreal Database Simulator!\n\n");
    printf("Today, we will be creating a database of imaginary creatures.\n");
    printf("Each creature will have a randomly generated ID, a randomly generated name, and a randomly generated age.\n\n");
    
    printf("How many creatures would you like to create? ");
    int num_creatures;
    scanf("%d", &num_creatures);
    
    Record *database = malloc(num_creatures * sizeof(Record));
    
    for (int i=0; i<num_creatures; i++) {
        database[i].id = rand() % 1000;
        sprintf(database[i].name, "%05d", rand() % 100000);
        database[i].age = rand() % 500;
    }
    
    printf("\nDatabase created. Here are the creatures:\n\n");
    printf("ID\tName\t\tAge\n");
    for (int i=0; i<num_creatures; i++) {
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
    
    free(database);
    
    printf("\nThank you for using the Surreal Database Simulator.\n");
    printf("Remember, even if the creatures in your database are imaginary, their data is still very real!\n");
    
    return 0;
}