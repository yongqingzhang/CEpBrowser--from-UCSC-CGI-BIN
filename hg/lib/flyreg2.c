/* flyreg2.c was originally generated by the autoSql program, which also 
 * generated flyreg2.h and flyreg2.sql.  This module links the database and
 * the RAM representation of objects. */

#include "common.h"
#include "linefile.h"
#include "dystring.h"
#include "jksql.h"
#include "flyreg2.h"

static char const rcsid[] = "$Id: flyreg2.c,v 1.1 2005/02/25 21:50:09 angie Exp $";

void flyreg2StaticLoad(char **row, struct flyreg2 *ret)
/* Load a row from flyreg2 table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->chrom = row[0];
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = row[3];
ret->target = row[4];
ret->pmid = sqlUnsigned(row[5]);
ret->fpid = sqlUnsigned(row[6]);
}

struct flyreg2 *flyreg2Load(char **row)
/* Load a flyreg2 from row fetched with select * from flyreg2
 * from database.  Dispose of this with flyreg2Free(). */
{
struct flyreg2 *ret;

AllocVar(ret);
ret->chrom = cloneString(row[0]);
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = cloneString(row[3]);
ret->target = cloneString(row[4]);
ret->pmid = sqlUnsigned(row[5]);
ret->fpid = sqlUnsigned(row[6]);
return ret;
}

struct flyreg2 *flyreg2LoadAll(char *fileName) 
/* Load all flyreg2 from a whitespace-separated file.
 * Dispose of this with flyreg2FreeList(). */
{
struct flyreg2 *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[7];

while (lineFileRow(lf, row))
    {
    el = flyreg2Load(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct flyreg2 *flyreg2LoadAllByChar(char *fileName, char chopper) 
/* Load all flyreg2 from a chopper separated file.
 * Dispose of this with flyreg2FreeList(). */
{
struct flyreg2 *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[7];

while (lineFileNextCharRow(lf, chopper, row, ArraySize(row)))
    {
    el = flyreg2Load(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct flyreg2 *flyreg2CommaIn(char **pS, struct flyreg2 *ret)
/* Create a flyreg2 out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new flyreg2 */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->chrom = sqlStringComma(&s);
ret->chromStart = sqlUnsignedComma(&s);
ret->chromEnd = sqlUnsignedComma(&s);
ret->name = sqlStringComma(&s);
ret->target = sqlStringComma(&s);
ret->pmid = sqlUnsignedComma(&s);
ret->fpid = sqlUnsignedComma(&s);
*pS = s;
return ret;
}

void flyreg2Free(struct flyreg2 **pEl)
/* Free a single dynamically allocated flyreg2 such as created
 * with flyreg2Load(). */
{
struct flyreg2 *el;

if ((el = *pEl) == NULL) return;
freeMem(el->chrom);
freeMem(el->name);
freeMem(el->target);
freez(pEl);
}

void flyreg2FreeList(struct flyreg2 **pList)
/* Free a list of dynamically allocated flyreg2's */
{
struct flyreg2 *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    flyreg2Free(&el);
    }
*pList = NULL;
}

void flyreg2Output(struct flyreg2 *el, FILE *f, char sep, char lastSep) 
/* Print out flyreg2.  Separate fields with sep. Follow last field with lastSep. */
{
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->chrom);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->chromStart);
fputc(sep,f);
fprintf(f, "%u", el->chromEnd);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->name);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->target);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->pmid);
fputc(sep,f);
fprintf(f, "%u", el->fpid);
fputc(lastSep,f);
}

/* -------------------------------- End autoSql Generated Code -------------------------------- */
