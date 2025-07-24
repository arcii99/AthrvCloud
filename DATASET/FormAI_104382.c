//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Enums to represent the state of different components
enum Status{ WORKING, DAMAGED, DESTROYED };

// Struct to represent a Performance-Critical Component
struct Component {
    char name[20];
    enum Status status;
    int health;
    int power_consumption;
};

// Function to initialize a component
void initialize_component(struct Component* component, char* name, int power_consumption) {
    strcpy(component->name, name);
    component->status = WORKING;
    component->health = 100;
    component->power_consumption = power_consumption;
}

// Function to simulate the effects of a component breaking down
void break_component(struct Component* component) {
    component->status = DAMAGED;
    component->health = get_random(50, 80);
    component->power_consumption += get_random(10, 20);
}

// Function to simulate the effects of a component being destroyed
void destroy_component(struct Component* component) {
    component->status = DESTROYED;
    component->health = 0;
    component->power_consumption = 0;
}

int main() {
    // Set random seed
    srand(time(0));
    
    // Create an array of components
    struct Component components[3];
    initialize_component(&components[0], "Reactor", 50);
    initialize_component(&components[1], "Water Purifier", 20);
    initialize_component(&components[2], "Security System", 30);
    
    // Simulate a post-apocalyptic scenario
    int days_survived = 0;
    int power_generated = 0;
    int water_generated = 0;
    while(1) {
        // Check if all components are working
        int all_working = 1;
        for(int i=0; i<3; i++) {
            if(components[i].status != WORKING) {
                all_working = 0;
                break_component(&components[i]);
            }
        }
        
        // If all components are working, generate power and water
        if(all_working) {
            power_generated +=  get_random(50, 100);
            water_generated += get_random(20, 40);
        }
        
        // Decrease health and power consumption of random component
        int rand_index = get_random(0, 2);
        struct Component* rand_component = &components[rand_index];
        if(rand_component->status == WORKING) {
            rand_component->health -= get_random(5, 15);
            rand_component->power_consumption += get_random(5, 10);
            if(rand_component->health <= 0) {
                destroy_component(rand_component);
            }
            else if(rand_component->health <= 20) {
                break_component(rand_component);
            }
        }
        
        // Print status of components and resources generated
        printf("Day %d\n", days_survived);
        for(int i=0; i<3; i++) {
            struct Component* component = &components[i];
            char* status_string;
            if(component->status == WORKING) {
                status_string = "Working";
            }
            else if(component->status == DAMAGED) {
                status_string = "Damaged";
            }
            else {
                status_string = "Destroyed";
            }
            printf("%s - %s - Health: %d - Power Consumption: %d\n", component->name, status_string, component->health, component->power_consumption);
        }
        printf("Power Generated: %d\n", power_generated);
        printf("Water Generated: %d\n", water_generated);
        
        // Sleep for a day
        sleep(1);
        days_survived++;
    }
    
    return 0;
}