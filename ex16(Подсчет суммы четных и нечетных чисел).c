#include <stdio.h>

// Функция для определения четности числа
int is_even(int num) {
    if (num % 2 == 0) {
        return 1; // Четное число
    }
    return 0; // Нечетное число
}

// Функция для подсчета суммы четных и нечетных чисел
void count_even_odd_sum(int* arr, int size, int* even_sum, int* odd_sum) {
    *even_sum = 0;
    *odd_sum = 0;

    for (int i = 0; i < size; i++) {
        if (is_even(arr[i])) {
            *even_sum += arr[i]; // Увеличиваем сумму четных чисел
        } else {
            *odd_sum += arr[i]; // Увеличиваем сумму нечетных чисел
        }
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int even_sum, odd_sum;

    count_even_odd_sum(numbers, size, &even_sum, &odd_sum);

    printf("Sum of even numbers: %d\n", even_sum);
    printf("Sum of odd numbers: %d\n", odd_sum);

    return 0;
}

