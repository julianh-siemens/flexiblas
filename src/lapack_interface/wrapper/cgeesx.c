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


static TLS_STORE uint8_t hook_pos_cgeesx = 0;
#ifdef FLEXIBLAS_ABI_INTEL
void FC_GLOBAL(cgeesx,CGEESX)(char* jobvs, char* sort, blaslogical* select, char* sense, blasint* n, float complex* a, blasint* lda, blasint* sdim, float complex* w, float complex* vs, blasint* ldvs, float* rconde, float* rcondv, float complex* work, blasint* lwork, float* rwork, blaslogical* bwork, blasint* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense)
#else
void FC_GLOBAL(cgeesx,CGEESX)(char* jobvs, char* sort, blaslogical* select, char* sense, blasint* n, float complex* a, blasint* lda, blasint* sdim, float complex* w, float complex* vs, blasint* ldvs, float* rconde, float* rcondv, float complex* work, blasint* lwork, float* rwork, blaslogical* bwork, blasint* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense)
#endif
{
    void (*fn) (void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense);
    void (*fn_hook) (void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense);

    if ( current_backend->post_init != 0 ) {
        __flexiblas_backend_init(current_backend);
        current_backend->post_init = 0;
    }
    *(void **) & fn = current_backend->lapack.cgeesx.f77_blas_function;
    *(void **) & fn_hook = __flexiblas_hooks->cgeesx.f77_hook_function[0];
    if ( fn_hook == NULL ) {
        fn((void*) jobvs, (void*) sort, (void*) select, (void*) sense, (void*) n, (void*) a, (void*) lda, (void*) sdim, (void*) w, (void*) vs, (void*) ldvs, (void*) rconde, (void*) rcondv, (void*) work, (void*) lwork, (void*) rwork, (void*) bwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobvs, ( flexiblas_fortran_charlen_t ) len_sort, ( flexiblas_fortran_charlen_t ) len_sense);
        return;
    } else {
        hook_pos_cgeesx = 0;
        fn_hook((void*) jobvs, (void*) sort, (void*) select, (void*) sense, (void*) n, (void*) a, (void*) lda, (void*) sdim, (void*) w, (void*) vs, (void*) ldvs, (void*) rconde, (void*) rcondv, (void*) work, (void*) lwork, (void*) rwork, (void*) bwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobvs, ( flexiblas_fortran_charlen_t ) len_sort, ( flexiblas_fortran_charlen_t ) len_sense);
        return;
    }
}
#ifndef __APPLE__
void FC_GLOBAL2(cgeesx,CGEESX)(char* jobvs, char* sort, blaslogical* select, char* sense, blasint* n, float complex* a, blasint* lda, blasint* sdim, float complex* w, float complex* vs, blasint* ldvs, float* rconde, float* rcondv, float complex* work, blasint* lwork, float* rwork, blaslogical* bwork, blasint* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense) __attribute__((alias(MTS(FC_GLOBAL(cgeesx,CGEESX)))));
void FC_GLOBAL3(cgeesx,CGEESX)(char* jobvs, char* sort, blaslogical* select, char* sense, blasint* n, float complex* a, blasint* lda, blasint* sdim, float complex* w, float complex* vs, blasint* ldvs, float* rconde, float* rcondv, float complex* work, blasint* lwork, float* rwork, blaslogical* bwork, blasint* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense) __attribute__((alias(MTS(FC_GLOBAL(cgeesx,CGEESX)))));
#else
void FC_GLOBAL2(cgeesx,CGEESX)(char* jobvs, char* sort, blaslogical* select, char* sense, blasint* n, float complex* a, blasint* lda, blasint* sdim, float complex* w, float complex* vs, blasint* ldvs, float* rconde, float* rcondv, float complex* work, blasint* lwork, float* rwork, blaslogical* bwork, blasint* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense){ FC_GLOBAL(cgeesx,CGEESX)((void*) jobvs, (void*) sort, (void*) select, (void*) sense, (void*) n, (void*) a, (void*) lda, (void*) sdim, (void*) w, (void*) vs, (void*) ldvs, (void*) rconde, (void*) rcondv, (void*) work, (void*) lwork, (void*) rwork, (void*) bwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobvs, (flexiblas_fortran_charlen_t) len_sort, (flexiblas_fortran_charlen_t) len_sense); }
void FC_GLOBAL3(cgeesx,CGEESX)(char* jobvs, char* sort, blaslogical* select, char* sense, blasint* n, float complex* a, blasint* lda, blasint* sdim, float complex* w, float complex* vs, blasint* ldvs, float* rconde, float* rcondv, float complex* work, blasint* lwork, float* rwork, blaslogical* bwork, blasint* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense){ FC_GLOBAL(cgeesx,CGEESX)((void*) jobvs, (void*) sort, (void*) select, (void*) sense, (void*) n, (void*) a, (void*) lda, (void*) sdim, (void*) w, (void*) vs, (void*) ldvs, (void*) rconde, (void*) rcondv, (void*) work, (void*) lwork, (void*) rwork, (void*) bwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobvs, (flexiblas_fortran_charlen_t) len_sort, (flexiblas_fortran_charlen_t) len_sense); }
#endif




