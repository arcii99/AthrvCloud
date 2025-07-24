//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
// Romeo and Juliet Sentiment Analysis Tool

#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int score = 0;
    printf("Enter the text to be analyzed: ");
    scanf("%[^\n]", text);
    int len = strlen(text);
    
    for(int i=0; i<len; i++) {
        if(text[i] == 'l' || text[i] == 'L') {
            score++;
        }
        else if(text[i] == 'h' || text[i] == 'H') {
            score--;
        }
    }
    
    printf("\nScore: %d\n", score);
    
    if(score > 0) {
        printf("Oh happy dagger! This is thy sheath; there rust, and let me die.\n");
    }
    else if(score < 0) {
        printf("O, I am fortune's fool!\n");
    }
    else {
        printf("Did my heart love till now? Forswear it, sight!\n");
    }
    
    return 0;
}