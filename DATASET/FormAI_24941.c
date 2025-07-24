//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include<stdio.h>
#include<string.h>

// Function to change all characters of the string to lower case
void toLowerCase(char *s) {
    int i;
    for(i=0;i<strlen(s);i++) {
        if(s[i]>='A' && s[i]<='Z')
            s[i] = s[i] + 32;
    }
}

// Function to check if a word is present in the given string
int findWord(char *s, char *word) {
    int i,j,flag=0;
    for(i=0;i<strlen(s)-strlen(word)+1;i++) {
        for(j=0;j<strlen(word);j++) {
            if(*(s+i+j)!=*(word+j)) {
                break;
            }
        }
        if(j==strlen(word)) {
            flag = 1;
            break;
        }
    }
    return flag;
}

// Function to remove punctuation marks from the string
void removePunctuations(char *s) {
    int i=0,j=0;
    while(s[i]) {
        if(ispunct(s[i])) {
            i++;
        }
        else {
            s[j++] = s[i++];
        }
    }
    s[j] = '\0';
}

// Function to perform sentiment analysis
void sentimentAnalysis(char *s) {
    char positiveWords[10][20] = {"happy","awesome","nice","great","good","excellent","amazing","fantastic","superb","wonderful"};
    char negativeWords[10][20] = {"sad","awful","bad","terrible","poor","unhappy","disappointing","pathetic","horrible","miserable"};
    char *token;
    int positiveCount=0,negativeCount=0;
    float sentimentScore;

    // Change all characters of string to lower case
    toLowerCase(s);

    // Remove punctuation marks from the string
    removePunctuations(s);

    // Calculate the number of positive and negative words in the string
    token = strtok(s," ");
    while(token!=NULL) {
        if(findWord(positiveWords,token)) {
            positiveCount++;
        }
        else if(findWord(negativeWords,token)) {
            negativeCount++;
        }
        token = strtok(NULL," ");
    }

    // Calculate the sentiment score
    sentimentScore = (float)(positiveCount-negativeCount)/(positiveCount+negativeCount);

    // Display the sentiment score
    printf("Sentiment Score: %f\n",sentimentScore);
}

int main() {
    char inputString[100];

    // Take input string from user
    printf("Enter a string: ");
    fgets(inputString,sizeof(inputString),stdin);
    inputString[strcspn(inputString,"\n")] = 0;

    // Perform sentiment analysis on the input string
    sentimentAnalysis(inputString);

    return 0;
}