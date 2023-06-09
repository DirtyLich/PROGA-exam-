#include <stdio.h>

// Функция для вычисления длины строки
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') { // Пока не достигнут символ конца строки '\0'
        length++; // Увеличиваем счетчик длины
    }
    return length;
}

// Функция для вставки фрагмента строки
void custom_insert(char* str, const char* fragment, int position) {
    int len1 = custom_strlen(str); // Длина исходной строки
    int len2 = custom_strlen(fragment); // Длина вставляемого фрагмента

    // Сдвигаем символы вправо, начиная с позиции вставки
    for (int i = len1; i >= position; i--) {
        str[i + len2] = str[i]; // Копируем символы на len2 позиций вправо
    }

    // Копируем фрагмент в освободившееся место
    for (int i = 0; i < len2; i++) {
        str[position + i] = fragment[i]; // Вставляем символы фрагмента на позицию position
    }
}

// Функция для удаления фрагмента строки
void custom_delete(char* str, int position, int length) {
    int len = custom_strlen(str); // Длина строки

    // Сдвигаем символы влево, перезаписывая удаляемый фрагмент
    for (int i = position + length; i <= len; i++) {
        str[i - length] = str[i]; // Копируем символы на length позиций влево
    }
}

int main() {
    char str[100] = "Hello, world!";
    const char* fragment = "beautiful ";
    int position = 7;
    int length = 5;

    printf("Original string: %s\n", str);

    custom_insert(str, fragment, position);
    printf("String after insertion: %s\n", str);

    custom_delete(str, position, length);
    printf("String after deletion: %s\n", str);

    return 0;
}

