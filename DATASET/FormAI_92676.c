//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include <stdio.h>

void redLight() {
    printf("Red light is on\n");
}

void yellowLight() {
    printf("Yellow light is on\n");
}

void greenLight() {
    printf("Green light is on\n");
}

int main() {
    char user_input;
    char prev_input = '\0';
    
    while (1) {
        printf("Enter a character to change the traffic light:\n");
        printf("Type r for red light\n");
        printf("Type y for yellow light\n");
        printf("Type g for green light\n");
        
        scanf("%c", &user_input);
        
        if (user_input != prev_input) {
            switch (user_input) {
                case 'r':
                    redLight();
                    break;
                case 'y':
                    yellowLight();
                    break;
                case 'g':
                    greenLight();
                    break;
                default:
                    printf("Invalid input\n");
                    break;
            }
            prev_input = user_input;
        }
    }
    return 0;
}