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


static TLS_STORE uint8_t hook_pos_slarfgp = 0;
#ifdef FLEXIBLAS_ABI_INTEL
void FC_GLOBAL(slarfgp,SLARFGP)(blasint* n, float* alpha, float* x, blasint* incx, float* tau)
#else
void FC_GLOBAL(slarfgp,SLARFGP)(blasint* n, float* alpha, float* x, blasint* incx, float* tau)
#endif
{
    void (*fn) (void* n, void* alpha, void* x, void* incx, void* tau);
    void (*fn_hook) (void* n, void* alpha, void* x, void* incx, void* tau);

    if ( current_backend->post_init != 0 ) {
        __flexiblas_backend_init(current_backend);
        current_backend->post_init = 0;
    }
    *(void **) & fn = current_backend->lapack.slarfgp.f77_blas_function;
    *(void **) & fn_hook = __flexiblas_hooks->slarfgp.f77_hook_function[0];
    if ( fn_hook == NULL ) {
        fn((void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) tau);
        return;
    } else {
        hook_pos_slarfgp = 0;
        fn_hook((void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) tau);
        return;
    }
}
#ifndef __APPLE__
void FC_GLOBAL2(slarfgp,SLARFGP)(blasint* n, float* alpha, float* x, blasint* incx, float* tau) __attribute__((alias(MTS(FC_GLOBAL(slarfgp,SLARFGP)))));
void FC_GLOBAL3(slarfgp,SLARFGP)(blasint* n, float* alpha, float* x, blasint* incx, float* tau) __attribute__((alias(MTS(FC_GLOBAL(slarfgp,SLARFGP)))));
#else
void FC_GLOBAL2(slarfgp,SLARFGP)(blasint* n, float* alpha, float* x, blasint* incx, float* tau){ FC_GLOBAL(slarfgp,SLARFGP)((void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) tau); }
void FC_GLOBAL3(slarfgp,SLARFGP)(blasint* n, float* alpha, float* x, blasint* incx, float* tau){ FC_GLOBAL(slarfgp,SLARFGP)((void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) tau); }
#endif




/* Real Implementation for Hooks */


void flexiblas_real_slarfgp_(void* n, void* alpha, void* x, void* incx, void* tau)
{
    void (*fn) (void* n, void* alpha, void* x, void* incx, void* tau);

    *(void **) & fn = current_backend->lapack.slarfgp.f77_blas_function;

    fn((void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) tau);

    return;
}
#ifndef __APPLE__
void flexiblas_real_slarfgp(void* n, void* alpha, void* x, void* incx, void* tau) __attribute__((alias("flexiblas_real_slarfgp_")));
#else
void flexiblas_real_slarfgp(void* n, void* alpha, void* x, void* incx, void* tau){flexiblas_real_slarfgp_((void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) tau);}
#endif




/* Chainloader for Hooks */


void flexiblas_chain_slarfgp_(void* n, void* alpha, void* x, void* incx, void* tau)
{
    void (*fn) (void* n, void* alpha, void* x, void* incx, void* tau);
    void (*fn_hook) (void* n, void* alpha, void* x, void* incx, void* tau);

    *(void **) &fn      = current_backend->lapack.slarfgp.f77_blas_function;

    hook_pos_slarfgp ++;
    if( hook_pos_slarfgp < __flexiblas_hooks->slarfgp.nhook) {
        *(void **) &fn_hook = __flexiblas_hooks->slarfgp.f77_hook_function[hook_pos_slarfgp];
        fn_hook((void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) tau);
    } else {
        hook_pos_slarfgp = 0;
        fn((void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) tau);
    }
    return;
}
#ifndef __APPLE__
void flexiblas_chain_slarfgp(void* n, void* alpha, void* x, void* incx, void* tau) __attribute__((alias("flexiblas_chain_slarfgp_")));
#else
void flexiblas_chain_slarfgp(void* n, void* alpha, void* x, void* incx, void* tau){flexiblas_chain_slarfgp_((void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) tau);}
#endif



