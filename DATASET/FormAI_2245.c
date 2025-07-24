//FormAI DATASET v1.0 Category: Unit converter ; Style: surrealist
#include <stdio.h>

// Function to greet the user
void greet() {
    printf("Welcome to the Surrealist Unit Converter!\n");
    printf("We'll be converting your wildest dreams into reality...\n\n");
}

// Function to convert feet to hands
double feet_to_hands(double feet) {
    double hands = feet * 3.1415;
    return hands;
}

// Function to convert inches to gnomes
int inches_to_gnomes(int inches) {
    int gnomes = inches * 42;
    return gnomes;
}

// Function to convert furlongs to fantasies
long long furlongs_to_fantasies(long long furlongs) {
    long long fantasies = furlongs * 666;
    return fantasies;
}

// Main function
int main() {
    greet();
    
    // Convert feet to hands
    double feet = 5;
    double hands = feet_to_hands(feet);
    printf("%.2f feet is equal to %.2f hands.\n", feet, hands);
    
    // Convert inches to gnomes
    int inches = 12;
    int gnomes = inches_to_gnomes(inches);
    printf("%d inches is equal to %d gnomes.\n", inches, gnomes);
    
    // Convert furlongs to fantasies
    long long furlongs = 3;
    long long fantasies = furlongs_to_fantasies(furlongs);
    printf("%lld furlongs is equal to %lld fantasies.\n", furlongs, fantasies);
    
    printf("\nThank you for using the Surrealist Unit Converter!\n");
    printf("Remember to always keep your imagination and dreams alive...\n");
    
    return 0;
}