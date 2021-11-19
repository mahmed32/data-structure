#include <assert.h>
#include "static_array.h"

void sa_init(s_array* array, int value)
{
    unsigned int i;
    while(i < SA_DEF_SIZE - 1)
        array->data[i++] = value;
    array->data[i] = value;

    return;
}

bool sa_set_data(s_array* array, int value, unsigned int index)
{
    if(index >= SA_DEF_SIZE) return 0;

    array->data[index] = value;
    return 1;
}

bool sa_get_at(s_array* array, unsigned int index, int* result)
{
    if(index >= SA_DEF_SIZE) return 0;

    *result = array->data[index];
    return 1;
}

bool sa_search(s_array* array, int value, unsigned int* result_index)
{
    unsigned int i;

    for(i = 0; i < SA_DEF_SIZE - 1; i++) /* the -1 is because i is unsigned */
        if(array->data[i] == value)
        {
            *result_index = i;
            return 1;
        }
    if(array->data[i] == value)
    {
        *result_index = i;
        return 1;
    }

    return 0;
}

int main(void)
{
    return 0;
    s_array arr;
    sa_init(&arr, 0);
    int holder;

    assert(sizeof(arr) == SA_DEF_SIZE * sizeof(int));
    assert(sa_set_data(&arr, 1, 0) == 1);
    assert(sa_set_data(&arr, 0, -1) == 0);
    assert(sa_set_data(&arr, 0, SA_DEF_SIZE) == 0);
    assert(sa_get_at(&arr, SA_DEF_SIZE, &holder));
    assert(sa_get_at(&arr, 0, &holder) == 1);
    assert(holder == 1);
    assert(sa_search(&arr, 1, &holder) == 1);
    assert(holder == 0);
    assert(sa_search(&arr, 2, &holder) == 0);
}
    

