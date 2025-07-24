//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 2 // number of threads

// function to convert RGB to Hex
void* RGBtoHex(void* rgb) {
    int r,g,b;
    char hex[7];

    // get the RGB values from the input array
    int* arr = (int*) rgb;
    r = arr[0];
    g = arr[1];
    b = arr[2];

    // converts the RGB values to hexadecimal
    sprintf(hex, "#%02x%02x%02x", r, g, b);

    // print the hexadecimal value
    printf("RGB (%d,%d,%d) is equivalent to %s\n", r, g, b, hex);

    pthread_exit(NULL); // exit thread
}

// function to convert Hex to RGB
void* HextoRGB(void* hex) {
    int r,g,b;
    
    // get the hex value from input
    char* val = (char*) hex;

    // convert hex string to RGB
    sscanf(val, "#%02x%02x%02x", &r, &g, &b);

    // print the RGB values
    printf("Hex %s is equivalent to RGB (%d,%d,%d)\n", val, r, g, b);

    pthread_exit(NULL); // exit thread
}

int main() {
    pthread_t threads[THREAD_NUM];
    int rgbValues[3] = {255, 127, 0}; // RGB input
    char* hexValue = "#8B008B"; // Hex input

    // create threads to convert RGB to Hex and Hex to RGB
    pthread_create(&threads[0], NULL, RGBtoHex, (void*)rgbValues);
    pthread_create(&threads[1], NULL, HextoRGB, (void*)hexValue);

    // wait for threads to finish before exiting
    for(int i = 0; i < THREAD_NUM; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}