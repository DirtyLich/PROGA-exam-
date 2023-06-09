#include <stdio.h>

// Функция для вычисления длины строки
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Функция для конкатенации строк
void custom_strcat(char* destination, const char* source) {
    int dest_len = custom_strlen(destination);
    int src_len = custom_strlen(source);

    int i, j;
    for (i = dest_len, j = 0; j < src_len; i++, j++) {
        destination[i] = source[j];
    }
    destination[i] = '\0'; // Устанавливаем завершающий нуль-символ
}

int main() {
    char str1[100] = "Hello, ";
    char str2[100] = "world!";
    printf("Initial strings: %s, %s\n", str1, str2);

    custom_strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    return 0;
}

