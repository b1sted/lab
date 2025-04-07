#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function prototypes
void inputArray(int arr[], int size);
void increaseElementsBy10(int arr[], int size);
int countNonNegative(int arr[], int size);
void printArray(const int arr[], int size);
void clearInputBuffer();

int main() {
    int array1[4], array2[5], array3[6];
    int nonNegativeCount = 0;

    // Input arrays
    printf("Enter 4 elements for array1 (integers only): \n");
    inputArray(array1, 4);
    printf("Enter 5 elements for array2 (integers only): \n");
    inputArray(array2, 5);
    printf("Enter 6 elements for array3 (integers only): \n");
    inputArray(array3, 6);

    // Increase each element by 10
    increaseElementsBy10(array1, 4);
    increaseElementsBy10(array2, 5);
    increaseElementsBy10(array3, 6);

    // Calculate the number of non-negative elements
    nonNegativeCount += countNonNegative(array1, 4);
    nonNegativeCount += countNonNegative(array2, 5);
    nonNegativeCount += countNonNegative(array3, 6);

    // Output results
    printf("\nArray1 after increasing by 10: ");
    printArray(array1, 4);
    printf("Array2 after increasing by 10: ");
    printArray(array2, 5);
    printf("Array3 after increasing by 10: ");
    printArray(array3, 6);

    printf("\nTotal number of non-negative elements in all arrays: %d\n", nonNegativeCount);

    return 0;
}

// Function to input an array with error checking for integers
void inputArray(int arr[], int size) {
    int i = 0;
    int temp;
    while (i < size) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &temp) != 1) {
            printf("Invalid input, please enter an integer.\n");
            clearInputBuffer();  // Clear the input buffer
        } else {
            arr[i] = temp;  // Valid input, store in array
            i++;  // Move to next element
        }
    }
}

// Function to increase each element of the array by 10
void increaseElementsBy10(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 10;
    }
}

// Function to count non-negative elements in an array
int countNonNegative(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            count++;
        }
    }
    return count;
}

// Function to print the elements of an array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Discard characters until newline or end of file
}
