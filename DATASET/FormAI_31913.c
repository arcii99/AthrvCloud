//FormAI DATASET v1.0 Category: Error handling ; Style: Ken Thompson
#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(){
    char str[50];
    FILE *fp;
    int errnoSave,temp;

    printf("Enter file name :");
    scanf("%s",str);
    
    fp=fopen(str,"r");
    if(fp==NULL){
        errnoSave=errno;
        fprintf(stderr,"Error opening file %s : %s\n",str,strerror(errnoSave));
        printf("Do you want to create the file? (Yes=1, No=0): ");
        scanf("%d",&temp);
        if(temp==1){
            fp=fopen(str,"w");
            if(fp==NULL){
                errnoSave=errno;
                fprintf(stderr,"Error creating file %s : %s\n",str,strerror(errnoSave));
                return errnoSave;
            }
            else{
                printf("File created successfully\n");
                return 0;
            }
        }
        else{
            return errnoSave;
        }
    }
    else{
        printf("File exists. Closing the file\n");
        fclose(fp);
        return 0;
    }
}