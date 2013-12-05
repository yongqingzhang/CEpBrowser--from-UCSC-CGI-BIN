/* isochores.c was originally generated by the autoSql program, which also 
 * generated isochores.h and isochores.sql.  This module links the database and the RAM 
 * representation of objects. */

#include "common.h"
#include "jksql.h"
#include "isochores.h"

static char const rcsid[] = "$Id: isochores.c,v 1.4 2005/04/13 06:25:54 markd Exp $";

void isochoresStaticLoad(char **row, struct isochores *ret)
/* Load a row from isochores table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->chrom = row[0];
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = row[3];
ret->gcPpt = sqlUnsigned(row[4]);
}

struct isochores *isochoresLoad(char **row)
/* Load a isochores from row fetched with select * from isochores
 * from database.  Dispose of this with isochoresFree(). */
{
struct isochores *ret;

AllocVar(ret);
ret->chrom = cloneString(row[0]);
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = cloneString(row[3]);
ret->gcPpt = sqlUnsigned(row[4]);
return ret;
}

struct isochores *isochoresCommaIn(char **pS, struct isochores *ret)
/* Create a isochores out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new isochores */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->chrom = sqlStringComma(&s);
ret->chromStart = sqlUnsignedComma(&s);
ret->chromEnd = sqlUnsignedComma(&s);
ret->name = sqlStringComma(&s);
ret->gcPpt = sqlUnsignedComma(&s);
*pS = s;
return ret;
}

void isochoresFree(struct isochores **pEl)
/* Free a single dynamically allocated isochores such as created
 * with isochoresLoad(). */
{
struct isochores *el;

if ((el = *pEl) == NULL) return;
freeMem(el->chrom);
freeMem(el->name);
freez(pEl);
}

void isochoresFreeList(struct isochores **pList)
/* Free a list of dynamically allocated isochores's */
{
struct isochores *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    isochoresFree(&el);
    }
*pList = NULL;
}

void isochoresOutput(struct isochores *el, FILE *f, char sep, char lastSep) 
/* Print out isochores.  Separate fields with sep. Follow last field with lastSep. */
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
fprintf(f, "%u", el->gcPpt);
fputc(lastSep,f);
}
