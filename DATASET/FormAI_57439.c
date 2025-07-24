//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    char resume[500], word[20];
    int count=0, i=0, j=0;
    char *words[50];

    printf("Enter your resume: \n");
    fgets(resume, 500, stdin);

    for(i=0; i<strlen(resume); i++){
        if(resume[i]==' ' || resume[i]=='\n'){
            word[j]='\0';
            words[count]=malloc(strlen(word)+1);
            strcpy(words[count], word);
            count++;
            j=0;
        }
        else{
            word[j]=resume[i];
            j++;
        }
    }

    printf("Parsed Resume: \n");

    for(i=0; i<count; i++){
        if(strcmp(words[i], "skills")==0){
            printf("Your skills are impressive!\n");
        }
        else if(strcmp(words[i], "experience")==0){
            printf("Wow, you've had quite the experience!\n");
        }
        else if(strcmp(words[i], "education")==0){
            printf("Your education is remarkable!\n");
        }
    }

    for(i=0; i<count; i++){
        free(words[i]);
    }
    return 0;
}