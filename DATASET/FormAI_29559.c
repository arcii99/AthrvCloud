//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_OF_BAGS 100 // The number of bags that need to be processed.
#define MAX_BAG_WEIGHT 50 // Maximum weight a bag can have in kilograms.
#define MAX_CONVEYOR_SPEED 5 // The maximum speed the conveyor belt can run at in meters per second.
#define MAX_TRUCK_CAPACITY 1000 // The maximum weight in kilograms that a truck can carry.

// A struct that represents a baggage object.
typedef struct Baggage {
    int id; // The id assigned to this baggage.
    int weight; // The weight, in kilograms, of this baggage.
    struct Baggage* next; // A pointer to the next baggage object in the linked list.
} Baggage;

// A struct that represents a truck object.
typedef struct Truck {
    int id; // The id assigned to this truck.
    int capacity; // The maximum weight capacity of this truck in kilograms.
    int current_weight; // The current weight of this truck in kilograms.
    Baggage* head; // The head pointer of the linked list of baggage objects that this truck is carrying.
    struct Truck* next; // A pointer to the next truck object in the linked list.
} Truck;

// Global variables used throughout the program.
Baggage* conveyor_belt_head = NULL;
Baggage* conveyor_belt_tail = NULL;
Truck* truck_head = NULL;

// Function declarations used throughout the program.
void add_baggage_to_conveyor_belt();
void remove_baggage_from_conveyor_belt();
void move_bags_from_conveyor_belt_to_trucks();
void add_truck_to_queue();
void remove_truck_from_queue();
void print_conveyor_belt();
void print_trucks();

int main() {
    srand(time(NULL)); // Seed the random number generator.
    
    printf("Initializing airport baggage handling simulation...\n\n");

    // Process the bags on the conveyor belt and load them onto trucks until there are no more bags left.
    while (conveyor_belt_head != NULL || truck_head != NULL) {
        add_baggage_to_conveyor_belt();
        remove_baggage_from_conveyor_belt();
        printf("\nConveyor belt:\n");
        print_conveyor_belt();
        printf("\nTrucks:\n");
        print_trucks();
        move_bags_from_conveyor_belt_to_trucks();
    }

    printf("\nAll bags have been processed and loaded onto trucks. Simulation complete.\n");

    return 0;
}

// Simulates adding a random bag to the conveyor belt.
void add_baggage_to_conveyor_belt() {
    if (rand() % 2 == 0) { // 50% chance of generating a new bag.
        int id = (conveyor_belt_head == NULL) ? 1 : conveyor_belt_tail->id + 1; // Assign a new id to the bag based on the current size of the conveyor belt.
        int weight = rand() % (MAX_BAG_WEIGHT + 1); // Generate a random weight for the bag.
        
        Baggage* new_baggage = malloc(sizeof(Baggage)); // Allocate memory for a new baggage object.
        new_baggage->id = id;
        new_baggage->weight = weight;
        new_baggage->next = NULL;
        
        if (conveyor_belt_head == NULL) { // If the conveyor belt is empty, set the head and tail pointers.
            conveyor_belt_head = new_baggage;
            conveyor_belt_tail = new_baggage;
        } else { // Otherwise, just add the new baggage object to the tail.
            conveyor_belt_tail->next = new_baggage;
            conveyor_belt_tail = new_baggage;
        }
    }
}

// Simulates removing a random bag from the conveyor belt.
void remove_baggage_from_conveyor_belt() {
    if (conveyor_belt_head != NULL && rand() % 2 == 0) { // 50% chance of removing a bag.
        Baggage* removed_baggage = conveyor_belt_head;
        conveyor_belt_head = conveyor_belt_head->next;
        
        printf("Baggage with id %d and weight %d kg has been removed from the conveyor belt.\n", removed_baggage->id, removed_baggage->weight);
        
        free(removed_baggage); // Deallocate memory for the removed baggage object.
    }
}

// Simulates moving bags from the conveyor belt onto waiting trucks.
void move_bags_from_conveyor_belt_to_trucks() {
    Truck* current_truck = truck_head;
    while (current_truck != NULL && conveyor_belt_head != NULL) {
        if (current_truck->current_weight + conveyor_belt_head->weight <= MAX_TRUCK_CAPACITY) { // Only load the bag onto the truck if there is enough room.
            Baggage* removed_baggage = conveyor_belt_head;
            conveyor_belt_head = conveyor_belt_head->next;
            
            printf("Baggage with id %d and weight %d kg has been loaded onto truck with id %d.\n", removed_baggage->id, removed_baggage->weight, current_truck->id);
            
            if (current_truck->head == NULL) { // If the truck is empty, set the head pointer.
                current_truck->head = removed_baggage;
                current_truck->current_weight = removed_baggage->weight;
            } else { // Otherwise, just add the new baggage object to the tail and update the current weight.
                current_truck->head->next = removed_baggage;
                current_truck->head = removed_baggage;
                current_truck->current_weight += removed_baggage->weight;
            }
        }
        current_truck = current_truck->next;
    }
}

// Simulates adding a new truck to the queue.
void add_truck_to_queue() {
    int id = (truck_head == NULL) ? 1 : truck_head->id + 1; // Assign a new id to the truck based on the current size of the queue.
    int capacity = rand() % (MAX_TRUCK_CAPACITY + 1); // Generate a random weight capacity for the truck.
    
    Truck* new_truck = malloc(sizeof(Truck)); // Allocate memory for a new truck object.
    new_truck->id = id;
    new_truck->capacity = capacity;
    new_truck->current_weight = 0;
    new_truck->head = NULL;
    new_truck->next = NULL;
    
    if (truck_head == NULL) { // If the queue is empty, set the head pointer.
        truck_head = new_truck;
    } else { // Otherwise, just add the new truck object to the tail.
        Truck* current_truck = truck_head;
        while (current_truck->next != NULL) {
            current_truck = current_truck->next;
        }
        current_truck->next = new_truck;
    }
}

// Simulates removing the first truck from the queue.
void remove_truck_from_queue() {
    if (truck_head != NULL) { // Only remove the truck if there is one in the queue.
        Truck* removed_truck = truck_head;
        truck_head = truck_head->next;
        
        printf("Truck with id %d and capacity %d kg has been removed from the queue.\n", removed_truck->id, removed_truck->capacity);
        
        while (removed_truck->head != NULL) { // Deallocate memory for all baggage objects attached to the truck's linked list.
            Baggage* removed_baggage = removed_truck->head;
            removed_truck->head = removed_truck->head->next;
            
            free(removed_baggage);
        }
        
        free(removed_truck); // Deallocate memory for the removed truck object.
    }
}

// Prints the current state of the conveyor belt.
void print_conveyor_belt() {
    Baggage* current_baggage = conveyor_belt_head;
    while (current_baggage != NULL) {
        printf("Baggage with id %d and weight %d kg\n", current_baggage->id, current_baggage->weight);
        current_baggage = current_baggage->next;
    }
}

// Prints the current state of the trucks waiting to be loaded.
void print_trucks() {
    Truck* current_truck = truck_head;
    while (current_truck != NULL) {
        printf("Truck with id %d, capacity %d kg, and current weight %d kg\n", current_truck->id, current_truck->capacity, current_truck->current_weight);
        current_truck = current_truck->next;
    }
}