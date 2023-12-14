CFLAGS += -Wall -Wextra -O0 -ggdb -lm -Wno-unused-variable -Wno-unused-parameter -no-pie

TARGETS:= merge-sort-test

all: $(TARGETS)

RUN := $(patsubst %,run_%, $(TARGETS))

clean:
	rm -f *.o $(TARGETS)
	rm -rf ../*.o $(TARGETS)

$(RUN): run_%: %
	valgrind --show-reachable=yes --leak-check=full --error-exitcode=1 ./$* \
	&& echo "No se detectaron errores de memoria"


merge-sort-test: merge-sort-test.o merge-sort.o ../vector.o
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: all clean

