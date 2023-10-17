// (STRLEN) ФУНКЦИЯ ДЛЯ ВЫЧИСЛЕНИЯ ДЛИНЫ СТРОКИ
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') { // Пока не достигнут символ конца строки '\0'
        length++; // Увеличиваем счетчик длины
    }
    return length;
}

// ФУНКЦИЯ ДЛЯ ВСТАВКИ ФРАГМЕНТА ИЗ СТРОКИ
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

// ФУНКЦИЯ ДЛЯ УДАЛЕНИЯ ФРАГМЕНТА СТРОКИ
void custom_delete(char* str, int position, int length) {
    int len = custom_strlen(str); // Длина строки

    // Сдвигаем символы влево, перезаписывая удаляемый фрагмент
    for (int i = position + length; i <= len; i++) {
        str[i - length] = str[i]; // Копируем символы на length позиций влево
    }
}


// ФУНКЦИЯ ДЛЯ ПРОВЕРКИ СОВПАДЕНИЯ СТРОК БЕЗ УЧЕТА РЕГИСТРА
int custom_strcasecmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char c1 = str1[i];
        char c2 = str2[i];

        if (c1 >= 'A' && c1 <= 'Z') {
            c1 += 32;
        }

        if (c2 >= 'A' && c2 <= 'Z') {
            c2 += 32;
        }

        if (c1 != c2) {
            return (int)(unsigned char)c1 - (int)(unsigned char)c2;
        }
        i++;
    }

    if (str1[i] != '\0') {
        return (int)(unsigned char)str1[i];
    }
    if (str2[i] != '\0') {
        return -((int)(unsigned char)str2[i]);
    }

    return 0;
}


//ФУНКЦИЯ ДЛЯ СРАВЕНИЯ СТРОК ПО АЛФАВИТУ
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


//ФУНКЦИЯ ДЛЯ КОПИРОВАНИЯ СТРОКИ
void custom_strcpy(char* destination, const char* source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Добавляем завершающий нуль в конец скопированной строки
}

//ФУНКЦИЯ ДЛЯ ПРОВЕРКИ ЯВЛЯЕТСЯ ЛИ СИМВОЛ ЗАГЛАВНОЙ БУКВОЙ
int custom_isupper(char c) {
    return c >= 'A' && c <= 'Z';
}


//ФУНКЦИЯ ДЛЯ ПРЕОБРАЗОВАНИЯ СИМВОЛА В НИЖНИЙ РЕГИСТР
char custom_tolower(char c) {
    if (custom_isupper(c)) {
        return c - 'A' + 'a';
    }
    return c;
}


//ФУНКЦИЯ ДЛЯ ПРЕОБРАЗОВАНИЯ СИМВОЛА В ВЕРХНИЙ РЕГИСТР
char custom_toupper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

//ФУКЦИЯ ДЛЯ ПОДСЧЕТА КОЛИЧЕСТВА ВХОЖДЕНИЙ СИМВОЛОВ ИЗ НАБОРА В СТРОКУ
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


//ОРПЕДЕЛЕНИЕ ПРЕФИКСА СТРОКИ
int is_valid_prefix(char* str, char* valid_chars) {
    int len = custom_strlen(str); // Вычисляем длину строки str
    int valid_len = custom_strlen(valid_chars); // Вычисляем длину строки valid_chars
    int i, j;
    for (i = 0; i < len; i++) { // Проходим по каждому символу в строке str
        char c = str[i]; // Получаем текущий символ
        int found = 0; // Флаг для указания, найден ли символ в списке допустимых символов
        for (j = 0; j < valid_len; j++) { // Проходим по каждому символу в списке допустимых символов
            if (c == valid_chars[j]) { // Если текущий символ совпадает с символом из списка
                found = 1; // Устанавливаем флаг found в значение 1
                break; // Прерываем цикл, так как символ уже найден
            }
        }
        if (!found) { // Если символ не найден в списке допустимых символов
            return i; // Возвращаем позицию символа, на котором нарушается условие
        }
    }
    return len; // Если все символы в строке являются допустимыми, возвращаем длину строки
}


//ФУНКЦИЯ ДЛЯ ПОИСКА ПОДСТРОКИ В СТРОКЕ
int custom_strstr(const char* str, const char* substr) {
    int len1 = custom_strlen(str); // Длина строки
    int len2 = custom_strlen(substr); // Длина подстроки

    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == len2) {
            return i; // Подстрока найдена, возвращаем индекс начала подстроки
        }
    }

    return -1; // Подстрока не найдена
}


//ФУНКЦИЯ ДЛЯ ПРЕОБРАЗОВАНИЯ СТРОКИ В ЧИСЛО
int custom_atoi(const char* str) {
    int num = 0; // Инициализируем число
    int sign = 1; // Знак числа (по умолчанию положительный)
    int i = 0; // Индекс символа строки

    // Пропускаем начальные пробелы
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v') {
        i++;
    }

    int len = custom_strlen(str); // Вычисляем длину строки

    // Определение знака числа
    if (str[i] == '-') { // Если символ '-' найден
        sign = -1; // Устанавливаем отрицательный знак
        i++;
    } else if (str[i] == '+') { // Если символ '+' найден
        i++;
    }

    // Преобразование символов в число
    while (i < len) { // Пока не достигнут конец строки
        if (str[i] >= '0' && str[i] <= '9') { // Если символ является цифрой
            num = num * 10 + (str[i] - '0'); // Увеличиваем число на значение цифры
            i++; // Переходим к следующему символу
        } else {
            break; // Если найден символ, не являющийся цифрой, прекращаем преобразование
        }
    }

    return num * sign; // Возвращаем число с учетом знака
}


//ФУНКЦИЯ ДЛЯ РАЗБИЕНИЯ СТРОКИ НА ПОЛЯ
void split_string(const char* str, char delimiter, char fields[MAX_FIELDS][MAX_FIELD_LENGTH], int* num_fields) {
    int str_length = custom_strlen(str); // Длина исходной строки
    int field_start = 0; // Начальная позиция текущего поля
    int field_length = 0; // Длина текущего поля

    for (int i = 0; i <= str_length; i++) {
        if (str[i] == delimiter || str[i] == '\0') {
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

//ФУНКЦИЯ ДЛЯ ВОССТАНОВЛЕНИЯ СТРОКИ ПОСЛЕ РАЗБИЕНИЯ
void join_fields(const char fields[MAX_FIELDS][MAX_FIELD_LENGTH], int num_fields, char delimiter, char* joined_str) {
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


//ФУНКЦИЯ ДЛЯ СЛИЯНИЯ СТРОК
void custom_strcat(char* destination, const char* source) {
    int dest_len = custom_strlen(destination);
    int src_len = custom_strlen(source);

    int i, j;
    for (i = dest_len, j = 0; j < src_len; i++, j++) {
        destination[i] = source[j];
    }
    destination[i] = '\0'; // Устанавливаем завершающий нуль-символ
}