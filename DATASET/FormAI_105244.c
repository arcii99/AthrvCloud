//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100], temp[50];
    int i, j, count;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("\nUnique word count in your sentence is: \n");

    for (i = 0; sentence[i] != '\0'; i++)
    {
        // Extracting a word
        for (j = 0; sentence[i] != ' ' && sentence[i] != '\0'; j++, i++)
        {
            temp[j] = sentence[i];
        }
        temp[j] = '\0';

        // Counting number of times the word repeats
        count = 1;
        for (j = i + 1; sentence[j] != '\0'; j++)
        {
            if (strcmp(temp, "") != 0 && strcmp(temp, " ") != 0 && strcmp(temp, "\n") != 0)
            {
                if (strcmp(temp, "the") != 0 && strcmp(temp, "The") != 0)
                {
                    if (strncmp(temp, &sentence[j], strlen(temp)) == 0)
                    {
                        count++;
                        // Breaking the loop when a different word is detected
                        if (sentence[j + strlen(temp)] == ' ' || sentence[j + strlen(temp)] == '\0')
                        {
                            i = j;
                            break;
                        }
                    }
                }
            }
        }
        // Printing the word count if it is unique
        if (count == 1)
        {
            printf("%s\n", temp);
        }
    }

    return 0;
}