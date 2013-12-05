/* qaToQac - convert from uncompressed to compressed 
 * quality score format. */
#include "common.h"
#include "linefile.h"
#include "qaSeq.h"

static char const rcsid[] = "$Id: qaToQac.c,v 1.3 2003/10/10 16:58:23 heather Exp $";

void usage()
/* Explain usage and exit. */
{
errAbort(
"qaToQac - convert from uncompressed to compressed\n"
"quality score format.\n"
"usage:\n"
"   qaToQac in.qa out.qac");
}

void qaToQac(char *inName, char *outName)
/* qaToQac - convert from uncompressed to compressed 
 * quality score format. */
{
struct lineFile *lf = lineFileOpen(inName, TRUE);
FILE *f = mustOpen(outName, "wb");
struct qaSeq *qa;

qacWriteHead(f);
while ((qa = qaReadNext(lf)) != NULL)
    {
    qacWriteNext(f, qa);
    qaSeqFree(&qa);
    }
lineFileClose(&lf);
fclose(f);
}

int main(int argc, char *argv[])
/* Process command line. */
{
if (argc < 2)
    usage();
qaToQac(argv[1], argv[2]);
return 0;
}