CC=clang
CFLAGS=-W -Wall -Werror -g
EXE=output.elf
CFILES=vertex.c graph.c adj_list_node.c adj_list.c
OBJ=vertex.o graph.o adj_list_node.o adj_list.o

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ): $(CFILES)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o $(EXE)
