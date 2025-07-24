//FormAI DATASET v1.0 Category: Computer Biology ; Style: brave
#include <stdio.h>

int main() {
    printf("Welcome to the Brave program!\n");

    int numberOfOrgans = 10;
    char organs[10][15] = {"heart", "lungs", "kidneys", "liver", "spleen", "pancreas", "stomach", "small intestine", "large intestine", "brain"};

    int organNumber;
    do {
        printf("Select an organ (1-10):\n");
        scanf("%d", &organNumber);
    } while (organNumber < 1 || organNumber > 10);

    printf("You have selected the %s.\n", organs[organNumber - 1]);

    if (organNumber == 1) {
        printf("The heart is responsible for pumping blood throughout the body.\n");
    } else if (organNumber == 2) {
        printf("The lungs are responsible for extracting oxygen from the air and removing carbon dioxide.\n");
    } else if (organNumber == 3) {
        printf("The kidneys are responsible for filtering waste from the blood and producing urine.\n");
    } else if (organNumber == 4) {
        printf("The liver is responsible for removing toxins from the blood and producing bile.\n");
    } else if (organNumber == 5) {
        printf("The spleen is responsible for filtering old and damaged red blood cells.\n");
    } else if (organNumber == 6) {
        printf("The pancreas is responsible for producing insulin and other hormones.\n");
    } else if (organNumber == 7) {
        printf("The stomach is responsible for breaking down food into smaller particles.\n");
    } else if (organNumber == 8) {
        printf("The small intestine is responsible for absorbing nutrients from food.\n");
    } else if (organNumber == 9) {
        printf("The large intestine is responsible for absorbing water and electrolytes from digestive waste.\n");
    } else {
        printf("The brain is responsible for controlling all bodily functions and thoughts.\n");
    }

    printf("Thank you for using the Brave program!\n");

    return 0;
}