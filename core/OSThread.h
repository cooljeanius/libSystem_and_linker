/*
 * Core Framework: OSThread.c
 * Copyright (c) 2012 Christina Brooks
 *
 * Threading support.
 * Now, I do not really know what I'm doing but I've tried to make
 * it work.
 */

#ifndef core_OSThread_h
#define core_OSThread_h

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#elif defined(HAVE_TIME_H)
#include <time.h>
#endif

typedef int OSLowLock;

extern int lll_futex_timed_wait(OSLowLock* futex,
						 int value,
						 const struct timespec *timeout);

int lll_futex_wait(OSLowLock* futex,
				   int value);

int lll_futex_wake(OSLowLock* futex,
				   int value);

void lll_lock_wait(OSLowLock* futex);

int lll_trylock(OSLowLock* futex);

void lll_unlock(OSLowLock* futex);

void lll_lock(OSLowLock* futex);

#endif
