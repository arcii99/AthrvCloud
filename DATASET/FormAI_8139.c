//FormAI DATASET v1.0 Category: Text Summarizer ; Style: active
#include<stdio.h>
#include<string.h>

//Function to remove unwanted characters from the text
void removeSpecialChars(char *text){
    int i,j=0;

    for(i=0;text[i]!='\0';i++){
        if((text[i]>='a'&&text[i]<='z')||(text[i]>='A'&&text[i]<='Z')||(text[i]==' ')){
            text[j++]=text[i];
        }
    }
    text[j]='\0';
}

//Function to calculate the frequency of each word in the text
void calcWordFreq(char *text){
    char temp[100];
    int freq[100]={0};
    int i,j=0,k,len=strlen(text);

    for(i=0;i<=len;i++){
        if(text[i]!=' '&&text[i]!='\0'){
            temp[j++]=text[i];
        }else{
            temp[j]='\0';
            j=0;
            k=0;

            while(freq[k]!=0){
                if(strcmp(temp,&text[freq[k]])==0){
                    freq[k+1]++;
                    break;
                }
                k+=2;
            }
            if(freq[k]==0){
                freq[k]=i-strlen(temp);
                freq[k+1]=1;
            }
        }
    }

    //Displaying the frequency of each word
    printf("Word\t\tFrequency\n");
    for(i=0;freq[i]!=0;i+=2){
        printf("%s\t\t%d\n",&text[freq[i]],freq[i+1]);
    }
}

//Main function
int main(){
    char text[1000];
    printf("Enter the text to summarize: ");
    fgets(text,1000,stdin);

    removeSpecialChars(text); //Remove unwanted characters from text
    calcWordFreq(text); //Calculate the frequency of each word in the text
    
    return 0;
}