//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

int main()
{
    char input_string[MAX_SIZE], compressed_string[MAX_SIZE];
    int count = 1;

    printf("Enter the string to compress: ");
    fgets(input_string, MAX_SIZE, stdin);

    int length = strlen(input_string);

    for(int i = 0; i < length; i++) {
        if(input_string[i] == input_string[i+1])
            count++;
        else {
            if(count == 1)
                strncat(compressed_string, &input_string[i], 1);
            else {
                char buffer[5];
                sprintf(buffer, "%d", count);
                strncat(compressed_string, buffer, strlen(buffer));
                strncat(compressed_string, &input_string[i], 1);
                count = 1;
            }
        }
    }

    printf("Compressed string: %s", compressed_string);

    return 0;
}