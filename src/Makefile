

OBJS= tokenizer.o history.o uimain.o

CFLAGS=-g

all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS) 

clean:
	rm -f *.o tokenize
run: tokenize
	./tokenize
