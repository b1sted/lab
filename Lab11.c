#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <float.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

double find_max_in_line(const char *line) {
    double max_value = -DBL_MAX;
    char temp[50];
    int index = 0;
    int in_number = 0;

    while (*line) {
        if (isdigit(*line) || *line == '.' || (*line == '-' && isdigit(*(line + 1)))) {
            if (!in_number) {
                in_number = 1;
                index = 0;
            }
            temp[index++] = *line;
        } else if (in_number) {
            temp[index] = '\0';
            double num = strtod(temp, NULL);
            if (num > max_value) {
                max_value = num;
            }
            in_number = 0;
        }
        line++;
    }

    if (in_number) {
        temp[index] = '\0';
        double num = strtod(temp, NULL);
        if (num > max_value) {
            max_value = num;
        }
    }
    return max_value;
}

void process_file(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    if (!in) {
        perror("Ошибка при открытии исходного файла");
        return;
    }

    FILE *out = fopen(output_file, "w");
    if (!out) {
        perror("Ошибка при открытии выходного файла");
        fclose(in);
        return;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), in)) {
        size_t len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        double max_line = find_max_in_line(line);
        fputs(line, out);
        fprintf(out, " %.2f\n", max_line);
    }

    fclose(in);
    fclose(out);
}

int main() {
    const char *input_file = "input.txt";
    const char *output_file = "output.txt";

    process_file(input_file, output_file);

    printf("Файл успешно обработан. Результат записан в %s. \n", output_file);

    return 0;
}
