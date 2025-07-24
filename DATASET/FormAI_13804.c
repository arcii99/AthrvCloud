//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    float invasion_probability;                     
    int aliens, countries, days_remaining;           
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of aliens in the invading army: ");
    scanf("%d", &aliens);                             
    printf("Enter the number of countries in the world: ");
    scanf("%d", &countries);                          
    printf("Enter the number of days remaining until the invasion: ");
    scanf("%d", &days_remaining);                     
    srand(time(0));                                   
    int i;
    int random_factor = rand()%10 + 1;                 
    printf("\nCalculating probability...\n");
    printf("Please wait...\n");
    for(i=0;i<random_factor;i++){                      
        printf(". ");
    }
    printf("\n\n");
    invasion_probability = (float)aliens/countries;   
    if(invasion_probability<1)                          // Low probability of invasion
    {
       invasion_probability *= 1.5;                    // Increase probability due to special circumstances
       printf("Attention all citizens: The probability of an alien invasion is low, but a higher probability is being predicted due to special circumstances.\n");
    }
    else if(invasion_probability>=1 && invasion_probability<5)      // Moderate probability of invasion
    {
       printf("Attention all citizens: The probability of an alien invasion is moderate. All countries are advised to take necessary precautions to protect themselves.\n");
    }
    else if(invasion_probability>=5 && invasion_probability<=10)    // High probability of invasion
    {
       invasion_probability *= 1.75;                   // Increase probability due to high probability
       printf("Attention all citizens: The probability of an alien invasion is high. All countries are advised to take immediate action to protect themselves.\n");
    }
    else                                                       // Imminent threat of invasion
    {
       invasion_probability *= 2;                      // Increase probability due to imminent threat
       printf("Attention all citizens: An alien invasion is imminent! All countries are advised to take immediate action to protect themselves.\n");
    }
    printf("The probability of an alien invasion is %.2f%%\n", invasion_probability);
    printf("Remember, in the event of an alien invasion, always listen to your government officials and follow their instructions.\n");
    return 0;
}