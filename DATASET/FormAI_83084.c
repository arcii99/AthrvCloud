//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
   float start, stop, t_elapsed, speed;
   int size, choice, retry;
   char name[20];
   
   printf("Welcome to Internet Speed Test Application\n");
   printf("------------------------------------------\n");

   printf("Enter your name: ");
   scanf("%s", name);

   printf("\nEnter the file size to download in MB: ");
   scanf("%d", &size);

   printf("\nChoose your Internet Service Provider\n");
   printf("1. AT&T \n2. Verizon \n3. Comcast \n4. Charter \n5. Optimum\n");
   printf("\nEnter your choice: ");
   scanf("%d", &choice);

   do{
       start = clock();
       system("ping -c 5 www.google.com");//ping the Google server
       stop = clock();

       t_elapsed = (stop - start)/CLOCKS_PER_SEC;
       speed = (float)size/(t_elapsed * 1000000);
       
       printf("\nHi %s, your Internet Download speed is %0.2f Mbps\n", name, speed);

       printf("\nDo you want to retry? (1 for yes/0 for no): ");
       scanf("%d", &retry);

   } while(retry == 1);

   printf("\nThanks for using our application!");

   return 0;
}