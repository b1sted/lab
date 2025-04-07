#include <stdio.h>
#include <string.h>

#define MAX_LEN 129
#define MAX_WORD 20

void swap_words(char *str) {
    char *words[MAX_WORD]; // Массив указателей на слова
    int word_count = 0;    // Счётчик количества слов

    // Разделение строки на слова
    char *token = strtok(str, " ");
    while (token != NULL) {
        words[word_count++] = token; // Сохранение указателя на слово
        token = strtok(NULL, " ");
    }

    // Замена второго слова первым
    if (word_count > 1) {
        char *temp = words[0]; // Временная переменная для первого слова
        words[0] = words[1];   // Первое слово становится вторым
        words[1] = temp;       // Второе слово становится первым
    }

    char result[MAX_LEN] = ""; // Массив для строки с поменянными словами
    for (int i = 0; i < word_count; i++) {
        if (i > 0) {
            strcat(result, " "); // Добавление пробела перед каждым словом
        }
        strcat(result, words[i]);
    }

    printf("Измененная строка: %s\n", result);
}

int main() {
    int n; // Количество строк

    printf("Введите количество строк: ");
    scanf("%d", &n); // Читаем количество строк
    getchar(); // Читаем оставшийся символ новой строки

    // Проверка на ограничение n <= 20
    if (n > 20 || n <= 0) {
        printf("Неверное значение n. Допустимый диапазон: 1 <= n <= 20.\n");
        return 1;
    }

    char str[MAX_LEN]; // Массив для каждой строки

    // Чтение и обработка строк
    for (int i = 0; i < n; i++) {
        printf("\nВведите строку %d: ", i + 1);
        fgets(str, sizeof(str), stdin); // Читаем строку

        // Убираем символ новой строки
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }

        swap_words(str);
    }

    return 0;
}
