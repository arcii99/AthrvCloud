//FormAI DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main()
{
    char input[BUFFER_SIZE], output[BUFFER_SIZE];
    int i, j, count;
    
    printf("Please enter a string to compress: ");
    fgets(input, BUFFER_SIZE, stdin);
    
    int len = strlen(input);
    input[len-1] = '\0';
    
    for(i = 0, j = 0; i < len;)
    {
        count = 1;
        while(input[i] == input[i+1] && i < len-1)
        {
            count++;
            i++;
        }
        if(count == 1)
        {
            output[j++] = input[i++];
        }
        else
        {
            char cnt[20];
            sprintf(cnt, "%d", count);
            int k = 0;
            while(cnt[k])
            {
                output[j++] = cnt[k++];
            }
            output[j++] = input[i];
            i += count;
        }
    }
    output[j] = '\0';
    printf("\nCompressed output: %s\n", output);
    return 0;
}