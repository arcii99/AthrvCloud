//FormAI DATASET v1.0 Category: Weather simulation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  srand(time(0));
  int temperature;
  int humidity;
  int radiation;
  char condition[50];
  
  int i=1;
  printf("\t\t\t\t\t\t\tWelcome to the Post-Apocalyptic Weather Simulation!\n\n");
  
  while(i<=10){
    temperature=rand()%80-20; //temperature range from -20 to 60 degrees Celsius 
    humidity=rand()%101; //humidity range from 0% to 100%
    radiation=rand()%501; //radiation levels range from 0 to 500 rads
    
    if(radiation>=400){
       sprintf(condition,"EXTREME RADIATION"); //set the condition to extreme radiation
       printf("\t\t\t\t\t\t\tDay %d: %dC %d%% %d rads - %s\n",i,temperature,humidity,radiation,condition);
    }
    else if(temperature<-10 && humidity>60){
      sprintf(condition,"BLIZZARD"); //set the condition to blizzard
      printf("\t\t\t\t\t\t\tDay %d: %dC %d%% %d rads - %s\n",i,temperature,humidity,radiation,condition);
    }
    else if(humidity>80){
      sprintf(condition,"RAINY"); //set the condition to rainy 
      printf("\t\t\t\t\t\t\tDay %d: %dC %d%% %d rads - %s\n",i,temperature,humidity,radiation,condition);
    }
    else if(temperature>=25 && radiation>=200){
      sprintf(condition,"RADIATION STORM"); //set the condition to radiation storm
      printf("\t\t\t\t\t\t\tDay %d: %dC %d%% %d rads - %s\n",i,temperature,humidity,radiation,condition);
    }
    else if(temperature>=35){
      sprintf(condition,"HEAT WAVE"); //set the condition to heat wave
      printf("\t\t\t\t\t\t\tDay %d: %dC %d%% %d rads - %s\n",i,temperature,humidity,radiation,condition);
    }
    else{
      sprintf(condition,"NORMAL"); //set the condition to normal weather
      printf("\t\t\t\t\t\t\tDay %d: %dC %d%% %d rads - %s\n",i,temperature,humidity,radiation,condition);
    }
    i++;
  }
  return 0;
}