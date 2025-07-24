//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: random
#include<stdio.h>
#include<string.h>

void check_password_strength(char password[]) {
   int i, length, flag=0, cnt1=0, cnt2=0, cnt3=0, cnt4=0;
   length = strlen(password);
   
   if(length < 8)
        printf("Password should be of atleast 8 characters!\n");
   else{
       for(i=0; i<length; i++) {
           
           if(password[i] >= '0' && password[i] <= '9')
                cnt1++; 
            else if(password[i] >= 'a' && password[i] <= 'z')
                cnt2++; 
            else if(password[i] >= 'A' && password[i] <= 'Z')
                cnt3++; 
            else
                cnt4++; 
       }
       
       if(cnt1 == length)
            flag = 1;
       if(cnt2 > 0 && cnt3 > 0 && cnt1 > 0 && cnt4 > 0) 
            flag = 1;
       
       if(flag == 1) {
           printf("Your password is strong!\n");
       }
       else {
           printf("Your password is weak!\n");
       }
   }
}

int main() {
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);
    
    check_password_strength(password);
    
    return 0;
}