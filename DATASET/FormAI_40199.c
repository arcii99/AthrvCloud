//FormAI DATASET v1.0 Category: System event logger ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Define the event structure */
typedef struct Event {
    int day;
    int month;
    int year;
    char time[10];
    char description[100];
} Event;

int main() {
    /* Seed the random number generator */
    srand(time(NULL));
    
    /* Create an array of events */
    Event events[10];
    
    /* Populate the array with surreal events */
    events[0].day = rand() % 31 + 1;
    events[0].month = rand() % 12 + 1;
    events[0].year = rand() % 100 + 1920;
    strcpy(events[0].time, "12:34PM");
    strcpy(events[0].description, "The sky turned orange and rained peanut butter sandwiches.");
    
    events[1].day = rand() % 31 + 1;
    events[1].month = rand() % 12 + 1;
    events[1].year = rand() % 100 + 1920;
    strcpy(events[1].time, "08:15AM");
    strcpy(events[1].description, "The trees danced a polka and sang opera.");
    
    events[2].day = rand() % 31 + 1;
    events[2].month = rand() % 12 + 1;
    events[2].year = rand() % 100 + 1920;
    strcpy(events[2].time, "01:23AM");
    strcpy(events[2].description, "The moon turned into a giant disco ball and everyone danced on it.");
    
    events[3].day = rand() % 31 + 1;
    events[3].month = rand() % 12 + 1;
    events[3].year = rand() % 100 + 1920;
    strcpy(events[3].time, "11:11PM");
    strcpy(events[3].description, "All the books in the library grew legs and ran out the door.");
    
    events[4].day = rand() % 31 + 1;
    events[4].month = rand() % 12 + 1;
    events[4].year = rand() % 100 + 1920;
    strcpy(events[4].time, "03:33PM");
    strcpy(events[4].description, "The sun turned into a giant ball of rainbow cotton candy.");
    
    events[5].day = rand() % 31 + 1;
    events[5].month = rand() % 12 + 1;
    events[5].year = rand() % 100 + 1920;
    strcpy(events[5].time, "05:55AM");
    strcpy(events[5].description, "Everyone's shoes turned into turtles and ran away.");
    
    events[6].day = rand() % 31 + 1;
    events[6].month = rand() % 12 + 1;
    events[6].year = rand() % 100 + 1920;
    strcpy(events[6].time, "09:09PM");
    strcpy(events[6].description, "The ocean turned into a giant bowl of soup and everyone went swimming in it.");
    
    events[7].day = rand() % 31 + 1;
    events[7].month = rand() % 12 + 1;
    events[7].year = rand() % 100 + 1920;
    strcpy(events[7].time, "02:22AM");
    strcpy(events[7].description, "All the buildings in town turned into giant mushrooms and everyone lived inside them.");
    
    events[8].day = rand() % 31 + 1;
    events[8].month = rand() % 12 + 1;
    events[8].year = rand() % 100 + 1920;
    strcpy(events[8].time, "06:06PM");
    strcpy(events[8].description, "The clouds turned into giant marshmallows and everyone ate them with chocolate sauce.");
    
    events[9].day = rand() % 31 + 1;
    events[9].month = rand() % 12 + 1;
    events[9].year = rand() % 100 + 1920;
    strcpy(events[9].time, "04:44AM");
    strcpy(events[9].description, "The wind turned into a giant accordion and played music all night.");

    /* Write the events to a file */
    FILE *fp;
    fp = fopen("events.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    for(int i = 0; i < 10; i++) {
        fprintf(fp, "Event %d\n", i+1);
        fprintf(fp, "Date: %d/%d/%d\n", events[i].day, events[i].month, events[i].year);
        fprintf(fp, "Time: %s\n", events[i].time);
        fprintf(fp, "Description: %s\n\n", events[i].description);
    }
    
    fclose(fp);
    
    printf("Events logged successfully!\n");
    
    return 0;
}