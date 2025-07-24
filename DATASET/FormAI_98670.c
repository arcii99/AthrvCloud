//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num_of_cases, num_of_aliens;
    printf("Enter the number of test cases: ");
    scanf("%d",&num_of_cases);
    srand(time(0)); //to generate a new set of random numbers every time program is executed
    for(int i=0; i<num_of_cases; i++)
    {
        printf("\nTest case %d:\n",i+1);
        printf("Enter the number of aliens invading: ");
        scanf("%d",&num_of_aliens);
        float base_probability = (float)num_of_aliens/1000; //the base probability of an alien invasion occurring
        float rand_num = ((float) rand() / (RAND_MAX)); //the random number generated between 0 and 1
        float final_probability = base_probability * rand_num; //the final probability of an alien invasion occurring
        printf("\nThe probability of an alien invasion occurring is %f\n",final_probability);
    }

    return 0;
}