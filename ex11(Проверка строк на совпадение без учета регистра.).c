#include <stdio.h>

// Функция для проверки совпадения строк без учета регистра
int custom_strcasecmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        // Преобразуем символы к одному регистру перед сравнением
        char c1 = (str1[i] >= 'A' && str1[i] <= 'Z') ? str1[i] + 32 : str1[i];
        char c2 = (str2[i] >= 'A' && str2[i] <= 'Z') ? str2[i] + 32 : str2[i];
        
        if (c1 != c2) {
            return (int)(unsigned char)c1 - (int)(unsigned char)c2;
        }
        i++;
    }
    
    // Если одна из строк еще не достигла завершающего нуля
    if (str1[i] != '\0') {
        return (int)(unsigned char)str1[i];
    }
    if (str2[i] != '\0') {
        return -((int)(unsigned char)str2[i]);
    }
    
    // Строки полностью совпадают
    return 0;
}

int main() {
    char str1[] = "Hello";
    char str2[] = "hello";

    int result = custom_strcasecmp(str1, str2);
    if (result == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }

    return 0;
}

