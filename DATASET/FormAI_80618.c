//FormAI DATASET v1.0 Category: System event logger ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int eventCodes[] = {100, 200, 300, 400, 500, 600, 700};
    char eventDescs[][50] = {"System Bootup", 
                             "System Shutdown",
                             "Critical Error Occured",
                             "Software Update Installed",
                             "Hardware Failure Detected",
                             "User Login Attempt",
                             "User Logout"};
    int numEvents = sizeof(eventCodes)/sizeof(eventCodes[0]);
    srand(time(NULL));     
    
    printf("Welcome to the C System Event Logger!\n");
    printf("------------------------------------\n\n");
    
    while(1) {
        int randomIndex = rand() % numEvents;
        int code = eventCodes[randomIndex];
        char desc[50];
        strcpy(desc, eventDescs[randomIndex]);
        printf("Event Code: %d\n", code);
        printf("Event Description: %s\n", desc);
        printf("Timestamp: %ld\n", time(NULL));
        printf("------------------------------------\n");
        
        printf("Do you want to log another event? (y/n)");
        char choice;
        scanf("%c", &choice);
        
        if(choice == 'n' || choice == 'N')
            break;
    }
    
    printf("Thanks for using the C System Event Logger!\n\n");
    return 0;
}