OBJS = uimain.c history.c tokenizer.c

CFLAGS=-g O3

all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CLAGS) $(OBJS)
$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokenize
run:tokenize
	./tokenize
