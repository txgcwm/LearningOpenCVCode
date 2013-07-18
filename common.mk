COMPILEC     := $(CC) 
COMPILECXX   := $(CXX)


CFLAGS += -Wall -g
LDFLAGS =

CV_LIBS     :=  $(shell pkg-config --libs opencv) 
CV_CFLAGS 	:= $(shell pkg-config --cflags opencv)

export CV_LIBS CV_CFLAGS COMPILEC COMPILECXX CFLAGS
