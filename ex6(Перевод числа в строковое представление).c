
#include <stdio.h>

// Функция для вычисления длины строки
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Функция для обращения строки
void custom_reverse(char* str) {
    int len = custom_strlen(str);
    int start = 0;
    int end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Функция для преобразования числа в строку
void custom_itoa(int num, char* str) {
    int i = 0;
    int sign = 0;

    // Обрабатываем отрицательное число
    if (num < 0) {
        sign = 1;
        num = -num;
    }

    // Преобразуем каждую цифру числа в символ и записываем в строку
    do {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);

    // Добавляем знак минуса, если число отрицательное
    if (sign) {
        str[i++] = '-';
    }

    str[i] = '\0';

    // Обращаем полученную строку
    custom_reverse(str);
}

int main() {
    int num = -12345;
    char str[20];

    custom_itoa(num, str);

    printf("Number: %d\n", num);
    printf("String: %s\n", str);

    return 0;
}
