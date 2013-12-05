/* cnpIafrate.c was originally generated by the autoSql program, which also 
 * generated cnpIafrate.h and cnpIafrate.sql.  This module links the database and
 * the RAM representation of objects. */

#include "common.h"
#include "linefile.h"
#include "dystring.h"
#include "jksql.h"
#include "cnpIafrate.h"

static char const rcsid[] = "$Id: cnpIafrate.c,v 1.1 2005/06/17 20:12:48 heather Exp $";

void cnpIafrateStaticLoad(char **row, struct cnpIafrate *ret)
/* Load a row from cnpIafrate table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->chrom = row[0];
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = row[3];
ret->variationType = row[4];
ret->score = atof(row[5]);
}

struct cnpIafrate *cnpIafrateLoad(char **row)
/* Load a cnpIafrate from row fetched with select * from cnpIafrate
 * from database.  Dispose of this with cnpIafrateFree(). */
{
struct cnpIafrate *ret;

AllocVar(ret);
ret->chrom = cloneString(row[0]);
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = cloneString(row[3]);
ret->variationType = cloneString(row[4]);
ret->score = atof(row[5]);
return ret;
}

struct cnpIafrate *cnpIafrateLoadAll(char *fileName) 
/* Load all cnpIafrate from a whitespace-separated file.
 * Dispose of this with cnpIafrateFreeList(). */
{
struct cnpIafrate *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[6];

while (lineFileRow(lf, row))
    {
    el = cnpIafrateLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct cnpIafrate *cnpIafrateLoadAllByChar(char *fileName, char chopper) 
/* Load all cnpIafrate from a chopper separated file.
 * Dispose of this with cnpIafrateFreeList(). */
{
struct cnpIafrate *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[6];

while (lineFileNextCharRow(lf, chopper, row, ArraySize(row)))
    {
    el = cnpIafrateLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct cnpIafrate *cnpIafrateCommaIn(char **pS, struct cnpIafrate *ret)
/* Create a cnpIafrate out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new cnpIafrate */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->chrom = sqlStringComma(&s);
ret->chromStart = sqlUnsignedComma(&s);
ret->chromEnd = sqlUnsignedComma(&s);
ret->name = sqlStringComma(&s);
ret->variationType = sqlStringComma(&s);
ret->score = sqlFloatComma(&s);
*pS = s;
return ret;
}

void cnpIafrateFree(struct cnpIafrate **pEl)
/* Free a single dynamically allocated cnpIafrate such as created
 * with cnpIafrateLoad(). */
{
struct cnpIafrate *el;

if ((el = *pEl) == NULL) return;
freeMem(el->chrom);
freeMem(el->name);
freeMem(el->variationType);
freez(pEl);
}

void cnpIafrateFreeList(struct cnpIafrate **pList)
/* Free a list of dynamically allocated cnpIafrate's */
{
struct cnpIafrate *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    cnpIafrateFree(&el);
    }
*pList = NULL;
}

void cnpIafrateOutput(struct cnpIafrate *el, FILE *f, char sep, char lastSep) 
/* Print out cnpIafrate.  Separate fields with sep. Follow last field with lastSep. */
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
fprintf(f, "%s", el->variationType);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%g", el->score);
fputc(lastSep,f);
}

/* -------------------------------- End autoSql Generated Code -------------------------------- */
