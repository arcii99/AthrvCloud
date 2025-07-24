//FormAI DATASET v1.0 Category: Digital signal processing ; Style: shape shifting
#include <stdio.h>

int main() {
    int option;
    float input;
    printf("Choose an option for signal processing:\n1. Low Pass Filter\n2. High Pass Filter\n3. Band Pass Filter\n4. Band Stop Filter\n");
    scanf("%d", &option);
    printf("Enter input signal frequency: ");
    scanf("%f", &input);

    switch(option) {
        case 1:
            printf("Low pass filter applied to signal at frequency %f Hz\n", input);
            break;
        case 2:
            printf("High pass filter applied to signal at frequency %f Hz\n", input);
            break;
        case 3:
            printf("Band pass filter applied to signal at frequency %f Hz\n", input);
            break;
        case 4:
            printf("Band stop filter applied to signal at frequency %f Hz\n", input);
            break;
        default:
            printf("Invalid option chosen\n");
    }

    return 0;
}