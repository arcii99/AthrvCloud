//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 100

int main(){

    char str1[MAX_LENGTH],str2[MAX_LENGTH],str3[MAX_LENGTH];
    int choice,length,difference,index;
    printf("Enter the first string: ");
    fgets(str1,MAX_LENGTH,stdin);
    str1[strcspn(str1,"\n")]='\0';
 
    printf("Enter the second string: ");
    fgets(str2,MAX_LENGTH,stdin);
    str2[strcspn(str2,"\n")]='\0';

    printf("Enter a choice from below:\n1. Length of String\n2. Concatenate String.\n3. Compare two strings.\n");
    printf("4. Copy a String.\n5. Reverse a String.\n6. Find the substring.\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            length=strlen(str1);
            printf("Length of %s is %d",str1,length);
            break;
        case 2:
            strcat(str1,str2);
            printf("Concatenated string is %s",str1);
            break;
        case 3:
            difference=strcmp(str1,str2);
            if(difference==0){
                printf("%s and %s are equal strings.",str1,str2);
            }
            else{
                printf("%s and %s are not equal strings.",str1,str2);
            }
            break;
        case 4:
            strcpy(str3,str1);
            printf("Copied string is %s",str3);
            break;
        case 5:
            length=strlen(str1);
            for(index=length-1;index>=0;index--){
                printf("%c",str1[index]);
            }
            break;
        case 6:
            char *substr;
            substr=strstr(str1,str2);
            if(substr){
                printf("Substring (%s) found at index %d.",str2,substr-str1);
            }
            else{
                printf("Substring not found!");
            }
            break;
        default:
            printf("Invalid Input!");
    }

    return 0;
}