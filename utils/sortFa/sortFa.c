/* sortFa - sort the order of records in a fa file. */
#include "common.h"
#include "fa.h"

static char const rcsid[] = "$Id: sortFa.c,v 1.1 2005/07/21 10:57:25 galt Exp $";

int dnaSeqNameCmp(const void *va, const void *vb)
/* Compare two slNames. */
{
const struct dnaSeq *a = *((struct dnaSeq **)va);
const struct dnaSeq *b = *((struct dnaSeq **)vb);
return strcmp(a->name, b->name);
}

void dnaSeqSort(struct dnaSeq **pList)
/* Sort slName list. */
{
slSort(pList, dnaSeqNameCmp);
}

void sortFa(char *inName, char *outName)
/* sortFa - scramble the order of records in an fa file. */
{
struct dnaSeq *seqList, *seq;
FILE *out;

seqList = faReadAllMixed(inName);  
out = mustOpen(outName, "w");
dnaSeqSort(&seqList);
for(seq=seqList; seq; seq=seq->next)
    {
    faWriteNext(out, seq->name, seq->dna, seq->size);
    }
fclose(out);
freeDnaSeqList(&seqList);
}

void usage()
/* Explain usage and exit. */
{
errAbort("sortFa - sort records in a fa file by id\n"
         "usage:\n"
	 "    sortFa in.fa out.fa");
}

int main(int argc, char *argv[])
/* Process command line. */
{
if (argc != 3)
    usage();
sortFa(argv[1], argv[2]);
return 0;
}
