//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void shapeShift(int* arr, int size) {
    printf("( ^_^)／ hello everyone! I am a shape shifting RAM monitor!\n");
    printf("Starting up...\n");
    printf("\n");
    int index = 0;
    while(1) {
        printf("\r|");
        for(int i = 0; i < size; i++) {
            if(i == index) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("| %d%%", arr[index]);
        index++;
        if(index == size) {
            index = 0;
        }
        fflush(stdout);
        sleep(1);
    }
}

int main() {
    int* arr = malloc(sizeof(int) * 10);
    memset(arr, 0, sizeof(int) * 10);
    int totalRAM = 4000;
    printf("Starting CRAM usage monitor...\n");
    printf("Total RAM: %d MB\n", totalRAM);
    printf("\n");
    while(1) {
        int currentRAM = rand() % totalRAM + 1000;
        int usage = (currentRAM * 100) / totalRAM;
        for(int i = 9; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = usage;
        shapeShift(arr, 10);
    }
    return 0;
}