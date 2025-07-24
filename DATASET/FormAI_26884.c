//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h> 

int main()
{
    //initialize variables
    int num_aliens, num_years, prob_percent;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of aliens that have currently been discovered: ");
    scanf("%d", &num_aliens);
    
    printf("Please enter the number of years that have passed since the first discovery: ");
    scanf("%d", &num_years);
    
    //calculate probability based on number of aliens and years
    prob_percent = (num_aliens * 10) / num_years;
    
    printf("Based on our calculations, there is a %d percent chance of an imminent alien invasion!\n", prob_percent);
    
    //modular function to display a message based on probability
    void messageDisplay(int probability)
    {
        if(probability < 30){
            printf("The probability is low. We may have nothing to worry about.");
        }
        else if(probability >= 30 && probability <= 60){
            printf("The probability is moderate. We should be cautious and prepare for the worst.");
        }
        else{
            printf("The probability is high. We must take immediate action to protect ourselves!");
        }
    }
    
    messageDisplay(prob_percent);
    
    return 0;
}