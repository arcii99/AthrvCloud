//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char sentence[100];
    int positive = 0, negative = 0, neutral = 0, count = 0;
    printf("My dear Romeo, enter a sentence for sentiment analysis: ");
    fgets(sentence, 100, stdin); 

    for(int i=0; i<strlen(sentence); i++){
        if(isalpha(sentence[i])){
            count++;
        }
    }
    for(int i=0; i<strlen(sentence); i++){
        if(isalpha(sentence[i])){
            char word[20];
            int j = 0;
            while(isalpha(sentence[i])){
                word[j] = sentence[i];
                j++;
                i++;
            }
            word[j] = '\0';

            if(strcmp(word, "love") == 0 || strcmp(word, "passion") == 0 || strcmp(word, "kiss") == 0 || strcmp(word, "dream") == 0){
                positive++;
            }
            else if(strcmp(word, "hate") == 0 || strcmp(word, "jealousy") == 0 || strcmp(word, "pain") == 0 || strcmp(word, "betrayal") == 0){
                negative++;
            }
            else{
                neutral++;
            }
        }
    }

    float positive_percent = (float)positive/count*100;
    float negative_percent = (float)negative/count*100;
    float neutral_percent = (float)neutral/count*100;

    printf("My sweet Romeo, upon analysis, I confess the following:\n");
    printf("Positive Sentiment: %.2f%%\n", positive_percent);
    printf("Negative Sentiment: %.2f%%\n", negative_percent);
    printf("Neutral Sentiment: %.2f%%\n", neutral_percent);

    printf("If these results are unsatisfactory to thee, please adjust thy words accordingly.\n");
    return 0;
}