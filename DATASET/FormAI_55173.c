//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number  
int generateRandomNumber(int n)
{
    srand(time(NULL));  
    return rand() % n;  
}

// function to calculate the probability of invasion  
float calculateInvasionProbability(int n, int alienPower[], int humanPower[])
{
    int alienTotalPower = 0;
    int humanTotalPower = 0;
    
    for(int i=0; i<n; i++){
        alienTotalPower += alienPower[i];  
        humanTotalPower += humanPower[i];  
    }
    
    float probability = (float)alienTotalPower/humanTotalPower;
    
    return probability;
}

int main()
{
    int n = 5; // number of forces
    
    // alien and human power arrays
    int alienPower[] = {50, 40, 30, 20, 10};  
    int humanPower[] = {60, 40, 30, 20, 10};  
    
    float probability = calculateInvasionProbability(n, alienPower, humanPower);
    
    printf("The probability of alien invasion is: %f\n", probability);  
    
    if(probability >= 1){
        printf("Alien invasion is highly probable!");  
    }
    else if(probability > 0 && probability < 1){
        printf("Alien invasion is possible but not highly probable!");  
    }
    else{
        printf("Alien invasion is not likely!");  
    }
    
    return 0;  
}