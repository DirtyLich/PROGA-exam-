#include <stdio.h>

// Функция для копирования строки
void custom_strcpy(char* destination, const char* source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Добавляем завершающий нуль в конец скопированной строки
}

int main() {
    char source[] = "Hello, world!";
    char destination[100];

    custom_strcpy(destination, source);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}

