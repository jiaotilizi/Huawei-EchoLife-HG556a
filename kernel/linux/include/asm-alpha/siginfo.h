#ifndef _ALPHA_SIGINFO_H
#define _ALPHA_SIGINFO_H

#define __ARCH_SI_PREAMBLE_SIZE		(4 * sizeof(int))
#define __ARCH_SI_TRAPNO

#define SIGEV_PAD_SIZE			((SIGEV_MAX_SIZE/sizeof(int)) - 4)

#include <asm-generic/siginfo.h>

#endif
