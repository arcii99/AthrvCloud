//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int love_score, invasion_probability;
    printf("O pandemic of sorrow, why dost thou plague my mind\n");
    printf("What shall we do, to calculate the chance of our fate entwined?\n");
    printf("Verily, let us create an algorithm most divine\n");
    printf("To know the probability of an alien invasion be near or far away in time\n");

    printf("Enter the love score: ");
    scanf("%d", &love_score);
    printf("Enter the invasion probability: ");
    scanf("%d", &invasion_probability);

    if (love_score >= 90 && invasion_probability <= 30) {
        printf("Forsooth, this is a match made in heaven\n");
        printf("And alas, the probability of an alien invasion be but a measly 30 percent\n");
        printf("Therefore, let us revel in our love, worry-free and glad\n");
    }
    else if (love_score >= 70 && invasion_probability <= 50) {
        printf("My dear Romeo/Juliet, our love is strong and true\n");
        printf("But alas, the probability of an alien invasion be 50 percent and it feels like a flu\n");
        printf("Therefore, let us strive to enjoy this moment, no matter how few\n");
    }
    else if (love_score >= 50 && invasion_probability <= 70) {
        printf("Oh Romeo/Juliet, our love may be met with strife and pain\n");
        printf("And lo, the probability of an alien invasion be 70 percent and it drives us insane\n");
        printf("But dare we say, we shall weather this storm, our spirits shall never wane!\n");
    }
    else {
        printf("Alack, alas, we are but doomed with love weak as a flame\n");
        printf("And worse off, the probability of an alien invasion be near, ripe for shame\n");
        printf("But let us brave the gloom with hearts unafraid, fight and never not game\n");
    }
    return 0;
}