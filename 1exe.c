#include <stdio.h>
#include <stdbool.h>

// Функция для проверки, является ли символ цифрой
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Функция для проверки корректности IP-адреса
bool isValidIpAddress(const char *ipAddress) {
    int num;
    int dots = 0;            // Количество точек в IP-адресе
    int segments = 0;        // Количество сегментов в IP-адресе
    int i = 0;               // Индекс текущего символа
    int segmentStart = 0;    // Индекс начала текущего сегмента
    
    // Проверяем каждый символ IP-адреса
    while (ipAddress[i] != '\0') {
        if (ipAddress[i] == '.') {
            dots++;
            if (segments > 3) {
                return false;  // IP-адрес содержит более 4 сегментов
            }
            if (i - segmentStart == 0) {
                return false;  // Пустой сегмент в IP-адресе
            }
            
            // Парсим числовое значение сегмента
            num = 0;
            for (int j = segmentStart; j < i; j++) {
                if (!isDigit(ipAddress[j])) {
                    return false;  // Сегмент содержит нецифровой символ
                }
                num = num * 10 + (ipAddress[j] - '0');
            }
            
            // Проверяем диапазон числового значения
            if (num < 0 || num > 255) {
                return false;  // Числовое значение сегмента выходит за пределы диапазона
            }
            
            segments++;
            segmentStart = i + 1;
        } else if (!isDigit(ipAddress[i])) {
            return false;  // Символ не является цифрой или точкой
        }
        i++;
    }
    
    // Проверяем количество точек и сегментов в IP-адресе
    if (segments != 3 || dots != 3) {
        return false;  // Неверное количество точек или сегментов в IP-адресе
    }
    
    return true;  // IP-адрес является корректным
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
