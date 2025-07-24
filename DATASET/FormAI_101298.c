//FormAI DATASET v1.0 Category: Fractal Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void plot(int x, int y){
    printf("X");
}

void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds){}
}

void fractal(int size, int x, int y, int angle, int level){
    int branch_size = size / 2;
    int end_x = branch_size * sin(angle * M_PI / 180) + x;
    int end_y = branch_size * cos(angle * M_PI / 180) + y;
    int i;
    
    if (level > 0) {
        for (i = 0; i < size; i++) {
            int cur_x = x + (end_x - x) * (i / (float)size);
            int cur_y = y + (end_y - y) * (i / (float)size);
            plot(cur_x, cur_y);
        }
        delay(50);
        
        int new_angle = angle + rand() % 60 - 30;
        fractal(branch_size, end_x, end_y, new_angle, level - 1);
        
        new_angle = angle + rand() % 60 - 30;
        fractal(branch_size, end_x, end_y, new_angle, level - 1);
    } 
}

int main(){
    int size = 64;
    int x = 50;
    int y = 50;
    int angle = -90;
    int level = 6;

    srand(time(NULL));
    
    fractal(size, x, y, angle, level);
    
    return 0;
}