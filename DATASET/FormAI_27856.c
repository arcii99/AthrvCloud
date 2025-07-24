//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QOS 10

/* Function to generate random QoS value */
int generateQoS(){
    return rand() % MAX_QOS + 1;
}

int main(){
    srand(time(NULL));

    printf("Welcome to the Happy QoS Monitor!\n");

    int count = 0;
    int qos = generateQoS();

    while(count < 10){
        printf("\n\nChecking QoS...\n");

        if(qos == MAX_QOS){
            printf("Wow! Your network is super speedy today!\n");
        }
        else if(qos >= 8){
            printf("Awesome! Your network is working great!\n");
        }
        else if(qos >= 5){
            printf("Your network is doing good, keep it up!\n");
        }
        else{
            printf("Uh oh, your network could use some improvement...\n");
        }

        printf("Current QoS rating: %d\n", qos);

        qos = generateQoS();
        count++;
    }

    printf("\n\nThank you for using the Happy QoS Monitor!\n");

    return 0;
}