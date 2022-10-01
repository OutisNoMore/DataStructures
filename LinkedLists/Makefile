IDIR1 = dep
ODIR  = bin
SDIR  = src
CC    = g++ 
FLAGS = -g -Wall -Wextra -Werror -I $(IDIR1)

main.bin: $(ODIR)/main.o
	$(CC) $(FLAGS) $^ -o $(ODIR)/$@

$(ODIR)/main.o: $(SDIR)/main.cpp $(IDIR1)/LinkedList.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm bin/main.bin bin/*.o