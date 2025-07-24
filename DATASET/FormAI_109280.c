//FormAI DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <errno.h>

void handleError(int errorno){
    switch(errorno){
        case EACCES:
            printf("Error: Permission denied.\n");
            break;
        case ENOENT:
            printf("Error: File not found.\n");
            break;
        case EINVAL:
            printf("Error: Invalid argument.\n");
            break;
        default:
            printf("Unknown error occurred.\n");
    }
}

int main(){
    FILE *fptr;
    char filename[20];
    int num;

    printf("Enter the name of the file: \n");
    scanf("%s", filename);

    fptr = fopen(filename, "r");
    if(fptr == NULL){
        handleError(errno);
        return 1;
    }

    printf("Enter an integer: \n");
    scanf("%d", &num);

    if(num < 0){
        handleError(EINVAL);
        fclose(fptr);
        return 1;
    }

    // Do something with num and the file

    fclose(fptr);
    return 0;
}