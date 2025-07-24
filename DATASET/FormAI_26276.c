//FormAI DATASET v1.0 Category: Data mining ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold information about each user
struct user {
    char name[50];
    int age;
    char job[50];
    char email[50];
};

int main() {
    // declare array of users
    struct user users[5];
    
    // populate array with dummy data
    strcpy(users[0].name, "Michael Scott");
    users[0].age = 45;
    strcpy(users[0].job, "Regional Manager");
    strcpy(users[0].email, "michael@dundermifflin.com");
    
    strcpy(users[1].name, "Jim Halpert");
    users[1].age = 32;
    strcpy(users[1].job, "Sales Representative");
    strcpy(users[1].email, "jim@dundermifflin.com");
    
    strcpy(users[2].name, "Dwight Schrute");
    users[2].age = 39;
    strcpy(users[2].job, "Assistant Regional Manager");
    strcpy(users[2].email, "dwight@dundermifflin.com");
    
    strcpy(users[3].name, "Pam Beesly");
    users[3].age = 31;
    strcpy(users[3].job, "Receptionist");
    strcpy(users[3].email, "pam@dundermifflin.com");
    
    strcpy(users[4].name, "Andy Bernard");
    users[4].age = 38;
    strcpy(users[4].job, "Sales Director");
    strcpy(users[4].email, "andy@dundermifflin.com");
    
    // print out the users in order of age
    printf("Users in order of age:\n");
    int i, j;
    struct user temp;
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (users[i].age > users[j].age) {
                // swap users[i] and users[j]
                temp = users[i];
                users[i] = users[j];
                users[j] = temp;
            }
        }
        printf("%s, %d, %s, %s\n", users[i].name, users[i].age, users[i].job, users[i].email);
    }
    
    // find users with specific job titles
    printf("\nUsers with 'Sales' in their job title:\n");
    for (i = 0; i < 5; i++) {
        if (strstr(users[i].job, "Sales")) {
            printf("%s, %d, %s, %s\n", users[i].name, users[i].age, users[i].job, users[i].email);
        }
    }
    
    // find users with specific email domain
    printf("\nUsers with email addresses from 'dundermifflin.com':\n");
    for (i = 0; i < 5; i++) {
        if (strstr(users[i].email, "dundermifflin.com")) {
            printf("%s, %d, %s, %s\n", users[i].name, users[i].age, users[i].job, users[i].email);
        }
    }
    
    return 0;
}