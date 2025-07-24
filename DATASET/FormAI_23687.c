//FormAI DATASET v1.0 Category: Browser Plugin ; Style: high level of detail
#include <stdio.h>

// Browser Plugin Functions
void onLoad() {
    printf("Plugin loaded successfully.\n");
}

void onUnload() {
    printf("Plugin unloaded.\n");
}

void onRender(char* html) {
    printf("Rendering page with:\n %s", html);
}

// Main Plugin Function
int main() {
    // Call onLoad function when plugin is loaded
    onLoad();
    
    // Simulate page rendering with HTML code
    char* html = "<html>\n<head>\n<title>My Page</title>\n</head>\n<body>\n<p>Hello World!</p>\n</body>\n</html>";
    onRender(html);
    
    // Call onUnload function when plugin is unloaded
    onUnload();
    
    return 0;
}