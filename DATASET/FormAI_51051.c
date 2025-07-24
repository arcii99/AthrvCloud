//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure that holds information about a car 
typedef struct {
    int id;
    int year;
    char make[25];
    char model[25];
    double price;
} Car;

// Generate a random number in the range [min, max]
int randomInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Print the information of a car
void printCar(Car car) {
    printf("%d %d %s %s $%.2f\n", car.id, car.year, car.make, car.model, car.price);
}

// Sort an array of cars in increasing order of their year of production
void sortCarsByYear(Car cars[], int numCars) {
    // Insertion sort algorithm
    int i, j;
    Car temp;
    for (i = 1; i < numCars; i++) {
        temp = cars[i];
        j = i - 1;
        while (j >= 0 && cars[j].year > temp.year) {
            cars[j + 1] = cars[j];
            j = j - 1;
        }
        cars[j + 1] = temp;
    }
}

int main() {
    srand(time(NULL)); // Initialize the random number generator

    int numCars = 10; // Number of cars in the array
    Car cars[numCars]; // Declare the array of cars

    // Generate random information for each of the cars
    int i;
    for (i = 0; i < numCars; i++) {
        cars[i].id = i+1;
        cars[i].year = randomInRange(2000, 2020);
        sprintf(cars[i].make, "Make%d", randomInRange(1,5));
        sprintf(cars[i].model, "Model%d", randomInRange(1,5));
        cars[i].price = randomInRange(20000, 50000) + (double)randomInRange(0, 99) / 100;
    }

    // Print the unsorted array of cars
    printf("Unsorted:\n");
    for (i = 0; i < numCars; i++) {
        printCar(cars[i]);
    }

    // Sort the array of cars by year
    sortCarsByYear(cars, numCars);

    // Print the sorted array of cars
    printf("Sorted:\n");
    for (i = 0; i < numCars; i++) {
        printCar(cars[i]);
    }

    return 0;
}