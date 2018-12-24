#include "ArrayList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* 'Private' methods (not in .h) --------------------------------------------*/
void doubleLenIfFull(ArrayList * arrList);
/*---------------------------------------------------------------------------*/

ArrayList * ArrayList_new(int elemSize)
{
    ArrayList * arrList = (ArrayList*)malloc(sizeof(ArrayList));
    
    arrList->len = 1;
    arrList->elemSize = elemSize;
    arrList->elems = (void *) malloc((arrList->len) * elemSize);
    
    arrList->numElems = 0;

    return arrList;
}

void ArrayList_free(ArrayList * arrList)
{
    free(arrList->elems);
    free(arrList);
}

int ArrayList_size(ArrayList * arrList)
{
    return arrList->elemSize;
}

int ArrayList_numElems(ArrayList * arrList)
{
    return arrList->numElems;
}

int ArrayList_length(ArrayList * arrList)
{
    return arrList->len;
}

void ArrayList_appendCopy(ArrayList * arrList, void * newElem)
{
    doubleLenIfFull(arrList);

    (arrList->numElems)++;
    void* dest = ArrayList_get(arrList, arrList->numElems - 1); 
    void* src = newElem;
    memcpy(dest, src, arrList->elemSize);
}

void ArrayList_prependCopy(ArrayList * arrList, void* newElem)
{
    doubleLenIfFull(arrList);

    void* src = ArrayList_get(arrList,0);
    void* dest = ArrayList_get(arrList,1);
    memmove(dest, src, arrList->numElems * arrList->elemSize);
    
    (arrList->numElems)++;
    src = newElem;
    dest = arrList->elems;
    memcpy(dest, src, arrList->elemSize);

}

void ArrayList_insertCopy(ArrayList * arrList, int i, void * newElem)
{
    doubleLenIfFull(arrList);

    if (i == arrList->numElems){return ArrayList_appendCopy(arrList, newElem);}
    if (i == 0){return ArrayList_prependCopy(arrList, newElem);}

    void * src = ArrayList_get(arrList, i);
    void * dest = ArrayList_get(arrList, i+1);
    memmove(dest, src, ((arrList->numElems) - i) * arrList->elemSize);

    (arrList->numElems)++;
    src = newElem;
    dest = ArrayList_get(arrList, i);
    memcpy(dest, src, arrList->elemSize);

}

void * ArrayList_get(ArrayList * arrList, int i)
{
    // ERROR HANDLING
    // Would need to remove this if I wanted to reuse this code in other
    // spots such as in the calculation of dest in ArrayList_appendCopy
    if (i >= arrList->numElems)
    {
        fprintf(stderr,"\nCalled ArrayList_get on index >= numElems\n");
        exit(1);
    }
    return (arrList->elems) + (arrList->elemSize * i);
}

void ArrayList_printAsInt(ArrayList * arrList)
{
    printf("[");
    for (int i = 0; i < arrList->numElems; i++)
    {
        if (i == (arrList->numElems - 1))
        {
            printf("%d",*((int*) (arrList->elems + arrList->elemSize * i)));
        }
        else 
        {
            printf("%d, ",*((int*) (arrList->elems + arrList->elemSize * i)));
        }
    }
    printf("]\n");
}
void ArrayList_printAsChar(ArrayList * arrList)
{
    printf("[");
    for (int i = 0; i < arrList->numElems; i++)
    {
        if (i == (arrList->numElems - 1))
        {
            printf("%c",*((char*) (arrList->elems + arrList->elemSize * i)));
        }
        else 
        {
            printf("%c, ",*((char*) (arrList->elems + arrList->elemSize * i)));
        }
    }
    printf("]\n");
}

/* 'Private' methods (not in .h) --------------------------------------------*/

void doubleLenIfFull(ArrayList * arrList)
{
    if (arrList->numElems == arrList->len)
    {
        arrList->elems = (void *) realloc(arrList->elems, 
                (arrList->len) * arrList->elemSize * 2);
    }
}
