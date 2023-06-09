#include <stdio.h>

// Функция для вычисления длины строки
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') { // Пока не достигнут символ конца строки
        length++; // Увеличиваем счетчик длины
    }
    return length; // Возвращаем длину строки
}

int is_valid_prefix(char* str, char* valid_chars) {
    int len = custom_strlen(str); // Вычисляем длину строки str
    int valid_len = custom_strlen(valid_chars); // Вычисляем длину строки valid_chars
    int i, j;
    for (i = 0; i < len; i++) { // Проходим по каждому символу в строке str
        char c = str[i]; // Получаем текущий символ
        int found = 0; // Флаг для указания, найден ли символ в списке допустимых символов
        for (j = 0; j < valid_len; j++) { // Проходим по каждому символу в списке допустимых символов
            if (c == valid_chars[j]) { // Если текущий символ совпадает с символом из списка
                found = 1; // Устанавливаем флаг found в значение 1
                break; // Прерываем цикл, так как символ уже найден
            }
        }
        if (!found) { // Если символ не найден в списке допустимых символов
            return i; // Возвращаем позицию символа, на котором нарушается условие
        }
    }
    return len; // Если все символы в строке являются допустимыми, возвращаем длину строки
}

int main() {
    char* str = "abc123xyz"; // Исходная строка
    char* valid_chars = "abcdefghijklmnopqrstuvwxyz0123456789"; // Список допустимых символов
    int prefix_len = is_valid_prefix(str, valid_chars); // Вызов функции для проверки префикса
    printf("Valid prefix length: %d\n", prefix_len); // Вывод длины допустимого префикса
    return 0;
}
