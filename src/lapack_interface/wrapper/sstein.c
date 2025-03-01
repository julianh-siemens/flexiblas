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


static TLS_STORE uint8_t hook_pos_sstein = 0;
#ifdef FLEXIBLAS_ABI_INTEL
void FC_GLOBAL(sstein,SSTEIN)(blasint* n, float* d, float* e, blasint* m, float* w, blasint* iblock, blasint* isplit, float* z, blasint* ldz, float* work, blasint* iwork, blasint* ifail, blasint* info)
#else
void FC_GLOBAL(sstein,SSTEIN)(blasint* n, float* d, float* e, blasint* m, float* w, blasint* iblock, blasint* isplit, float* z, blasint* ldz, float* work, blasint* iwork, blasint* ifail, blasint* info)
#endif
{
    void (*fn) (void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info);
    void (*fn_hook) (void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info);

    if ( current_backend->post_init != 0 ) {
        __flexiblas_backend_init(current_backend);
        current_backend->post_init = 0;
    }
    *(void **) & fn = current_backend->lapack.sstein.f77_blas_function;
    *(void **) & fn_hook = __flexiblas_hooks->sstein.f77_hook_function[0];
    if ( fn_hook == NULL ) {
        fn((void*) n, (void*) d, (void*) e, (void*) m, (void*) w, (void*) iblock, (void*) isplit, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) ifail, (void*) info);
        return;
    } else {
        hook_pos_sstein = 0;
        fn_hook((void*) n, (void*) d, (void*) e, (void*) m, (void*) w, (void*) iblock, (void*) isplit, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) ifail, (void*) info);
        return;
    }
}
#ifndef __APPLE__
void FC_GLOBAL2(sstein,SSTEIN)(blasint* n, float* d, float* e, blasint* m, float* w, blasint* iblock, blasint* isplit, float* z, blasint* ldz, float* work, blasint* iwork, blasint* ifail, blasint* info) __attribute__((alias(MTS(FC_GLOBAL(sstein,SSTEIN)))));
void FC_GLOBAL3(sstein,SSTEIN)(blasint* n, float* d, float* e, blasint* m, float* w, blasint* iblock, blasint* isplit, float* z, blasint* ldz, float* work, blasint* iwork, blasint* ifail, blasint* info) __attribute__((alias(MTS(FC_GLOBAL(sstein,SSTEIN)))));
#else
void FC_GLOBAL2(sstein,SSTEIN)(blasint* n, float* d, float* e, blasint* m, float* w, blasint* iblock, blasint* isplit, float* z, blasint* ldz, float* work, blasint* iwork, blasint* ifail, blasint* info){ FC_GLOBAL(sstein,SSTEIN)((void*) n, (void*) d, (void*) e, (void*) m, (void*) w, (void*) iblock, (void*) isplit, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) ifail, (void*) info); }
void FC_GLOBAL3(sstein,SSTEIN)(blasint* n, float* d, float* e, blasint* m, float* w, blasint* iblock, blasint* isplit, float* z, blasint* ldz, float* work, blasint* iwork, blasint* ifail, blasint* info){ FC_GLOBAL(sstein,SSTEIN)((void*) n, (void*) d, (void*) e, (void*) m, (void*) w, (void*) iblock, (void*) isplit, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) ifail, (void*) info); }
#endif




/* Real Implementation for Hooks */


void flexiblas_real_sstein_(void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info)
{
    void (*fn) (void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info);

    *(void **) & fn = current_backend->lapack.sstein.f77_blas_function;

    fn((void*) n, (void*) d, (void*) e, (void*) m, (void*) w, (void*) iblock, (void*) isplit, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) ifail, (void*) info);

    return;
}
#ifndef __APPLE__
void flexiblas_real_sstein(void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info) __attribute__((alias("flexiblas_real_sstein_")));
#else
void flexiblas_real_sstein(void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info){flexiblas_real_sstein_((void*) n, (void*) d, (void*) e, (void*) m, (void*) w, (void*) iblock, (void*) isplit, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) ifail, (void*) info);}
#endif




/* Chainloader for Hooks */


void flexiblas_chain_sstein_(void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info)
{
    void (*fn) (void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info);
    void (*fn_hook) (void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info);

    *(void **) &fn      = current_backend->lapack.sstein.f77_blas_function;

    hook_pos_sstein ++;
    if( hook_pos_sstein < __flexiblas_hooks->sstein.nhook) {
        *(void **) &fn_hook = __flexiblas_hooks->sstein.f77_hook_function[hook_pos_sstein];
        fn_hook((void*) n, (void*) d, (void*) e, (void*) m, (void*) w, (void*) iblock, (void*) isplit, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) ifail, (void*) info);
    } else {
        hook_pos_sstein = 0;
        fn((void*) n, (void*) d, (void*) e, (void*) m, (void*) w, (void*) iblock, (void*) isplit, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) ifail, (void*) info);
    }
    return;
}
#ifndef __APPLE__
void flexiblas_chain_sstein(void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info) __attribute__((alias("flexiblas_chain_sstein_")));
#else
void flexiblas_chain_sstein(void* n, void* d, void* e, void* m, void* w, void* iblock, void* isplit, void* z, void* ldz, void* work, void* iwork, void* ifail, void* info){flexiblas_chain_sstein_((void*) n, (void*) d, (void*) e, (void*) m, (void*) w, (void*) iblock, (void*) isplit, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) ifail, (void*) info);}
#endif



