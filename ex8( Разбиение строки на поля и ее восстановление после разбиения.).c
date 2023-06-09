#include <stdio.h>

// Функция для вычисления длины строки
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Функция для разбиения строки на поля
void split_string(const char* str, char delimiter, char** fields, int* num_fields) {
    int str_length = custom_strlen(str); // Длина исходной строки
    int field_start = 0; // Начальная позиция текущего поля
    int field_length = 0; // Длина текущего поля

    for (int i = 0; i <= str_length; i++) {
        if (str[i] == delimiter || str[i] == '\0') {
            // Выделяем память для поля
            fields[*num_fields] = (char*)malloc((field_length + 1) * sizeof(char));

            // Копируем символы из исходной строки в поле
            for (int j = 0; j < field_length; j++) {
                fields[*num_fields][j] = str[field_start + j];
            }

            fields[*num_fields][field_length] = '\0'; // Устанавливаем символ конца строки

            (*num_fields)++; // Увеличиваем количество полей

            field_start = i + 1; // Обновляем начальную позицию следующего поля
            field_length = 0; // Сбрасываем длину текущего поля
        } else {
            field_length++; // Увеличиваем длину текущего поля
        }
    }
}

// Функция для восстановления строки после разбиения
void join_fields(const char** fields, int num_fields, char delimiter, char* joined_str) {
    int index = 0; // Индекс текущей позиции в объединенной строке

    for (int i = 0; i < num_fields; i++) {
        int field_length = custom_strlen(fields[i]); // Длина текущего поля

        for (int j = 0; j < field_length; j++) {
            joined_str[index] = fields[i][j]; // Копируем символы из поля в объединенную строку
            index++; // Увеличиваем индекс
        }

        if (i < num_fields - 1) {
            joined_str[index] = delimiter; // Добавляем разделитель
            index++; // Увеличиваем индекс
        }
    }

    joined_str[index] = '\0'; // Устанавливаем символ конца строки
}

int main() {
    char str[] = "Hello,world,how,are,you";
    char delimiter = ',';
    char fields[100][100];
    int num_fields = 0;

    printf("Original string: %s\n", str);

    split_string(str, delimiter, fields, &num_fields);

    printf("Fields:\n");
    for (int i = 0; i < num_fields; i++) {
        printf("%s\n", fields[i]);
    }

   
    char joined_str[1000];
    join_fields((const char**)fields, num_fields, delimiter, joined_str);

    printf("Joined string: %s\n", joined_str);

    return 0;
}
