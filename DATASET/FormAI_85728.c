//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: sophisticated
#include<stdio.h>
#include<string.h>

int main(){
    char fileName[20];
    int i, len;
    char ext[6];
    printf("Enter file name: ");
    scanf("%s", fileName);
    len = strlen(fileName);

    // Extract file extension
    for(i=len-1;i>=0;i--){
        if(fileName[i] == '.'){
            strncpy(ext, fileName+i+1, 5);
            break;
        }
    }
    ext[5] = '\0';

    // Compare extension with known virus extensions
    if(strcmp(ext, "exe")==0 || strcmp(ext, "bat")==0 || strcmp(ext, "vbs")==0){
        printf("The file '%s' is a virus.\n", fileName);
    }
    else{
        printf("The file '%s' is not a virus.\n", fileName);
    }

    return 0;
}