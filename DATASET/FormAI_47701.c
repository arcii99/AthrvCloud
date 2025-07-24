//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void timeTravel(int year){
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    time_t raw_time = mktime(&timeinfo);
    printf("You have traveled back to %s", asctime(localtime(&raw_time)));
}

int main(){
    srand(time(NULL));
    
    int current_year = 2021;
    int random_year = rand() % current_year;
    
    printf("Welcome to the Time Travel Simulator\n");
    printf("You will be randomly sent back to a year between 1900 and %d\n", current_year);
    
    timeTravel(random_year);
    
    printf("Congratulations, you have completed your time travel adventure!\n");
    
    return 0;
}