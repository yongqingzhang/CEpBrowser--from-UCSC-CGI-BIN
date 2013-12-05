/* mouseSyn.c was originally generated by the autoSql program, which also 
 * generated mouseSyn.h and mouseSyn.sql.  This module links the database and the RAM 
 * representation of objects. */

#include "common.h"
#include "jksql.h"
#include "mouseSyn.h"

static char const rcsid[] = "$Id: mouseSyn.c,v 1.4 2005/04/13 06:25:55 markd Exp $";

void mouseSynStaticLoad(char **row, struct mouseSyn *ret)
/* Load a row from mouseSyn table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->chrom = row[0];
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = row[3];
ret->segment = sqlSigned(row[4]);
}

struct mouseSyn *mouseSynLoad(char **row)
/* Load a mouseSyn from row fetched with select * from mouseSyn
 * from database.  Dispose of this with mouseSynFree(). */
{
struct mouseSyn *ret;

AllocVar(ret);
ret->chrom = cloneString(row[0]);
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = cloneString(row[3]);
ret->segment = sqlSigned(row[4]);
return ret;
}

struct mouseSyn *mouseSynCommaIn(char **pS, struct mouseSyn *ret)
/* Create a mouseSyn out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new mouseSyn */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->chrom = sqlStringComma(&s);
ret->chromStart = sqlUnsignedComma(&s);
ret->chromEnd = sqlUnsignedComma(&s);
ret->name = sqlStringComma(&s);
ret->segment = sqlSignedComma(&s);
*pS = s;
return ret;
}

void mouseSynFree(struct mouseSyn **pEl)
/* Free a single dynamically allocated mouseSyn such as created
 * with mouseSynLoad(). */
{
struct mouseSyn *el;

if ((el = *pEl) == NULL) return;
freeMem(el->chrom);
freeMem(el->name);
freez(pEl);
}

void mouseSynFreeList(struct mouseSyn **pList)
/* Free a list of dynamically allocated mouseSyn's */
{
struct mouseSyn *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    mouseSynFree(&el);
    }
*pList = NULL;
}

void mouseSynOutput(struct mouseSyn *el, FILE *f, char sep, char lastSep) 
/* Print out mouseSyn.  Separate fields with sep. Follow last field with lastSep. */
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
fprintf(f, "%d", el->segment);
fputc(lastSep,f);
}
