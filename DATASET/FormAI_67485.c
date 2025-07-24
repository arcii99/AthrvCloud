//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    printf("Welcome to the Cyberpunk Typing Speed Test!\n\n");
    printf("Instructions:\nType the partially obscured word shown on the screen before time runs out to score points.\nYou have 1 second per word.\n\n");
    
    int score = 0;
    time_t start_time, curr_time;
    srand(time(NULL));
    
    while (1)
    {
        int random_num = rand() % 10;
        char obscured_word[10][8] = {"c@nt¥", "b(_*ke", "h4x0r", "d^ckT", "r@&idE", "t#e@d0w", "m0ds", "n3tRun3r", "r3n#g@d3", "ch1pp¥"};
        int word_len = strlen(obscured_word[random_num]);
        
        // Obscure the word by randomly replacing some characters with underscores
        int num_underscores = rand() % (word_len - 1); // always leave the last letter visible
        int underscore_pos[word_len];
        for (int i = 0; i < num_underscores; i++)
        {
            int pos = rand() % word_len;
            while (pos == word_len - 1 || strchr(underscore_pos, pos) != NULL)
            {
                pos = rand() % word_len;
            }
            underscore_pos[i] = pos;
            obscured_word[random_num][pos] = '_';
        }
        
        printf("%s\n\n", obscured_word[random_num]);
        
        start_time = time(NULL);
        char input[word_len];
        fgets(input, word_len, stdin);
        
        curr_time = time(NULL);
        double diff = difftime(curr_time, start_time);
        if (diff >= 1)
        {
            printf("Time ran out!\n");
            break;
        }
        else if (strncmp(input, obscured_word[random_num], word_len - 1) == 0 && isalpha(input[word_len - 1]))
        {
            score++;
            printf("Correct! Score: %d\n\n", score);
        }
        else
        {
            printf("Incorrect.\n\n");
        }
    }
    
    printf("Your final score is %d.\n", score);
    
    return 0;
}