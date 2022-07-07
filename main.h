#ifndef MAIN_H
#define MAIN_H

int* createIndexArr(int n);

int* duplicateNumbers(const int* numbers, int length);

int* fib(int max_num);

typedef struct ArrayList ArrayList;
struct ArrayList
{
    int* arr;
    size_t capacity;
    size_t index;
};

ArrayList newArrayList(size_t capacity);

int getAtIndex(ArrayList* pList, size_t index);

int addToList(ArrayList* pList, int value);

int removeAtIndex(ArrayList* pList, size_t index);

ArrayList cloneList(ArrayList* pList);

void printReverse(char string[], size_t sizeOfString);

int stringCompare(const char* a, const char* b);

char** split(const char* str, int* pOutputCount);

#endif