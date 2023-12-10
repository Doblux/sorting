#include "../sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tests_selection_sort(){
    vector_t* vector_test = nuevo_vector();
    vector_t* vector_res = nuevo_vector();
    push_back(vector_test, 100);
    push_back(vector_test, 45);
    push_back(vector_test, 32);
    push_back(vector_test, 11);
    push_back(vector_test, 55);
    push_back(vector_test, 58);
    push_back(vector_test, 57);
    push_back(vector_test, 233);
    push_back(vector_test, 123);
    push_back(vector_test, 189);
    push_back(vector_test, 22);
    push_back(vector_test, 111);
    push_back(vector_test, 77);
    push_back(vector_test, 7);
    push_back(vector_test, 8);
    push_back(vector_test, 5);
    push_back(vector_test, 12);
    push_back(vector_test, 1);
    push_back(vector_test, 777);
    push_back(vector_test, 555);
    push_back(vector_test, 5555);

    push_back(vector_res, 1);
    push_back(vector_res, 5);
    push_back(vector_res, 7);
    push_back(vector_res, 8);
    push_back(vector_res, 11);
    push_back(vector_res, 12);
    push_back(vector_res, 22);
    push_back(vector_res, 32);
    push_back(vector_res, 45);
    push_back(vector_res, 55);
    push_back(vector_res, 57);
    push_back(vector_res, 58);
    push_back(vector_res, 77);
    push_back(vector_res, 100);
    push_back(vector_res, 111);
    push_back(vector_res, 123);
    push_back(vector_res, 189);
    push_back(vector_res, 233);
    push_back(vector_res, 555);
    push_back(vector_res, 777);
    push_back(vector_res, 5555);

    selection_sort(vector_test);

    if (son_iguales(vector_test, vector_res))
    {
        free(vector_test->array);
        free(vector_res->array);
        free(vector_test);
        free(vector_res);
        printf("=========================================\n");
        printf("¡Pasaron todos los tests!\n");
        printf("=========================================\n");
        exit(0);
    } else {
        printf("Los vectores no son iguales");

        printf("\nVector_test res\n");
        for (uint32_t i = 0; i < vector_test->size; i++){
            printf(" %i", vector_test->array[i]);
        }
        printf("\n=========================================\n");
        printf("\nVector_res res\n");
        for (uint32_t i = 0; i < vector_res->size; i++){
            printf(" %i", vector_res->array[i]);
        }
        free(vector_test->array);
        free(vector_res->array);
        free(vector_test);
        free(vector_res);
        exit(1);
    }
}

int main(){
    printf("= Tests de vector_test:\n");
    printf("=========================================\n");

    tests_selection_sort();

    printf("¡Pasaron todos los tests!\n");
    exit(0);
}