/* Real Implementation for Hooks */


void flexiblas_real_cgeesx_(void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense)
{
    void (*fn) (void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense);

    *(void **) & fn = current_backend->lapack.cgeesx.f77_blas_function;

    fn((void*) jobvs, (void*) sort, (void*) select, (void*) sense, (void*) n, (void*) a, (void*) lda, (void*) sdim, (void*) w, (void*) vs, (void*) ldvs, (void*) rconde, (void*) rcondv, (void*) work, (void*) lwork, (void*) rwork, (void*) bwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobvs, ( flexiblas_fortran_charlen_t ) len_sort, ( flexiblas_fortran_charlen_t ) len_sense);

    return;
}
#ifndef __APPLE__
void flexiblas_real_cgeesx(void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense) __attribute__((alias("flexiblas_real_cgeesx_")));
#else
void flexiblas_real_cgeesx(void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense){flexiblas_real_cgeesx_((void*) jobvs, (void*) sort, (void*) select, (void*) sense, (void*) n, (void*) a, (void*) lda, (void*) sdim, (void*) w, (void*) vs, (void*) ldvs, (void*) rconde, (void*) rcondv, (void*) work, (void*) lwork, (void*) rwork, (void*) bwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobvs, (flexiblas_fortran_charlen_t) len_sort, (flexiblas_fortran_charlen_t) len_sense);}
#endif




/* Chainloader for Hooks */


void flexiblas_chain_cgeesx_(void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense)
{
    void (*fn) (void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense);
    void (*fn_hook) (void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense);

    *(void **) &fn      = current_backend->lapack.cgeesx.f77_blas_function;

    hook_pos_cgeesx ++;
    if( hook_pos_cgeesx < __flexiblas_hooks->cgeesx.nhook) {
        *(void **) &fn_hook = __flexiblas_hooks->cgeesx.f77_hook_function[hook_pos_cgeesx];
        fn_hook((void*) jobvs, (void*) sort, (void*) select, (void*) sense, (void*) n, (void*) a, (void*) lda, (void*) sdim, (void*) w, (void*) vs, (void*) ldvs, (void*) rconde, (void*) rcondv, (void*) work, (void*) lwork, (void*) rwork, (void*) bwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobvs, ( flexiblas_fortran_charlen_t ) len_sort, ( flexiblas_fortran_charlen_t ) len_sense);
    } else {
        hook_pos_cgeesx = 0;
        fn((void*) jobvs, (void*) sort, (void*) select, (void*) sense, (void*) n, (void*) a, (void*) lda, (void*) sdim, (void*) w, (void*) vs, (void*) ldvs, (void*) rconde, (void*) rcondv, (void*) work, (void*) lwork, (void*) rwork, (void*) bwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobvs, ( flexiblas_fortran_charlen_t ) len_sort, ( flexiblas_fortran_charlen_t ) len_sense);
    }
    return;
}
#ifndef __APPLE__
void flexiblas_chain_cgeesx(void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense) __attribute__((alias("flexiblas_chain_cgeesx_")));
#else
void flexiblas_chain_cgeesx(void* jobvs, void* sort, void* select, void* sense, void* n, void* a, void* lda, void* sdim, void* w, void* vs, void* ldvs, void* rconde, void* rcondv, void* work, void* lwork, void* rwork, void* bwork, void* info, flexiblas_fortran_charlen_t len_jobvs, flexiblas_fortran_charlen_t len_sort, flexiblas_fortran_charlen_t len_sense){flexiblas_chain_cgeesx_((void*) jobvs, (void*) sort, (void*) select, (void*) sense, (void*) n, (void*) a, (void*) lda, (void*) sdim, (void*) w, (void*) vs, (void*) ldvs, (void*) rconde, (void*) rcondv, (void*) work, (void*) lwork, (void*) rwork, (void*) bwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobvs, (flexiblas_fortran_charlen_t) len_sort, (flexiblas_fortran_charlen_t) len_sense);}
#endif



