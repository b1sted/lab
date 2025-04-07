#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

int n;

// Структура для хранения информации о запасах
typedef struct {
    char name[50];
    int normative;
    char unit[20];
    int currentValue;
} Stocks;

// Функция для ввода массива структур
void inputStruct(Stocks nomenclature[]) {
    for (int i = 0; i < n; i++) {
        printf("Введите данные для товара %d:\n", i + 1);
        printf("Наименование товара: ");
        getchar(); // Устранение символа новой строки после предыдущего ввода
        fgets(nomenclature[i].name, sizeof(nomenclature[i].name), stdin);
        nomenclature[i].name[strcspn(nomenclature[i].name, "\n")] = '\0'; // Устранение символа новой строки

        printf("Норматив на величину товара: ");
        scanf("%d", &nomenclature[i].normative);
        getchar(); // Очищаем буфер от лишнего символа новой строки

        printf("Единица измерения: ");
        fgets(nomenclature[i].unit, sizeof(nomenclature[i].unit), stdin);
        nomenclature[i].unit[strcspn(nomenclature[i].unit, "\n")] = '\0'; // Устранение символа новой строки

        printf("Текущее значение запаса: ");
        scanf("%d", &nomenclature[i].currentValue);
        getchar(); // Очищаем буфер от лишнего символа новой строки

        printf("\n");
    }
}

// Функция для обработки массива структур
void processStruct(Stocks nomenclature[]) {
    printf("Сведения о товарах, запасы которых меньше норматива:\n");
    for (int i = 0; i < n; i++) {
        if (nomenclature[i].currentValue < nomenclature[i].normative) {
            printf("Наименование товара: %s\n", nomenclature[i].name);
            printf("Отличие текущего значения запаса от нормативного: %d %s\n", nomenclature[i].normative - nomenclature[i].currentValue, 
            nomenclature[i].unit);
            printf("\n");
        }
    }
}

// Функция для вывода результатов
void displayStruct(Stocks nomenclature[]) {
    processStruct(nomenclature);
}

int main() {
    // Ввод количества товаров
    printf("Введите количество товаров: ");
    scanf("%d", &n);

    Stocks nomenclature[n];

    // Ввод данных о товарах
    inputStruct(nomenclature);

    // Вывод товаров, запасы которых меньше норматива
    displayStruct(nomenclature);

    return 0;
}