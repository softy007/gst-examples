CC=gcc
CFLAGS=-Wall
PKG_CONFIG=`pkg-config --libs --cflags gstreamer-0.10`

all: 
	$(CC) $(CFLAGS) $(PKG_CONFIG) main.c -o $(LDLIBS) example1

clean:
	rm example1

.PHONY: all clean
