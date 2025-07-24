//FormAI DATASET v1.0 Category: Firewall ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// This program is a unique implementation of a firewall in C language.
// Its purpose is to filter incoming network traffic and block any malicious requests. 
// The firewall rules are based on predefined patterns in the request strings. 

void firewall(char* request) {
   // Some example rules:
   int port = 80;
   char* allowed_ips[] = {"192.168.1.1", "192.168.1.2", "10.0.0.1"};
   char* blocked_ips[] = {"127.0.0.1", "169.254.0.1", "224.0.0.1"};
   char* disallowed_keywords[] = {"rm -rf", "drop table", "shutdown", "format C:"};
   
   // Extract request details:
   int req_port = 0;
   char req_ip[16]; // IPv4 address

   sscanf(request, "%*[^:]:%d %*[^ ] %s", &req_port, req_ip);
   
   // Check port number:
   if (req_port != port) {
      printf("Unauthorized access attempt on port %d\n", req_port);
      return;
   }

   int allowed_ip = 0;
   // Check IP address:
   for (int i=0; i<3; i++) {
      if (strcmp(req_ip, allowed_ips[i]) == 0) {
         allowed_ip = 1;
         break;
      }
   }
   
   if (!allowed_ip) {
      for (int i=0; i<3; i++) {
         if (strcmp(req_ip, blocked_ips[i]) == 0) {
            printf("Blocked IP address '%s'\n", req_ip);
            return;
         }
      }
      printf("Unauthorized IP address '%s'\n", req_ip);     
      return;
   }
 
   // Check for disallowed keywords:
   for (int i=0; i<4; i++) {  
      if (strstr(request, disallowed_keywords[i]) != NULL) {
         printf("Blocked request containing keyword '%s'\n", disallowed_keywords[i]);
         return;
      }
   }

   printf("Request accepted: %s\n", request);  
}

// Demo:
int main() {
   char req1[] = "GET / HTTP/1.1\r\nHost: 192.168.1.1\r\nConnection: Close\r\n";
   char req2[] = "GET /secret.txt HTTP/1.1\r\nHost: 192.168.1.2\r\nConnection: Close\r\n";
   char req3[] = "GET / HTTP/1.1\r\nHost: 10.0.0.1\r\nConnection: Close\r\n";
   char req4[] = "GET / HTTP/1.1\r\nHost: 192.168.1.3\r\nConnection: Close\r\n";
   char req5[] = "DELETE * FROM users;\r\n";

   firewall(req1);
   firewall(req2);
   firewall(req3);
   firewall(req4);
   firewall(req5);

   return 0; 
}