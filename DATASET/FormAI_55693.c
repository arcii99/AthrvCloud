//FormAI DATASET v1.0 Category: Text Summarizer ; Style: romantic
#include<stdio.h>
#include<string.h>
#define MAX_LEN 1000
void removeExtraSpaces(char* s)
{
    int i,j;
    for (i = j = 0; s[i]; i++)
        if (s[i] != ' ' || (i > 0 && s[i - 1] != ' '))
            s[j++] = s[i];
    s[j] = '\0';
}
void summarizer(char *s){
    char *ptr;
    int count=0;
    ptr = strtok(s," ");
    while(ptr != NULL){
        count++;
        ptr = strtok(NULL," ");
    }
    if(count>=75){
        char res[MAX_LEN] = "";
        for(int j=1;j<5;j++){
            char *ptr;
            ptr = strtok(s,".");
            strcat(res,"\"");
            strcat(res, ptr);
            strcat(res,".\"");
            strcat(res,"\n");
        }
        printf("%s", res);
    }
    else{
        printf("The text is not long enough.\n");
    }
}
int main(){
    char s[MAX_LEN];
    printf("Write your text:\n");
    fgets(s, MAX_LEN, stdin);
    removeExtraSpaces(s);
    summarizer(s);
    return 0;
}