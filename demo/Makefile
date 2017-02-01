include ../Makefile.in

DEBUG := -g
OPT :=

SRCS := $(wildcard *.c)
HEADERS := $(wildcard *.h)
TARGETS := $(SRCS:.c=)


.PHONY: default all demo
default all demo: $(TARGETS)

%: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(DEBUG) $(OPT) -o $@ $< -L../build/double-static -lftu -lfftw3 -lm


.PHONY: clean-demo clean
clean-demo clean:
	rm -f $(TARGETS)
