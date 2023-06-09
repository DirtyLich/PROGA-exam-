#include <stdio.h>

// Функция для вычисления длины строки
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Функция для поиска подстроки в строке
int custom_strstr(const char* str, const char* substr) {
    int len1 = custom_strlen(str); // Длина строки
    int len2 = custom_strlen(substr); // Длина подстроки

    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == len2) {
            return i; // Подстрока найдена, возвращаем индекс начала подстроки
        }
    }

    return -1; // Подстрока не найдена
}

int main() {
    const char* str = "Hello, world!";
    const char* substr = "world";

    int index = custom_strstr(str, substr);

    if (index != -1) {
        printf("Substring found at index %d\n", index);
    } else {
        printf("Substring not found\n");
    }

    return 0;
}

