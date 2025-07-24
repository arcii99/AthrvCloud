//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    printf("Welcome to the Cryptic Internet Speed Test Application!\n\n");
    printf("Initializing the test...\n\n");

    int counter = 0;
    float total_time = 0;
    while(counter < 10){
        float start_time = (float)clock();
        system("ping 8.8.8.8 -c 1");
        float end_time = (float)clock();
        float elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;
        total_time += elapsed_time;
        counter++;
    }

    float average_time = total_time / counter;
    float speed = 8 / average_time;

    printf("\n\nTest completed successfully!\n");
    printf("Your internet speed is %f Mbps\n", speed);

    return 0;
}