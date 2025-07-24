//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants
#define MAP_SIZE 100
#define MAX_STEPS 50
#define RADIO_RANGE 5
#define WATER_POINTS 3
#define FOOD_POINTS 2
#define MEDICAL_POINTS 1

// define struct for location
typedef struct {
    int x;
    int y;
} Location;

// define struct for item
typedef struct {
    char name[20];
    int point;
} Item;

// initialize items
Item water = {"water", WATER_POINTS};
Item food = {"food", FOOD_POINTS};
Item medical = {"medical kit", MEDICAL_POINTS};
Item noItem = {"", 0};

// define struct for map
typedef struct {
    Item item;
    char terrain;
} MapCell;

// declare functions
void initializeMap(MapCell map[][MAP_SIZE]);
Location generateRandomLocation();
void printMap(MapCell map[][MAP_SIZE], Location current, int stepsLeft);
Item searchItem(MapCell map[][MAP_SIZE], Location current, int radius);
void updateMap(MapCell map[][MAP_SIZE], Location current, Item item);

int main() {
    // declare variables
    MapCell map[MAP_SIZE][MAP_SIZE];
    Location currentLocation, destination;
    int stepsLeft = MAX_STEPS;
    srand(time(NULL));
    
    // initialize map and current location
    initializeMap(map);
    currentLocation = generateRandomLocation();
    
    // present welcome message
    printf("Welcome to the post-apocalyptic GPS navigation simulation!\n");
    printf("Your goal is to find the safe haven within %d steps.\n", MAX_STEPS);
    printf("You are currently at location (%d, %d).\n", currentLocation.x, currentLocation.y);
    
    // loop until destination is found or steps run out
    while (1) {
        // present map and steps left
        printMap(map, currentLocation, stepsLeft);
        
        // prompt user to input direction
        printf("Which direction do you want to go (up/down/left/right)? ");
        char direction[10];
        scanf("%s", direction);
        
        // calculate new location based on direction input
        Location newLocation;
        if (strcmp(direction, "up") == 0) {
            newLocation.x = currentLocation.x - 1;
            newLocation.y = currentLocation.y;
        } else if (strcmp(direction, "down") == 0) {
            newLocation.x = currentLocation.x + 1;
            newLocation.y = currentLocation.y;
        } else if (strcmp(direction, "left") == 0) {
            newLocation.x = currentLocation.x;
            newLocation.y = currentLocation.y - 1;
        } else if (strcmp(direction, "right") == 0) {
            newLocation.x = currentLocation.x;
            newLocation.y = currentLocation.y + 1;
        } else {
            printf("Invalid direction. Please try again.\n\n");
            continue;
        }
        
        // check if new location is within map boundary
        if (newLocation.x < 0 || newLocation.x >= MAP_SIZE || newLocation.y < 0 || newLocation.y >= MAP_SIZE) {
            printf("You reached the edge of the world. Please try another direction.\n\n");
            continue;
        }
        
        // calculate distance between new location and destination
        int distance = abs(newLocation.x - MAP_SIZE / 2) + abs(newLocation.y - MAP_SIZE / 2);
        
        // update steps left
        stepsLeft--;
        
        // check if steps run out
        if (stepsLeft == 0) {
            printf("You ran out of steps. Game over.\n");
            return 0;
        }
        
        // check if new location is the destination
        if (distance == 0) {
            printf("Congratulations! You found the safe haven in %d steps.\n", MAX_STEPS - stepsLeft);
            return 0;
        }
        
        // check if new location is within radio range
        int radioDistance = abs(newLocation.x - MAP_SIZE / 2) + abs(newLocation.y - MAP_SIZE / 2);
        if (radioDistance <= RADIO_RANGE) {
            printf("Radio signal detected from the safe haven. Distance: %d.\n", radioDistance);
        }
        
        // search for item
        Item foundItem = searchItem(map, newLocation, RADIO_RANGE);
        if (strcmp(foundItem.name, "") != 0) {
            printf("You found a %s. You gained %d points.\n", foundItem.name, foundItem.point);
            updateMap(map, newLocation, noItem);
        }
        
        // update current location
        currentLocation = newLocation;
    }
}

// function to initialize map
void initializeMap(MapCell map[][MAP_SIZE]) {
    // loop through each cell in the map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            // generate random terrain (0:land, 1:water)
            int terrain = rand() % 2;
            
            // assign item to cell randomly (0:no item, 1:water, 2:food, 3:medical kit)
            int item = rand() % 4;
            if (item == 1) {
                map[i][j].item = water;
            } else if (item == 2) {
                map[i][j].item = food;
            } else if (item == 3) {
                map[i][j].item = medical;
            } else {
                map[i][j].item = noItem;
            }
            
            // assign terrain to cell
            if (terrain == 0) {
                map[i][j].terrain = '.';
            } else {
                map[i][j].terrain = '~';
            }
        }
    }
}

// function to generate random location
Location generateRandomLocation() {
    Location location;
    location.x = rand() % MAP_SIZE;
    location.y = rand() % MAP_SIZE;
    return location;
}

// function to print map
void printMap(MapCell map[][MAP_SIZE], Location current, int stepsLeft) {
    printf("\n");
    // loop through each cell in the map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            // check if current location and print symbol accordingly
            if (i == current.x && j == current.y) {
                printf("+");
            } else {
                printf("%c", map[i][j].terrain);
            }
        }
        printf("\n");
    }
    // print steps left
    printf("Steps left: %d\n\n", stepsLeft);
}

// function to search item within radio range
Item searchItem(MapCell map[][MAP_SIZE], Location current, int radius) {
    // loop through each cell in the map within radio range
    for (int i = current.x - radius; i <= current.x + radius; i++) {
        for (int j = current.y - radius; j <= current.y + radius; j++) {
            // check if cell is within map boundary and contains item
            if (i >= 0 && i < MAP_SIZE && j >= 0 && j < MAP_SIZE && (
                strcmp(map[i][j].item.name, water.name) == 0 ||
                strcmp(map[i][j].item.name, food.name) == 0 ||
                strcmp(map[i][j].item.name, medical.name) == 0
                )) {
                // return item found and exit function
                return map[i][j].item;
            }
        }
    }
    // return no item found
    return noItem;
}

// function to update map with found item
void updateMap(MapCell map[][MAP_SIZE], Location current, Item item) {
    map[current.x][current.y].item = item;
}