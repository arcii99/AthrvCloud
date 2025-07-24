//FormAI DATASET v1.0 Category: Log analysis ; Style: automated
#include<stdio.h>

/* Function to calculate the occurrence of a character in a string */
int char_occurrence(char* str, char ch){
    int count=0;
    for(int i=0;str[i]!='\0';i++)
        if(str[i]==ch)
            count++;
    return count;
}

int main(){
    FILE *file;
    char log_entry[100];
    char error_type[20] = "ERROR";
    char warn_type[20] = "WARNING";
    int error_count = 0;
    int warn_count = 0;
    
    file = fopen("logfile.txt", "r");
    
    if(file == NULL){
        printf("File not found!\n");
        return 0;
    }
    
    printf("LOG ANALYSIS PROGRAM\n\n");
    
    while(fgets(log_entry, 100, file) != NULL){
        if(char_occurrence(log_entry, '(') >= 3){
            if(char_occurrence(log_entry, error_type[0]) == 5 && char_occurrence(log_entry, error_type[1]) == 2){
                error_count++;
            }else if(char_occurrence(log_entry, warn_type[0]) == 7 && char_occurrence(log_entry, warn_type[1]) == 4){
                warn_count++;
            }           
        }
    }
    
    printf("Total number of errors: %d\n", error_count);
    printf("Total number of warnings: %d\n", warn_count);
    
    fclose(file);
    return 0;
}