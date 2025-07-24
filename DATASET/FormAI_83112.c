//FormAI DATASET v1.0 Category: Spam Detection System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    char message[100];
    int i, j = 0, count = 0, content_count = 0;
    char *spam[5] = {"Buy", "Cheap", "Viagra", "Free", "Win"};
    char *content[5] = {"Congratulations", "Sale", "Deal", "Special", "Discount"};
    int spam_count[5] = {0};
    int content_len[5] = {0};
 
    printf("Enter a message: ");
    fgets(message, 100, stdin);
 
    for (i = 0; i < 5; i++){
        if (strstr(message, spam[i]) != NULL){
            spam_count[i]++;
        }
        if (strstr(message, content[i]) != NULL){
            content_len[i] = strlen(content[i]);
            content_count++;
        }
    }
 
    if (content_count > 1){
        printf("Warning: Multiple content keywords detected.\n");
    }
 
    for (i = 0; i < 5; i++){
        if (spam_count[i] > 0){
            printf("Detected keyword: %s\n", spam[i]);
            count++;
        }
    }
 
    for (i = 0; i < 5; i++){
        if (content_len[i] > 0){
            if (strstr(message, content[i] + content_len[i]) != NULL){
                printf("Detected keyword: %s\n", content[i]);
                count++;
            }
        }
    }
 
    if (count > 0){
        printf("Potential spam detected. Enter 1 to mark as spam: ");
        scanf("%d", &j);
        if (j == 1){
            printf("Message marked as spam.\n");
        }else{
            printf("Message not marked as spam.\n");
        }
    }else{
        printf("No spam detected.\n");
    }
 
    return 0;
}