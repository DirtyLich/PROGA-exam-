#include <stdio.h>

// Функция для вычисления длины строки
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Функция для получения допустимого префикса
char* get_valid_prefix(char* str) {
    char* prefix = str; // Указатель на начало строки является префиксом по умолчанию
    int len = custom_strlen(str); // Вычисляем длину строки с помощью пользовательской функции
    for (int i = 0; i < len; i++) { // Проходим по каждому символу в строке
        if (!isalpha(str[i]) && !isdigit(str[i])) { // Проверяем, является ли символ буквой или цифрой
            prefix[i] = '\0'; // Если символ не является допустимым, устанавливаем его на место завершающего нуля
            break; // Прекращаем цикл, так как достигнут недопустимый символ
        }
    }
    return prefix; // Возвращаем префикс
}

int main() {
    char str[] = "abc123!@#"; // Исходная строка
    char* prefix = get_valid_prefix(str); // Вызов функции для получения допустимого префикса
    printf("Prefix: %s\n", prefix); // Вывод допустимого префикса
    return 0;
}
