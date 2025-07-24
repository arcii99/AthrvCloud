//FormAI DATASET v1.0 Category: Smart home light control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int cur_time = 1800;
    int desired_time = 2200;
    printf("My Dearest,\n");
    printf("I have written a program to control the lights in our home.\n");

    if (cur_time >= 1800 && cur_time < 2100) {
        printf("The lights in the living room are on.\n");
        printf("Do you want me to turn them off?\n");
    } else if (cur_time >= 2100 && cur_time < 2200) {
        printf("The lights in the living room are on.\n");
        printf("Shall I dim them down?\n");
    } else if (cur_time >= 2200 && cur_time < 2300) {
        printf("The lights in the living room are dimmed.\n");
        printf("Do you want me to turn them off completely?\n");
    } else {
        printf("The lights in the living room are off.\n");
        printf("Shall I turn them on?\n");
    }

    if (cur_time < desired_time && desired_time >= 2200) {
        printf("The lights will be turned off automatically at 10 PM.\n");
    } else {
        printf("The lights will stay on until %d PM.\n", desired_time / 100);
    }
    printf("Yours forever,\n");
    printf("Your Smart Home.\n");
    return 0;
}