//FormAI DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

void beautify(char *filename){
    FILE *fp;
    FILE *out;
    char c;
    int count=0;
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("Failed to open file\n");
        exit(1);
    }
    out=fopen("formatted.html","w");
    if(out==NULL){
        printf("Failed to create file\n");
        exit(1);
    }

    while((c=fgetc(fp))!=EOF){
        if(c=='<' || c=='>'){
            fputc('\n',out);
            for(int i=0;i<count;i++){
                fputc('\t',out);
            }
            if(c=='<'){
                count++;
            }
            else{
                count--;
            }
        }
        fputc(c,out);
    }

    fclose(fp);
    fclose(out);
}

int main(){
    char filename[100];
    printf("Enter the name of the HTML file:");
    scanf("%s",filename);
    beautify(filename);
    printf("File successfully beautified!");
    return 0;
}