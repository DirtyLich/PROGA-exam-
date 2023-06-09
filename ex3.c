#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* get_valid_prefix(char* str) {
    char* prefix = str;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isalpha(str[i]) && !isdigit(str[i])) {
            prefix[i] = '\0';
            break;
        }
    }
    return prefix;
}

int main() {
    char str[] = "abc123!@#";
    char* prefix = get_valid_prefix(str);
    printf("Prefix: %s\n", prefix);
    return 0;
}
