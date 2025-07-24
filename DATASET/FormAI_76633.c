//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure for logged events */
struct EventLog {
    int eventID;
    char eventDesc[100];
};

/* Define structure for User */
struct User {
    char username[25];
    char password[25];
    struct EventLog log[100];
    int logCount;
};

/* Function to check for unauthorised access attempts */
void checkUserAccess(struct User user, char* attemptedPass) {
    if (strcmp(user.password, attemptedPass) == 0) {
        printf("Access granted for user: %s\n", user.username);
    } else {
        printf("Access denied for user: %s\n", user.username);
        /* Log unauthorised access attempt */
        user.log[user.logCount].eventID = 1;
        strcpy(user.log[user.logCount].eventDesc, "Unauthorised access attempt");
        user.logCount++;
    }
}

/* Function to display all logged events for a user */
void displayEventLog(struct User user) {
    printf("Event Log for User: %s\n", user.username);
    for (int i = 0; i < user.logCount; i++) {
        printf("%d\t%s\n", user.log[i].eventID, user.log[i].eventDesc);
    }
}

int main(void) {
    /* Define users */
    struct User user1 = {"John", "password1"};
    struct User user2 = {"Sarah", "password2"};
    
    /* Attempt to access user accounts with incorrect passwords */
    checkUserAccess(user1, "password2");
    checkUserAccess(user2, "password1");
    
    /* Display event logs for users */
    displayEventLog(user1);
    displayEventLog(user2);
    
    return 0;
}