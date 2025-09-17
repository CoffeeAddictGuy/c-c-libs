#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int* array, int arraySize) {
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (int i = 1; i < arraySize; i++) {
            if (array[i] < array[i-1]) {
                swap(&array[i], &array[i-1]);
                swapped = 1;
            }
        }
    }
}

void gnomeSort(int* array, int arraySize) {
    int i = 1;
    int j = 2;
    while (i < arraySize) {
        if (array[i - 1] < array[i]){
            i = j;
            j += 1;
        }
        else {
            swap(&array[i - 1], &array[i]);
            i = i - 1;
            if (i == 0) {
                i = j;
                j += 1;
            }
        }
    }
}

void combSort(int* array, int arraySize) {
    int diff = arraySize - 1 - 0;
    float delFactor = 1.25;

    while (diff > 1) {
        for (int i = 0; i < arraySize - diff; i++) {
            if (array[i] > array[i + diff]) {
                swap(&array[i], &array[i + diff]);
            }
        }
        diff /= 1.25;
    }

    for (int i = 1; i < arraySize; i++) {
        if (array[i] < array[i - 1]) {
            swap(&array[i], &array[i - 1]);
        }
    }
}