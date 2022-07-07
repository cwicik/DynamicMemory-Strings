#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

int* createIndexArr(int n)
{
    int* arr = malloc(n);
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    return arr;
}

int* duplicateNumbers(const int* numbers, int length)
{
    int* arr = malloc(length);
    for (size_t i = 0; i < length; i++)
    {
        arr[i] = numbers[i];
    }
    return arr;
}

int* fib(int max_num)
{
    int firstValue = 0;
    int secondValue = 1;
    int* fibArr = (int*)malloc(sizeof(int));
    size_t i = 0;
    do
    {
        int nextValue = firstValue + secondValue;
        firstValue = secondValue;
        secondValue = nextValue;
        fibArr = (int*)realloc(fibArr, (i + 1) * sizeof(int));
        fibArr[i] = nextValue;
        i++;
    } while (secondValue < max_num);
    
    return fibArr;
}

ArrayList newArrayList(size_t capacity)
{
    struct ArrayList list = {malloc(capacity * sizeof(int)), capacity, 0};
    return list;
}

int getAtIndex(ArrayList* pList, size_t index)
{
    if (pList->index <= index || pList->index < 0)
    {
        printf("ERROR: INDEX OUT OF BOUNDS");
        exit(-1);
    }
    return pList->arr[index];
}

int addToList(ArrayList* pList, int value)
{
    if (pList->index == pList->capacity)
    {
        pList->arr = (int*)realloc(pList->arr, pList->capacity * 2 * sizeof(int));
        pList->capacity *= 2;
    }
    pList->arr[pList->index] = value;
    pList->index++;    
}   

int removeAtIndex(ArrayList* pList, size_t index)
{
    if (pList->index <= index || pList->index < 0)
    {
        printf("ERROR: INDEX OUT OF BOUNDS");
        exit(-1);
    }
    pList->index--;   
    for (size_t i = index; i < pList->index; i++)
    {
        pList->arr[i] = pList->arr[i + 1];
    }
}

ArrayList cloneList(ArrayList* pList)
{
    struct ArrayList list = newArrayList(pList->capacity);
    for (size_t i = 0; i < pList->index; i++)
    {
        addToList(&list, pList->arr[i]);
    }
    return list;
}

void printReverse(char* string, size_t sizeOfString)
{
    for (int i = sizeOfString - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }  
    printf("\n");
}

int stringCompare(const char* a, const char* b)
{
    size_t i = 0;
    
    do {
        char aChar = tolower(a[i]);
        char bChar = tolower(b[i]);

        if (aChar < bChar)
        {
            return -1;
        } 
        else if (bChar < aChar) 
        {
            return 1;
        }
        i++;
    }while(a[i]);

    if(!b[i]) 
    {
        return 0;
    }
    return -1; 
}

char** split(const char* str, int* pOutputCount)
{
    size_t stringIndex = 0;
    size_t wordIndex = 0;
    char** words = malloc(sizeof(char));

    while(str[stringIndex])
    {
        wordIndex++;
        stringIndex++; 

        if (str[stringIndex] == ' ' || str[stringIndex] == '\0')
        {           
            char* word = malloc(wordIndex * sizeof(char) + 1);

            int startOfWord = stringIndex - wordIndex;
            for (size_t i = startOfWord + (startOfWord ? 1 : 0); i < stringIndex; i++)
            {
                word[i - startOfWord] = str[i];
            }
            word[wordIndex] = '\0';
            wordIndex = 0;
            words = (char**)realloc(words, ((*pOutputCount) + 1) * sizeof(char*));
            words[*pOutputCount] = word; 
            (*pOutputCount)++;
        }       
    }
    return words;
}

int main()
{
    //1
    //a
    // int* arr = createIndexArr(5);
    // size_t sizeOfArr = 5;
    // for (size_t i = 0; i < sizeOfArr; i++)
    // {
    //     printf("%d\n", arr[i]);
    // }
    
    //b
    // int arr[] = {1,3,5,7};
    // size_t sizeOfArr = sizeof(arr) / sizeof(arr[0]);
    // int* dupArr = duplicateNumbers(arr, sizeOfArr);
    // for (size_t i = 0; i < sizeOfArr; i++)
    // {
    //     printf("%d\n", dupArr[i]);
    // }

    //c
    // int* dupArr = fib(14);
    // for (size_t i = 0; i < 6; i++)
    // {
    //     printf("%d\n", dupArr[i]);
    // }

    //2
    //a + b
    // struct ArrayList list1 = newArrayList(10);
    // for (size_t i = 0; i < 12; i++)
    // {
    //     addToList(&list1, i);
    // }

    // for (size_t i = 0; i < list1.index; i++)
    // {
    //     printf("%d\n", getAtIndex(&list1, i));
    // }
    
    // removeAtIndex(&list1, 10);

    // for (size_t i = 0; i < list1.index; i++)
    // {
    //     printf("%d\n", getAtIndex(&list1, i));
    // }

    // struct ArrayList list2 = cloneList(&list1);

    // removeAtIndex(&list2, 10);

    // printf("list2:\n");
    // for (size_t i = 0; i < list2.index; i++)
    // {
    //     printf("%d\n", getAtIndex(&list2, i));
    // }

    // printf("list1:\n");

    // for (size_t i = 0; i < list1.index; i++)
    // {
    //     printf("%d\n", getAtIndex(&list1, i));
    // }

    //3
    //a
    // char* string = "abcd";
    // printReverse(string, sizeof(string));

    //b
    // printf(" %d\n", stringCompare("abc", "abc"));

    //c
    char* sentance = "Mamas 53 Empire!";
    size_t pCount = 0;
    char** words = split(sentance, &pCount);
    
    for (size_t i = 0; i < pCount; i++)
    {
        size_t wordIndex = 0;
        char* word = words[i];
        printf("%s\n", word);
    }    

    return 0;
}
