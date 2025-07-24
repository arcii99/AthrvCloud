//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: future-proof
#include<stdio.h>

int main(){

  char text[100];
  printf("Enter the text to be converted to ASCII art: ");
  scanf("%[^\n]", text);
  
  int ascii;
  for(int i=0; text[i]!='\0';i++){
    ascii = text[i];
    switch(ascii){
      case 32: printf("          "); break;
      case 33: printf(" __     __   \n/  \\   /  \\ \n\\__/   \\__/ \n              \n"); break;
      case 34: printf(" _  _   \n( \\/ )  \n \\  / \n  \\/  \n"); break;
      case 35: printf("    /\\   \n   /  \\  \n  / /\\ \\ \n / ____ \\\n/_/    \\_\\\n"); break;
      case 36: printf("   /\\     \n  /  \\    \n / /\\ \\   \n( (__) )  \n \\____/   \n"); break;
      case 37: printf("%%\\    /%%\n  \\__/   \n / /  \\  \n( /    ) \n \\__/\\_)\n"); break;
      case 38: printf("   _____   \n / ____  \\ \n( (    \\ / \n \\ \\    /_\n \\ \\____/ \n"); break;
      case 39: printf(" __  \n/  \\ \n\\__/ \n     \n"); break;
      case 40: printf("   __ \n /  \\\n(    \\\n \\    \\\n/    /\n \\__/ \n"); break;
      case 41: printf(" __   \n/  \\  \n\\    ) \n/    /\n\\   ( \n \\__/ \n"); break;
      case 42: printf("  ___   \n / _ \\  \n/ /_\\ \\\n> / _ <\n/_/ \\_\\\n"); break;
      case 43: printf("    \n  /\\  \n /  \\ \n/ /\\ \\\n\\/_/\\_\\\n"); break;
      case 44: printf("    \n    \n    \n __ \n/  \\\n\\__/ \n"); break;
      case 45: printf("     \n     \n ____\n/ ___\\\n\\___ \\ \n\\____/\n"); break;
      case 46: printf("    \n    \n    \n __ \n/  \\\n\\__/ \n"); break;
      case 47: printf("     __\n    / /\n   / / \n  / /  \n / /   \n/_/    \n"); break;
      case 48: printf("  ___   \n / __\\  \n/ /    \n> >    \n\\ \\___ \n \\____\\\n"); break;
      case 49: printf("   __  \n _/  |_\n|_   _|\n  | |  \n  |_|  \n"); break;
      case 50: printf(" ____   \n/__  \\  \n   ) | \n  / /  \n / /___\n|______|\n"); break;
      case 51: printf("  ____  \n /___ \\ \n|___ \\ |\n  ___) |\n |____/ \n"); break;
      case 52: printf(" _  __  \n| |/ /  \n| ' / \n|  <   \n|_|\\_\\ \n"); break;
      case 53: printf(" _____ \n| ____|\n| |___ \n|___ \\ \n ___) |\n|____/ \n"); break;
      case 54: printf("  __   \n / /_  \n| '_ \\ \n| (_) |\n \\___/ \n"); break;
      case 55: printf(" _____ \n|__  / \n  / /  \n / /_  \n/____| \n"); break;
      case 56: printf("  ___  \n / _ \\ \n| (_) |\n > _ < \n/_/ \\_\\\n"); break;
      case 57: printf("  ___   \n / _ \\  \n| (_) | \n \\__, | \n   /_/  \n"); break;
      case 58: printf("    \n __ \n/  \\\n\\__/ \n __ \n/  \\\n\\__/ \n"); break;
      case 59: printf("    \n __ \n/  \\\n\\__/ \n __ \n/  \\\n\\__/ \n"); break;
      case 60: printf("  __  \n/<_> \\\n| <_/ \n\\___/ \n"); break;
      case 61: printf("     \n ____\n|____|\n ____\n|____|\n     \n"); break;
      case 62: printf(" __ \n/_ |\n | |\n | |\n/_/ \n"); break;
      case 63: printf(" ____   \n|  _ \\  \n| |_) | \n|  _ <  \n|_| \\_\\\n"); break;
      case 64: printf("   ____     \n  / __ \\   \n / / _` | \n| | (_| | \n \\ \\__,_| \n  \\____/  \n"); break;
      case 65: printf("   __   \n /\\_\\  \n/_/\\ \\ \n\\ \\ \\ \n \\ \\_\\\n  \\/_/\n"); break;
      case 66: printf(" ____   \n|  _ \\  \n| |_) | \n|  _ <  \n|_| \\_\\\n"); break;
      case 67: printf("  ____  \n / ___| \n| |     \n| |___  \n \\____| \n"); break;
      case 68: printf(" ____   \n|  _ \\  \n| | \\ \\ \n| | | |\n|_| |_| \n"); break;
      case 69: printf(" _____ \n| ____|\n| |__  \n|___ \\ \n ___) |\n|____/ \n"); break;
      case 70: printf(" _____ \n| ____|\n| |__  \n|___ \\ \n| |___ \n|_____| \n"); break;
      case 71: printf("  ____  \n / ___| \n| |  _  \n| |_| |\n \\____| \n"); break;
      case 72: printf(" _   _  \n| | | | \n| |_| | \n|  _  | \n|_| |_| \n"); break;
      case 73: printf(" ____ \n|_  /\n | | \n | | \n|_/ \n"); break;
      case 74: printf("     __\n    / /\n   / / \n  / /  \n / /   \\/\n/_/     ()\n"); break;
      case 75: printf(" _   __\n| | / / \n| |/ /  \n| |\ <   \n|_| \\_\\\n"); break;
      case 76: printf(" _     \n| |    \n| |    \n| |___ \n|_____| \n"); break;
      case 77: printf(" __  __ \n|  \\/  |\n| |\\/| |\n| |  | |\n|_|  |_| \n"); break;
      case 78: printf(" _   _ \n| \\ | |\n|  \\| |\n| |\\  |\n|_| \\_| \n"); break;
      case 79: printf("  ____  \n / __ \\ \n| |  | |\n| |  | |\n| |__| |\n \\____/ \n"); break;
      case 80: printf(" ____  \n|  _ \\ \n| |_) )\n|  _ < \n|_| \\_\\\n"); break;
      case 81: printf("  ____   \n / __ \\  \n| |  | | \n| |__| | \n\\___\\_\\_\n"); break;
      case 82: printf(" ____  \n|  _ \\ \n| |_) )\n|  __/ \n|_|    \n"); break;
      case 83: printf(" ____  \n/ ___) \n\\___ \\ \n ___) )\n|____/ \n"); break;
      case 84: printf(" _____ \n|_   _|\n  | |  \n  | |  \n  |_|  \n"); break;
      case 85: printf(" _   _  \n| | | | \n| | | | \n| |_| | \n \\___/  \n"); break;
      case 86: printf(" _   _\n| | | |\n| | | |\n| |_| |\n \\___/ \n"); break;
      case 87: printf(" _    _ \n| |  | |\n| |  | |\n| |/\\| |\n\\  /\\  /\n \\/  \\/ \n"); break;
      case 88: printf("_   _ \n\\_/ / \n  / /  \n / /   \n/ /___ \n\\____/\n"); break;
      case 89: printf("_   _ \n\\_(_) \n | |  \n | |  \n | |  \n |_|  \n"); break;
      case 90: printf(" _____ \n|___ / \n  |_ \\ \n ___) |\n|____/ \n"); break;
      case 91: printf(" __ \n/  |\n| | \n| | \n| | \n|_| \n"); break;
      case 92: printf("/     \n\\ \\    \n \\ \\   \n  \\ \\  \n   \\_\\\n"); break;
      case 93: printf(" __ \n|_ |\n | |\n | |\n | |\n|__|\n"); break;
      case 94: printf("   /\\ \n  /  \\ \n / /\\ \\\n/_/  \\_\\\n"); break;
      case 95: printf("     \n     \n     \n ____\n|____|\n"); break;
      case 96: printf(" __ \n/  |\n`| |\n | |\n |_| \n"); break;
      case 97: printf("  ___  \n / _ \\ \n/ /_\\ \\\n|  _  |\n|_| |_| \n"); break;
      case 98: printf(" ____  \n|  _ \\ \n| |_) )\n|  _ < \n|_| \\_\\\n"); break;
      case 99: printf("  ____ \n / ___|\n| |    \n| |___ \n \\____|\n"); break;
      case 100: printf(" ____   \n|  _ \\  \n| | \\ \\ \n| | | |\n|_| |_| \n"); break;
      case 101: printf(" ____  \n/ ___\\\n\\ \\___\n \\___ \\\n(____/\n"); break;
      case 102: printf(" _____ \n| ____|\n| |__  \n|___ \\ \n|____) |\n|_____/ \n"); break;
      case 103: printf("  ____  \n / __ \\ \n/ / _` |\n| | (_| |\n \\ \\__, |\n  \\____/ \n"); break;
      case 104: printf(" _     \n| |    \n| |___ \n|  _  |\n|_| |_| \n"); break;
      case 105: printf(" _ \n(_)\n| |\n| |\n|_|\n"); break;
      case 106: printf("   _ \n  (_)\n  | |\n  | |\n _/ |\n|__/ \n"); break;
      case 107: printf(" _    \n| |   \n| | __\n| |/ /\n|   < \n|_|\\_\\\n"); break;
      case 108: printf(" _ \n| |\n| |\n| |\n|_|\n"); break;
      case 109: printf(" _ __ ___   \n| '_ ` _ \\ \n| | | | | |\n|_| |_| |_|\n"); break;
      case 110: printf(" _   _ \n| | | |\n| | | |\n| |_| |\n \\___/ \n"); break;
      case 111: printf("  ____  \n / __ \\ \n/ / _` |\n| | (_| |\n \\ \\__,_|\n  \\____/ \n"); break;
      case 112: printf(" ____   \n|  _ \\  \n| |_) )\n|  _ < \n|_| \\_\\\n"); break;
      case 113: printf("  ____   \n / __ \\  \n/ / _` | \n| \\ (_| | \n \\ \\__, | \n  \\____/  \n"); break;
      case 114: printf(" ____  \n|  _ \\ \n| |_) )\n|  _ < \n|_| \\_\\\n"); break;
      case 115: printf(" ____  \n/ ___\\\n\\___ \\\n ___) |\n|____/ \n"); break;
      case 116: printf(" ____  \n|_  / \n | |  \n | |  \n/___| \n"); break;
      case 117: printf(" _   _  \n| | | | \n| | | | \n| |_| | \n \\__,_| \n"); break;
      case 118: printf("_   _ \n| | | |\n| | | |\n\\ V / \n \\_/  \n"); break;
      case 119: printf("_    _ \n| |  | |\n| |  | |\n\\ \\/' / \n \\_/\\_\\\n"); break;
      case 120: printf("_   _ \n\\_/ / \n/ _ \\ \n\\ \\ \\\n \\_\\\n"); break;
      case 121: printf("_   _ \n| | | |\n| | | |\n\\ V / \n \\_/ | \n    |/  \n"); break;
      case 122: printf(" _____\n|___ / \n  |_ \\ \n ___) |\n|____/ \n"); break;
      case 123: printf("    __\n   / /\n  / / \n | |  \n | |  \n  \\_\\\n"); break;
      case 124: printf(" __ \n|  |\n|  |\n|  |\n|__|\n"); break;
      case 125: printf(" __   \n\\ \\  \n \\ \\ \n  | |\n  | |\n/_/ \n"); break;
      case 126: printf("  /\\/| \n |/\\/ \n       \n       \n"); break;
      default: printf("\nThe entered text contains an unsupported character.\n");break;
    }
  }
  return 0;
}