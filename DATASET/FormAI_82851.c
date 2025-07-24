//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to compress the given input string
char* compress(char* input)
{
    int len = strlen(input);
    char* output = (char*)malloc(2 * len * sizeof(char)); //allocate memory for output string
    
    int i = 0, j = 0;
    while(i < len)
    {
        int count = 1;
        while(i < len-1 && input[i] == input[i+1])
        {
            count++;
            i++;
        }
        output[j++] = input[i];
        output[j++] = count + '0';
        i++;
    }
    output[j] = '\0'; //add null character at the end
    return output;
}

int main()
{
    char input[100], *output;
    printf("Enter the input string: ");
    scanf("%s", input);
    output = compress(input);
    printf("Compressed string: %s\n", output);
    free(output); //free the allocated memory
    return 0;
}