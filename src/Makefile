
# Files for program
OBJS= tokenizer.o history.o uimain.o

#-g to debug -O3 to optimize code for performance
CFLAGS= -g -O3 

# first target built in make
all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)
clean:
	rm -f *.o tokenize
run: tokenize
	./tokenize
