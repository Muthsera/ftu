include ../Makefile.in

demo: demo.o
	$(LD) -L.. -o $@ $< -lfftutilc -lfftw3 -lm

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -I.. -c $<
