//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
int main() 
{ 
  
    float alien_prob, human_books_prob, human_weapons_prob, human_scientists_prob; 
    int outcome; 
  
    printf("Welcome to the Alien Invasion Probability Calculator! \n"); 
    printf("We will calculate the probability of an alien invasion based on human factors. \n"); 

    printf("\nEnter the probability of aliens existing in the universe from 0.0 to 1.0: "); 
    scanf("%f", &alien_prob); 

    if (alien_prob < 0.0 || alien_prob > 1.0) { 
        printf("Invalid probability input! Please enter a value between 0.0 to 1.0.\n"); 
        return 1; 
    } 

    printf("\nEnter the percentage of human population that reads books on astronomy, cosmology, and astrophysics: "); 
    scanf("%f", &human_books_prob); 

    printf("\nEnter the percentage of human population that possesses lethal weapons: "); 
    scanf("%f", &human_weapons_prob); 

    printf("\nEnter the percentage of human population that work in scientific fields related to space: "); 
    scanf("%f", &human_scientists_prob); 

    srand(time(NULL)); //initialize random seed

    outcome = rand() % 100; //generate random number between 0 and 99

    /* Probability calculation */
    float total_prob = human_books_prob/100 * human_weapons_prob/100 * human_scientists_prob/100;
    float invasion_prob = alien_prob * total_prob;

    /* Output the probability of an alien invasion */
    if (outcome < invasion_prob * 100) { 
        printf("\n\nALERT! Alien invasion is imminent!\n"); 
    } 
    else { 
        printf("\n\nNo immediate alien invasion detected.\n"); 
    } 

    return 0; 
}