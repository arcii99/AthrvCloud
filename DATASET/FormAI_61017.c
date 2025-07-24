//FormAI DATASET v1.0 Category: Smart home light control ; Style: romantic
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    int on, off, time_on, time_off, ch;
    printf("Welcome to our Smart Home, Love!\n");
    printf("Let's set the ambiance tonight.\n");
    while(1){
        printf("Which light would you like to control?(1-5): ");
        scanf("%d", &ch);
        printf("For how many hours would you like the light to be turned on? : ");
        scanf("%d", &time_on);
        printf("How many hours would you like the light to be turned off? : ");
        scanf("%d", &time_off);
        on = time_on * 60 * 60;
        off = time_off * 60 * 60;
        time_t now;
        time(&now);
        char *start_time = ctime(&now);
        printf("Turning on light %d for %d hours starting at %s.\n", ch, time_on, start_time);
        sleep(on);
        time_t off_time;
        time(&off_time);
        char *stop_time = ctime(&off_time);
        printf("Turning off light %d for %d hours at %s.\n", ch, time_off, stop_time);
        sleep(off);
    }
    return 0;
}