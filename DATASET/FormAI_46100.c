//FormAI DATASET v1.0 Category: Computer Biology ; Style: happy
#include <stdio.h>

int main(){

    printf("Welcome to the Happy Bio Project!\n\n");
    
    // Defining an organism structure
    struct organism {
        char* name;
        int age;
        char* classification;
        float weight;
    } happy_organism;
    
    // Assigning values to the organism variables
    happy_organism.name = "HappyBee";
    happy_organism.age = 1;
    happy_organism.classification = "Insect";
    happy_organism.weight = 0.1;
    
    // Printing the organism's name, age, classification, and weight
    printf("Name: %s\n", happy_organism.name);
    printf("Age: %d\n", happy_organism.age);
    printf("Classification: %s\n", happy_organism.classification);
    printf("Weight: %.2f\n\n", happy_organism.weight);
    
    // Creating a simple function to calculate the organism's lifespan
    int calculate_lifespan(int organism_age){
        int lifespan = 0;
        
        if (organism_age < 5){
            lifespan = 10;
        }
        else if (organism_age >= 5 && organism_age < 10){
            lifespan = 5;
        }
        else {
            lifespan = 1;
        }
        
        return lifespan;
    }
    
    // Calculating the organism's lifespan and printing the result
    printf("Lifespan (in years): %d\n\n", calculate_lifespan(happy_organism.age));
    
    // Creating an array of favorite foods for the organism
    char favorite_foods[3][20] = {"Honey", "Nectar", "Pollen"};
    
    // Printing the organism's favorite foods
    printf("Favorite Foods:\n");
    for (int i = 0; i < 3; i++){
        printf("- %s\n", favorite_foods[i]);
    }
    
    printf("\nHappyBee: Buzz buzz! I'm so happy with my sweet and delicious favorite foods!\n");
    
    return 0;
}