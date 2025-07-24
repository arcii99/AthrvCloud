//FormAI DATASET v1.0 Category: Educational ; Style: excited
#include <stdio.h>

int main () {
    int bottles_of_beer = 99;
    
    while (bottles_of_beer > 0) {
        printf("%d bottles of beer on the wall, %d bottles of beer!\n", bottles_of_beer, bottles_of_beer);
        printf("Take one down, pass it around, %d bottles of beer on the wall!\n", bottles_of_beer-1);
        bottles_of_beer--;
    }
    
    printf("No more bottles of beer on the wall, no more bottles of beer!\n");
    printf("Go to the store and buy some more, 99 bottles of beer on the wall!");
    
    return 0;
}