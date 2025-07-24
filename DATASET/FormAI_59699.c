//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: medieval
#include <stdio.h>

int main() {
    printf("Welcome to the Medieval Checksum Calculator!\n");
    printf("Please enter a string of characters to calculate the checksum:\n");
    char str[100];
    scanf("%s", str);
    int sum = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        sum += (int)str[i];
        if(sum > 1000) {
            sum = (sum % 100) + 50;
        }
    }
    printf("The checksum for \"%s\" is %d.\n", str, sum);
    return 0;
}