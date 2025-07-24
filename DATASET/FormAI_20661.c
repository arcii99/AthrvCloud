//FormAI DATASET v1.0 Category: Word Count Tool ; Style: creative
#include<stdio.h>
#include<string.h>

int countWord(char str[],char word[]){
    int i,j,count=0,flag;

    int n=strlen(str);
    int m=strlen(word);

    for(i=0;i<=n-m;i++){
        flag=1;
        for(j=0;j<m;j++){
            if(str[i+j]!=word[j]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            count++;
        }
    }
    return count;
}

int main(){
    char str[100],word[20];
    printf("Enter a string: ");
    gets(str);

    printf("Enter a word to count: ");
    scanf("%s",word);

    int cnt=countWord(str,word);

    printf("The total occurrence of %s in %s is: %d\n",word,str,cnt);

    return 0;
}