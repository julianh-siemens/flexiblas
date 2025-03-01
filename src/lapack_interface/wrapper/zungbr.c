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


static TLS_STORE uint8_t hook_pos_zungbr = 0;
#ifdef FLEXIBLAS_ABI_INTEL
void FC_GLOBAL(zungbr,ZUNGBR)(char* vect, blasint* m, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* tau, double complex* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_vect)
#else
void FC_GLOBAL(zungbr,ZUNGBR)(char* vect, blasint* m, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* tau, double complex* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_vect)
#endif
{
    void (*fn) (void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect);
    void (*fn_hook) (void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect);

    if ( current_backend->post_init != 0 ) {
        __flexiblas_backend_init(current_backend);
        current_backend->post_init = 0;
    }
    *(void **) & fn = current_backend->lapack.zungbr.f77_blas_function;
    *(void **) & fn_hook = __flexiblas_hooks->zungbr.f77_hook_function[0];
    if ( fn_hook == NULL ) {
        fn((void*) vect, (void*) m, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) tau, (void*) work, (void*) lwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_vect);
        return;
    } else {
        hook_pos_zungbr = 0;
        fn_hook((void*) vect, (void*) m, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) tau, (void*) work, (void*) lwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_vect);
        return;
    }
}
#ifndef __APPLE__
void FC_GLOBAL2(zungbr,ZUNGBR)(char* vect, blasint* m, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* tau, double complex* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_vect) __attribute__((alias(MTS(FC_GLOBAL(zungbr,ZUNGBR)))));
void FC_GLOBAL3(zungbr,ZUNGBR)(char* vect, blasint* m, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* tau, double complex* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_vect) __attribute__((alias(MTS(FC_GLOBAL(zungbr,ZUNGBR)))));
#else
void FC_GLOBAL2(zungbr,ZUNGBR)(char* vect, blasint* m, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* tau, double complex* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_vect){ FC_GLOBAL(zungbr,ZUNGBR)((void*) vect, (void*) m, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) tau, (void*) work, (void*) lwork, (void*) info, (flexiblas_fortran_charlen_t) len_vect); }
void FC_GLOBAL3(zungbr,ZUNGBR)(char* vect, blasint* m, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* tau, double complex* work, blasint* lwork, blasint* info, flexiblas_fortran_charlen_t len_vect){ FC_GLOBAL(zungbr,ZUNGBR)((void*) vect, (void*) m, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) tau, (void*) work, (void*) lwork, (void*) info, (flexiblas_fortran_charlen_t) len_vect); }
#endif




/* Real Implementation for Hooks */


void flexiblas_real_zungbr_(void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect)
{
    void (*fn) (void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect);

    *(void **) & fn = current_backend->lapack.zungbr.f77_blas_function;

    fn((void*) vect, (void*) m, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) tau, (void*) work, (void*) lwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_vect);

    return;
}
#ifndef __APPLE__
void flexiblas_real_zungbr(void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect) __attribute__((alias("flexiblas_real_zungbr_")));
#else
void flexiblas_real_zungbr(void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect){flexiblas_real_zungbr_((void*) vect, (void*) m, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) tau, (void*) work, (void*) lwork, (void*) info, (flexiblas_fortran_charlen_t) len_vect);}
#endif




/* Chainloader for Hooks */


void flexiblas_chain_zungbr_(void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect)
{
    void (*fn) (void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect);
    void (*fn_hook) (void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect);

    *(void **) &fn      = current_backend->lapack.zungbr.f77_blas_function;

    hook_pos_zungbr ++;
    if( hook_pos_zungbr < __flexiblas_hooks->zungbr.nhook) {
        *(void **) &fn_hook = __flexiblas_hooks->zungbr.f77_hook_function[hook_pos_zungbr];
        fn_hook((void*) vect, (void*) m, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) tau, (void*) work, (void*) lwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_vect);
    } else {
        hook_pos_zungbr = 0;
        fn((void*) vect, (void*) m, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) tau, (void*) work, (void*) lwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_vect);
    }
    return;
}
#ifndef __APPLE__
void flexiblas_chain_zungbr(void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect) __attribute__((alias("flexiblas_chain_zungbr_")));
#else
void flexiblas_chain_zungbr(void* vect, void* m, void* n, void* k, void* a, void* lda, void* tau, void* work, void* lwork, void* info, flexiblas_fortran_charlen_t len_vect){flexiblas_chain_zungbr_((void*) vect, (void*) m, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) tau, (void*) work, (void*) lwork, (void*) info, (flexiblas_fortran_charlen_t) len_vect);}
#endif



