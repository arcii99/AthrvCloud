//FormAI DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("\n\n\t\tWelcome to the Weather Simulation Program!\n");

    int i,j,temp,humidity;
    srand(time(0));
    // srand is used to generate random numbers based on the current time

    for(i=1;i<=7;i++){
    // the simulation runs for 7 days
        printf("\n\nDay %d: \n",i);

        temp = (rand()%30) + 1;
        // generates a randome temperature between 1 and 30 degrees Celsius
        printf("Temperature: %d C\n",temp);

        humidity = (rand()%100) + 1;
        // generates a random humidity between 1 and 100 percent
        printf("Humidity: %d%%\n",humidity);

        if(temp>25 && humidity>80){
            printf("It's a hot and humid day today!\n");
        }
        else if(temp<15 && humidity<50){
            printf("It's a cool and dry day today!\n");
        }
        else if(temp>15 && temp<25 && humidity>50 && humidity<80){
            printf("It's a pleasant day today!\n");
        }
        else{
            printf("The weather today is normal!\n");
        }

    }

    printf("\n\n\t\tThank you for using the Weather Simulation Program!");

    return 0;
}