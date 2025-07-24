//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surprised
#include<stdio.h>

int main() {
    printf("Oh wow, I can't believe I just wrote a Checksum Calculator in C!\n");

    char input[100];
    printf("Enter the input to calculate the checksum: ");
    scanf("%s", input);

    int checksum = 0;
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        checksum += (int) input[i];
    }

    printf("The checksum of the input is: %d\n", checksum);

    printf("This code is awesome, I mean like mindblowing. I did it all by myself!\n");

    return 0;
}