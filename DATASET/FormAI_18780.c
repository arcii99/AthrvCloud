//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int calculate_checksum(char *input_string)
{
    int checksum = 0;
    int i;
    int len = strlen(input_string);
    
    for(i=0; i<len; i++)
    {
        checksum += (int)input_string[i];
    }
    
    return checksum;
}

int main()
{
    char input_string[100];
    int checksum;
    
    printf("Enter a string: ");
    fgets(input_string, 100, stdin);

    // Remove new line characters from input string
    input_string[strcspn(input_string, "\n")] = 0;
    
    checksum = calculate_checksum(input_string);
    
    printf("Checksum of %s is %d.", input_string, checksum);
    
    return 0;
}