//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sentiment{
    int positive;
    int negative;
    int neutral;
};

struct sentiment analyze(char *text);

int main(){
    char text[1000];
    printf("Enter a statement:\n");
    fgets(text, 1000, stdin);
    struct sentiment result = analyze(text);
    
    printf("Positive: %d\nNegative: %d\nNeutral: %d\n", result.positive, result.negative, result.neutral);
    return 0;
}

struct sentiment analyze(char *text){
    struct sentiment result;
    result.positive = 0;
    result.negative = 0;
    result.neutral = 0;
    
    char *positive[10] = {"good", "great", "awesome", "excellent", "fantastic", "amazing", "superb", "perfect", "happy", "joyful"};
    char *negative[10] = {"bad", "terrible", "horrible", "awful", "disappointing", "depressing", "disgusting", "hate", "angry", "sad"};
    char *temp;
    
    temp = strtok(text, " ,.-\n");
    while(temp != NULL){
        for(int i=0; i<10; i++){
            if(strcmp(temp, positive[i]) == 0){
                result.positive++;
                break;
            }
            if(strcmp(temp, negative[i]) == 0){
                result.negative++;
                break;
            }
        }
        if(result.positive==0 && result.negative==0){
            result.neutral++;
        }
        temp = strtok(NULL, " ,.-\n");
    }
    return result;
}