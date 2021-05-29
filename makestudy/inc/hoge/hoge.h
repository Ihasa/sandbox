#ifndef HOGE_H
#define HOGE_H

#ifdef DEF_HOGE_C
#define GLOBAL
#else
#define GLOBAL extern
#endif

GLOBAL void sayHello();

#undef GLOBAL
#endif