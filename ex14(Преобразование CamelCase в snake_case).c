#include <stdio.h>

// Функция для преобразования CamelCase в snake_case
void convert_camel_to_snake(char* str) {
    int i = 0;
    int j = 0;
    char prev = '\0'; // Предыдущий символ

    while (str[i] != '\0') {
        if (prev != '\0' && isupper(str[i])) {
            // Вставляем символ "_" перед каждой заглавной буквой, кроме первой
            str[j] = '_';
            j++;
        }
        str[j] = tolower(str[i]); // Преобразуем символ в нижний регистр
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

