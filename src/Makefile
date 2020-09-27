
# Files for program
OBJS= tokenizer.o history.o uimain.o

#-g to debug -O3 to optimize code for performance
CFLAGS= -g -O3

# first target built in make
all: tokenize

#compiles files with -g -O3 options and names executable tokenize
tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)

#deletes object files and executable
clean:
	rm -f *.o tokenize
#runs main program
run: tokenize
	./tokenize
