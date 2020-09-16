

OBJS = tokenizer.o uimain.o

CFLAGS = -g -O3

all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h 

clean:
	rm -f *.o tokenize
run:tokenize
	./tokenize
