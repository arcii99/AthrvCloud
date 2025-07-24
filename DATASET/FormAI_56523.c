//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

//Function to generate random number between min and max
int rand_between(int min,int max)
{
    return (rand()%(max-min+1))+min;
}

int main()
{
    printf("Welcome to Crazy Traffic Flow Simulator!\n");
    printf("Buckle up and hold on tight, because we're about to enter the world of unpredictable traffic!\n");

    //Initializing values for simulation
    int cars = rand_between(10,50);
    int time = rand_between(1,5);

    printf("Today's traffic report shows there are %d cars on the road and it is currently %d o'clock.\n", cars, time);

    //Starting the simulation
    for(int i=1;i<=time;i++)
    {
        printf("-----------Hour %d of Simulation-----------\n", i);

        //Creating random events for the hour
        int accident = rand_between(0,9);
        int construction = rand_between(0,7);
        int rush_hour = rand_between(0,5);

        //Accident event
        if(accident>7){
            printf("Oh no! There's been an accident ahead! Cars are backed up for miles!\n");
            cars = cars - rand_between(5,15);
        }

        //Construction event
        if(construction>5){
            printf("Looks like there's construction up ahead! Expect some delays.\n");
            cars = cars - rand_between(3,8);
        }

        //Rush hour event
        if(rush_hour>3){
            printf("It's rush hour! Everyone's trying to get home at once!\n");
            cars = cars - rand_between(10,20);
        }

        //Displaying updated traffic report
        printf("There are currently %d cars on the road.\n", cars);

        //Ending the simulation if there are no more cars on the road
        if(cars<=0){
            printf("Wow, that was quick! All the cars have miraculously disappeared!\nEnding Simulation...\n");
            break;
        }

        //Letting the user know how many cars are left on the road
        printf("There are %d cars left on the road.\n", cars);

        //Adding a delay between simulation hours
        printf("Now waiting for one hour...\n\n");
        sleep(1);
    }

    printf("Simulation Complete! Thanks for joining us on this wild ride through crazy traffic flow!\n");

    return 0;
}