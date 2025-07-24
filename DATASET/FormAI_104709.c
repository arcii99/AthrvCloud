//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char user_input[100];
    printf("\nEnter your text:\n");
    fgets(user_input,sizeof(user_input),stdin);

    //Removing punctuations from the user input
    for(int i=0;i<strlen(user_input);i++){
        if(ispunct(user_input[i])){
            user_input[i]=' ';
        }
    }

    //Storing words in an array
    char *words[50];
    char *token=strtok(user_input," ");
    int i=0;
    while(token!=NULL){
        words[i++]=token;
        token=strtok(NULL," ");
    }

    //Assigning polarity values to each word
    int polarity_values[i];
    memset(polarity_values,0,sizeof(polarity_values));
    for(int j=0;j<i;j++){
        char word[20];
        strcpy(word,words[j]);
        if(strcmp(word,"cyberpunk")==0){
            polarity_values[j]+=5;
        }
        else if(strcmp(word,"dystopia")==0 || strcmp(word,"dark")==0 || strcmp(word,"doom")==0){
            polarity_values[j]+=4;
        }
        else if(strcmp(word,"technology")==0 || strcmp(word,"future")==0 || strcmp(word,"neon")==0){
            polarity_values[j]+=3;
        }
        else if(strcmp(word,"rebellion")==0 || strcmp(word,"revolution")==0){
            polarity_values[j]+=2;
        }
        else if(strcmp(word,"optimism")==0 || strcmp(word,"utopian")==0 || strcmp(word,"bright")==0){
            polarity_values[j]+=1;
        }
    }

    //Calculating overall polarity value of the text
    int sum=0;
    for(int j=0;j<i;j++){
        sum+=polarity_values[j];
    }

    printf("\n");
    if(sum>20){
        printf("This text is highly cyberpunk!\n");
    }
    else if(sum>10){
        printf("This text is cyberpunk.\n");
    }
    else{
        printf("This text is not very cyberpunk-ish.\n");
    }

    return 0;
}