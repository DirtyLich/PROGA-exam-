#include <stdio.h>

// Функция для подсчета количества вхождений символов из набора в строку
int count_occurrences(const char* str, const char* chars) {
    int count = 0;
    while (*str != '\0') {
        const char* ch = chars;
        while (*ch != '\0') {
            if (*str == *ch) {
                count++;
                break;
            }
            ch++;
        }
        str++;
    }
    return count;
}

int main() {
    const char* str = "Hello, World!";
    const char* chars = "lo"; // Набор символов для поиска
    int occurrences = count_occurrences(str, chars);

    printf("Number of occurrences: %d\n", occurrences);

    return 0;
}

