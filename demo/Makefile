include ../Makefile.in

demo: demo.o
	$(LD) -L.. -o $@ $< -lfft_utilc -lfftw3 -lm

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -I.. -c $<
