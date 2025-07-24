//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ada Lovelace
/*PROGRAM NAME: SENTIMENT ANALYSIS TOOL*/
/*CREATED BY: ADA LOVELACE*/

#include<stdio.h>
#include<string.h>

/*Declaring function to count positive words*/
int positive_count(char *text){

    char positive_words[5][10]={"happy","love","excited","great","wonderful"};
    int count=0, i=0, j=0;
    char word[10];

    while(text[i] != '\0'){     //Run loop until end of the text
        if(isalnum(text[i])){   //Checks if the character is letter or number
            word[j++] = tolower(text[i]);  //Adds the character to a word
        }
        else if(word[0] != '\0'){   //Checks if the word is not empty
            word[j] = '\0';         //Ends the word with null character
            for(int k=0; k<5; k++){  //Compares the word with the positive words list
                if(strcmp(word, positive_words[k])==0){
                    count += 1;      //Increases the count for each positive word found
                    break;
                }
            }
            j=0;           //Resets the word to empty
            word[0]='\0';
        }
        i++;
    }
    return count;           //Returns the positive words count
}

/*Declaring function to count negative words*/
int negative_count(char *text){

    char negative_words[5][10]={"sad","angry","hate","upset","frustrated"};
    int count=0, i=0, j=0;
    char word[10];

    while(text[i] != '\0'){     //Run loop until end of the text
        if(isalnum(text[i])){   //Checks if the character is letter or number
            word[j++] = tolower(text[i]);  //Adds the character to a word
        }
        else if(word[0] != '\0'){   //Checks if the word is not empty
            word[j] = '\0';         //Ends the word with null character
            for(int k=0; k<5; k++){  //Compares the word with the negative words list
                if(strcmp(word, negative_words[k])==0){
                    count += 1;      //Increases the count for each negative word found
                    break;
                }
            }
            j=0;           //Resets the word to empty
            word[0]='\0';
        }
        i++;
    }
    return count;           //Returns the negative words count
}

/*Main function*/
int main(){

    char text[1000];
    int pos_count, neg_count;

    printf("ENTER YOUR TEXT HERE: ");
    fgets(text, 1000, stdin);   //Reads input from user

    pos_count = positive_count(text);   //Calculates positive words count
    neg_count = negative_count(text);   //Calculates negative words count

    printf("POSITIVE WORDS COUNT: %d\n", pos_count);
    printf("NEGATIVE WORDS COUNT: %d\n", neg_count);

    if(pos_count > neg_count){
        printf("SENTIMENT: POSITIVE\n");
    }
    else if(neg_count > pos_count){
        printf("SENTIMENT: NEGATIVE\n");
    }
    else{
        printf("SENTIMENT: NEUTRAL\n");
    }

    return 0;
}