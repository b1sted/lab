#include <stdio.h>
#include "array_functions.h"

int n;

int main() {
    // Ввод размера массива
    printf("Введите размер массивов (n): ");
    scanf("%d", &n);

    // Проверка на ограничение n <= 20
    if (n > 20 || n <= 0) {
        printf("Неверное значение n. Допустимый диапазон: 1 <= n <= 20.\n");
        return 1;
    }

    // Объявление массивов
    float a[20], b[20], c[20], x[20], y[20];

    // Ввод массивов
    printf("Введите элементы массива a: ");
    input_array(a);
    printf("Введите элементы массива b: ");
    input_array(b);
    printf("Введите элементы массива c: ");
    input_array(c);

    // Вычисление массивов x и y
    calculate_arrays(a, b, x);
    calculate_arrays(b, c, y);

    // Вывод результатов
    printf("Массив x: ");
    output_array(x);
    printf("Массив y: ");
    output_array(y);

    return 0;
}
