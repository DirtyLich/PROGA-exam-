#include <stdio.h>

int my_strlen(const char* str)
{
    int len = 0;
    while (*str++)
        len++;
    return len;
}
int is_valid_ip_address(const char* ip_address) {
    int num, dots = 0;
    char c;
    int len = my_strlen(ip_address);
    int i = 0;
    
    for(i = 0; i < len; i++) {
        c = ip_address[i];
        if(c == '.') {
            dots++;
            if(dots > 3) {
                return 0;
            }
            continue;
        }
        if(c < '0' || c > '9') {
            return 0;
        }
        num = 0;
        while(c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            if(num > 255) {
                return 0;
            }
            i++;
            c = ip_address[i];
        }
        i--;
    }
    if(dots != 3) {
        return 0;
    }
    return 1;
}

int main() {
    const char* ip_address = "192.168.0.1";
    if(is_valid_ip_address(ip_address)) {
        printf("IP address %s is valid\n", ip_address);
    } else {
        printf("IP address %s is not valid\n", ip_address);
    }
    return 0;
}
