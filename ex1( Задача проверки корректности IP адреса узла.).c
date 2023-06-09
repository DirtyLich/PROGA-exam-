#include <stdio.h>

// Функция для вычисления длины строки
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {  // Итеративно увеличиваем длину до достижения нулевого символа
        length++;
    }
    return length;
}

// Функция для проверки корректности IP-адреса
int is_valid_ip_address(const char* ip_address) {
    int num, dots = 0;
    char c;
    int len = custom_strlen(ip_address);  // Получаем длину строки IP-адреса
    int i = 0;
    
    for(i = 0; i < len; i++) {
        c = ip_address[i];
        if(c == '.') {
            dots++;
            if(dots > 3) {  // Проверяем, что количество точек не превышает 3
                return 0;  // Возвращаем 0, если IP-адрес некорректный
            }
            continue;
        }
        if(c < '0' || c > '9') {  // Проверяем, что символ является цифрой
            return 0;  // Возвращаем 0, если IP-адрес некорректный
        }
        num = 0;
        while(c >= '0' && c <= '9') {  // Извлекаем число из цифровой группы
            num = num * 10 + (c - '0');
            if(num > 255) {  // Проверяем, что число не превышает 255
                return 0;  // Возвращаем 0, если IP-адрес некорректный
            }
            i++;
            c = ip_address[i];
        }
        i--;
    }
    if(dots != 3) {  // Проверяем, что количество точек равно 3
        return 0;  // Возвращаем 0, если IP-адрес некорректный
    }
    return 1;  // Возвращаем 1, если IP-адрес корректный
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
