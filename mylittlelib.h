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