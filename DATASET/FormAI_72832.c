//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PLANETS 10

struct Planet {
    char name[20];
    bool visited;
    int resources;
};

struct Spaceship {
    char name[20];
    int fuel;
    struct Planet current_location;
};

void generate_planets(struct Planet planets[]) {
    char planet_names[MAX_PLANETS][20] = {"Aerilon", "Aquaria", "Canceron", "Caprica", 
                                          "Gemenon", "Libran", "Picon", "Sagittaron", "Scorpia", "Tauron"};
    for(int i = 0; i < MAX_PLANETS; i++) {
        strcpy(planets[i].name, planet_names[i]);
        planets[i].visited = false;
        planets[i].resources = rand() % 1000 + 1;
    }
}

int get_available_planets(struct Planet planets[]) {
    int count = 0;
    for(int i = 0; i < MAX_PLANETS; i++) {
        if(!planets[i].visited) {
            count++;
        }
    }
    return count;
}

bool check_planet_visited(struct Planet planet) {
    return planet.visited;
}

void visit_planet(struct Planet *planet, struct Spaceship *spaceship) {
    planet->visited = true;
    spaceship->current_location = *planet;
    spaceship->fuel -= rand() % 100 + 10;
    spaceship->current_location.resources -= rand() % 50 + 10;
    printf("Visited planet %s. Current fuel: %d and resources: %d\n", planet->name, spaceship->fuel, spaceship->current_location.resources);
}

void fly_to_planet(struct Spaceship *spaceship, struct Planet planets[]) {
    int available_planets = get_available_planets(planets);
    if(available_planets == 0) {
        printf("All planets visited. Game over!\n");
        exit(0);
    }
    int planet_choice;
    do {
        planet_choice = rand() % MAX_PLANETS;
    } while(check_planet_visited(planets[planet_choice]));
    visit_planet(&planets[planet_choice], spaceship);
}

int main() {
    srand(time(NULL));
    struct Planet planets[MAX_PLANETS];
    generate_planets(planets);
    struct Spaceship spaceship;
    printf("Enter spaceship name: ");
    scanf("%s", spaceship.name);
    spaceship.fuel = rand() % 1000 + 500;
    spaceship.current_location = planets[rand() % MAX_PLANETS];
    printf("Welcome aboard the spaceship %s. Starting fuel: %d\n", spaceship.name, spaceship.fuel);
    while(true) {
        printf("Available options:\n");
        printf("1. Visit planet\n");
        printf("2. Fly to new planet\n");
        printf("3. Quit game\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                visit_planet(&spaceship.current_location, &spaceship);
                break;
            case 2:
                fly_to_planet(&spaceship, planets);
                break;
            case 3:
                printf("Quitting game...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}