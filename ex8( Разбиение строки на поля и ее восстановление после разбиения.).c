#include <stdio.h>

// Функция для вычисления длины строки
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') { // Пока не достигнут символ конца строки
        length++; // Увеличиваем счетчик длины
    }
    return length; // Возвращаем длину строки
}

// Функция для копирования строки
void custom_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') { // Пока не достигнут символ конца строки
        dest[i] = src[i]; // Копируем символ из исходной строки в целевую строку
        i++; // Переходим к следующему символу
    }
    dest[i] = '\0'; // Устанавливаем символ конца строки в целевой строке
}

// Функция для разбиения строки на поля
void split_string(const char* str, char delimiter, char** fields, int* num_fields) {
    int len = custom_strlen(str); // Вычисляем длину строки
    int field_start = 0; // Индекс начала текущего поля
    int field_count = 0; // Счетчик полей

    for (int i = 0; i < len; i++) {
        if (str[i] == delimiter) { // Если найден разделитель
            // Выделяем память для поля и копируем символы из исходной строки
            fields[field_count] = (char*)malloc((i - field_start + 1) * sizeof(char));
            custom_strcpy(fields[field_count], str + field_start);
            fields[field_count][i - field_start] = '\0'; // Устанавливаем символ конца строки

            field_start = i + 1; // Обновляем индекс начала следующего поля
            field_count++; // Увеличиваем счетчик полей
        }
    }

    // Выделяем память и копируем символы для последнего поля после последнего разделителя
    fields[field_count] = (char*)malloc((len - field_start + 1) * sizeof(char));
    custom_strcpy(fields[field_count], str + field_start);
    fields[field_count][len - field_start] = '\0'; // Устанавливаем символ конца строки

    *num_fields = field_count + 1; // Обновляем количество полей
}

// Функция для восстановления строки после разбиения
char* join_fields(char** fields, int num_fields, char delimiter) {
    int total_length = 0; // Общая длина строки
    for (int i = 0; i < num_fields; i++) {
        total_length += custom_strlen(fields[i]); // Добавляем длину текущего поля

        if (i < num_fields - 1) {
            total_length++; // Увеличиваем длину на 1 для разделителя
        }
    }

    char* joined_str = (char*)malloc((total_length + 1) * sizeof(char)); // Выделяем память для объединенной строки
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

    return joined_str; // Возвращаем объединенную строку
}

int main() {
    char str[] = "Hello,world,how,are,you";
    char delimiter = ',';
    char* fields[100];
    int num_fields = 0;

    printf("Original string: %s\n", str);

    split_string(str, delimiter, fields, &num_fields);

    printf("Fields:\n");
    for (int i = 0; i < num_fields; i++) {
        printf("%s\n", fields[i]);
    }

    char* joined_str = join_fields(fields, num_fields, delimiter);
    printf("Joined string: %s\n", joined_str);

    // Освобождаем память, выделенную для полей
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }

    // Освобождаем память, выделенную для объединенной строки
    free(joined_str);

    return 0;
}
// Функция для восстановления строки после разбиения
char* join_fields(char** fields, int num_fields, char delimiter) {
    int total_length = 0; // Общая длина строки
    for (int i = 0; i < num_fields; i++) {
        total_length += custom_strlen(fields[i]); // Добавляем длину текущего поля

        if (i < num_fields - 1) {
            total_length++; // Увеличиваем длину на 1 для разделителя
        }
    }

    char* joined_str = (char*)malloc((total_length + 1) * sizeof(char)); // Выделяем память для объединенной строки
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

    return joined_str; // Возвращаем объединенную строку
}

int main() {
    char str[] = "Hello,world,how,are,you";
    char delimiter = ',';
    char* fields[100];
    int num_fields = 0;

    printf("Original string: %s\n", str);

    split_string(str, delimiter, fields, &num_fields);

    printf("Fields:\n");
    for (int i = 0; i < num_fields; i++) {
        printf("%s\n", fields[i]);
    }

    char* joined_str = join_fields(fields, num_fields, delimiter);
    printf("Joined string: %s\n", joined_str);

    // Освобождаем память, выделенную для полей
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }

    // Освобождаем память, выделенную для объединенной строки
    free(joined_str);

    return 0;
}

