#include <stdio.h>

// Функция для сравнения строк по алфавиту
int custom_strcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        // Сравниваем символы строк
        if (str1[i] != str2[i]) {
            return (int)(unsigned char)str1[i] - (int)(unsigned char)str2[i];
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
    char str1[] = "apple";
    char str2[] = "banana";

    int result = custom_strcmp(str1, str2);
    if (result < 0) {
        printf("%s comes before %s in alphabetical order.\n", str1, str2);
    } else if (result > 0) {
        printf("%s comes after %s in alphabetical order.\n", str1, str2);
    } else {
        printf("%s and %s are equal in alphabetical order.\n", str1, str2);
    }

    return 0;
}

