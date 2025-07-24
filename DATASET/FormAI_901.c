//FormAI DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to the happy C System event logger!\n\n");
    
    // get user's name
    char name[50];
    printf("What's your name? ");
    scanf("%s", name);
    
    // greet user
    printf("Hi, %s! Let's get started.\n", name);
    
    // ask for number of events
    int numEvents;
    printf("How many events would you like to log? ");
    scanf("%d", &numEvents);
    
    // create array of events
    char events[numEvents][50];
    
    // log events
    for (int i = 0; i < numEvents; i++) {
        printf("Event %d: ", i+1);
        scanf("%s", events[i]);
        printf("Event %d logged successfully!\n", i+1);
    }
    
    // display all events
    printf("\n\nHere are all the events you logged:\n");
    for (int i = 0; i < numEvents; i++) {
        printf("%d. %s\n", i+1, events[i]);
    }
    
    printf("Thank you for using the C System event logger. Happy logging, %s!\n", name);
    
    return 0;
}