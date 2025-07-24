//FormAI DATASET v1.0 Category: Ebook reader ; Style: real-life
#include<stdio.h>
#include<string.h>

int main(){
    char bookList[5][50] = {"C Programming", "Java For Beginners", "Python Made Easy", "Data Structures & Algorithms", "Operating Systems"};
    int bookNo, option;
    
    printf("****Ebook Reader****\n\n");
    
    while(1){
        printf("Choose an Ebook to read:\n");
        for(int i = 0; i < 5; i++){
            printf("%d. %s\n", i+1, bookList[i]);
        }
        
        printf("Enter the book number (Press 0 to exit): ");
        scanf("%d", &bookNo);
        
        if(bookNo == 0){
            printf("Thank you for using Ebook Reader!");
            break;
        }
        
        FILE *fp;
        char fileName[50];
        
        switch(bookNo){
            case 1:
                strcpy(fileName, "CProgramming.txt");
                break;
            case 2:
                strcpy(fileName, "JavaForBeginners.txt");
                break;
            case 3:
                strcpy(fileName, "PythonMadeEasy.txt");
                break;
            case 4:
                strcpy(fileName, "DatastructuresAndAlgorithms.txt");
                break;
            case 5:
                strcpy(fileName, "OperatingSystems.txt");
                break;
            default:
                printf("Invalid book number.\n");
                continue;
        }
        
        fp = fopen(fileName, "r");
        if(fp == NULL){
            printf("Error opening file.\n");
            continue;
        }
        
        printf("\n****Book Preview****\n\n");
        char line[100];
        while(fgets(line, 100, fp) != NULL){
            printf("%s", line);
        }
        printf("\n");
        
        fclose(fp);
        
        while(1){
            printf("Do you want to read the full book? (1: Yes / 2: No): ");
            scanf("%d", &option);
            
            if(option == 1){
                fp = fopen(fileName, "r");
                printf("\n****Book Contents****\n\n");
                while(fgets(line, 100, fp) != NULL){
                    printf("%s", line);
                }
                printf("\n");
                fclose(fp);
                break;
            } else if(option == 2){
                break;
            } else {
                printf("Invalid option.\n");
            }
        }
    }
    
    return 0;
}