//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: irregular
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Please enter the year you wish to travel to:\n");

    int year;
    scanf("%d", &year);

    int time_travel_years = year - t/31556952;

    if(time_travel_years > 0) {
        printf("Preparing to travel %d years into the future...\n", time_travel_years);
        while(time_travel_years > 0) {
            printf("%d...\n", time_travel_years);
            sleep(1);
            time_travel_years--;
        }
        
        printf("You have arrived in the year %d!\n", year);
    } else if(time_travel_years < 0) {
        printf("Preparing to travel %d years into the past...\n", -time_travel_years);
        while(time_travel_years < 0) {
            printf("%d...\n", -time_travel_years);
            sleep(1);
            time_travel_years++;
        }

        printf("You have arrived in the year %d!\n", year);
    } else {
        printf("You are already in the year %d!\n", year);
    }

    return 0;
}