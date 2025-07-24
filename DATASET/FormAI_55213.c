//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: ultraprecise
#include <stdio.h>
#include <unistd.h> //for sleep function

int main(){
    int red = 1;
    int yellow = 0;
    int green = 0;
    
    while(1) {
        if(red == 1 && yellow == 0 && green == 0) {
            printf("Red light on\n");
            sleep(10);
            red = 0;
            yellow = 1;
        }
        else if (red == 0 && yellow == 1 && green == 0) {
            printf("Yellow light on\n");
            sleep(2);
            yellow = 0;
            green = 1;
        }
        else if (red == 0 && yellow == 0 && green == 1) {
            printf("Green light on\n");
            sleep(10);
            green = 0;
            yellow = 1;
        }
        else {
            printf("Yellow light on\n");
            sleep(2);
            yellow = 0;
            red = 1;
        }
    }
    
    return 0;
}