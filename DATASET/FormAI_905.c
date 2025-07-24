//FormAI DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>

int main() {
   int x = 7;
   int y = 3;
   int ans;
   
   printf("Let's do some arithmetic! Hold on tight!\n\n");
   printf("7 + 3 = ");
   ans = x + y;
   printf("%d\n", ans);
   printf("Whoaa! That was easy!\n\n");
   
   printf("7 - 3 = ");
   ans = x - y;
   printf("%d\n", ans);
   printf("That's right! I got it!\n\n");

   printf("7 * 3 = ");
   ans = x * y;
   printf("%d\n", ans);
   printf("Whoa! I'm on fire!\n\n");

   printf("7 / 3 = ");
   ans = x / y;
   printf("%d\n", ans);
   printf("What!? That's not right...let me fix that..\n");
   
   ans = x % y;
   printf("7 %% 3 = %d\n", ans);
   printf("Phew! Almost thought I lost my touch..\n\n");

   printf("5 + 4 * 7 - 2 = ");
   ans = 5 + 4 * 7 - 2;
   printf("%d\n", ans);
   printf("Oi! That was a tough one\n\n");

   printf("(5 + 3) * 10 / 2 = ");
   ans = (5 + 3) * 10 / 2;
   printf("%d\n", ans);
   printf("Nailed it! What else ya got for me?\n\n");
   
   printf("Ok ok let's take it up a notch, 2^6 = ");
   ans = 1;
   for(int i = 0; i < 6; i++){
       ans *= 2;
   }
   printf("%d\n", ans);
   printf("Whew! I'm sweatin' now!\n\n");
   
   printf("Alright this is the final one, you ready? 1 + 2 + 3 + ... + 99 + 100 = ");
   ans = 0;
   for(int i = 1; i <= 100; i++){
       ans += i;
   }
   printf("%d\n", ans);
   printf("Yes! I've still got it!\n\n");
   
   printf("Well that was quite the ride, wasn't it? Until next time, folks!\n");
   
   return 0;
}