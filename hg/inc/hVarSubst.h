/** Handle variable substitutions in strings from trackDb and other
 * labels. See trackDb/README for descriptions of values that 
 * can be substitute. */
#ifndef hVarSubst_h
#define hVarSubst_h
struct trackDb;

char *hVarSubst(char *desc, struct trackDb *tdb, char *database, char *src);
/* Parse a string and substitute variable references.  Return NULL if
 * no variable references were found.  Error on missing variables (except
 * $matrix).  desc is a brief description to print on error to help with
 * debugging. tdb maybe NULL to only do substitutions based on database
 * and organism. See trackDb/README for more information.*/

void hVarSubstInVar(char *desc, struct trackDb *tdb, char *database, char **varPtr);
/* hVarSubst on a dynamically allocated string, replacing string in substitutions
 * occur, freeing the old memory if necessary.  See hVarSubst for details.
 */

void hVarSubstTrackDb(struct trackDb *tdb, char *database);
/* Substitute variables in trackDb shortLabel, longLabel, and html fields. */

#endif
