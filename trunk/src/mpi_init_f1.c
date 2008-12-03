/*
 *  Override mpi_init_ in Fortran.
 *
 *  $Id$
 */

#include "config.h"
#include "common.h"
#include "monitor.h"

typedef void mpi_init_fcn_t(int *);
#ifdef MONITOR_STATIC
extern mpi_init_fcn_t  __real_mpi_init_;
#endif
static mpi_init_fcn_t  *real_mpi_init = NULL;

void
MONITOR_WRAP_NAME(mpi_init_)(int *ierror)
{
    int argc;
    char **argv;

    MONITOR_DEBUG1("\n");
    MONITOR_GET_REAL_NAME_WRAP(real_mpi_init, mpi_init_);
    (*real_mpi_init)(ierror);
    MONITOR_DEBUG1("calling monitor_init_mpi() ...\n");
    monitor_get_main_args(&argc, &argv, NULL);
    monitor_init_mpi(&argc, &argv);
}
