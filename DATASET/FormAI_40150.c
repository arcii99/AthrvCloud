//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

/* Define a struct for luggage information */
struct Luggage {
    int weight;
    char* destination;
    struct Luggage* next;
};

/* Define a struct for a baggage conveyor belt */
struct ConveyorBelt {
    struct Luggage* first;
    struct Luggage* last;
};

/* Define global variables */
int num_flights = 0;
int num_luggages = 0;

/* Function prototypes */
void add_luggage(struct ConveyorBelt* conveyor, int weight, char* destination);
void print_luggages(struct ConveyorBelt* conveyor);
void transfer_luggage(struct ConveyorBelt* conveyor, char* destination);

int main() {
    // Initialize the conveyor belt
    struct ConveyorBelt conveyor;
    conveyor.first = NULL;
    conveyor.last = NULL;
    
    // Prompt the user to input the number of flights
    printf("How many flights are there today?\n");
    scanf("%d", &num_flights);
    
    // Prompt the user to input the number of luggages
    printf("How many luggages need to be loaded?\n");
    scanf("%d", &num_luggages);
    
    // Load the luggages onto the conveyor belt
    for (int i = 0; i < num_luggages; i++) {
        int weight;
        char* destination = malloc(sizeof(char) * 50);
        printf("Enter the weight of luggage %d: ", i+1);
        scanf("%d", &weight);
        printf("Enter the destination of luggage %d: ", i+1);
        scanf("%s", destination);
        add_luggage(&conveyor, weight, destination);
    }
    
    // Print the luggages on the conveyor belt
    printf("Luggages on the conveyor belt:\n");
    print_luggages(&conveyor);
    
    // Transfer the luggages to the respective flights
    for (int i = 0; i < num_flights; i++) {
        char* destination = malloc(sizeof(char) * 50);
        printf("Enter the destination of flight %d: ", i+1);
        scanf("%s", destination);
        transfer_luggage(&conveyor, destination);
    }
    
    // Print the remaining luggages on the conveyor belt
    printf("Luggages remaining on the conveyor belt:\n");
    print_luggages(&conveyor);
    
    return 0;
}

/* Function to add a luggage to the conveyor belt */
void add_luggage(struct ConveyorBelt* conveyor, int weight, char* destination) {
    // Create a new luggage
    struct Luggage* luggage = malloc(sizeof(struct Luggage));
    luggage->weight = weight;
    luggage->destination = destination;
    luggage->next = NULL;
    
    // Add the luggage to the end of the conveyor belt
    if (conveyor->last == NULL) {
        conveyor->first = luggage;
        conveyor->last = luggage;
    }
    else {
        conveyor->last->next = luggage;
        conveyor->last = luggage;
    }
}

/* Function to print all luggages on the conveyor belt */
void print_luggages(struct ConveyorBelt* conveyor) {
    struct Luggage* current = conveyor->first;
    
    while (current != NULL) {
        printf("%d kg luggage to %s\n", current->weight, current->destination);
        current = current->next;
    }
}

/* Function to transfer luggages to a flight */
void transfer_luggage(struct ConveyorBelt* conveyor, char* destination) {
    struct Luggage* current = conveyor->first;
    struct Luggage* previous = NULL;
    
    while (current != NULL) {
        if (strcmp(current->destination, destination) == 0) {
            // Remove the luggage from the conveyor belt
            if (previous == NULL) {
                conveyor->first = current->next;
            }
            else {
                previous->next = current->next;
            }
            if (current == conveyor->last) {
                conveyor->last = previous;
            }
            
            // Free the memory allocated for the luggage's destination string
            free(current->destination);
            
            // Print a message indicating that the luggage has been transferred
            printf("Luggage weighing %d kg to %s transferred to flight\n", current->weight, destination);
            
            // Free the memory allocated for the luggage struct
            free(current);
            
            // Move on to the next luggage
            current = (previous == NULL) ? conveyor->first : previous->next;
        }
        else {
            // Move on to the next luggage
            previous = current;
            current = current->next;
        }
    }
}