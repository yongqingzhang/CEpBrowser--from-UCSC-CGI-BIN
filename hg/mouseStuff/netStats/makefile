include ../../../inc/common.mk

L += -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = netStats.o

netStats: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/netStats $O $(MYLIBS) $L
	${STRIP} ${BINDIR}/netStats${EXE}

clean::
	rm -f ${O}
