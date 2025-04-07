#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int arr[15];
    int count = 0;

    printf("Введите размерность одномерного массива: ");
    scanf("%d", &N);

    if (N <= 15) {
        for (int i = 0; i < N; i++) {
            printf("Введите элемент массива: ");
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < N; i++) {
            if (arr[i] < 0 && abs(arr[i]) > 10) {
                count++;
            }
        }

        printf("Исходный массив: ");
        for (int i = 0; i < N; i++)
            printf("%d ", arr[i]);
    } 
    else {
        printf("\nРазмерность массива слишком велика (разрешено создавать массивы, не превышающие 15 элементов).\n");
    }

    printf("\nКоличество отрицательных элементов, модуль которых больше 10: %d\n", count);
    return 0;
}

