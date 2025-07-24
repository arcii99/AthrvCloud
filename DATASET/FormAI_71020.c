//FormAI DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include<stdio.h>
#include<string.h>

int main(){

    char log[1000];
    int num_info = 0, num_warning = 0, num_error = 0;

    printf("Enter the log: ");
    fgets(log, 1000, stdin);
    printf("\n");

    char* token = strtok(log, " ");

    while(token != NULL){

        if(strcmp(token, "INFO") == 0)
            num_info++;
        else if(strcmp(token, "WARNING") == 0)
            num_warning++;
        else if(strcmp(token, "ERROR") == 0)
            num_error++;

        token = strtok(NULL, " ");
    }

    if(num_info > num_warning && num_info > num_error)
        printf("This log contains more INFO messages.\n");
    else if(num_warning > num_info && num_warning > num_error)
        printf("This log contains more WARNING messages.\n");
    else if(num_error > num_info && num_error > num_warning)
        printf("This log contains more ERROR messages.\n");
    else
        printf("This log contains an equal number of all messages.\n");

    return 0;
}