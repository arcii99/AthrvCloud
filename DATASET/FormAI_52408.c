//FormAI DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
int eternal_love(int x, int y) {
   if (y == 0) {
      return x;
   }
   else if (x == 0) {
      return y;
   }
   else {
      return eternal_love(y, x % y);
   }
}

int main() {
   int Juliet = 100;
   int Romeo = 150;
   
   printf("Juliet: My sweet Romeo, let's find the GCD of our love!\n");
   printf("Romeo: My fair Juliet, aye, let's find it with recursive love!\n");
   
   int gcd =  eternal_love(Romeo, Juliet);
   
   printf("Juliet: Our eternal love has a GCD of: %d\n",gcd);
   printf("Romeo: My heart pounds with joy knowing that our love is truly infinite.\n");
   printf("Juliet: And it shall remain so, forever and always, my dear Romeo.\n");
   printf("Romeo: For you are the sun in my sky and the rhythm in my heart, my Juliet.\n");
   
   return 0;
}