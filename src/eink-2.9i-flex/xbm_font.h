#ifndef __XBM_FONT__
#define __XBM_FONT__


typedef struct {
    char ascii;
    unsigned char w;
    unsigned char h;
    char *bits;
} xbm_font;

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif //__XBM_FONT__
