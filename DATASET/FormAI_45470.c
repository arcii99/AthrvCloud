//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void display_banner();
void display_ram_usage(float usage);

int main() {
    srand(time(0)); // initialize random seed
    
    float usage = 0.0;
    int count = 0;
    char state[10];
    
    display_banner();
    while(1) {
        // randomly update ram usage
        usage += ((float)rand()/(float)(RAND_MAX)) * 0.1 - 0.05;
        if(usage < 0.0) {
            usage = 0.0;
            strcpy(state, "Low");
        }else if(usage > 1.0) {
            usage = 1.0;
            strcpy(state, "High");
        }else {
            strcpy(state, "Normal");
        }
        display_ram_usage(usage);
        
        // wait for 1 second
        count++;
        if(count % 10 == 0) {
            printf("\nState: %s\n", state);
        }
        sleep(1);
    }
    
    return 0;
}

void display_banner() {
    printf("******************************************************\n");
    printf("****** Surreal RAM Usage Monitor Example Program ******\n");
    printf("******************************************************\n\n");
}

void display_ram_usage(float usage) {
    int percent = (int)(usage * 100);
    printf("***************************************\n");
    printf("*\tRAM usage: %d%%\t\t*\n", percent);
    printf("***************************************\n");
}