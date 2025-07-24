//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 20
#define HEIGHT 10
#define PIXEL_SIZE 2

char pixels[HEIGHT][WIDTH];

void initialize_pixels();
void set_pixel(int x, int y, char value);
char get_pixel(int x, int y);
void print_pixels();
void save_art(char* filename);

int main(){
    srand(time(NULL));

    initialize_pixels();
    print_pixels();
    save_art("art_before.txt");

    printf("\nGenerating new art:\n");

    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            if(rand() % 10 == 0){
                set_pixel(x, y, 'X');
            }
        }
    }
    print_pixels();
    save_art("art_after.txt");

    return 0;
}

void initialize_pixels(){
    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            pixels[y][x] = '-';
        }
    }
}

void set_pixel(int x, int y, char value){
    pixels[y][x] = value;
}

char get_pixel(int x, int y){
    return pixels[y][x];
}

void print_pixels(){
    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            for(int i=0; i<PIXEL_SIZE; i++){
                for(int j=0; j<PIXEL_SIZE; j++){
                    printf("%c", pixels[y][x]);
                }
            }
        }
        printf("\n");
    }
}

void save_art(char* filename){
    FILE *fp;
    fp = fopen(filename, "w");
    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            fprintf(fp, "%c", pixels[y][x]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}