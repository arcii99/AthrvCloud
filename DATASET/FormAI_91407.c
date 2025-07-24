//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LIFESPAN 60 // maximum lifespan of a human in years
#define MIN_LIFESPAN 20 // minimum lifespan of a human in years
#define MAX_HEALTH 100 // maximum health of a human
#define MIN_HEALTH 0 // minimum health of a human
#define MAX_STAMINA 100 // maximum stamina of a human
#define MIN_STAMINA 0 // minimum stamina of a human
#define MAX_SPEED 10 // maximum speed of a human
#define MIN_SPEED 0 // minimum speed of a human
#define MAX_STRENGTH 10 // maximum strength of a human
#define MIN_STRENGTH 0 // minimum strength of a human
#define MAX_AGILITY 10 // maximum agility of a human
#define MIN_AGILITY 0 // minimum agility of a human
#define MAX_INTELLIGENCE 10 // maximum intelligence of a human
#define MIN_INTELLIGENCE 0 // minimum intelligence of a human
#define MAX_LUCK 10 // maximum luck of a human
#define MIN_LUCK 0 // minimum luck of a human

typedef struct {
    int lifespan;
    int health;
    int stamina;
    int speed;
    int strength;
    int agility;
    int intelligence;
    int luck;
} fitness_tracker;

void generate_stats(fitness_tracker* tracker);
void print_stats(fitness_tracker* tracker);
void update_stats(fitness_tracker* tracker, int steps_walked, int calories_burned, int hours_slept, int hours_exercised);

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // create fitness tracker object
    fitness_tracker tracker;
    
    // generate initial stats
    generate_stats(&tracker);
    
    // print initial stats
    print_stats(&tracker);
    
    // simulation loop
    int days = 0;
    while (tracker.health > MIN_HEALTH && days < MAX_LIFESPAN*365) {
        // simulate a day in the wasteland
        
        // simulate walking
        int steps_walked = rand() % 10000;
        int calories_burned = steps_walked / 20;
        // simulate sleeping
        int hours_slept = rand() % 8 + 4;
        // simulate exercising
        int hours_exercised = rand() % 3;
        
        // update stats based on simulation
        update_stats(&tracker, steps_walked, calories_burned, hours_slept, hours_exercised);
        
        // print updated stats
        printf("After day %d:\n", days);
        print_stats(&tracker);
        
        // wait for user input before continuing to next day
        printf("Press enter to continue...");
        getchar();
        
        // increment day counter
        days++;
    }
    
    // print final stats
    printf("Final stats:\n");
    print_stats(&tracker);
    
    // print cause of death
    if (tracker.health <= MIN_HEALTH) {
        printf("You died of natural causes. You lived %d years and %d days.\n", tracker.lifespan, days);
    } else {
        printf("You died in the wasteland. You lived %d years and %d days.\n", tracker.lifespan, days);
    }

    return 0;
}

void generate_stats(fitness_tracker* tracker) {
    tracker->lifespan = rand() % (MAX_LIFESPAN - MIN_LIFESPAN + 1) + MIN_LIFESPAN;
    tracker->health = MAX_HEALTH;
    tracker->stamina = MAX_STAMINA;
    tracker->speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
    tracker->strength = rand() % (MAX_STRENGTH - MIN_STRENGTH + 1) + MIN_STRENGTH;
    tracker->agility = rand() % (MAX_AGILITY - MIN_AGILITY + 1) + MIN_AGILITY;
    tracker->intelligence = rand() % (MAX_INTELLIGENCE - MIN_INTELLIGENCE + 1) + MIN_INTELLIGENCE;
    tracker->luck = rand() % (MAX_LUCK - MIN_LUCK + 1) + MIN_LUCK;
}

void print_stats(fitness_tracker* tracker) {
    printf("Lifespan: %d\n", tracker->lifespan);
    printf("Health: %d\n", tracker->health);
    printf("Stamina: %d\n", tracker->stamina);
    printf("Speed: %d\n", tracker->speed);
    printf("Strength: %d\n", tracker->strength);
    printf("Agility: %d\n", tracker->agility);
    printf("Intelligence: %d\n", tracker->intelligence);
    printf("Luck: %d\n", tracker->luck);
}

void update_stats(fitness_tracker* tracker, int steps_walked, int calories_burned, int hours_slept, int hours_exercised) {
    // update stamina
    tracker->stamina -= steps_walked / 100;
    if (tracker->stamina < MIN_STAMINA) {
        tracker->stamina = MIN_STAMINA;
    }
    
    // update health
    tracker->health -= calories_burned / 10;
    if (tracker->health < MIN_HEALTH) {
        tracker->health = MIN_HEALTH;
    }
    
    // update speed
    tracker->speed += hours_exercised / 2;
    if (tracker->speed > MAX_SPEED) {
        tracker->speed = MAX_SPEED;
    }
    
    // update strength
    tracker->strength += hours_exercised / 3;
    if (tracker->strength > MAX_STRENGTH) {
        tracker->strength = MAX_STRENGTH;
    }
    
    // update agility
    tracker->agility += hours_exercised / 4;
    if (tracker->agility > MAX_AGILITY) {
        tracker->agility = MAX_AGILITY;
    }
    
    // update intelligence
    tracker->intelligence += rand() % (hours_slept / 2 + 1);
    if (tracker->intelligence > MAX_INTELLIGENCE) {
        tracker->intelligence = MAX_INTELLIGENCE;
    }
    
    // update luck
    tracker->luck += rand() % 2;
    if (tracker->luck > MAX_LUCK) {
        tracker->luck = MAX_LUCK;
    }
    
    // update lifespan
    tracker->lifespan--;
}