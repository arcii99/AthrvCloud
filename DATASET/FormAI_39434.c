//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main(){
    char sentence[1000];
    int positiveCount = 0, negativeCount = 0;
    
    printf("Enter a sentence:\n");
    fgets(sentence, 1000, stdin);
    
    char* token = strtok(sentence, " ");
    
    while(token != NULL){
        if(strncasecmp(token, "good", 4) == 0 || strncasecmp(token, "great", 5) == 0 || strncasecmp(token, "awesome", 7) == 0 || strncasecmp(token, "excellent", 9) == 0){
            positiveCount++;
        }
        else if(strncasecmp(token, "bad", 3) == 0 || strncasecmp(token, "terrible", 8) == 0 || strncasecmp(token, "horrible", 8) == 0 || strncasecmp(token, "awful", 5) == 0){
            negativeCount++;
        }
        token = strtok(NULL, " ");
    }
    
    if(positiveCount > negativeCount){
        printf("Positive sentence\n");
    }
    else if(negativeCount > positiveCount){
        printf("Negative sentence\n");
    }
    else{
        printf("Neutral sentence\n");
    }
    
    return 0;
}