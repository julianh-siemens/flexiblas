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


static TLS_STORE uint8_t hook_pos_dbdsvdx = 0;
#ifdef FLEXIBLAS_ABI_INTEL
void FC_GLOBAL(dbdsvdx,DBDSVDX)(char* uplo, char* jobz, char* range, blasint* n, double* d, double* e, double* vl, double* vu, blasint* il, blasint* iu, blasint* ns, double* s, double* z, blasint* ldz, double* work, blasint* iwork, blasint* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range)
#else
void FC_GLOBAL(dbdsvdx,DBDSVDX)(char* uplo, char* jobz, char* range, blasint* n, double* d, double* e, double* vl, double* vu, blasint* il, blasint* iu, blasint* ns, double* s, double* z, blasint* ldz, double* work, blasint* iwork, blasint* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range)
#endif
{
    void (*fn) (void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range);
    void (*fn_hook) (void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range);

    if ( current_backend->post_init != 0 ) {
        __flexiblas_backend_init(current_backend);
        current_backend->post_init = 0;
    }
    *(void **) & fn = current_backend->lapack.dbdsvdx.f77_blas_function;
    *(void **) & fn_hook = __flexiblas_hooks->dbdsvdx.f77_hook_function[0];
    if ( fn_hook == NULL ) {
        fn((void*) uplo, (void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) ns, (void*) s, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_uplo, ( flexiblas_fortran_charlen_t ) len_jobz, ( flexiblas_fortran_charlen_t ) len_range);
        return;
    } else {
        hook_pos_dbdsvdx = 0;
        fn_hook((void*) uplo, (void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) ns, (void*) s, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_uplo, ( flexiblas_fortran_charlen_t ) len_jobz, ( flexiblas_fortran_charlen_t ) len_range);
        return;
    }
}
#ifndef __APPLE__
void FC_GLOBAL2(dbdsvdx,DBDSVDX)(char* uplo, char* jobz, char* range, blasint* n, double* d, double* e, double* vl, double* vu, blasint* il, blasint* iu, blasint* ns, double* s, double* z, blasint* ldz, double* work, blasint* iwork, blasint* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range) __attribute__((alias(MTS(FC_GLOBAL(dbdsvdx,DBDSVDX)))));
void FC_GLOBAL3(dbdsvdx,DBDSVDX)(char* uplo, char* jobz, char* range, blasint* n, double* d, double* e, double* vl, double* vu, blasint* il, blasint* iu, blasint* ns, double* s, double* z, blasint* ldz, double* work, blasint* iwork, blasint* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range) __attribute__((alias(MTS(FC_GLOBAL(dbdsvdx,DBDSVDX)))));
#else
void FC_GLOBAL2(dbdsvdx,DBDSVDX)(char* uplo, char* jobz, char* range, blasint* n, double* d, double* e, double* vl, double* vu, blasint* il, blasint* iu, blasint* ns, double* s, double* z, blasint* ldz, double* work, blasint* iwork, blasint* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range){ FC_GLOBAL(dbdsvdx,DBDSVDX)((void*) uplo, (void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) ns, (void*) s, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) info, (flexiblas_fortran_charlen_t) len_uplo, (flexiblas_fortran_charlen_t) len_jobz, (flexiblas_fortran_charlen_t) len_range); }
void FC_GLOBAL3(dbdsvdx,DBDSVDX)(char* uplo, char* jobz, char* range, blasint* n, double* d, double* e, double* vl, double* vu, blasint* il, blasint* iu, blasint* ns, double* s, double* z, blasint* ldz, double* work, blasint* iwork, blasint* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range){ FC_GLOBAL(dbdsvdx,DBDSVDX)((void*) uplo, (void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) ns, (void*) s, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) info, (flexiblas_fortran_charlen_t) len_uplo, (flexiblas_fortran_charlen_t) len_jobz, (flexiblas_fortran_charlen_t) len_range); }
#endif




/* Real Implementation for Hooks */


void flexiblas_real_dbdsvdx_(void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range)
{
    void (*fn) (void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range);

    *(void **) & fn = current_backend->lapack.dbdsvdx.f77_blas_function;

    fn((void*) uplo, (void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) ns, (void*) s, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_uplo, ( flexiblas_fortran_charlen_t ) len_jobz, ( flexiblas_fortran_charlen_t ) len_range);

    return;
}
#ifndef __APPLE__
void flexiblas_real_dbdsvdx(void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range) __attribute__((alias("flexiblas_real_dbdsvdx_")));
#else
void flexiblas_real_dbdsvdx(void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range){flexiblas_real_dbdsvdx_((void*) uplo, (void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) ns, (void*) s, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) info, (flexiblas_fortran_charlen_t) len_uplo, (flexiblas_fortran_charlen_t) len_jobz, (flexiblas_fortran_charlen_t) len_range);}
#endif




/* Chainloader for Hooks */


void flexiblas_chain_dbdsvdx_(void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range)
{
    void (*fn) (void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range);
    void (*fn_hook) (void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range);

    *(void **) &fn      = current_backend->lapack.dbdsvdx.f77_blas_function;

    hook_pos_dbdsvdx ++;
    if( hook_pos_dbdsvdx < __flexiblas_hooks->dbdsvdx.nhook) {
        *(void **) &fn_hook = __flexiblas_hooks->dbdsvdx.f77_hook_function[hook_pos_dbdsvdx];
        fn_hook((void*) uplo, (void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) ns, (void*) s, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_uplo, ( flexiblas_fortran_charlen_t ) len_jobz, ( flexiblas_fortran_charlen_t ) len_range);
    } else {
        hook_pos_dbdsvdx = 0;
        fn((void*) uplo, (void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) ns, (void*) s, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) info, ( flexiblas_fortran_charlen_t ) len_uplo, ( flexiblas_fortran_charlen_t ) len_jobz, ( flexiblas_fortran_charlen_t ) len_range);
    }
    return;
}
#ifndef __APPLE__
void flexiblas_chain_dbdsvdx(void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range) __attribute__((alias("flexiblas_chain_dbdsvdx_")));
#else
void flexiblas_chain_dbdsvdx(void* uplo, void* jobz, void* range, void* n, void* d, void* e, void* vl, void* vu, void* il, void* iu, void* ns, void* s, void* z, void* ldz, void* work, void* iwork, void* info, flexiblas_fortran_charlen_t len_uplo, flexiblas_fortran_charlen_t len_jobz, flexiblas_fortran_charlen_t len_range){flexiblas_chain_dbdsvdx_((void*) uplo, (void*) jobz, (void*) range, (void*) n, (void*) d, (void*) e, (void*) vl, (void*) vu, (void*) il, (void*) iu, (void*) ns, (void*) s, (void*) z, (void*) ldz, (void*) work, (void*) iwork, (void*) info, (flexiblas_fortran_charlen_t) len_uplo, (flexiblas_fortran_charlen_t) len_jobz, (flexiblas_fortran_charlen_t) len_range);}
#endif



