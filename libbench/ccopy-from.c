/* not worth copyrighting */
/* $Id: ccopy-from.c,v 1.1 2002-06-03 15:44:18 athena Exp $ */
#include "bench.h"

/* default routine, can be overridden by user */
void problem_ccopy_from(struct problem *p, bench_complex *in)
{
     if (p->kind == PROBLEM_COMPLEX)
          copy_c2c_from(p, in);
     else {
	  if (p->sign == -1) {
	       /* forward real->hermitian transform */
	       copy_c2r(p, in);
	  } else {
	       /* backward hermitian->real transform */
	       copy_c2h(p, in);
	  }
     }

     after_problem_ccopy_from(p, in);
}
