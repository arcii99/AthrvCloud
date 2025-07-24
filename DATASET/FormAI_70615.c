//FormAI DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main()
{

    char sentence[100];
    printf("Hello there! I'm a program that counts vowels in your input. Enter a sentence: \n");
    fgets(sentence, 100, stdin);
    printf("Thanks! Here's your sentence: %s\n", sentence);

    int a_count = 0;
    int e_count = 0;
    int i_count = 0;
    int o_count = 0;
    int u_count = 0;

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == 'a' || sentence[i] == 'A')
            a_count++;
        else if (sentence[i] == 'e' || sentence[i] == 'E')
            e_count++;
        else if (sentence[i] == 'i' || sentence[i] == 'I')
            i_count++;
        else if (sentence[i] == 'o' || sentence[i] == 'O')
            o_count++;
        else if (sentence[i] == 'u' || sentence[i] == 'U')
            u_count++;
    }

    printf("\n\nAfter counting the vowels in your input, here are the results: \n\n");
    printf("A: %d\n", a_count);
    printf("E: %d\n", e_count);
    printf("I: %d\n", i_count);
    printf("O: %d\n", o_count);
    printf("U: %d\n\n", u_count);
    printf("Thank you for using my program! Have a great day!\n");

    return 0;
}