//    SPDX-License-Identifier: LGPL-3.0-or-later
/*
    This file is part of FlexiBLAS, a BLAS/LAPACK interface wrapper library.
    Copyright (C) 2013-2025 Martin Koehler

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software Foundation,
    Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <complex.h>

#include "flexiblas_config.h"

#include "flexiblas_fortran_mangle.h"

#include "flexiblas.h"

#include "flexiblas_fortran_char_len.h"


static TLS_STORE uint8_t hook_pos_dggsvp3 = 0;
#ifdef FLEXIBLAS_ABI_INTEL
void FC_GLOBAL(dggsvp3,DGGSVP3)(char* jobu, char* jobv, char* jobq, blasint* m, blasint* p, blasint* n, double* a, blasint* lda, double* b, blasint* ldb, double* tola, double* tolb, blasint* k, blasint* l, double* u, blasint* ldu, double* v, blasint* ldv, double* q, blasint* ldq, blasint* iwork, double* tau, double* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq)
#else
void FC_GLOBAL(dggsvp3,DGGSVP3)(char* jobu, char* jobv, char* jobq, blasint* m, blasint* p, blasint* n, double* a, blasint* lda, double* b, blasint* ldb, double* tola, double* tolb, blasint* k, blasint* l, double* u, blasint* ldu, double* v, blasint* ldv, double* q, blasint* ldq, blasint* iwork, double* tau, double* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq)
#endif
{
    void (*fn) (void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq);
    void (*fn_hook) (void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq);

    if ( current_backend->post_init != 0 ) {
        __flexiblas_backend_init(current_backend);
        current_backend->post_init = 0;
    }
    *(void **) & fn = current_backend->lapack.dggsvp3.f77_blas_function;
    *(void **) & fn_hook = __flexiblas_hooks->dggsvp3.f77_hook_function[0];
    if ( fn_hook == NULL ) {
        fn((void*) jobu, (void*) jobv, (void*) jobq, (void*) m, (void*) p, (void*) n, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) tola, (void*) tolb, (void*) k, (void*) l, (void*) u, (void*) ldu, (void*) v, (void*) ldv, (void*) q, (void*) ldq, (void*) iwork, (void*) tau, (void*) work, (void*) lwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobu, ( flexiblas_fortran_charlen_t ) len_jobv, ( flexiblas_fortran_charlen_t ) len_jobq);
        return;
    } else {
        hook_pos_dggsvp3 = 0;
        fn_hook((void*) jobu, (void*) jobv, (void*) jobq, (void*) m, (void*) p, (void*) n, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) tola, (void*) tolb, (void*) k, (void*) l, (void*) u, (void*) ldu, (void*) v, (void*) ldv, (void*) q, (void*) ldq, (void*) iwork, (void*) tau, (void*) work, (void*) lwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobu, ( flexiblas_fortran_charlen_t ) len_jobv, ( flexiblas_fortran_charlen_t ) len_jobq);
        return;
    }
}
#ifndef __APPLE__
void FC_GLOBAL2(dggsvp3,DGGSVP3)(char* jobu, char* jobv, char* jobq, blasint* m, blasint* p, blasint* n, double* a, blasint* lda, double* b, blasint* ldb, double* tola, double* tolb, blasint* k, blasint* l, double* u, blasint* ldu, double* v, blasint* ldv, double* q, blasint* ldq, blasint* iwork, double* tau, double* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq) __attribute__((alias(MTS(FC_GLOBAL(dggsvp3,DGGSVP3)))));
void FC_GLOBAL3(dggsvp3,DGGSVP3)(char* jobu, char* jobv, char* jobq, blasint* m, blasint* p, blasint* n, double* a, blasint* lda, double* b, blasint* ldb, double* tola, double* tolb, blasint* k, blasint* l, double* u, blasint* ldu, double* v, blasint* ldv, double* q, blasint* ldq, blasint* iwork, double* tau, double* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq) __attribute__((alias(MTS(FC_GLOBAL(dggsvp3,DGGSVP3)))));
#else
void FC_GLOBAL2(dggsvp3,DGGSVP3)(char* jobu, char* jobv, char* jobq, blasint* m, blasint* p, blasint* n, double* a, blasint* lda, double* b, blasint* ldb, double* tola, double* tolb, blasint* k, blasint* l, double* u, blasint* ldu, double* v, blasint* ldv, double* q, blasint* ldq, blasint* iwork, double* tau, double* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq){ FC_GLOBAL(dggsvp3,DGGSVP3)((void*) jobu, (void*) jobv, (void*) jobq, (void*) m, (void*) p, (void*) n, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) tola, (void*) tolb, (void*) k, (void*) l, (void*) u, (void*) ldu, (void*) v, (void*) ldv, (void*) q, (void*) ldq, (void*) iwork, (void*) tau, (void*) work, (void*) lwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobu, (flexiblas_fortran_charlen_t) len_jobv, (flexiblas_fortran_charlen_t) len_jobq); }
void FC_GLOBAL3(dggsvp3,DGGSVP3)(char* jobu, char* jobv, char* jobq, blasint* m, blasint* p, blasint* n, double* a, blasint* lda, double* b, blasint* ldb, double* tola, double* tolb, blasint* k, blasint* l, double* u, blasint* ldu, double* v, blasint* ldv, double* q, blasint* ldq, blasint* iwork, double* tau, double* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq){ FC_GLOBAL(dggsvp3,DGGSVP3)((void*) jobu, (void*) jobv, (void*) jobq, (void*) m, (void*) p, (void*) n, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) tola, (void*) tolb, (void*) k, (void*) l, (void*) u, (void*) ldu, (void*) v, (void*) ldv, (void*) q, (void*) ldq, (void*) iwork, (void*) tau, (void*) work, (void*) lwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobu, (flexiblas_fortran_charlen_t) len_jobv, (flexiblas_fortran_charlen_t) len_jobq); }
#endif




/* Real Implementation for Hooks */


