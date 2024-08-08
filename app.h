#ifdef __cplusplus
extern "C" {
#endif

#include "ev3api.h"

#define MAIN_PRIORITY    TMIN_APP_TPRI + 1
#define POLLING_PRIORITY    TMIN_APP_TPRI + 2
#define TRACER_PRIORITY    TMIN_APP_TPRI + 2
#define JUDGE_PRIORITY    TMIN_APP_TPRI + 3

#ifndef STACK_SIZE
#define STACK_SIZE      4096
#endif /* STACK_SIZE */

#ifndef TOPPERS_MACRO_ONLY

extern void main_task(intptr_t exinf);
extern void polling_task(intptr_t exinf);
extern void tracer_task(intptr_t exinf);
extern void judge_task(intptr_t exinf);

static void user_system_create();
static void user_system_destroy();

#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif

