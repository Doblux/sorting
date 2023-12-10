#include "../sorting.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t buscar_minimo_index(vector_t* vector, uint32_t d){
    uint32_t min = vector->array[d];
    uint32_t res = d;
    for (uint32_t i = d; i < vector->size; i++){
        if (min > vector->array[i]){
            min = vector->array[i];
            res = i;
        }
    }
    return res;
}


void selection_sort(vector_t* vector){
    uint32_t d = 0;
    for (uint32_t i = 0; i < vector->size; i++) {
        uint32_t min_index = buscar_minimo_index(vector, d);

        const uint32_t tmp = vector->array[i];
        vector->array[i] = vector->array[min_index];
        vector->array[min_index] = tmp;
        d++;

    }
}
