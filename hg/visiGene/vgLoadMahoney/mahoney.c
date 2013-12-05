/* mahoney.c was originally generated by the autoSql program, which also 
 * generated mahoney.h and mahoney.sql.  This module links the database and
 * the RAM representation of objects. */

#include "common.h"
#include "linefile.h"
#include "dystring.h"
#include "jksql.h"
#include "mahoney.h"

static char const rcsid[] = "$Id: mahoney.c,v 1.2 2005/10/27 17:44:23 kent Exp $";

void mahoneyStaticLoad(char **row, struct mahoney *ret)
/* Load a row from mahoney table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->empty = row[0];
ret->mtf = sqlSigned(row[1]);
ret->sameAs = row[2];
ret->geneName = row[3];
ret->domain = row[4];
ret->genbank = row[5];
ret->locusId = row[6];
ret->unigene = row[7];
ret->fragSize = row[8];
ret->linzyme = row[9];
ret->rnaPol = row[10];
ret->cloneVector = row[11];
ret->seqVerified = row[12];
ret->startLoc = row[13];
ret->endLoc = row[14];
ret->fPrimer = row[15];
ret->rPrimer = row[16];
ret->fAdaptor = row[17];
ret->rAdaptor = row[18];
}

struct mahoney *mahoneyLoad(char **row)
/* Load a mahoney from row fetched with select * from mahoney
 * from database.  Dispose of this with mahoneyFree(). */
{
struct mahoney *ret;

AllocVar(ret);
ret->empty = cloneString(row[0]);
ret->mtf = sqlSigned(row[1]);
ret->sameAs = cloneString(row[2]);
ret->geneName = cloneString(row[3]);
ret->domain = cloneString(row[4]);
ret->genbank = cloneString(row[5]);
ret->locusId = cloneString(row[6]);
ret->unigene = cloneString(row[7]);
ret->fragSize = cloneString(row[8]);
ret->linzyme = cloneString(row[9]);
ret->rnaPol = cloneString(row[10]);
ret->cloneVector = cloneString(row[11]);
ret->seqVerified = cloneString(row[12]);
ret->startLoc = cloneString(row[13]);
ret->endLoc = cloneString(row[14]);
ret->fPrimer = cloneString(row[15]);
ret->rPrimer = cloneString(row[16]);
ret->fAdaptor = cloneString(row[17]);
ret->rAdaptor = cloneString(row[18]);
return ret;
}

struct mahoney *mahoneyLoadAll(char *fileName) 
/* Load all mahoney from a whitespace-separated file.
 * Dispose of this with mahoneyFreeList(). */
{
struct mahoney *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[19];

while (lineFileRow(lf, row))
    {
    el = mahoneyLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct mahoney *mahoneyLoadAllByChar(char *fileName, char chopper) 
/* Load all mahoney from a chopper separated file.
 * Dispose of this with mahoneyFreeList(). */
{
struct mahoney *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[19];

while (lineFileNextCharRow(lf, chopper, row, ArraySize(row)))
    {
    el = mahoneyLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct mahoney *mahoneyCommaIn(char **pS, struct mahoney *ret)
/* Create a mahoney out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new mahoney */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->empty = sqlStringComma(&s);
ret->mtf = sqlSignedComma(&s);
ret->sameAs = sqlStringComma(&s);
ret->geneName = sqlStringComma(&s);
ret->domain = sqlStringComma(&s);
ret->genbank = sqlStringComma(&s);
ret->locusId = sqlStringComma(&s);
ret->unigene = sqlStringComma(&s);
ret->fragSize = sqlStringComma(&s);
ret->linzyme = sqlStringComma(&s);
ret->rnaPol = sqlStringComma(&s);
ret->cloneVector = sqlStringComma(&s);
ret->seqVerified = sqlStringComma(&s);
ret->startLoc = sqlStringComma(&s);
ret->endLoc = sqlStringComma(&s);
ret->fPrimer = sqlStringComma(&s);
ret->rPrimer = sqlStringComma(&s);
ret->fAdaptor = sqlStringComma(&s);
ret->rAdaptor = sqlStringComma(&s);
*pS = s;
return ret;
}

void mahoneyFree(struct mahoney **pEl)
/* Free a single dynamically allocated mahoney such as created
 * with mahoneyLoad(). */
{
struct mahoney *el;

if ((el = *pEl) == NULL) return;
freeMem(el->empty);
freeMem(el->sameAs);
freeMem(el->geneName);
freeMem(el->domain);
freeMem(el->genbank);
freeMem(el->locusId);
freeMem(el->unigene);
freeMem(el->fragSize);
freeMem(el->linzyme);
freeMem(el->rnaPol);
freeMem(el->cloneVector);
freeMem(el->seqVerified);
freeMem(el->startLoc);
freeMem(el->endLoc);
freeMem(el->fPrimer);
freeMem(el->rPrimer);
freeMem(el->fAdaptor);
freeMem(el->rAdaptor);
freez(pEl);
}

void mahoneyFreeList(struct mahoney **pList)
/* Free a list of dynamically allocated mahoney's */
{
struct mahoney *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    mahoneyFree(&el);
    }
*pList = NULL;
}

void mahoneyOutput(struct mahoney *el, FILE *f, char sep, char lastSep) 
/* Print out mahoney.  Separate fields with sep. Follow last field with lastSep. */
{
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->empty);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%d", el->mtf);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->sameAs);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->geneName);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->domain);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->genbank);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->locusId);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->unigene);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->fragSize);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->linzyme);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->rnaPol);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->cloneVector);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->seqVerified);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->startLoc);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->endLoc);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->fPrimer);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->rPrimer);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->fAdaptor);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->rAdaptor);
if (sep == ',') fputc('"',f);
fputc(lastSep,f);
}

/* -------------------------------- End autoSql Generated Code -------------------------------- */
