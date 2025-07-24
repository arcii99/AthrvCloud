//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Welcome to the Silly CSV Reader!\n");
    printf("Please enter the file name: ");
    char fileName[100];
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "r");
    if(!fp){
        printf("Oops, couldn't open the file!\n");
        return 0;
    }

    char data[100];
    int rowCounter = 0;
    int colCounter = 0;
    while(fgets(data, 100, fp) != NULL){
        rowCounter++;
        colCounter = 0;
        printf("\n");
        printf("Row %d: ", rowCounter);

        for(int i = 0; data[i] != '\0'; i++){
            if(data[i] == ','){
                printf("\n");
                printf("Column %d: ", colCounter+1);
                colCounter++;
            }
            else{
                printf("%c", data[i]);
            }
        }
    }
    fclose(fp);
    printf("\n\n\nCSV read complete! P.S. Honestly, I never was very good at counting...\n");
    return 0;
}