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


static TLS_STORE uint8_t hook_pos_sorbdb2 = 0;
#ifdef FLEXIBLAS_ABI_INTEL
void FC_GLOBAL(sorbdb2,SORBDB2)(blasint* m, blasint* p, blasint* q, float* x11, blasint* ldx11, float* x21, blasint* ldx21, float* theta, float* phi, float* taup1, float* taup2, float* tauq1, float* work, blasint* lwork, blasint* info)
#else
void FC_GLOBAL(sorbdb2,SORBDB2)(blasint* m, blasint* p, blasint* q, float* x11, blasint* ldx11, float* x21, blasint* ldx21, float* theta, float* phi, float* taup1, float* taup2, float* tauq1, float* work, blasint* lwork, blasint* info)
#endif
{
    void (*fn) (void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info);
    void (*fn_hook) (void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info);

    if ( current_backend->post_init != 0 ) {
        __flexiblas_backend_init(current_backend);
        current_backend->post_init = 0;
    }
    *(void **) & fn = current_backend->lapack.sorbdb2.f77_blas_function;
    *(void **) & fn_hook = __flexiblas_hooks->sorbdb2.f77_hook_function[0];
    if ( fn_hook == NULL ) {
        fn((void*) m, (void*) p, (void*) q, (void*) x11, (void*) ldx11, (void*) x21, (void*) ldx21, (void*) theta, (void*) phi, (void*) taup1, (void*) taup2, (void*) tauq1, (void*) work, (void*) lwork, (void*) info);
        return;
    } else {
        hook_pos_sorbdb2 = 0;
        fn_hook((void*) m, (void*) p, (void*) q, (void*) x11, (void*) ldx11, (void*) x21, (void*) ldx21, (void*) theta, (void*) phi, (void*) taup1, (void*) taup2, (void*) tauq1, (void*) work, (void*) lwork, (void*) info);
        return;
    }
}
#ifndef __APPLE__
void FC_GLOBAL2(sorbdb2,SORBDB2)(blasint* m, blasint* p, blasint* q, float* x11, blasint* ldx11, float* x21, blasint* ldx21, float* theta, float* phi, float* taup1, float* taup2, float* tauq1, float* work, blasint* lwork, blasint* info) __attribute__((alias(MTS(FC_GLOBAL(sorbdb2,SORBDB2)))));
void FC_GLOBAL3(sorbdb2,SORBDB2)(blasint* m, blasint* p, blasint* q, float* x11, blasint* ldx11, float* x21, blasint* ldx21, float* theta, float* phi, float* taup1, float* taup2, float* tauq1, float* work, blasint* lwork, blasint* info) __attribute__((alias(MTS(FC_GLOBAL(sorbdb2,SORBDB2)))));
#else
void FC_GLOBAL2(sorbdb2,SORBDB2)(blasint* m, blasint* p, blasint* q, float* x11, blasint* ldx11, float* x21, blasint* ldx21, float* theta, float* phi, float* taup1, float* taup2, float* tauq1, float* work, blasint* lwork, blasint* info){ FC_GLOBAL(sorbdb2,SORBDB2)((void*) m, (void*) p, (void*) q, (void*) x11, (void*) ldx11, (void*) x21, (void*) ldx21, (void*) theta, (void*) phi, (void*) taup1, (void*) taup2, (void*) tauq1, (void*) work, (void*) lwork, (void*) info); }
void FC_GLOBAL3(sorbdb2,SORBDB2)(blasint* m, blasint* p, blasint* q, float* x11, blasint* ldx11, float* x21, blasint* ldx21, float* theta, float* phi, float* taup1, float* taup2, float* tauq1, float* work, blasint* lwork, blasint* info){ FC_GLOBAL(sorbdb2,SORBDB2)((void*) m, (void*) p, (void*) q, (void*) x11, (void*) ldx11, (void*) x21, (void*) ldx21, (void*) theta, (void*) phi, (void*) taup1, (void*) taup2, (void*) tauq1, (void*) work, (void*) lwork, (void*) info); }
#endif




/* Real Implementation for Hooks */


void flexiblas_real_sorbdb2_(void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info)
{
    void (*fn) (void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info);

    *(void **) & fn = current_backend->lapack.sorbdb2.f77_blas_function;

    fn((void*) m, (void*) p, (void*) q, (void*) x11, (void*) ldx11, (void*) x21, (void*) ldx21, (void*) theta, (void*) phi, (void*) taup1, (void*) taup2, (void*) tauq1, (void*) work, (void*) lwork, (void*) info);

    return;
}
#ifndef __APPLE__
void flexiblas_real_sorbdb2(void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info) __attribute__((alias("flexiblas_real_sorbdb2_")));
#else
void flexiblas_real_sorbdb2(void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info){flexiblas_real_sorbdb2_((void*) m, (void*) p, (void*) q, (void*) x11, (void*) ldx11, (void*) x21, (void*) ldx21, (void*) theta, (void*) phi, (void*) taup1, (void*) taup2, (void*) tauq1, (void*) work, (void*) lwork, (void*) info);}
#endif




/* Chainloader for Hooks */


void flexiblas_chain_sorbdb2_(void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info)
{
    void (*fn) (void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info);
    void (*fn_hook) (void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info);

    *(void **) &fn      = current_backend->lapack.sorbdb2.f77_blas_function;

    hook_pos_sorbdb2 ++;
    if( hook_pos_sorbdb2 < __flexiblas_hooks->sorbdb2.nhook) {
        *(void **) &fn_hook = __flexiblas_hooks->sorbdb2.f77_hook_function[hook_pos_sorbdb2];
        fn_hook((void*) m, (void*) p, (void*) q, (void*) x11, (void*) ldx11, (void*) x21, (void*) ldx21, (void*) theta, (void*) phi, (void*) taup1, (void*) taup2, (void*) tauq1, (void*) work, (void*) lwork, (void*) info);
    } else {
        hook_pos_sorbdb2 = 0;
        fn((void*) m, (void*) p, (void*) q, (void*) x11, (void*) ldx11, (void*) x21, (void*) ldx21, (void*) theta, (void*) phi, (void*) taup1, (void*) taup2, (void*) tauq1, (void*) work, (void*) lwork, (void*) info);
    }
    return;
}
#ifndef __APPLE__
void flexiblas_chain_sorbdb2(void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info) __attribute__((alias("flexiblas_chain_sorbdb2_")));
#else
void flexiblas_chain_sorbdb2(void* m, void* p, void* q, void* x11, void* ldx11, void* x21, void* ldx21, void* theta, void* phi, void* taup1, void* taup2, void* tauq1, void* work, void* lwork, void* info){flexiblas_chain_sorbdb2_((void*) m, (void*) p, (void*) q, (void*) x11, (void*) ldx11, (void*) x21, (void*) ldx21, (void*) theta, (void*) phi, (void*) taup1, (void*) taup2, (void*) tauq1, (void*) work, (void*) lwork, (void*) info);}
#endif



