# a Makefile should be capitalized, as per GNU standards, the standards of \
# the creator
all: main.c
	gcc -o pipe_it main.c

run: all
	./pipe_it
clean:
	rm pipe_it
