PREFIX = /usr/local

LIBNAME := ftu
HEADER := $(LIBNAME).h
MAJOR_VERSION := 1
MINOR_VERSION := 0
VERSION := $(MAJOR_VERSION).$(MINOR_VERSION)

TARGETS := float-static float-shared double-static double-shared \
		  long-static long-shared

DEFAULT_TYPE := double
DEFAULT_LIB := static

# if one suffix or extension is empty,
# use empty string ""
FLOAT_SUFFIX := f
DOUBLE_SUFFIX := ""
LONG_SUFFIX := l
STATIC_EXT := .a
SHARED_EXT := .so

SRCDIR := src
BUILDDIR := build
DEPDIR := dep

.PHONY: default
default: $(DEFAULT_TYPE)-$(DEFAULT_LIB)


include Makefile.in