void flexiblas_real_dggsvp3_(void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq)
{
    void (*fn) (void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq);

    *(void **) & fn = current_backend->lapack.dggsvp3.f77_blas_function;

    fn((void*) jobu, (void*) jobv, (void*) jobq, (void*) m, (void*) p, (void*) n, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) tola, (void*) tolb, (void*) k, (void*) l, (void*) u, (void*) ldu, (void*) v, (void*) ldv, (void*) q, (void*) ldq, (void*) iwork, (void*) tau, (void*) work, (void*) lwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobu, ( flexiblas_fortran_charlen_t ) len_jobv, ( flexiblas_fortran_charlen_t ) len_jobq);

    return;
}
#ifndef __APPLE__
void flexiblas_real_dggsvp3(void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq) __attribute__((alias("flexiblas_real_dggsvp3_")));
#else
void flexiblas_real_dggsvp3(void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq){flexiblas_real_dggsvp3_((void*) jobu, (void*) jobv, (void*) jobq, (void*) m, (void*) p, (void*) n, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) tola, (void*) tolb, (void*) k, (void*) l, (void*) u, (void*) ldu, (void*) v, (void*) ldv, (void*) q, (void*) ldq, (void*) iwork, (void*) tau, (void*) work, (void*) lwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobu, (flexiblas_fortran_charlen_t) len_jobv, (flexiblas_fortran_charlen_t) len_jobq);}
#endif




/* Chainloader for Hooks */


void flexiblas_chain_dggsvp3_(void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq)
{
    void (*fn) (void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq);
    void (*fn_hook) (void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq);

    *(void **) &fn      = current_backend->lapack.dggsvp3.f77_blas_function;

    hook_pos_dggsvp3 ++;
    if( hook_pos_dggsvp3 < __flexiblas_hooks->dggsvp3.nhook) {
        *(void **) &fn_hook = __flexiblas_hooks->dggsvp3.f77_hook_function[hook_pos_dggsvp3];
        fn_hook((void*) jobu, (void*) jobv, (void*) jobq, (void*) m, (void*) p, (void*) n, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) tola, (void*) tolb, (void*) k, (void*) l, (void*) u, (void*) ldu, (void*) v, (void*) ldv, (void*) q, (void*) ldq, (void*) iwork, (void*) tau, (void*) work, (void*) lwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobu, ( flexiblas_fortran_charlen_t ) len_jobv, ( flexiblas_fortran_charlen_t ) len_jobq);
    } else {
        hook_pos_dggsvp3 = 0;
        fn((void*) jobu, (void*) jobv, (void*) jobq, (void*) m, (void*) p, (void*) n, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) tola, (void*) tolb, (void*) k, (void*) l, (void*) u, (void*) ldu, (void*) v, (void*) ldv, (void*) q, (void*) ldq, (void*) iwork, (void*) tau, (void*) work, (void*) lwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobu, ( flexiblas_fortran_charlen_t ) len_jobv, ( flexiblas_fortran_charlen_t ) len_jobq);
    }
    return;
}
#ifndef __APPLE__
void flexiblas_chain_dggsvp3(void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq) __attribute__((alias("flexiblas_chain_dggsvp3_")));
#else
void flexiblas_chain_dggsvp3(void* jobu, void* jobv, void* jobq, void* m, void* p, void* n, void* a, void* lda, void* b, void* ldb, void* tola, void* tolb, void* k, void* l, void* u, void* ldu, void* v, void* ldv, void* q, void* ldq, void* iwork, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_jobu, flexiblas_fortran_charlen_t len_jobv, flexiblas_fortran_charlen_t len_jobq){flexiblas_chain_dggsvp3_((void*) jobu, (void*) jobv, (void*) jobq, (void*) m, (void*) p, (void*) n, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) tola, (void*) tolb, (void*) k, (void*) l, (void*) u, (void*) ldu, (void*) v, (void*) ldv, (void*) q, (void*) ldq, (void*) iwork, (void*) tau, (void*) work, (void*) lwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobu, (flexiblas_fortran_charlen_t) len_jobv, (flexiblas_fortran_charlen_t) len_jobq);}
#endif



