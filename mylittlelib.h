#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int getRadix(int num) {
    return floor(log10(num))+1;
}

int getAnyNumberByIndex(int num, int index, int base) {
    int radix = getRadix(num)-1;
    int indexRad = (int)(pow(10, radix-index));
    if (index > radix)
        return -1;
    return num/indexRad % base;
}

int getArraySize(int *array) {
    return sizeof(array) / sizeof(array[0]);
}

void printArray(int *num, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (i == arraySize - 1)
            printf("%d\n", num[i]);
        else 
            printf("%d - ", num[i]);
    }
    printf("\n");
}

int reverseInt(int num) {
    int radix = getRadix(num)-1;
    for (int i = 0; i < radix; i++) {
        
    }
    return 0;
}