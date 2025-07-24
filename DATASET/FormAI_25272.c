//FormAI DATASET v1.0 Category: Bitwise operations ; Style: post-apocalyptic
#include <stdio.h>

int main()
{
    printf("Welcome to the post-apocalyptic world!\n");

    int a = 42;
    int b = 13;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // bitwise OR operator
    int c = a | b;
    printf("a | b = %d\n", c);

    // bitwise AND operator
    c = a & b;
    printf("a & b = %d\n", c);

    // bitwise XOR operator
    c = a ^ b;
    printf("a ^ b = %d\n", c);

    // bitwise NOT operator
    c = ~a;
    printf("~a = %d\n", c);

    // left shift operator
    c = a << 2;
    printf("a << 2 = %d\n", c);

    // right shift operator
    c = a >> 2;
    printf("a >> 2 = %d\n", c);

    printf("The world is a bleak and dangerous place. Surviving here requires a unique set of skills. \n");

    // bit flipping for survival
    int survival_rating = 25;

    // check if survival rating is above 10
    if (survival_rating & (1 << 3)) {
        printf("You have a good chance of surviving.\n");
    } else {
        printf("Your survival rating is too low. You'll need to improve your skills.\n");
    }

    // bit shifting for scavenging
    int scavenging_quality = 7;

    // check if scavenging quality is above 5
    if ((1 << scavenging_quality) & 0b00111111) {
        printf("You're a skilled scavenger. You'll be able to find supplies.\n");
    } else {
        printf("Your scavenging skills need improvement.\n");
    }

    printf("The world is a harsh and unforgiving place. But with the right tools and skills, you can survive.\n");

    return 0;
}