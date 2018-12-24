typedef struct ArrayList
{
    int len;
    int elemSize;
    void * elems;
    int numElems;
    // Add void* for method suite pointer?
}ArrayList;

ArrayList * ArrayList_new(int elemSize);
void ArrayList_free(ArrayList * arrList);
int ArrayList_size(ArrayList * arrList);
int ArrayList_numElems(ArrayList * arrList);
int ArrayList_length(ArrayList * arrList);
void ArrayList_appendCopy(ArrayList * arrList, void * newElem);
void ArrayList_prependCopy(ArrayList * arrList, void* newElem);
void ArrayList_insert(ArrayList * arrList,int i, void * newElem);
void * ArrayList_get(ArrayList * arrList, int i);
void ArrayList_printAsInt(ArrayList * arrList);
void ArrayList_printAsChar(ArrayList * arrList);
