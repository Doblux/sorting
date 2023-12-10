#ifndef __SORTING_H__
#define __SORTING_H__


#include "vector.h"
#include <stddef.h>
#include <stdint.h>

// in-place --> que no pide memoria adicional


// Se va insertando en el lugar correspondiente cada elemento en un arreglo
// ordenado. Son n elementos e insertar ordenado cuesta O(n). Trabaja in-place.
void insertion_sort(vector_t*, uint32_t);

//Busca el mínimo elemento entre una posición i y el final de la lista, lo
//intercambia con el elemento de la posición i e incrementa i. Buscar el menor
//cuesta O(n) y son n elementos. Trabaja in-place.
void selection_sort(vector_t*);

#endif
