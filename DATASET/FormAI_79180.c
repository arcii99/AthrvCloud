//FormAI DATASET v1.0 Category: Firewall ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

    printf("My firewall protects my love from harm,\n");
    printf("I filter out any packets that could cause alarm.\n");
    
    bool loveIsSafe = true;
    char input[100];
    
    while(loveIsSafe) {
        printf("Enter a packet to analyze, my dear:\n");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;
        
        for(int i = 0; i < strlen(input); i++) {
            if(!isalnum(input[i])) {
                loveIsSafe = false;
                printf("My love! This packet is dangerous, it's not allowed!\n");
                break;
            }
        }
        
        if(loveIsSafe) {
            printf("This packet may pass through to my heart,\n");
            printf("My firewall protects us, we'll never be apart.\n");
        }
    }
    
    printf("My dear, my love, I must now take action,\n");
    printf("I'll block this packet, it's causing a distraction.\n");

    return 0;
}