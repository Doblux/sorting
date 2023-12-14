#include "../sorting.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void merge(uint32_t* arr, uint32_t low, uint32_t mid, uint32_t high){
    uint32_t n1 = mid - low + 1;
    uint32_t n2 = high - mid;

    // Crear arreglos temporales
    // uint32_t L[n1], R[n2];
    uint32_t* L = malloc(n1 * sizeof(uint32_t));
    uint32_t* R = malloc(n2 * sizeof(uint32_t));

    // Copiar datos a los arreglos temporales L[] y R[]
    for (uint32_t i = 0; i < n1; i++){
        L[i] = arr[low + i];
    }

    for (uint32_t j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }


    // Fusionar los arreglos temporales de vuelta al arreglo original arr[l..r]
    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void merge_sort_con_limites(vector_t* vector, uint32_t low, uint32_t high){
    if (low < high)
    {
        uint32_t mid = (high + low) / 2;
        merge_sort_con_limites(vector, low, mid);
        merge_sort_con_limites(vector, mid+1, high);

        merge(vector->array, low, mid, high);
    }
}

void merge_sort(vector_t* vector){
    merge_sort_con_limites(vector, 0, vector->size - 1);
}
