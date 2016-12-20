CC := gcc -std=c99
CFLAGS := -Wall -Wextra
DEBUG := -g
OPT :=
LD := gcc
LFLAGS :=
INSTALL := cp -p
UNINSTALL := rm -f
AR := ar crs

LIB := libfft_util.a
HEADER := fft_util.h

PREFIX := /usr/local

$(LIB): $(OBJS) $(HDRS)
	$(AR) $@ $^

install: $(LIB)
	$(INSTALL) src/$(HEADER) $(PREFIX)/include/
	$(INSTALL) build/$(LIB) $(PREFIX)/lib/

uninstall:
	$(UNINSTALL) $(PREFIX)/include/$(HEADER)
	$(UNINSTALL) $(PREFIX)/lib/$(LIB)
