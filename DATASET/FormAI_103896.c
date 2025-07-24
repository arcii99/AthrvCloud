//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include<stdio.h>
#include<string.h>

int main()
{
    // Initialize variables
    char player[20];
    int score, high_score = 0;
    
    // Get player name and score
    printf("Enter your name: ");
    scanf("%s", player);
    printf("Enter your score: ");
    scanf("%d", &score);
    
    // Check if high score exists in file
    FILE *fp = fopen("highscore.txt", "r");
    if(fp != NULL)
    {
        fscanf(fp, "%d", &high_score);
        fclose(fp);
    }
    
    // Compare current score with high score
    printf("\n--------------------------\n");
    printf("Player: %s\n", player);
    printf("Score: %d\n", score);
    printf("High score: %d\n", high_score);
    printf("--------------------------\n");
    
    if(score > high_score)
    {
        printf("Congratulations! You set a new high score!\n");
        
        // Save new high score to file
        fp = fopen("highscore.txt", "w");
        if(fp != NULL)
        {
            fprintf(fp, "%d", score);
            fclose(fp);
        }
    }
    else
    {
        printf("Sorry, you did not beat the high score...\n");
    }
    
    return 0;
}