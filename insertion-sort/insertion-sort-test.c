#include "../sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tests_insertion_sort(void){
    vector_t* vectorA = nuevo_vector();
    vector_t* vectorB = nuevo_vector();

    insertion_sort(vectorA, 9);
    insertion_sort(vectorA, 8);
    insertion_sort(vectorA, 7);
    insertion_sort(vectorA, 6);
    insertion_sort(vectorA, 5);
    insertion_sort(vectorA, 4);
    insertion_sort(vectorA, 3);
    insertion_sort(vectorA, 2);
    insertion_sort(vectorA, 1);

    push_back(vectorB, 1);
    push_back(vectorB, 2);
    push_back(vectorB, 3);
    push_back(vectorB, 4);
    push_back(vectorB, 5);
    push_back(vectorB, 6);
    push_back(vectorB, 7);
    push_back(vectorB, 8);
    push_back(vectorB, 9);


    if (son_iguales(vectorA, vectorB))
    {
        printf("Pasó exitosamente el test de Insertion Sort");
    } else {
        printf("Los vectores no son iguales");

        printf("\nVectorA res\n");

        for (uint32_t i = 0; i < vectorA->size; i++){
            printf("%i", vectorA->array[i]);
        }

        printf("\n=========================================\n");

        printf("\nVectorB res\n");
        for (uint32_t i = 0; i < vectorB->size; i++){
            printf("%i", vectorB->array[i]);
        }

        free(vectorA->array);
        free(vectorB->array);
        free(vectorA);
        free(vectorB);
        exit(1);
    }
    free(vectorA->array);
    free(vectorB->array);
    free(vectorA);
    free(vectorB);
}

int main(){
    printf("= Tests de vector:\n");
    printf("=========================================\n");

    tests_insertion_sort();


    printf("¡Pasaron todos los tests!\n");
    exit(0);
}
