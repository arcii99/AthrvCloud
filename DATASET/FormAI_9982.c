//FormAI DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to hold data about the clients
typedef struct {
    int id;
    char name[50];
    char address[100];
    int age;
    char marital_status[20];
} client;

int main() {
    // Initialize the random seed
    srand(time(NULL));
    
    // Declare and initialize variables
    client db[100];
    int num_clients = 0;
    int num_married = 0;
    int num_single = 0;
    int num_divorced = 0;
    int total_age = 0;
    float avg_age = 0.0;

    // Generate data for 100 clients and add them to the database
    for (int i = 0; i < 100; i++) {
        client c;
        c.id = i + 1;
        sprintf(c.name, "Client%d", c.id);
        sprintf(c.address, "Address%d", c.id);
        c.age = rand() % 61 + 18;
        int status = rand() % 3;
        switch (status) {
            case 0:
                sprintf(c.marital_status, "Married");
                num_married++;
                break;
            case 1:
                sprintf(c.marital_status, "Single");
                num_single++;
                break;
            case 2:
                sprintf(c.marital_status, "Divorced");
                num_divorced++;
                break;
        }
        db[i] = c;
        num_clients++;
        total_age += c.age;
    }

    // Calculate the average age of the clients
    if (num_clients != 0) {
        avg_age = (float) total_age / (float) num_clients;
    }

    // Print the database statistics
    printf("Number of clients: %d\n", num_clients);
    printf("Number of married clients: %d\n", num_married);
    printf("Number of single clients: %d\n", num_single);
    printf("Number of divorced clients: %d\n", num_divorced);
    printf("Average age of clients: %.2f\n", avg_age);

    // Search for a client in the database by name
    char search_name[50];
    printf("Enter client name to search: ");
    fgets(search_name, 50, stdin);
    search_name[strcspn(search_name, "\n")] = '\0'; // Remove trailing newline
    for (int i = 0; i < num_clients; i++) {
        if (strcmp(db[i].name, search_name) == 0) {
            printf("Client found! ID: %d, Name: %s, Address: %s, Age: %d, Marital Status: %s\n", db[i].id, db[i].name, db[i].address, db[i].age, db[i].marital_status);
            break;
        }
    }

    return 0;
}