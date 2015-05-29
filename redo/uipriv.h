// 6 april 2015
#include <stdlib.h>

#define uthash_fatal(msg) complain("uthash failed: %s", (msg))
#define uthash_malloc(sz) uiAlloc((sz), "(uthash internal)")
#define uthash_free(ptr,sz) uiFree((ptr))
#include "uthash/uthash.h"

extern uiInitOptions options;

extern void *uiAlloc(size_t, const char *);
#define uiNew(T) ((T *) uiAlloc(sizeof (T), #T))
extern void *uiRealloc(void *, size_t, const char *);
extern void uiFree(void *);

extern void complain(const char *, ...);

extern void queueResize(uiControl *);

// ptrarray.c
struct ptrArray {
	void **ptrs;
	uintmax_t len;
	uintmax_t cap;
};
struct ptrArray *newPtrArray(void);
void ptrArrayDestroy(struct ptrArray *);
void ptrArrayAppend(struct ptrArray *, void *);
void ptrArrayInsertAt(struct ptrArray *, uintmax_t, void *);
void ptrArrayDelete(struct ptrArray *, uintmax_t);
#define ptrArrayIndex(p, T, i) ((T) ((p)->ptrs[(i)]))

// shouldquit.c
extern int shouldQuit(void);

// types.c
extern uiTyped *newTyped(uintmax_t type);
