//FormAI DATASET v1.0 Category: System event logger ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void logEvent(char* event){
   time_t now = time(0);
   char* timeString=ctime(&now);
   FILE *fp;
   fp=fopen("eventlog.txt","a");
   fprintf(fp,"%s: %s\n",timeString,event);
   fclose(fp);
};

int main(){
   char* event="System Startup";
   logEvent(event);

   event="Login Success";
   logEvent(event);

   event="Failed Login Attempt: Incorrect Password";
   logEvent(event);

   event="Critical System Error: Unable to Restart Services";
   logEvent(event);

   event="System Shutdown";
   logEvent(event);

   return 0;
};