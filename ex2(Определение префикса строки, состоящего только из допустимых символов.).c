#include <stdio.h>

// Функция для определения префикса строки
int prefixIsValid(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            break; // Если символ не является буквой, выходим из цикла
        }
        i++;
    }
    return i; // Возвращаем индекс первого недопустимого символа или длину строки, если все символы допустимы
}

int main() {
    const char* str = "Hello123";
    int prefixLength = prefixIsValid(str);
    
    printf("Prefix: ");
    for (int i = 0; i < prefixLength; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}

