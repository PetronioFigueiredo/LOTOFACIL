CC =gcc

FILES= main.c LOTOFACIL.c

OUTPUT = run

all: main.c
	$(CC) $(FILES) -o $(OUTPUT)


