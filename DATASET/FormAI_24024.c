//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int is_prime(int n){
    int i, flag=0;
    for(i=2;i<=n/2;i++){
        if(n%i==0){
            flag = 1;
            break;
        }
    }
    if(flag==0){
        return 1;
    }
    else{
        return 0;
    }
}

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

void main(){
   int p, q, n, phi, e, d, message, cipher, decrypt;
   printf("Oh my gosh! We are going to do some Public-Key Algorithm stuff!\n");
   printf("Enter a prime number p: ");
   scanf("%d",&p);
   while(!is_prime(p)){
       printf("The entered number is not prime.Try again:");
       scanf("%d",&p);
   }
   printf("Awesome! Now enter another prime number q: ");
   scanf("%d",&q);
   while(!is_prime(q)){
       printf("The entered number is not prime.Try again:");
       scanf("%d",&q);
   }
   printf("WOW! You are doing great! Now let's do some calculations.\n");
   n = p*q;
   phi = (p-1)*(q-1);
   printf("n : %d and phi : %d\n",n,phi);
   e = 2;
   while(e<phi){
       if(gcd(e,phi)==1){
           break;
       }
       else{
           e++;
       }
   }
   printf("Cool! The public key is (%d,%d)\n",e,n);
   printf("Now, enter the message to encrypt: ");
   scanf("%d",&message);
   cipher = fmod(pow(message,e),n);
   printf("The encrypted message is : %d\n",cipher);
   d = 1/e;
   while(((d*e-1)%phi)!=0){
       d++;
   }
   printf("Yay! The private key is %d\n",d);
   printf("Do you want to decrypt the message? (yes or no) : ");
   char ans[3];
   scanf("%s",ans);
   if(strcmp(ans,"yes")==0){
       decrypt = fmod(pow(cipher,d),n);
       printf("The decrypted message is : %d\n",decrypt);
   }
   else{
       printf("Okay! Feel free to play around with the code :)\n");
   }
   printf("Thank you for using this Public-Key Algorithm program. Have a wonderful day!\n");
}