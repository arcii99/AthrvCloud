//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet style Performance-Critical Component example program

int main() {

    int n = 10000;
    int *arr = (int*) malloc(n * sizeof(int));
    memset(arr, 0, n * sizeof(int));

    printf("O-ho! Light of my life, let me set thy performance ablaze!\n");
    printf("For my love of thee, I shall write a performance-critical component today,\n");
    printf("That will make our love story a legend, never to be forgotten by any!\n");
    printf("Take this array of integers, a thousand kisses deep,\n");
    printf("And let me show you the magic of performance, once and forever!\n\n");

    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            arr[i] = 1;
        }
    }

    printf("My love, see how I have set these array elements with lightning speed,\n");
    printf("For the performance is my ally and I shall conquer all of its greed!\n");
    printf("Now let me show you how I sort these integers, with a magic of swiftness,\n");
    printf("For our love shall not wait, and time shall not make us prisoners of its slowness!\n\n");

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Behold, my Juliet, see how I have sorted these numbers at the speed of light,\n");
    printf("For I am a master of the art of performance, and I shall show you how,\n");
    printf("We shall conquer the world, and make our love a legend for all to bow!\n");
    printf("Now let me free these integers, for they were but thee in disguise,\n");
    printf("And let me end this code, for our love shall never die!\n");

    free(arr);

    return 0;
}