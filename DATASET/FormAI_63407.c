//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Checksum Calculator!\n");
    printf("Please enter a string of data (in hexadecimal format): ");

    char input[100];
    scanf("%s", input);

    int sum = 0;

    for(int i = 0; i < strlen(input); i+=2) {
        char byte[3];
        byte[0] = input[i];
        byte[1] = input[i+1];
        byte[2] = '\0';
        sum += strtol(byte, NULL, 16);
        if(sum > 0xFF)
            sum -= 0xFF;
    }

    int checksum = 0xFF - sum + 1;
    printf("The checksum of your data is: %X\n", checksum);

    return 0;
}