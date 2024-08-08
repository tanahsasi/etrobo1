#ifndef MY_UNTL_H_
#define MY_UNTL_H_

#include "ev3api.h"

extern void init_f(const char *str);
extern void msg_f(const char *str, int32_t line);

extern void msg_log(const char *str);
extern void msg_out();
extern void msg_num(char c,double x,double y,double z,  double w,double p);
extern  double msg_logbuf[30000][10];
extern  int log_max;
extern  int log_idx;

static FILE *fp=nullptr;

#endif  // MY_UNTL_H_
