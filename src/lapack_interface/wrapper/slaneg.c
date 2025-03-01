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


static TLS_STORE uint8_t hook_pos_slaneg = 0;
#ifdef FLEXIBLAS_ABI_INTEL
blasint FC_GLOBAL(slaneg,SLANEG)(blasint* n, float* d, float* lld, float* sigma, float* pivmin, blasint* r)
#else
blasint FC_GLOBAL(slaneg,SLANEG)(blasint* n, float* d, float* lld, float* sigma, float* pivmin, blasint* r)
#endif
{
    blasint (*fn) (void* n, void* d, void* lld, void* sigma, void* pivmin, void* r);
    blasint (*fn_hook) (void* n, void* d, void* lld, void* sigma, void* pivmin, void* r);
    blasint ret;

    if ( current_backend->post_init != 0 ) {
        __flexiblas_backend_init(current_backend);
        current_backend->post_init = 0;
    }
    *(void **) & fn = current_backend->lapack.slaneg.f77_blas_function;
    *(void **) & fn_hook = __flexiblas_hooks->slaneg.f77_hook_function[0];
    if ( fn_hook == NULL ) {
        ret = fn((void*) n, (void*) d, (void*) lld, (void*) sigma, (void*) pivmin, (void*) r);
        return ret;
    } else {
        hook_pos_slaneg = 0;
        ret = fn_hook((void*) n, (void*) d, (void*) lld, (void*) sigma, (void*) pivmin, (void*) r);
        return ret;
    }
}
#ifndef __APPLE__
blasint FC_GLOBAL2(slaneg,SLANEG)(blasint* n, float* d, float* lld, float* sigma, float* pivmin, blasint* r) __attribute__((alias(MTS(FC_GLOBAL(slaneg,SLANEG)))));
blasint FC_GLOBAL3(slaneg,SLANEG)(blasint* n, float* d, float* lld, float* sigma, float* pivmin, blasint* r) __attribute__((alias(MTS(FC_GLOBAL(slaneg,SLANEG)))));
#else
blasint FC_GLOBAL2(slaneg,SLANEG)(blasint* n, float* d, float* lld, float* sigma, float* pivmin, blasint* r){ return FC_GLOBAL(slaneg,SLANEG)((void*) n, (void*) d, (void*) lld, (void*) sigma, (void*) pivmin, (void*) r); }
blasint FC_GLOBAL3(slaneg,SLANEG)(blasint* n, float* d, float* lld, float* sigma, float* pivmin, blasint* r){ return FC_GLOBAL(slaneg,SLANEG)((void*) n, (void*) d, (void*) lld, (void*) sigma, (void*) pivmin, (void*) r); }
#endif




/* Real Implementation for Hooks */


blasint flexiblas_real_slaneg_(void* n, void* d, void* lld, void* sigma, void* pivmin, void* r)
{
    blasint (*fn) (void* n, void* d, void* lld, void* sigma, void* pivmin, void* r);
    blasint ret;

    *(void **) & fn = current_backend->lapack.slaneg.f77_blas_function;

    ret = fn((void*) n, (void*) d, (void*) lld, (void*) sigma, (void*) pivmin, (void*) r);

    return ret;
}
#ifndef __APPLE__
blasint flexiblas_real_slaneg(void* n, void* d, void* lld, void* sigma, void* pivmin, void* r) __attribute__((alias("flexiblas_real_slaneg_")));
#else
blasint flexiblas_real_slaneg(void* n, void* d, void* lld, void* sigma, void* pivmin, void* r){return flexiblas_real_slaneg_((void*) n, (void*) d, (void*) lld, (void*) sigma, (void*) pivmin, (void*) r);}
#endif




/* Chainloader for Hooks */


blasint flexiblas_chain_slaneg_(void* n, void* d, void* lld, void* sigma, void* pivmin, void* r)
{
    blasint (*fn) (void* n, void* d, void* lld, void* sigma, void* pivmin, void* r);
    blasint (*fn_hook) (void* n, void* d, void* lld, void* sigma, void* pivmin, void* r);
    blasint ret;

    *(void **) &fn      = current_backend->lapack.slaneg.f77_blas_function;

    hook_pos_slaneg ++;
    if( hook_pos_slaneg < __flexiblas_hooks->slaneg.nhook) {
        *(void **) &fn_hook = __flexiblas_hooks->slaneg.f77_hook_function[hook_pos_slaneg];
        ret = fn_hook((void*) n, (void*) d, (void*) lld, (void*) sigma, (void*) pivmin, (void*) r);
    } else {
        hook_pos_slaneg = 0;
        ret = fn((void*) n, (void*) d, (void*) lld, (void*) sigma, (void*) pivmin, (void*) r);
    }
    return ret;
}
#ifndef __APPLE__
blasint flexiblas_chain_slaneg(void* n, void* d, void* lld, void* sigma, void* pivmin, void* r) __attribute__((alias("flexiblas_chain_slaneg_")));
#else
blasint flexiblas_chain_slaneg(void* n, void* d, void* lld, void* sigma, void* pivmin, void* r){return flexiblas_chain_slaneg_((void*) n, (void*) d, (void*) lld, (void*) sigma, (void*) pivmin, (void*) r);}
#endif



