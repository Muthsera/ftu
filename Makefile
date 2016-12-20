include Makefile.in

LIB := libfft_util.a
HEADER := fft_util.h

PREFIX := /usr/local

$(LIB): $(OBJS) $(HDRS)
	$(AR) $@ $^

.PHONY: demo
demo: $(LIB)
	$(MAKE) -C demo

install: $(LIB)
	$(INSTALL) src/$(HEADER) $(PREFIX)/include/
	$(INSTALL) build/$(LIB) $(PREFIX)/lib/

uninstall:
	$(UNINSTALL) $(PREFIX)/include/$(HEADER)
	$(UNINSTALL) $(PREFIX)/lib/$(LIB)
