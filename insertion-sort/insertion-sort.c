#include "../sorting.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertion_sort(vector_t* vector, uint32_t elem){
    push_back(vector, elem);

    uint32_t i = vector->size - 1;

    while (i > 0)
    {
        if (i-1 >= 0 && vector->array[i] < vector->array[i-1])
        {
            uint32_t tmp = vector->array[i];
            vector->array[i] = vector->array[i-1];
            vector->array[i-1] = tmp;
        }
        i--;
    }
}
