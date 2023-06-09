#include <stdio.h>

// Функция для проверки совпадения строк с учетом регистра
int custom_strcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0') {
            return 0; // Строки полностью совпадают
        }
        i++;
    }
    // Строки отличаются по символу на позиции i
    return (int)(unsigned char)str1[i] - (int)(unsigned char)str2[i];
}

int main() {
    char str1[] = "Hello";
    char str2[] = "HELLO";

    int result = custom_strcmp(str1, str2);
    if (result == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }

    return 0;
}

