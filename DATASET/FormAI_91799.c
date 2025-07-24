//FormAI DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
//Robot Variables
int pos_x=0, pos_y=0, steps=0;
char direction = 'N';

//Move function
void move(char d, int s){
    char curr_dir = direction;
    int curr_x = pos_x;
    int curr_y = pos_y;

    if(d == 'N'){
        pos_y += s;
    } else if(d == 'S'){
        pos_y -= s;
    } else if(d == 'E'){
        pos_x += s;
    } else if(d == 'W'){
        pos_x -= s;
    }

    //Checking for border violation
    if(pos_x < 0 || pos_y < 0 || pos_x > 10 || pos_y > 10){
        printf("Warning! Border Violation Detected\n");
        pos_x = curr_x;
        pos_y = curr_y;
    }

    //Updating direction
    if(curr_dir == 'N' && d == 'L') direction = 'W';
    else if(curr_dir == 'N' && d == 'R') direction = 'E';
    else if(curr_dir == 'S' && d == 'L') direction = 'E';
    else if(curr_dir == 'S' && d == 'R') direction = 'W';
    else if(curr_dir == 'E' && d == 'L') direction = 'N';
    else if(curr_dir == 'E' && d == 'R') direction = 'S';
    else if(curr_dir == 'W' && d == 'L') direction = 'S';
    else if(curr_dir == 'W' && d == 'R') direction = 'N';

    //Updating steps
    steps += s;
}

int main(){
    //Initial state
    printf("Robot movement control program. Current direction: %c Position: (%d,%d) Steps: %d\n", direction, pos_x, pos_y, steps);

    //Commands
    move('N', 5);
    printf("Robot moved North by 5. Current direction: %c Position: (%d,%d) Steps: %d\n", direction, pos_x, pos_y, steps);

    move('L', 90);
    printf("Robot turned Left by 90 degrees. Current direction: %c Position: (%d,%d) Steps: %d\n", direction, pos_x, pos_y, steps);

    move('S', 3);
    printf("Robot moved South by 3. Current direction: %c Position: (%d,%d) Steps: %d\n", direction, pos_x, pos_y, steps);

    move('R', 180);
    printf("Robot turned Right by 180 degrees. Current direction: %c Position: (%d,%d) Steps: %d\n", direction, pos_x, pos_y, steps);

    move('E', 6);
    printf("Robot moved East by 6. Current direction: %c Position: (%d,%d) Steps: %d\n", direction, pos_x, pos_y, steps);

    move('L', 270);
    printf("Robot turned Left by 270 degrees. Current direction: %c Position: (%d,%d) Steps: %d\n", direction, pos_x, pos_y, steps);

    move('W', 12);
    printf("Robot moved West by 12. Current direction: %c Position: (%d,%d) Steps: %d\n", direction, pos_x, pos_y, steps);

    //Final state
    printf("Final state of the Robot: Current direction: %c Position: (%d,%d) Steps: %d\n", direction, pos_x, pos_y, steps);

    return 0;
}