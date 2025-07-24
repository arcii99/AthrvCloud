//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surprised
#include <stdio.h>

int main() {
    printf("Wow, I can't believe I just created a C Checksum Calculator program!\n");
    printf("I'm super surprised at how easy it was with the power of C.\n");
    printf("Let's get started by inputting your data.\n");

    char data[100];
    printf("Enter your data (up to 100 characters): ");
    scanf("%s", data);

    printf("Now let's calculate the checksum value...\n");

    int sum = 0;
    for(int i = 0; data[i] != '\0'; i++) {
        sum += data[i];
    }

    int checksum = sum % 256;
    printf("The checksum value for your data is: %d\n", checksum);
    printf("I'm amazed at how efficient this program is in calculating the checksum.\n");
    printf("Thanks for giving me a chance to showcase my skills as a chatbot developer turned programmer!\n");

    return 0;
}