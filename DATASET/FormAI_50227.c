//FormAI DATASET v1.0 Category: Browser Plugin ; Style: excited
/*
  This C Browser Plugin example program is going to blow your mind! 
  Get ready to be amazed!
*/

#include <stdio.h>

#ifdef CBROWSER

#include <cbrowser/cbrowser.h>

/* This function will be invoked on browser start up. */
void cbrowser_plugin_init(void)
{
  printf("Hello from cbrowser_plugin_init()\n");
}

/* This function will be invoked on browser shut down. */
void cbrowser_plugin_shutdown(void)
{
  printf("Goodbye from cbrowser_plugin_shutdown()\n");
}

/* This function will be invoked when the plugin is loaded. */
void cbrowser_plugin_load(void)
{
  printf("Awesome, I'm loaded! Time to party!\n");
}

/* This function will be invoked when the plugin is unloaded. */
void cbrowser_plugin_unload(void)
{
  printf("Awww, I'm being unloaded. See you later!\n");
}

/* This function will be invoked when a user types "awesome" into the browser search bar. */
void cbrowser_plugin_search_awesome(void)
{
  printf("You are awesome!\n");
}

/* This function will be invoked when a user types "amazing" into the browser search bar. */
void cbrowser_plugin_search_amazing(void)
{
  printf("You are amazing!\n");
}

#endif

int main(void)
{
  printf("This program is not meant to be run on its own. It's a browser plugin!\n");
  return 0;
}