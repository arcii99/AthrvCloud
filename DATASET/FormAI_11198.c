//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include<stdio.h>
#include<string.h>

int main()
{
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    int len = strlen(input);

    int count[26] = {0};
    for(int i = 0; i < len; i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z') // check if character is lowercase letter
        {
            int index = input[i] - 'a'; // get index of character
            count[index]++; // increment corresponding element in count array
        }
    }
    
    int max = 0;
    int max_index = 0;
    for(int i = 0; i < 26; i++)
    {
        if(count[i] > max) // check if count of current character is greater than current max
        {
            max = count[i]; // update max
            max_index = i; // update index of character with max count
        }
    }

    printf("\nMost common lowercase letter: %c\n", max_index + 'a');

    return 0;
}