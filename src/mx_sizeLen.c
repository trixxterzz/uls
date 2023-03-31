#include "../inc/uls.h"

int mx_sizeLen(long size){
    if (size == 0) return 1;
    long sizeBuff = size;
    int sizeLen = 0;
    while(sizeBuff > 0){
        sizeBuff /= 10;
        sizeLen++;
    }
    return sizeLen;
}
