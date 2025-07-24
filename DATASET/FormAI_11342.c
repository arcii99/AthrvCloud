//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    printf("Enter a sentence: \n");
    fgets(input, 1000, stdin);

    int length = strlen(input);
    int score = 0;

    for (int i = 0; i < length; i++) {
        if (input[i] == 'h' && input[i+1] == 'a' && input[i+2] == 't' && input[i+3] == 'e')
            score -= 5;
        else if (input[i] == 'l' && input[i+1] == 'o' && input[i+2] == 'v' && input[i+3] == 'e')
            score += 5;
        else if (input[i] == 'f' && input[i+1] == 'u' && input[i+2] == 'n' && input[i+3] == 'n' && input[i+4] == 'y')
            score += 3;
        else if (input[i] == 's' && input[i+1] == 'a' && input[i+2] == 'd')
            score -= 3;
        else if (input[i] == 'h' && input[i+1] == 'a' && input[i+2] == 'p' && input[i+3] == 'p' && input[i+4] == 'y')
            score += 3;
        else if (input[i] == 'a' && input[i+1] == 'n' && input[i+2] == 'g' && input[i+3] == 'r' && input[i+4] == 'y')
            score -= 4;
    }
    
    printf("Sentiment score: %d\n", score);
    
    if (score > 0)
        printf("The sentence has a positive sentiment.\n");
    else if (score < 0)
        printf("The sentence has a negative sentiment.\n");
    else
        printf("The sentence has a neutral sentiment.\n");

    return 0;
}