//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: active
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int length, num_count = 0, alpha_count = 0, special_count = 0;
    
    printf("Enter password: ");
    scanf("%s", password);
    
    length = strlen(password);
    
    for(int i = 0; i < length; i++){
        if(isdigit(password[i])){
            num_count++;
        }else if(isalpha(password[i])){
            alpha_count++;
        }else{
            special_count++;
        }
    }
    
    printf("Password Strength: ");
    
    if(length <= 6){
        printf("Weak\n");
    }else if(length <= 10){
        printf("Moderate\n");
    }else{
        printf("Strong\n");
    }
    
    if(num_count >= 1 && alpha_count >= 1 && special_count >= 1){
        printf("Password Complexity: High\n");
    }else if(num_count >= 1 && alpha_count >= 1){
        printf("Password Complexity: Medium\n");
    }else{
        printf("Password Complexity: Low\n");
    }
    
    return 0;
}