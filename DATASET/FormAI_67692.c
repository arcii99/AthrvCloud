//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>

int main() {

    // Let's imagine we have 3 taps in front of us
    int tap1 = 9;       // binary: 1001
    int tap2 = 25;      // binary: 11001
    int tap3 = 13;      // binary: 1101

    // We want to know if the taps are leaking or not
    // We can do this using Bitwise AND operator
    // If we AND two binary digits and if both are 1, we get 1 else 0
    // So let's AND all the taps
    int isLeaking = tap1 & tap2 & tap3;
    // binary: 1001 & 11001 & 1101 = 1001 (which is non-zero)

    // If isLeaking is non-zero, then at least one of the taps is leaking
    if(isLeaking) {
        printf("Uh-oh, one or more taps are leaking!\n");
    } else {
        printf("All taps are working perfectly!\n");
    }

    // Now let's try to fix the leaking taps
    // We can use Bitwise OR operator
    // If we OR two binary digits and if at least one of them is 1, we get 1 else 0
    // So let's OR the first two taps (tap1 and tap2)
    int fixedTap1and2 = tap1 | tap2;
    // binary: 1001 | 11001 = 11101

    // And let's OR the last two taps (tap2 and tap3)
    int fixedTap2and3 = tap2 | tap3;
    // binary: 11001 | 1101 = 11101

    // Now let's see if the leaking stopped
    int isLeakingNow = fixedTap1and2 & fixedTap2and3;
    // binary: 11101 & 11101 = 11101 (which is non-zero)

    // If isLeakingNow is non-zero, then the taps are still leaking
    if(isLeakingNow) {
        printf("Oops, looks like the taps are still leaking...\n");
    } else {
        printf("Yay! The taps are fixed and not leaking anymore!\n");
    }

    // But wait, there's more we can do!
    // Let's say we want to know which taps are leaking
    // We can use Bitwise XOR operator
    // If we XOR two binary digits and if both are different, we get 1 else 0
    // So let's XOR each tap with isLeakingNow
    // If the result is non-zero, that means the tap is leaking
    if(tap1 ^ isLeakingNow) {
        printf("Tap 1 is leaking!\n");
    }
    if(tap2 ^ isLeakingNow) {
        printf("Tap 2 is leaking!\n");
    }
    if(tap3 ^ isLeakingNow) {
        printf("Tap 3 is leaking!\n");
    }

    // And that's how we can use Bitwise operations to fix and detect leaks in our taps

    return 0;
}