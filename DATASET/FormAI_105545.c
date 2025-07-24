//FormAI DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main(){
    char message[MAX_LEN];
    int i, j, len;
    int count = 0;

    printf("Enter your message: ");
    fgets(message, MAX_LEN, stdin);

    len = strlen(message);

    for(i=0; i<len; i++){
        if(message[i] == 'c' || message[i] == 'C'){
            for(j=i+1; j<i+4; j++){
                if(message[j] == 'a' || message[j] == 'A'){
                    for(int k=j+1; k<j+5; k++){
                        if(message[k] == 's' || message[k] == 'S'){
                            for(int l=k+1; l<k+5; l++){
                                if(message[l] == 'h' || message[l] == 'H'){
                                    count++;
                                    i = l;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }

    if(count > 0){
        printf("The message contains %d instances of the word 'cash'. This is likely spam.\n", count);
    }else{
        printf("The message does not contain the word 'cash'. It is not spam.\n");
    }

    return 0;
}