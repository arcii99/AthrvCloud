//FormAI DATASET v1.0 Category: Temperature Converter ; Style: funny
#include<stdio.h>

int main(){
    printf("\nHey there! I am your friendly neighborhood temperature converter!\n");
    printf("What's the temperature out there in good old Celsius? Please enter:\n");
    
    float celsius;
    scanf("%f", &celsius);
    
    printf("\nFingers crossed, I am trying to convert it to Fahrenheit...(drumroll)\n");
    
    float fahrenheit = (celsius * 9/5) + 32;
    
    printf("\nAnd voila! Your temperature in Fahrenheit is.......\n");
    printf("Wait for it....\n");
    printf("Wait for it....\n");
    printf("Wait for it....\n\n");
    
    printf("%f degrees Fahrenheit!! Yayy! Congratulations!!\n", fahrenheit);
    printf("Aren't you glad you have a super smart temperature converter like me in your life? Haha!\n\n");
    
    printf("But wait, there's more!!\n");
    printf("I am not just any ordinary temperature converter, I also convert in Kelvin, just for you! Hold your breath!\n\n");
    
    float kelvin = celsius + 273.15;
    
    printf("Ta-da!! Your temperature in Kelvin is %f. I know, I know, I am a genius!!\n", kelvin);
    printf("You can trust me with all your temperature conversion needs! Woohoo!\n");
    
    return 0;
}