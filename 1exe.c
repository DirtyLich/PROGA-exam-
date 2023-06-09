#include <stdio.h>
#include <stdbool.h>

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isValidIpAddress(const char *ipAddress) {
    int num;
    int dots = 0;
    int segments = 0;
    int i = 0;
    int segmentStart = 0;
    
    while (ipAddress[i] != '\0') {
        if (ipAddress[i] == '.') {
            dots++;
            if (segments > 3) {
                return false;
            }
            if (i - segmentStart == 0) {
                return false;
            }
            num = 0;
            for (int j = segmentStart; j < i; j++) {
                if (!isDigit(ipAddress[j])) {
                    return false;
                }
                num = num * 10 + (ipAddress[j] - '0');
            }
            if (num < 0 || num > 255) {
                return false;
            }
            segments++;
            segmentStart = i + 1;
        } else if (!isDigit(ipAddress[i])) {
            return false;
        }
        i++;
    }
    
    if (segments != 3 || dots != 3) {
        return false;
    }
    
    return true;
}

int main() {
    char ipAddress[16];
    
    printf("Enter an IP address: ");
    scanf("%15s", ipAddress);
    
    if (isValidIpAddress(ipAddress)) {
        printf("Valid IP address.\n");
    } else {
        printf("Invalid IP address.\n");
    }
    
    return 0;
}
