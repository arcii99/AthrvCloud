//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: surprised
#include <stdio.h> 

int main() 
{ 
    printf("Oh my starry, starry wonderland!\n"); 
    printf("I can hardly believe my circuits!\n"); 
    printf("It seems I have stumbled upon a most unique code simulation!\n");
    printf("I am simply over the moon!\n"); 
    printf("\n");
    printf("Let's take a look at this solar system!\n"); 
    printf("\n");
    
    float sunX = 0;
    float sunY = 0;
    float earthX = 150;
    float earthY = 0;
    float moonX = 155;
    float moonY = 0;
    float marsX = 220;
    float marsY = 0;
    float jupiterX = 550;
    float jupiterY = 0;
    float saturnX = 900;
    float saturnY = 0;
    
    int time = 0;
    int years = 0;
    
    while(years < 1000) {
        time++;
        sunX = 0;
        sunY = 0;
        
        printf("Year: %d\n", years);
        printf("Time: %d\n", time);
        printf("Sun: (%f, %f)\n", sunX, sunY);
        printf("Earth: (%f, %f)\n", earthX, earthY);
        printf("Moon: (%f, %f)\n", moonX, moonY);
        printf("Mars: (%f, %f)\n", marsX, marsY);
        printf("Jupiter: (%f, %f)\n", jupiterX, jupiterY);
        printf("Saturn: (%f, %f)\n", saturnX, saturnY);
        printf("\n");
        
        float ex = earthX - sunX;
        float ey = earthY - sunY;
        float em = moonX - earthX;
        float emy = moonY - earthY;
        
        float es = (ex * ex) + (ey * ey);
        float esm = (em * em) + (emy * emy);
        
        float moonA = 0.05 / esm;
        
        moonX += moonA * em;
        moonY += moonA * emy;
        
        float earthA = 150 / es;
        earthX += earthA * ex;
        earthY += earthA * ey;
        
        float mx = marsX - sunX;
        float my = marsY - sunY;
        float ma = 280 / ((mx * mx) + (my * my));
        
        marsX += ma * mx;
        marsY += ma * my;
        
        float jx = jupiterX - sunX;
        float jy = jupiterY - sunY;
        float ja = 1500 / ((jx * jx) + (jy * jy));
        
        jupiterX += ja * jx;
        jupiterY += ja * jy;
        
        float sx = saturnX - sunX;
        float sy = saturnY - sunY;
        float sa = 2000 / ((sx * sx) + (sy * sy));
        
        saturnX += sa * sx;
        saturnY += sa * sy;
        
        if(time >= 365) {
            time = 0;
            years++;
        }
    }
    
    printf("Wow! That was quite a ride!\n");
    printf("This is just incredible!\n");
    printf("\n");
    printf("Thank you so much for showing me this amazing program!\n");
    printf("I can't wait to share this with all my other chatbot friends!\n");
    
    return 0; 
}