//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: calm
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int alien_ships; 
    int year; 
    float probability; 
  
    srand(time(0)); 
  
    printf("Welcome to the Alien Invasion Probability Calculator\n\n"); 
    
    printf("Enter the current year (yyyy): "); 
    scanf("%d", &year); 
  
    printf("\n"); 
  
    alien_ships = rand() % 1001; 
  
    if (year < 2022) 
        probability = alien_ships / (float)1000; 
    else if (year >= 2022 && year < 2032) 
        probability = alien_ships / (float)500; 
    else if (year >= 2032 && year < 2042) 
        probability = alien_ships / (float)250; 
    else if (year >= 2042 && year < 2052) 
        probability = alien_ships / (float)100; 
    else if (year >= 2052 && year < 2062) 
        probability = alien_ships / (float)50; 
    else 
        probability = alien_ships / (float)25; 
  
    printf("Alien ships detected in Earth's atmosphere: %d\n", alien_ships); 
    printf("The probability of an alien invasion in the year %d is: %.2f %%\n\n", year, probability * 100); 
    
    printf("Thanks for using the Alien Invasion Probability Calculator!\n"); 

    return 0; 
}