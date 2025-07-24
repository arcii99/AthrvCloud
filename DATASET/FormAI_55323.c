//FormAI DATASET v1.0 Category: Firewall ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    printf("C Firewall (Retro Style)\n");
    
    char blockList[10][20] = {"facebook.com", "twitter.com", "instagram.com", "tiktok.com", "youtube.com", "netflix.com", "amazon.com", "reddit.com", "spotify.com", "linkedin.com"};
    
    printf("Block list: \n");
    for(int i = 0; i < 10; i++){
        printf("%s \n", blockList[i]);
    }
    
    char input[20];
    bool blocked = false;
    printf("\nEnter a URL: ");
    scanf("%s", input);
    
    for(int i = 0; i < 10; i++){
        if(strcmp(input, blockList[i]) == 0){
            blocked = true;
            break;
        }
    }
    
    if(blocked){
        printf("\nAccess to %s has been blocked by the firewall.\n", input);
    } else {
        printf("\nAccess to %s is allowed.\n", input);
    }
    
    return 0;
}