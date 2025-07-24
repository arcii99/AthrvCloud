//FormAI DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include<stdio.h>
void input(char *text){
    printf("Enter the HTML code:\n");
    gets(text);
}

void beautify(char *text){
    int indent=0,index=0;
    while(text[index]!='\0'){
        if(text[index]=='<'){
            printf("\n");
            for(int i=0;i<indent;i++){
                printf("   ");
            }
            printf("%c",text[index]);
            if(text[index+1]=='/'){
                indent--;
            }else{
                indent++;
            }
        }else if(text[index]=='>'){
            printf("%c\n",text[index]);
        }else if(text[index]==';'){
            printf("%c\n",text[index]);
            for(int i=0;i<indent;i++){
                printf("   ");
            }
        }else{
            printf("%c",text[index]);
        }

        index++;
    }
}

int main(){
    char text[1000];
    input(text);
    beautify(text);
    return 0;
}