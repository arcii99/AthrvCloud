//FormAI DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define a struct to simulate a database table
typedef struct {
    int id;
    char name[20];
    char description[50];
} Record;

int main() {
    int num_records = 5;
    Record *database = malloc(num_records * sizeof(Record));

    // Fill in the database with some surreal data
    database[0].id = 1;
    sprintf(database[0].name, "The Dancing Moon");
    sprintf(database[0].description, "A moon that dances across the sky every night, bringing joy to everyone who watches.");

    database[1].id = 2;
    sprintf(database[1].name, "The Talking Fish");
    sprintf(database[1].description, "A fish that can speak perfect human language, but only tells bad jokes.");

    database[2].id = 3;
    sprintf(database[2].name, "The Flying Toaster");
    sprintf(database[2].description, "A toaster that sprouts wings and flies around the room, toasting bread mid-air.");

    database[3].id = 4;
    sprintf(database[3].name, "The Singing Tree");
    sprintf(database[3].description, "A tree that sings beautiful songs, but only when no one is listening.");

    database[4].id = 5;
    sprintf(database[4].name, "The Invisible Giraffe");
    sprintf(database[4].description, "A giraffe that can turn invisible at will, but hates being ignored.");

    // Print out the surreal database
    printf("Surreal Database:\n");
    printf("ID | Name                | Description\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < num_records; i++) {
        printf("%2d | %-20s | %s\n", database[i].id, database[i].name, database[i].description);
    }

    free(database);
    return 0;
}