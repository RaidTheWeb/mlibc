
#ifndef _SCHED_H
#define _SCHED_H

#include <abi-bits/pid_t.h>
#include <bits/size_t.h>
#include <mlibc-config.h>

// MISSING: time_t, struct timespec

// MISSING: POSIX [PS], [SS] and [TSP] options

#ifdef __cplusplus
extern "C" {
#endif

#if __MLIBC_LINUX_OPTION
#include <bits/linux/linux_sched.h>
#include <bits/linux/cpu_set.h>
#endif

#define SCHED_OTHER 0
#define SCHED_FIFO 1
#define SCHED_RR 2
#define SCHED_BATCH 3
#define SCHED_IDLE 5
#define SCHED_DEADLINE 6
#define SCHED_RESET_ON_FORK 0x40000000

struct sched_param {
	int sched_priority;
};

#ifndef __MLIBC_ABI_ONLY

int sched_yield(void);

int sched_get_priority_max(int policy);
int sched_get_priority_min(int policy);

int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param);

int sched_getparam(pid_t pid, struct sched_param *param);

#endif /* !__MLIBC_ABI_ONLY */

#ifdef __cplusplus
}
#endif

#endif // _SCHED_H

