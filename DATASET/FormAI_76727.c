//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(0));
    int num = rand() % 10;
    if(num < 5) {
        printf("The website is up!\n");
    } else {
        printf("The website is down!\n");
    }
    return 0;
}