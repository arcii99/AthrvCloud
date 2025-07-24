//FormAI DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

int main(){
    char ch,prev_ch;
    int indent=0;
    FILE *fp1, *fp2;
    fp1=fopen("input.html","r");
    fp2=fopen("output.html","w");
    if(fp1 == NULL || fp2 == NULL){
        printf("Error opening files");
        exit(1);
    }
    while((ch=fgetc(fp1))!=EOF){
        if(ch=='<' && prev_ch!='/'){
            indent+=4;
            fprintf(fp2,"\n%*s%c",indent,"",ch);
        }
        else if(ch=='>' && prev_ch!='/'){
            fprintf(fp2,"%c\n%*s",ch,indent,"");
        }
        else{
            fprintf(fp2,"%c",ch);
        }
        prev_ch=ch;
    }
    fclose(fp1);
    fclose(fp2);
    printf("HTML Beautifier successful!");
    return 0;
}