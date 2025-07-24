//FormAI DATASET v1.0 Category: Educational ; Style: Linus Torvalds
/*
 * Linux-style example program in C
 * Author: Chatbot
 */

#include <stdio.h>

#define MAX 10
#define MIN 1

int main(int argc, char* argv[]) {
    int num;

    printf("Enter a number between %d and %d: ", MIN, MAX);

    if(scanf("%d", &num) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if(num < MIN || num > MAX) {
        printf("Number out of range\n");
        return 1;
    }

    for(int i = 1; i <= num; i++) {
        if(i % 2 == 0) {
            printf("%d: even\n", i);
        } else {
            printf("%d: odd\n", i);
        }
    }

    return 0;
}