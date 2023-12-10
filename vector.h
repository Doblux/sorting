#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h>
#include <stdint.h>

typedef struct vector_s {
	uint64_t size;
    uint64_t capacity;
	uint32_t* array;
} vector_t;

// Construye y retorna un nuevo vector vacío con capacity=2.
vector_t* nuevo_vector(void);

// Retorna la cantidad de elementos (válidos) del vector.
uint64_t get_size(vector_t*);

// Agrega un elemento al final del vector.
// Pista: leer el manual de malloc (man malloc en la Terminal) y buscar de qué
// forma se puede modificar el tamaño del bloque de memoria previamente devuelto
// por un llamado a malloc.
// Por ejemplo: si malloc nos devolvió un puntero a un bloque de 16 bytes de
// memoria, investigar de qué manera podemos hacer que ese mismo puntero ahora
// apunte a un bloque de 32 bytes (o cualquier otro tamaño que quisiéramos).
void push_back(vector_t*, uint32_t);

// Retorna el elemento i-ésimo del vector.
// Precondición: vector es válido.
// Devuelve 0 en caso que el índice sea inválido.
uint32_t iesimo(vector_t*, size_t);

// Retorna 1 si dado 2 vectores estos son iguales, es decir si todos sus elementos coinciden. Retorna 0 de otro modo.
int son_iguales(vector_t*, vector_t*);

// Copia el elemento i-ésimo del vector a la memoria apuntada por out.
void copiar_iesimo(vector_t* vector, size_t index, uint32_t* out);

// Dado un array de vectores, devuelve un puntero a aquel con mayor longitud.
// Si hay más de uno con dicha longitud, devuelve el primero. Si el array es
// vacío, devuelve NULL.
vector_t* vector_mas_grande(vector_t**, size_t);

#endif // __VECTOR_H__

