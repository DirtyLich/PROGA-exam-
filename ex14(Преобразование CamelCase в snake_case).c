#include <stdio.h>

// Функция для проверки, является ли символ заглавной буквой
int custom_isupper(char c) {
    return c >= 'A' && c <= 'Z';
}

// Функция для преобразования символа в нижний регистр
char custom_tolower(char c) {
    if (custom_isupper(c)) {
        return c - 'A' + 'a';
    }
    return c;
}

// Функция для преобразования CamelCase в snake_case
void convert_camel_to_snake(char* str) {
    int i = 0;
    int j = 0;
    char prev = '\0'; // Предыдущий символ

    while (str[i] != '\0') {
        if (prev != '\0' && custom_isupper(str[i])) {
            // Вставляем символ "_" перед каждой заглавной буквой, кроме первой
            str[j] = '_';
            j++;
        }
        str[j] = custom_tolower(str[i]); // Преобразуем символ в нижний регистр
        prev = str[i];
        i++;
        j++;
    }
    str[j] = '\0'; // Добавляем завершающий нуль
}

int main() {
    char str[] = "CamelCaseString";
    printf("Before conversion: %s\n", str);

    convert_camel_to_snake(str);

    printf("After conversion: %s\n", str);

    return 0;
}
