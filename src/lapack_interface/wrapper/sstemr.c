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


static TLS_STORE uint8_t hook_pos_sstemr = 0;
#ifdef FLEXIBLAS_ABI_INTEL
void FC_GLOBAL(sstemr,SSTEMR)(char* jobz, char* range, blasint* n, float* d, float* e, float* vl, float* vu, blasint* il, blasint* iu, blasint* m, float* w, float* z, blasint* ldz, blasint* nzc, blasint* isuppz, blaslogical* tryrac, float* work, blasint* lwork, blasint* iwork, blasint* liwork, blasint* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range)
#else
void FC_GLOBAL(sstemr,SSTEMR)(char* jobz, char* range, blasint* n, float* d, float* e, float* vl, float* vu, blasint* il, blasint* iu, blasint* m, float* w, float* z, blasint* ldz, blasint* nzc, blasint* isuppz, blaslogical* tryrac, float* work, blasint* lwork, blasint* iwork, blasint* liwork, blasint* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range)
#endif
{
    void (*fn) (void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range);
    void (*fn_hook) (void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range);

    if ( current_backend->post_init != 0 ) {
        __flexiblas_backend_init(current_backend);
        current_backend->post_init = 0;
    }
    *(void **) & fn = current_backend->lapack.sstemr.f77_blas_function;
    *(void **) & fn_hook = __flexiblas_hooks->sstemr.f77_hook_function[0];
    if ( fn_hook == NULL ) {
        fn((void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) m, (void*) w, (void*) z, (void*) ldz, (void*) nzc, (void*) isuppz, (void*) tryrac, (void*) work, (void*) lwork, (void*) iwork, (void*) liwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobz, ( flexiblas_fortran_charlen_t ) len_range);
        return;
    } else {
        hook_pos_sstemr = 0;
        fn_hook((void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) m, (void*) w, (void*) z, (void*) ldz, (void*) nzc, (void*) isuppz, (void*) tryrac, (void*) work, (void*) lwork, (void*) iwork, (void*) liwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobz, ( flexiblas_fortran_charlen_t ) len_range);
        return;
    }
}
#ifndef __APPLE__
void FC_GLOBAL2(sstemr,SSTEMR)(char* jobz, char* range, blasint* n, float* d, float* e, float* vl, float* vu, blasint* il, blasint* iu, blasint* m, float* w, float* z, blasint* ldz, blasint* nzc, blasint* isuppz, blaslogical* tryrac, float* work, blasint* lwork, blasint* iwork, blasint* liwork, blasint* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range) __attribute__((alias(MTS(FC_GLOBAL(sstemr,SSTEMR)))));
void FC_GLOBAL3(sstemr,SSTEMR)(char* jobz, char* range, blasint* n, float* d, float* e, float* vl, float* vu, blasint* il, blasint* iu, blasint* m, float* w, float* z, blasint* ldz, blasint* nzc, blasint* isuppz, blaslogical* tryrac, float* work, blasint* lwork, blasint* iwork, blasint* liwork, blasint* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range) __attribute__((alias(MTS(FC_GLOBAL(sstemr,SSTEMR)))));
#else
void FC_GLOBAL2(sstemr,SSTEMR)(char* jobz, char* range, blasint* n, float* d, float* e, float* vl, float* vu, blasint* il, blasint* iu, blasint* m, float* w, float* z, blasint* ldz, blasint* nzc, blasint* isuppz, blaslogical* tryrac, float* work, blasint* lwork, blasint* iwork, blasint* liwork, blasint* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range){ FC_GLOBAL(sstemr,SSTEMR)((void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) m, (void*) w, (void*) z, (void*) ldz, (void*) nzc, (void*) isuppz, (void*) tryrac, (void*) work, (void*) lwork, (void*) iwork, (void*) liwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobz, (flexiblas_fortran_charlen_t) len_range); }
void FC_GLOBAL3(sstemr,SSTEMR)(char* jobz, char* range, blasint* n, float* d, float* e, float* vl, float* vu, blasint* il, blasint* iu, blasint* m, float* w, float* z, blasint* ldz, blasint* nzc, blasint* isuppz, blaslogical* tryrac, float* work, blasint* lwork, blasint* iwork, blasint* liwork, blasint* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range){ FC_GLOBAL(sstemr,SSTEMR)((void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) m, (void*) w, (void*) z, (void*) ldz, (void*) nzc, (void*) isuppz, (void*) tryrac, (void*) work, (void*) lwork, (void*) iwork, (void*) liwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobz, (flexiblas_fortran_charlen_t) len_range); }
#endif




/* Real Implementation for Hooks */


void flexiblas_real_sstemr_(void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range)
{
    void (*fn) (void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range);

    *(void **) & fn = current_backend->lapack.sstemr.f77_blas_function;

    fn((void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) m, (void*) w, (void*) z, (void*) ldz, (void*) nzc, (void*) isuppz, (void*) tryrac, (void*) work, (void*) lwork, (void*) iwork, (void*) liwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobz, ( flexiblas_fortran_charlen_t ) len_range);

    return;
}
#ifndef __APPLE__
void flexiblas_real_sstemr(void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range) __attribute__((alias("flexiblas_real_sstemr_")));
#else
void flexiblas_real_sstemr(void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range){flexiblas_real_sstemr_((void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) m, (void*) w, (void*) z, (void*) ldz, (void*) nzc, (void*) isuppz, (void*) tryrac, (void*) work, (void*) lwork, (void*) iwork, (void*) liwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobz, (flexiblas_fortran_charlen_t) len_range);}
#endif




/* Chainloader for Hooks */


void flexiblas_chain_sstemr_(void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range)
{
    void (*fn) (void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range);
    void (*fn_hook) (void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range);

    *(void **) &fn      = current_backend->lapack.sstemr.f77_blas_function;

    hook_pos_sstemr ++;
    if( hook_pos_sstemr < __flexiblas_hooks->sstemr.nhook) {
        *(void **) &fn_hook = __flexiblas_hooks->sstemr.f77_hook_function[hook_pos_sstemr];
        fn_hook((void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) m, (void*) w, (void*) z, (void*) ldz, (void*) nzc, (void*) isuppz, (void*) tryrac, (void*) work, (void*) lwork, (void*) iwork, (void*) liwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobz, ( flexiblas_fortran_charlen_t ) len_range);
    } else {
        hook_pos_sstemr = 0;
        fn((void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) m, (void*) w, (void*) z, (void*) ldz, (void*) nzc, (void*) isuppz, (void*) tryrac, (void*) work, (void*) lwork, (void*) iwork, (void*) liwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_jobz, ( flexiblas_fortran_charlen_t ) len_range);
    }
    return;
}
#ifndef __APPLE__
void flexiblas_chain_sstemr(void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range) __attribute__((alias("flexiblas_chain_sstemr_")));
#else
void flexiblas_chain_sstemr(void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* m, void* w, void* z, void* ldz, void* nzc, void* isuppz, void* tryrac, void* work, void* lwork, void* iwork, void* liwork, void* info, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range){flexiblas_chain_sstemr_((void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) m, (void*) w, (void*) z, (void*) ldz, (void*) nzc, (void*) isuppz, (void*) tryrac, (void*) work, (void*) lwork, (void*) iwork, (void*) liwork, (void*) info, (flexiblas_fortran_charlen_t) len_jobz, (flexiblas_fortran_charlen_t) len_range);}
#endif



