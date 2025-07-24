//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include<stdio.h>
#include<string.h>

void spamDetection(char* message){
    char spamWords[10][20] = {"viagra", "free money", "lottery", "prince", "inheritance", "cheap", "deal", "click here", "limited time", "act now"};
    int i,j,spamCount=0;
    char temp[1000],temp2[1000];
    strcpy(temp,message);
    for(i=0;i<strlen(temp);i++){
        if(temp[i]==',' || temp[i]=='.' || temp[i]==' '){
            temp[i]='\0';
        }
    }
    for(i=0;i<10;i++){
        strcpy(temp2,temp);
        for(j=0;j<strlen(temp2);j++){
            temp2[j]=tolower(temp2[j]);
        }
        if(strstr(temp2,spamWords[i])!=NULL){
            spamCount++;
        }
    }
    if(spamCount>0){
        printf("This message contains %d spam words.\n\n",spamCount);
    }
    else{
        printf("This message is not a spam.\n\n");
    }
}

int main(){
    char message[1000];
    printf("Enter the message to check for spam:\n");
    fgets(message,sizeof(message),stdin);
    spamDetection(message);
    return 0;
}