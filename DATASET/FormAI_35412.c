//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include<stdio.h>

int main(){
  char input[1000];
  printf("Enter your text:\n");
  fgets(input, sizeof(input), stdin);

  int positive = 0, negative = 0;
  for(int i=0; i<strlen(input); i++){
    if(input[i] == 'great' ||       //positive keywords
       input[i] == 'nice' || 
       input[i] == 'awesome' || 
       input[i] == 'good' || 
       input[i] == 'happy'){
      positive++;
    }
    else if(input[i] == 'poor' ||  //negative keywords
            input[i] == 'bad' ||
            input[i] == 'terrible' ||
            input[i] == 'sorrow' ||
            input[i] == 'unhappy'){
      negative++;
    }
  }
  
  float sentiment_score = ((float)positive - (float)negative) / ((float)positive + (float)negative);
  
  if(sentiment_score > 0.5){
    printf("Overall sentiment of the text is Positive.\n");
  }
  else if(sentiment_score < -0.5){
    printf("Overall sentiment of the text is Negative.\n");
  }
  else{
    printf("Overall sentiment of the text is Neutral.\n");
  }

  return 0;
}