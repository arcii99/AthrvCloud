//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: funny
#include <stdio.h>

int main() {
    printf("Hello, I am a checksum calculator! What do you want me to do?\n");
    printf("Calculating the checksum of your enemies list? Ok, let's get to it!\n");
    
    char enemyList[50];
    printf("Please enter your enemies list: ");
    scanf("%s", enemyList);
    
    int checksum = 0;
    for(int i = 0; i < strlen(enemyList); i++) {
        checksum += enemyList[i];
    }
    
    printf("The checksum for your enemies list is: %d\n", checksum);
    printf("Oh wait, you forgot to add your mother-in-law to the list! Let's add her now.\n");
    
    enemyList[strlen(enemyList)] = ' ';
    enemyList[strlen(enemyList)] = '&';
    enemyList[strlen(enemyList)] = ' ';
    enemyList[strlen(enemyList)] = 'M';
    enemyList[strlen(enemyList)] = 'o';
    enemyList[strlen(enemyList)] = 't';
    enemyList[strlen(enemyList)] = 'h';
    enemyList[strlen(enemyList)] = 'e';
    enemyList[strlen(enemyList)] = 'r';
    enemyList[strlen(enemyList)] = '-';
    enemyList[strlen(enemyList)] = 'i';
    enemyList[strlen(enemyList)] = 'n';
    enemyList[strlen(enemyList)] = '-';
    enemyList[strlen(enemyList)] = 'L';
    enemyList[strlen(enemyList)] = 'a';
    enemyList[strlen(enemyList)] = 'w';    
    
    checksum = 0;
    for(int i = 0; i < strlen(enemyList); i++) {
        checksum += enemyList[i];
    }
    
    printf("The new checksum for your enemies list with your mother-in-law added is: %d\n", checksum);
    printf("That should do it! Thanks for using the checksum calculator. Have a nice day!\n");
    
    return 0;
}