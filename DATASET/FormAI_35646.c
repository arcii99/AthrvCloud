//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: peaceful
#include<stdio.h>
#include<string.h>

// Function to translate the C Cat Language 
void translateCcat(char sentence[]){
    int len = strlen(sentence);
    for(int i=0; i<len; i++){
        if(sentence[i] == 'm'){
            if(i < len-1 && sentence[i+1] == 'e'){
                printf("you ");
                i++;
            }
            else{
                printf("pur ");
            }
        }
        else if(sentence[i] == 'w'){
            if(i < len-2 && sentence[i+1] == 'o' && sentence[i+2] == 'o'){
                printf("meow ");
                i+=2;
            }
            else{
                printf("purr ");
            }
        }
        else if(sentence[i] == 'h'){
            if(i < len-2 && sentence[i+1] == 'i' && sentence[i+2] == 's'){
                printf("my ");
                i+=2;
            }
            else{
                printf("mew ");
            }
        }
        else if(sentence[i] == 'b'){
            printf("paw ");
        }
        else if(sentence[i] == 'c'){
            printf("tail ");
        }
        else if(sentence[i] == 'f'){
            printf("fish ");
        }
        else if(sentence[i] == 't'){
            printf("tuna ");
        }
        else{
            printf("%c", sentence[i]);
        }
    }
}

// Driver function
int main(){
    char sentence[100];
    printf("Enter a sentence in C Cat Language: ");
    fgets(sentence, 100, stdin);
    printf("Translated sentence: ");
    translateCcat(sentence);
    return 0;
}