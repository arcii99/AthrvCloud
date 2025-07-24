//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Romeo and Juliet
/* 
* Oh, sweet RAM, how thee doth serve us well
* In thee, we store our memories and tales
* But as we use thee, we must be aware
* Of how much space we have left to spare
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    // Let us start by introducing ourselves
    printf("Good day, gentle user! May I know thy name?\n");
    char name[20];
    fgets(name, sizeof(name), stdin);
    printf("Ah, welcome, %s! It is nice to meet thee.\n", name);

    // Now, let us begin to check our RAM usage
    printf("Let us see how much RAM we have left to use.\n");
    printf("Give me a moment as I gather the necessary information.\n");

    // We will use the system call 'free' to check the memory usage
    const char* command = "free";
    system(command);

    // To keep things interesting, let us add a love story to it
    printf("Oh, sweet RAM, thou art like true love\n");
    printf("In thee, we store memories that time cannot move\n");
    printf("But, like love, we must be careful how we use,\n");
    printf("Or we'll find ourselves running short as we cruise.\n");

    // Let us check for memory usage every 10 seconds
    while(1) {
        sleep(10);
        printf("\nLet us see how much RAM we have left to use.\n");
        printf("Give me a moment as I gather the necessary information.\n");
        const char* command = "free";
        system(command);
    }

    // Farewell, gentle user! May thy dreams be sweet.
    printf("Thank thee for using this RAM usage monitor!\n");
    printf("Farewell, %s! May thy dreams be sweet.\n", name);
    return 0;
}