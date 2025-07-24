//FormAI DATASET v1.0 Category: String manipulation ; Style: interoperable
#include<stdio.h>
#include<string.h>

int main(){
    char str1[100], str2[100], temp[100];
    int i, j, k, choice, len1, len2;

    printf("Enter two strings: ");
    scanf("%s %s",str1, str2);

    printf("Select an option:\n1. Concatenate\n2. Swap\n3. Compare\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            strcat(str1,str2);
            printf("Concatenated string is: %s",str1);
            break;
        case 2:
            strcpy(temp,str1);
            strcpy(str1,str2);
            strcpy(str2,temp);
            printf("Swapped strings are: %s %s",str1, str2);
            break;
        case 3:
            len1 = strlen(str1);
            len2 = strlen(str2);
            if(len1 != len2){
                printf("Strings are not equal");
                break;
            }
            for(i=0; i<len1; i++){
                if(str1[i] != str2[i]){
                    printf("Strings are not equal");
                    return 0;
                }
            }
            printf("Strings are equal");
            break;
        default:
            printf("Please select a valid option");
    }

    return 0;
}