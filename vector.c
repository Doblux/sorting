#include "vector.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

vector_t* nuevo_vector(void){
    vector_t* n = malloc(sizeof(vector_t));
    n->capacity = 2;
    n->size = 0;
    n->array = malloc(n->capacity * sizeof(uint32_t));
    return n;
}

uint64_t get_size(vector_t* v){
    return v->size;
}

void push_back(vector_t* v, uint32_t elem){
    if (v->array == NULL)
    {
        return;
    }

    if (v->array == NULL){
        v->capacity = 2;
        v->size = 1;
        v->array = malloc(v->capacity * sizeof(uint32_t));
        v->array[0] = elem;
        return;
    } else {
        if (v->size < v->capacity)
        {
            v->array[v->size] = elem;
            v->size++;
        } else if (v->size == v->capacity){
            uint64_t nueva_capacidad = 2 * v->capacity;
            uint32_t* n = realloc(v->array, nueva_capacidad * sizeof(uint32_t));
            if (n != NULL)
            {
                v->array = n;
                v->capacity = nueva_capacidad;
                v->array[v->size] = elem;
                v->size++;
            }
        } else {
            return;
        }
    }
}

int son_iguales(vector_t* v1, vector_t* v2) {
    int res = 1;
    if (v1->size != v2->size)
    {
        return 0;
    } else {
        for (uint32_t i = 0; i < v1->size; i++) {
            res = res && (v1->array[i] == v2->array[i]);
        }
    }
    return res;
}


uint32_t iesimo(vector_t* vector, size_t index){
    if ( 0 <= index && index < vector->size )
    {
        return vector->array[index];
    } else {
        return 0;
    }
}


// Copia el elemento i-ésimo del vector a la memoria apuntada por out.
void copiar_iesimo(vector_t* vector, size_t index, uint32_t* out){
    uint32_t i_esimo = iesimo(vector, index);
    *out = i_esimo;
}


vector_t* vector_mas_grande(vector_t** vector, size_t longitud_del_array){
    if (longitud_del_array > 0)
    {
        uint64_t max = vector[0]->size;
        vector_t* vec_max = vector[0];
        for (uint32_t i = 0; i < longitud_del_array; i++) {
           if (max < vector[i]->size)
           {
               max = vector[i]->size;
               vec_max = vector[i];
           }
        }
        return vec_max;
    } else {
        return NULL;
    }
}
