//FormAI DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    char output[1000];
    char line[100];
    int i, len_input, len_line, count = 0;

    printf("Enter your text:\n");

    fgets(input, 1000, stdin); // read the input from user

    printf("Enter the word you want to replace:\n");
    scanf("%s", line);

    len_input = strlen(input); // get the length of input string

    while(count < len_input)
    {
        i = 0;

        while(input[count] != ' ' && input[count] != '.' && input[count] != ',' && input[count] != '\n')
        {
            line[i++] = input[count++]; // keep adding to the line array until we reach a space or the end of line characters
        }

        line[i] = '\0'; // add null character at the end of line string

        len_line = strlen(line); // get the length of line string

        if(strcmp(line, "expert") == 0) // check if the word matches with the given word
        {
            strcat(output, "pro"); // if yes, replace it with "pro" and add it to the output string
        }
        else
        {
            strcat(output, line); // if not, add the whole word as it is to the output string
        }

        if(input[count] == ' ')
        {
            strcat(output, " "); // if we reached a space, add it to the output string
            count++;
        }
        else if(input[count] == '.' || input[count] == ',' || input[count] == '\n')
        {
            strcat(output, &input[count]); // if we reached a punctuation mark or end of line character, add it to the output string
            break;
        }
    }

    printf("\nOriginal Text:\n%s", input);
    printf("\nText after processing:\n%s\n", output);

    return 0;
}