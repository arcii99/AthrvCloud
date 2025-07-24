//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
    printf("Welcome to the Time Travel Simulator! \n");
  
    //get user input for year to travel to
    int year;
    printf("Enter a year to travel to: ");
    scanf("%d", &year);
    
    //get current year
    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    int current_year = current_time->tm_year + 1900;
    
    //calculate difference in years
    int years_travelled = abs(year - current_year);
    
    //print out travel details
    printf("\nYou are travelling from the year %d to the year %d\n", current_year, year);
    printf("You will be travelling through time for %d years.\n\n", years_travelled);
    
    //simulate time travel
    for(int i = 0; i < years_travelled; i++) {
    
        if(year > current_year) {
            printf("Travelling forward in time... \n");
            current_year++;
        }
        else if(year < current_year) {
            printf("Travelling back in time... \n");
            current_year--;
        }
        
        //wait for 1 second to simulate time travel
        sleep(1);
    }
    
    //print message upon arrival
    printf("\n\nYou have arrived in the year %d. Enjoy your time travelling experience!\n", year);

  return 0;
}