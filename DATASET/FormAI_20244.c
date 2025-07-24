//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define GREEN 0
#define YELLOW 1
#define RED 2

int traffic_light = GREEN;

int main() {
    srand(time(NULL));
    printf("The traffic light is currently: GREEN\n");

    while(1) {
        switch(traffic_light) {
            case GREEN:
                green_light();
                break;
            case YELLOW:
                yellow_light();
                break;
            case RED:
                red_light();
                break;
        }
    }

    return 0;
}

void green_light() {
    int random = rand() % 10;
    printf("The traffic light is currently: GREEN\n");

    if(random == 0) {
        printf("A unicorn has just crossed the street. YELLOW\n");
        traffic_light = YELLOW;
    }
    else {
        printf("No one is crossing the street. RED\n");
        traffic_light = RED;
    }
}

void yellow_light() {
    int random = rand() % 10;
    printf("The traffic light is currently: YELLOW\n");

    if(random == 0) {
        printf("A giant rubber duck is crossing the street. RED\n");
        traffic_light = RED;
    }
    else {
        printf("The street is clear. GREEN\n");
        traffic_light = GREEN;
    }
}

void red_light() {
    int random = rand() % 10;
    printf("The traffic light is currently: RED\n");

    if(random == 0) {
        printf("A group of penguins is crossing the street. GREEN\n");
        traffic_light = GREEN;
    }
    else {
        printf("No one is crossing the street. YELLOW\n");
        traffic_light = YELLOW;
    }
}