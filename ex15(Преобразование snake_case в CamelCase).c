#include <stdio.h>

// Функция для преобразования символа в заглавную букву
char custom_toupper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// Функция для преобразования snake_case в CamelCase
void convert_snake_to_camel(char* str) {
    int i = 0;
    int j = 0;
    int capitalize = 0;

    while (str[i] != '\0') {
        if (str[i] == '_') {
            capitalize = 1; // Установка флага для следующего символа
        } else {
            if (capitalize) {
                str[j] = custom_toupper(str[i]); // Преобразование символа в заглавную букву
                capitalize = 0; // Сброс флага
            } else {
                str[j] = str[i];
            }
            j++;
        }
        i++;
    }
    str[j] = '\0'; // Добавляем завершающий нуль
}

int main() {
    char str[] = "snake_case_string";
    printf("Before conversion: %s\n", str);

    convert_snake_to_camel(str);

    printf("After conversion: %s\n", str);

    return 0;
}

