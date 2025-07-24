//FormAI DATASET v1.0 Category: Text Summarizer ; Style: post-apocalyptic
#include<stdio.h>
#include<string.h>

char* summarizer(char* text){
    int len = strlen(text), i, j, k;
    char summary[1000] = {'\0'};
    for(i=0; i<len; i++){
        if(text[i] == '.' || text[i] == '\n'){
            for(j=i+1; text[j] == ' ' || text[j] == '\n'; j++);
            if(i<999){
                strncat(summary,&text[k],j-k);
                strcat(summary," ");
            }
            k=j;
            i=j;
        }
        if(summary[strlen(summary)-2] == '.' && summary[strlen(summary)-1] == ' '){
            summary[strlen(summary)-2] = '.';
            summary[strlen(summary)-1] = '\n';
        }
    }
    return summary;
}

int main(){
    char text[] = "It was the end of the world as we knew it. The sky was hazy with smoke, and the ground was littered with debris. The survivors were few and far between, and it was hard to trust anyone. However, in the midst of all the destruction, there was a glimmer of hope. Scientists had discovered a way to purify water using a combination of chemicals and energy. This newfound technology meant that we could survive for a little while longer. It wasn't much, but it was enough to keep us going. We still had a long way to go, but at least there was a light at the end of the tunnel.";
    char *summary = summarizer(text);
    printf("%s\n",summary);
    return 0;
}