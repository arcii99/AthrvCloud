//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int calculate_checksum(char* str);

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int checksum = calculate_checksum(str);
    printf("Checksum: %d\n", checksum);

    return 0;
}

int calculate_checksum(char* str)
{
    int sum = 0;
    int i = 0;
    while(str[i] != '\0') {
        sum += str[i];
        i++;
    }
    return sum % 255;
}