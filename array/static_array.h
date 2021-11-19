#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#define SA_DEF_SIZE 256
typedef unsigned char bool;

typedef struct static_array {
    int data[SA_DEF_SIZE];
} s_array;

void sa_init(s_array* array, int value);
bool sa_set_data_at(s_array* array, int value, unsigned int index);
bool sa_get_at(s_array* array, unsigned int index, int* result);
bool sa_search(s_array* array, int value, unsigned int* result_index);

/* both of insert and delete functions require keep tracking of the current 
 * size of my data in the Array which is not allowed in my simple static array
 *
bool sa_insert_at(s_array* array, unsigned int index, int value);
bool sa_delete_at(s_array* array, unsigned int index);
*/

#endif
