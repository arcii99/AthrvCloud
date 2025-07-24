//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>

// Function to scan file for virus
void scan(char *filename){
    FILE *fp;
    char buffer[1024];
    char virus[] = "virus signature";
    int infected = 0;
    
    fp = fopen(filename, "r");
    
    while(fgets(buffer, sizeof(buffer), fp)){
        // Check if buffer contains virus signature
        if(strstr(buffer, virus)){
            printf("%s infected with virus!\n", filename);
            infected = 1;
            break;
        }
    }
    
    if(!infected){
        printf("%s is clean!\n", filename);
    }
    
    fclose(fp);
}

int main(){
    char filename[256];
    printf("Enter filename to scan: ");
    scanf("%s", filename);
    
    scan(filename);
    
    return 0;
}