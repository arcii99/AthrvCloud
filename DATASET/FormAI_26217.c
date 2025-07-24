//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Romeo and Juliet
/* 
  Romeo: Oh my dearest Juliet, heed this noble request
          I am in great need of monitoring my website's uptime
  Juliet: My love, fear not for your technical quest
          I shall help you craft the perfect program sublime
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char *website = "https://www.mywebsite.com";
  
  // Romeo scans the website for its current state
  printf("Romeo: Fair Juliet, prithee tell me what sayeth thou,\n");
  printf("        when thou honorest %s with thine URL bow?\n", website);

  // Juliet sends an HTTP request to the website and checks the response
  int status = system("curl --head --silent https://www.mywebsite.com | head -n 1 | grep \"HTTP/1.[01]\" | awk '{print $2}'");

  // If the website is up, thy status code shall be 200
  if (status == 200) {
    printf("Juliet: Dearest Romeo, my eyes doth see\n");
    printf("          that thy website is as alive as thee\n");
    
  // If the website is down, thy status code shall be 000    
  } else if (status == 0) {
    printf("Juliet: Alas, my good Romeo, please close thy weeping eye\n");
    printf("          for thy website doth sleep and shall soon arise on high\n");
  
  // In case of any error, fair Juliet shall report it  
  } else {
    printf("Juliet: Romeo, my love, a most strange sight to behold\n");
    printf("          Your website shows an error, something is amiss, I am told\n");
  }
  
  return 0;
}