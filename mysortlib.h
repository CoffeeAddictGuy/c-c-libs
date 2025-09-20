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

void merge(int* array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(sizeof(int) * n1);
    int* R = (int*)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int j = 0; j < n2; j++) R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) array[k++] = L[i++];
        else array[k++] = R[j++];
    }

    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

int partition(int* array, int left, int right) {
    int pivot = array[right];
    printf("Pivot - %d\n", pivot);
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[right]);
    return i + 1;

}

void quickSort(int* array, int left, int right) {
    if (left < right) {
        int p = partition(array, left, right);
        printf("P - %d\n", p);
        quickSort(array, left, p - 1);
        quickSort(array, p, right);
    }
}

void bidirectionalSelectionSort(int* array, int left, int right) {
    /* Изначально должна была быть сортировка перемешиванием, но меня смутила постоянная перестановка, в итоге изобрёл велосипед :^) */
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        int mn = left, mx = right-1;
        for (int i = left; i < right; i++) {
            if (array[mn] > array[i]) mn = i;
            else if (array[mx] < array[i]) mx = i;
        }

        if (mn == right - 1 && mx == left) {
            swap(&array[left], &array[right - 1]);
            swapped = 1;
        }
        else if (mn != left || mx != right -1) {
            swap(&array[mn], &array[left]);
            swap(&array[mx], &array[right-1]);
            swapped = 1;
        }
        left = left + 1;
        right = right - 1;
    }
}

void selectionSort(int* array, int arraySize) {
	int left = 0;
	while (left != arraySize - 1) {
		int mn = left;
		for (int i = left; i < arraySize; i++) {
			if (array[mn] > array[i]) mn = i;
		}
		swap(&array[mn], &array[left]);
		left = left + 1;
	}
}
