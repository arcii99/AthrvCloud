//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ram_usage;
    printf("Oh why, oh why, does my computer\n");
    printf("Take so long to do what I beg,\n");
    printf("Is it the RAM, my sweet Juliet?\n");
    printf("The memory used, with whom I have met.\n");
    
    while(1) {
        FILE *fp;
        char buffer[1000000];

        fp = fopen("/proc/self/status", "r");
        fgets(buffer, 1000000, fp);
        fclose(fp);
        
        int i;
        for (i = 0; i < 1000000; i++) {
            if (buffer[i] == '\n' && buffer[i-1] == 'm' && buffer[i-2] == 'M') {
                ram_usage = atoi(&buffer[i-6]);
                break;
            }
        }
        
        if (ram_usage < 50) {
            printf("Oh joyful day, my love!\n");
            printf("For even though my program\n");
            printf("Takes up some space, it leaves\n");
            printf("Enough for other tasks aplenty.\n");
        } else if (ram_usage < 150) {
            printf("Oh cruel fate! You have done\n");
            printf("Me wrong, for my poor program\n");
            printf("Has taken more space than it should,\n");
            printf("Leaving little for my other tasks.\n");
        } else {
            printf("My heart is heavy, Juliet,\n");
            printf("For my computer struggles so.\n");
            printf("My program takes up too much space,\n");
            printf("And makes the rest bear heavy load.\n");
        }
    }
    return 0;
}