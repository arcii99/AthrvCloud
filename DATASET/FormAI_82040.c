//FormAI DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_NAME_SIZE 20
#define MAX_WEAPON_SIZE 30

/* Struct representing a survivor. */
typedef struct survivor {
    int id;
    char name[MAX_NAME_SIZE];
    int age;
    char weapon[MAX_WEAPON_SIZE];
} Survivor;

/* Data for our survivors. */
Survivor survivors[MAX_SIZE];
int num_survivors = 0;

/* Function to create a new survivor. */
Survivor create_survivor(int id, char *name, int age, char *weapon) {
    Survivor s;
    s.id = id;
    strncpy(s.name, name, MAX_NAME_SIZE);
    s.age = age;
    strncpy(s.weapon, weapon, MAX_WEAPON_SIZE);
    return s;
}

/* Function to add a survivor to the database. */
void add_survivor(int id, char *name, int age, char *weapon) {
    if (num_survivors < MAX_SIZE) {
        Survivor s = create_survivor(id, name, age, weapon);
        survivors[num_survivors++] = s;
        printf("Survivor added successfully.\n");
    } else {
        printf("Cannot add survivor. Database is full.\n");
    }
}

/* Function to print out all survivors in the database. */
void print_survivors() {
    printf("Survivor database:\n");
    for (int i = 0; i < num_survivors; i++) {
        printf("ID: %d, Name: %s, Age: %d, Weapon: %s\n",
                survivors[i].id, survivors[i].name, survivors[i].age,
                survivors[i].weapon);
    }
}

/* Function to search for a survivor by their ID. */
void search_survivor(int id) {
    for (int i = 0; i < num_survivors; i++) {
        if (survivors[i].id == id) {
            printf("ID: %d, Name: %s, Age: %d, Weapon: %s\n",
                    survivors[i].id, survivors[i].name, survivors[i].age,
                    survivors[i].weapon);
            return;
        }
    }
    printf("Survivor with ID %d not found.\n", id);
}

int main() {
    /* Start the simulation. */
    printf("Welcome to the post-apocalyptic survivor database.\n");
    
    /* Add some sample survivors. */
    add_survivor(1, "Alice", 23, "Baseball bat");
    add_survivor(2, "Bob", 28, "Shotgun");
    add_survivor(3, "Charlie", 35, "Machete");
    add_survivor(4, "Danielle", 19, "Handgun");

    /* Print all the survivors in the database. */
    print_survivors();

    /* Search for a survivor by their ID. */
    search_survivor(2);

    return 0;
}