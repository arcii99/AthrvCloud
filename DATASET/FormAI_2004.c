//FormAI DATASET v1.0 Category: Educational ; Style: imaginative
/* Imagine we are building a program that simulates a virtual farm with various types of crops.
   Our program needs to handle multiple crop types and have functions to plant, water, and harvest the crops. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define our crop types
typedef enum CropType { Wheat, Corn, Tomato } CropType;

// Define our crop struct
typedef struct Crop {
    CropType type;
    int age;
    int waterLevel;
    int height;
} Crop;

// Define our functions for planting, watering, and harvesting crops
void plantCrop(Crop *crop, CropType type);
void waterCrop(Crop *crop);
void harvestCrop(Crop *crop);

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Create a new wheat crop
    Crop wheat;
    plantCrop(&wheat, Wheat);
    
    // Create a new corn crop
    Crop corn;
    plantCrop(&corn, Corn);
    
    // Create a new tomato crop
    Crop tomato;
    plantCrop(&tomato, Tomato);
    
    // Simulate a week of growth
    for (int i = 0; i < 7; i++) {
        // Water the crops
        waterCrop(&wheat);
        waterCrop(&corn);
        waterCrop(&tomato);
        
        // Add a random amount of growth to each crop
        wheat.age += rand() % 3;
        corn.age += rand() % 3;
        tomato.age += rand() % 3;
        wheat.height += rand() % 2;
        corn.height += rand() % 2;
        tomato.height += rand() % 2;
        
        // Simulate harvesting mature crops
        if (wheat.age >= 10) {
            harvestCrop(&wheat);
            plantCrop(&wheat, Wheat);
        }
        if (corn.age >= 10) {
            harvestCrop(&corn);
            plantCrop(&corn, Corn);
        }
        if (tomato.age >= 10) {
            harvestCrop(&tomato);
            plantCrop(&tomato, Tomato);
        }
    }
    
    // Print the final crop states
    printf("Wheat: Age %d, Water Level %d, Height %d\n", wheat.age, wheat.waterLevel, wheat.height);
    printf("Corn: Age %d, Water Level %d, Height %d\n", corn.age, corn.waterLevel, corn.height);
    printf("Tomato: Age %d, Water Level %d, Height %d\n", tomato.age, tomato.waterLevel, tomato.height);

    return 0;
}

void plantCrop(Crop *crop, CropType type) {
    // Initialize the crop values
    crop->type = type;
    crop->age = 0;
    crop->waterLevel = 0;
    crop->height = 0;
}

void waterCrop(Crop *crop) {
    // Increase the water level by one
    crop->waterLevel += 1;
}

void harvestCrop(Crop *crop) {
    // Reset the crop values
    crop->age = 0;
    crop->waterLevel = 0;
    crop->height = 0;
}