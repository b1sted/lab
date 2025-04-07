#include <stdio.h>

/* Определение размеров массивов через использование констант */
#define SIZE1 5
#define SIZE2 4
#define SIZE3 6

/* Прототипы функций, используемых в дальнейшем */
void inputArray(int array[], int size, int arrayNumber);
void changeSign(const int source[], int dest[], int size);
int countPositive(const int array[], int size);
void printArray(const int array[], int size, int arrayNumber);

int main() {
    /* Объявление массивов: три исходных массива (array1, array2, array3) и три массива для хранения изменненных элементов (array1_neg, array2_neg, array3_neg) */
    int array1[SIZE1];
    int array2[SIZE2];
    int array3[SIZE3];

    int array1_neg[SIZE1];
    int array2_neg[SIZE2];
    int array3_neg[SIZE3];

    /* Объявление переменных для хранения количества положительных элементов в массивах */
    int positiveCount1, positiveCount2, positiveCount3;

    /* Ввод элементов массивов */
    inputArray(array1, SIZE1, 1);
    inputArray(array2, SIZE2, 2);
    inputArray(array3, SIZE3, 3);

    /* Изменение знака элементов и формирование новых массивов */
    changeSign(array1, array1_neg, SIZE1);
    changeSign(array2, array2_neg, SIZE2);
    changeSign(array3, array3_neg, SIZE3);

    /* Вывод исходных массивов */
    printf("\nИсходные массивы:\n");
    printArray(array1, SIZE1, 1);
    printArray(array2, SIZE2, 2);
    printArray(array3, SIZE3, 3);

    /* Вывод измененных массивов */
    printf("\nМассивы с измененным знаком элементов:\n");
    printArray(array1_neg, SIZE1, 1);
    printArray(array2_neg, SIZE2, 2);
    printArray(array3_neg, SIZE3, 3);

    /* Подсчет положительных элементов в исходных массивах */
    positiveCount1 = countPositive(array1_neg, SIZE1);
    positiveCount2 = countPositive(array2_neg, SIZE2);
    positiveCount3 = countPositive(array3_neg, SIZE3);

    /* Вывод количества положительных элементов */
    printf("\nКоличество положительных элементов в измененных массивах:\n");
    printf("Массив 1: %d\n", positiveCount1);
    printf("Массив 2: %d\n", positiveCount2);
    printf("Массив 3: %d\n", positiveCount3);

    return 0;
}

/**
 * Функция для ввода элементов массива:
 *  Аргумент array - массив для заполнения;
 *  Аргумент size - размер массива;
 *  Аргумент arrayNumber - номер массива для отображения пользователю.
 */
void inputArray(int array[], int size, int arrayNumber) {
    int i, result, c;

    printf("Введите %d элементов для массива %d:\n", size, arrayNumber);
    for (i = 0; i < size; i++) {
        printf("Элемент %d: ", i + 1);
        while (1) {
            result = scanf("%d", &array[i]);

            if (result != 1) {
                /* Если ввод не является целым числом, очистка буфера и повторный запрос */
                while (getchar() != '\n' && !feof(stdin));
                printf("Неверный ввод. Пожалуйста, введите целое число для элемента %d: ", i + 1);
            } else {
                /* Проверка, остались ли символы после числа (например, точка) */
                c = getchar();
                if (c == '\n' || c == EOF) {
                    /* Корректный ввод целого числа */
                    break;
                } else {
                    /* Если после числа есть дополнительные символы, очистка буфера и повторный запрос */
                    while (getchar() != '\n' && !feof(stdin));
                    printf("Неверный ввод. Пожалуйста, введите целое число для элемента %d: ", i + 1);
                }
            }
        }
    }
}

/**
 * Функция для изменения знака всех элементов массива:
 *  Аргумент source - исходный массив.
 *  Аргумент dest - массив для хранения измененных элементов;
 *  Аргумент size - размер массива.
 */
void changeSign(const int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = -source[i];
    }
}

/**
 * Функция для подсчета количества положительных элементов в массиве:
 *  Аргумент array - массив для анализа.
 *  Аргумент size - размер массива.
 */
int countPositive(const int array[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            count++;
        }
    }
    return count;
}

/**
 * Функция для вывода элементов массива:
 *  Аргумент array - массив для вывода;
 *  Аргумент size - размер массива;
 *  Аргумент arrayNumber - номер массива для отображения пользователю.
 */
void printArray(const int array[], int size, int arrayNumber) {
    printf("Массив %d: ", arrayNumber);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
