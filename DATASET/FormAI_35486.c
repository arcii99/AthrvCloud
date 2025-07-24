//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//function to calculate the term frequency of each word
void termFrequency(int tf[], char text[][100], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<strlen(text[i]);j++){
            if(isalpha(text[i][j])){
                tf[i]++;
            }
        }
        tf[i] /= strlen(text[i]); //normalize
    }
}

//function to calculate inverse document frequency of each word
void inverseDocumentFrequency(int idf[], char text[][100], int n, char keywords[][100], int numKeywords){
    int i,j;
    float cnt;
    for(i=0;i<numKeywords;i++){
        cnt = 0;
        for(j=0;j<n;j++){
            if(strstr(text[j],keywords[i])){
                cnt++;
            }
        }
        idf[i] = log10(n/cnt);
    }
}

int main(){
    //inputs
    char text[5][100] = {"The world is a dark and dangerous place","The corporations control everything","The hackers are the only ones who can fight back","The government is corrupt","Cybernetic implants are the latest trend"};
    char keywords[3][100] = {"hackers","government","cybernetic"};

    //variables
    int n = 5; //number of sentences
    int numKeywords = 3;
    int tf[5] = {0}; //term frequency of each sentence
    int idf[3] = {0}; //inverse document frequency of each keyword

    //calculate tf and idf
    termFrequency(tf, text, n);
    inverseDocumentFrequency(idf, text, n, keywords, numKeywords);

    //calculate tf-idf of each sentence
    float tfIdf[5] = {0};
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<numKeywords;j++){
            if(strstr(text[i],keywords[j])){
                tfIdf[i] += tf[i]*idf[j];
            }
        }
    }

    //sort sentences by tf-idf score
    int index[5];
    for(i=0;i<n;i++){
        index[i]=i;
    }
    int temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(tfIdf[index[i]]<tfIdf[index[j]]){
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    //print summary
    printf("The cyberpunk world is a dangerous place. ");
    for(i=0;i<2;i++){
        printf("%s. ", text[index[i]]);
    }
    printf("The trend of cybernetic implants is on the rise. ");

    return 0;
}