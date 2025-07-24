//FormAI DATASET v1.0 Category: System boot optimizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  printf("Welcome to the C System boot optimizer!\n");
  printf("This program will help make your boot process lightning fast and improve your overall system performance!\n");
  
  // Check for root user permissions
  if(geteuid() != 0)
  {
    printf("Error: This program must be run with root user permissions.\nPlease restart the program with sudo.\n");
    return 1;
  }
  
  // Set file paths for optimization
  char *bootconf = "/etc/default/grub";
  char *sysctlconf = "/etc/sysctl.conf";
  
  // Backup files before optimization
  char *bootconfbkup = "/etc/default/grub.bkup";
  char *sysctlconfbkup = "/etc/sysctl.conf.bkup";
  
  printf("Backing up configuration files...\n");
  if(system("cp /etc/default/grub /etc/default/grub.bkup") == -1 || system("cp /etc/sysctl.conf /etc/sysctl.conf.bkup") == -1)
  {
    printf("Error: Unable to backup configuration files. Please check your permissions and try again.\n");
    return 1;
  }
  
  printf("Files backed up successfully!\n");
  
  // Modify grub configuration
  printf("Modifying GRUB configuration...\n");
  FILE *fbootconf;
  fbootconf = fopen(bootconf, "r+");
  if(fbootconf == NULL)
  {
    printf("Error: Unable to open GRUB config file. Please check if it exists.\n");
    return 1;
  }
  
  char buf[1024];
  char *findstr = "GRUB_TIMEOUT=";
  char *newline = "GRUB_TIMEOUT=0";
  
  int line = 0;
  while(fgets(buf, 1024, fbootconf) != NULL)
  {
    line++;
    if(strstr(buf, findstr) != NULL)
    {
      fseek(fbootconf, -strlen(buf), SEEK_CUR);
      fprintf(fbootconf, "%s", newline);
      break;
    }
  }

  fclose(fbootconf);
  
  printf("GRUB configuration modified successfully!\n");
  
  // Modify sysctl configuration
  printf("Modifying sysctl configuration...\n");
  FILE *fsysctlconf;
  fsysctlconf = fopen(sysctlconf, "a");
  if(fsysctlconf == NULL)
  {
    printf("Error: Unable to open sysctl config file. Please check if it exists.\n");
    return 1;
  }
  
  char *sysctlbuf = "vm.swappiness=10\n";
  int count = fputs(sysctlbuf, fsysctlconf);
  
  fclose(fsysctlconf);
  
  if(count < 0)
  {
    printf("Error: Unable to modify sysctl configuration. Please check your permissions and try again.\n");
    return 1;
  }
  
  printf("Sysctl configuration modified successfully!\n");
  
  // Reboot to apply changes
  printf("Rebooting in 3 seconds...\n");
  sleep(3);
  if(system("reboot") == -1)
  {
    printf("Error: Unable to reboot system. Please try again.\n");
    return 1;
  }
  
  // End program
  printf("System boot optimization successful! Goodbye!\n");
  return 0;
}