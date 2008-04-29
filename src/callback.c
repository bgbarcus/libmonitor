/*
 *  Libmonitor default callback functions.
 *
 *  Define the defaults as weak symbols and allow the client to
 *  override a subset of them.
 *
 *  This file is in the public domain.
 *
 *  $Id$
 */

#include <sys/types.h>
#include <unistd.h>
#include "config.h"
#include "common.h"
#include "monitor.h"

void __attribute__ ((weak))
monitor_init_library(void)
{
    MONITOR_DEBUG1("(default callback)\n");
}

void __attribute__ ((weak))
monitor_fini_library(void)
{
    MONITOR_DEBUG1("(default callback)\n");
}

void * __attribute__ ((weak))
monitor_pre_fork(void)
{
    MONITOR_DEBUG1("(default callback)\n");
    return (NULL);
}

void __attribute__ ((weak))
monitor_post_fork(pid_t child, void *data)
{
    MONITOR_DEBUG("(default callback) child = %d\n", child);
}

void * __attribute__ ((weak))
monitor_init_process(int *argc, char **argv, void *data)
{
    int i;

    MONITOR_DEBUG("(default callback) parent = %d, argc = %d\n",
		  (int)getppid(), *argc);
    for (i = 0; i < *argc; i++) {
	MONITOR_DEBUG("argv[%d] = %s\n", i, argv[i]);
    }
    return (data);
}

void __attribute__ ((weak))
monitor_fini_process(int how, void *data)
{
    MONITOR_DEBUG("(default callback) how = %d\n", how);
}

void * __attribute__ ((weak))
monitor_thread_pre_create(void)
{
    MONITOR_DEBUG1("(default callback)\n");
    return (NULL);
}

void __attribute__ ((weak))
monitor_thread_post_create(void *data)
{
    MONITOR_DEBUG1("(default callback)\n");
}

void __attribute__ ((weak))
monitor_init_thread_support(void)
{
    MONITOR_DEBUG1("(default callback)\n");
}

void * __attribute__ ((weak))
monitor_init_thread(int tid, void *data)
{
    MONITOR_DEBUG("(default callback) tid = %d\n", tid);
    return (data);
}

void __attribute__ ((weak))
monitor_fini_thread(void *data)
{
    MONITOR_DEBUG1("(default callback)\n");
}

void __attribute__ ((weak))
monitor_pre_dlopen(const char *path, int flags)
{
}

void __attribute__ ((weak))
monitor_dlopen(const char *path, int flags, void *handle)
{
    MONITOR_DEBUG("(default callback) path = %s, flags = %d, handle = %p\n",
		  path, flags, handle);
}

void __attribute__ ((weak))
monitor_dlclose(void *handle)
{
    MONITOR_DEBUG("(default callback) handle = %p\n", handle);
}

void __attribute__ ((weak))
monitor_post_dlclose(void *handle, int ret)
{
}

void __attribute__ ((weak))
monitor_init_mpi(int *argc, char ***argv)
{
    int i;

    MONITOR_DEBUG("(default callback) size = %d, rank = %d, argc = %d\n",
		  monitor_mpi_comm_size(), monitor_mpi_comm_rank(), *argc);
    for (i = 0; i < *argc; i++) {
	MONITOR_DEBUG("argv[%d] = %s\n", i, (*argv)[i]);
    }
}

void __attribute__ ((weak))
monitor_fini_mpi(void)
{
    MONITOR_DEBUG1("(default callback)\n");
}