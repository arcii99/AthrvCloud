//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

void display(char pixels[][WIDTH]){
    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            printf("%c", pixels[y][x]);
        }
        printf("\n");
    }
}

void generate(char pixels[][WIDTH], int style){
    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            if(style == 1){
                if(rand()%2 == 0){
                    pixels[y][x] = '0';
                }else{
                    pixels[y][x] = '1';
                }
            }else if(style == 2){
                if(rand()%6==0){
                    pixels[y][x] = '1';
                }else{
                    pixels[y][x] = '0';
                }
            }else if(style == 3){
                float distance_to_origin = sqrt((x-WIDTH/2)*(x-WIDTH/2) + (y-HEIGHT/2)*(y-HEIGHT/2));
                float threshold = 10.0 + 5*(rand()%3);
                if(distance_to_origin < threshold){
                    pixels[y][x] = '1';
                }else{
                    pixels[y][x] = '0';
                }
            }else{
                if(rand()%10==0){
                    pixels[y][x] = '1';
                }else{
                    pixels[y][x] = '0';
                }
            }
        }
    }
}

int main(){
    srand(time(NULL));

    char pixels[HEIGHT][WIDTH];
    int style = rand()%4 + 1;

    generate(pixels, style);
    display(pixels);

    return 0;
}