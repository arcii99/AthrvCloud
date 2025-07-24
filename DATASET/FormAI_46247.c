//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

int main() {

    srand(time(NULL)); 

    int random_light;
    int i, j; 

    for (i=0; i<10; i++) { 
        random_light = rand() % 3 + 1; 

        if (random_light == GREEN) { 
            printf("Green Light\n"); 
            sleep(5); 
        } 
        else if(random_light == YELLOW){
            printf("Yellow Light\n");
            sleep(2);
        }
        else{ 
            printf("Red Light\n"); 
            sleep(4); 
        } 

        for(j=0; j<10; j++){ 
            printf("."); 
            sleep(1); 
        } 
        printf("\n\n"); 
    } 

    return 0; 
}