CFLAGS += -Wall -Wextra -O0 -ggdb -lm -Wno-unused-variable -Wno-unused-parameter -no-pie

TARGETS:= tests_vector

all: $(TARGETS)

RUN := $(patsubst %,run_%, $(TARGETS))

clean:
	rm -f *.o $(TARGETS)
	rm -rf ../*.o $(TARGETS)

$(RUN): run_%: %
	valgrind --show-reachable=yes --leak-check=full --error-exitcode=1 ./$* \
	&& echo "No se detectaron errores de memoria"


tests_vector: tests_vector.o ../vector.o
	$(CC) $(CFLAGS) $^ -o $@

vector.o: ../vector.c

.PHONY: all clean

