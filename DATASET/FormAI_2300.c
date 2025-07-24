//FormAI DATASET v1.0 Category: Recursive ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>

/* Cyberpunk style recursive function */
void hack_in_progress(int level){
    printf("Executing hack level %d...\n", level);
    
    if(level == 0){
        printf("Access granted! You've hacked in successfully.\n");
    }
    else{
        /* Generate random number for progress update */
        int progress = rand() % 10 + 1;
        printf("Progress: %d%%\n", progress*10);
        
        if(progress < 8){
            printf("Hack failed. Retrying...\n");
            hack_in_progress(level);
        }
        else{
            /* Generate random sub-level to hack */
            int sub_level = rand() % level + 1;
            printf("Advancing to sub-level %d...\n", sub_level);
            hack_in_progress(sub_level-1);
        }
    }
}

int main(){
    printf("Welcome to the cyberpunk recursive hack program!\n\n");
    
    /* Get desired hack level from user*/
    int hack_level;
    printf("Enter hack level: ");
    scanf("%d", &hack_level);
    
    /* Call the recursive function to start the hack */
    hack_in_progress(hack_level);
    
    printf("\nHack complete. Terminating program...\n");
    
    return 0;
}