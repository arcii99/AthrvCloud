//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>

int main() {
    int num = 35;
    int bit = 3;
    
    //Setting the bit
    int set_mask = 1 << bit;
    num = num | set_mask;
    printf("After setting bit %d, num becomes: %d\n", bit, num); //Output: After setting bit 3, num becomes: 43

    //Clearing the bit
    int clear_mask = ~(1 << bit);
    num = num & clear_mask;
    printf("After clearing bit %d, num becomes: %d\n", bit, num); //Output: After clearing bit 3, num becomes: 35

    //Toggling the bit
    int toggle_mask = 1 << bit;
    num = num ^ toggle_mask;
    printf("After toggling bit %d, num becomes: %d\n", bit, num); //Output: After toggling bit 3, num becomes: 43

    //Checking if the bit is set
    int is_set = num & (1 << bit);
    if(is_set) {
        printf("Bit %d is set\n", bit); //Output: Bit 3 is set
    } else {
        printf("Bit %d is not set\n", bit); 
    }

    //Checking if the bit is clear
    int is_clear = (num & (1 << bit)) == 0;
    if(is_clear) {
        printf("Bit %d is clear\n", bit); 
    } else {
        printf("Bit %d is not clear\n", bit); //Output: Bit 3 is not clear
    }

    return 0;
}