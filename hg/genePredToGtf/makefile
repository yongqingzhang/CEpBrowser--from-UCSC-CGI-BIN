include ../../inc/common.mk

MYLIBDIR = ../../lib/$(MACHTYPE)
L += $(MYSQLLIBS) -lm
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = genePredToGtf.o

genePredToGtf: $O $(MYLIBS) makefile
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/genePredToGtf $O $(MYLIBS) $L
	${STRIP} ${BINDIR}/genePredToGtf${EXE}

test:
	cd tests && ${MAKE} test

clean:
	rm -f $O $B
	cd tests && ${MAKE} clean
