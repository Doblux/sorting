CFLAGS += -Wall -Wextra -O0 -ggdb -lm -Wno-unused-variable -Wno-unused-parameter -no-pie

TARGETS:= insertion-sort-test

all: $(TARGETS)

RUN := $(patsubst %,run_%, $(TARGETS))

clean:
	rm -f *.o $(TARGETS)
	rm -rf ../*.o $(TARGETS)

$(RUN): run_%: %
	valgrind --show-reachable=yes --leak-check=full --error-exitcode=1 ./$* \
	&& echo "No se detectaron errores de memoria"


insertion-sort-test: insertion-sort-test.o insertion-sort.o ../vector.o
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: all clean

