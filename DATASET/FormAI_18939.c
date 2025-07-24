//FormAI DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdio.h>

int main() {

int lights[4] = {0, 0, 0, 0};
int room_num = 0;
char action[10];

printf("Welcome to the Smart Home Light Control System!\n");

while(1) {

    printf("Which room do you want to control? (1-4)\n");
    scanf("%d", &room_num);

    printf("What do you want to do? (on/off)\n");
    scanf("%s", action);

    if(strcmp(action, "on") == 0) {
        lights[room_num-1] = 1;
        printf("Turning On Lights in Room %d\n", room_num);
    }
    else if(strcmp(action, "off") == 0) {
        lights[room_num-1] = 0;
        printf("Turning Off Lights in Room %d\n", room_num);
    }
    else {
        printf("Error: Invalid Action\n");
    }

    printf("Current Light State: %d %d %d %d\n", lights[0], lights[1], lights[2], lights[3]);

    int total_lights = 0;

    for(int i = 0; i < 4; i++) {
        if(lights[i] == 1) {
            total_lights++;
        }
    }

    if(total_lights == 0) {
        printf("All Lights Are Off. Good Night!\n");
        break;
    }

}

return 0;
}