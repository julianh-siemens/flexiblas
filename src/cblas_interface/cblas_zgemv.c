/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Linking FlexiBLAS statically or dynamically with other modules is making a
 * combined work based on FlexiBLAS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * As a special exception, the copyright holders of FlexiBLAS give you permission
 * to combine FlexiBLAS program with free software programs or libraries that are
 * released under the GNU LGPL and with independent modules that communicate with
 * FlexiBLAS solely through the BLAS/LAPACK interface as provided by the
 * BLAS/LAPACK reference implementation. You may copy and distribute such a system
 * following the terms of the GNU GPL for FlexiBLAS and the licenses of the other
 * code concerned, provided that you include the source code of that other code
 * when and as the GNU GPL requires distribution of source code and provided that
 * you do not modify the BLAS/LAPACK interface.
 *
 * Note that people who make modified versions of FlexiBLAS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release a
 * modified version without this exception; this exception also makes it possible
 * to release a modified version which carries forward this exception. If you
 * modify the BLAS/LAPACK interface, this exception does not apply to your
 * modified version of FlexiBLAS, and you must remove this exception when you
 * distribute your modified version.
 *
 * This exception is an additional permission under section 7 of the GNU General
 * Public License, version 3 (“GPLv3”)
 *
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) Martin Koehler, 2013-2022
 */


#include "cblas.h"
#include "cblas_f77.h"
#include "../flexiblas.h"
#include "cblas_flexiblas.h"

static TLS_STORE uint8_t hook_cblas_zgemv_pos = 0;

void cblas_zgemv(const CBLAS_LAYOUT layout,
        const CBLAS_TRANSPOSE TransA, const CBLAS_INT M, const CBLAS_INT N,
        const void *alpha, const void  *A, const CBLAS_INT lda,
        const void  *X, const CBLAS_INT incX, const void *beta,
        void  *Y, const CBLAS_INT incY)
{
    void (*fn)
        (const CBLAS_LAYOUT layout,
         const CBLAS_TRANSPOSE TransA, const CBLAS_INT M, const CBLAS_INT N,
         const void *alpha, const void  *A, const CBLAS_INT lda,
         const void  *X, const CBLAS_INT incX, const void *beta,
         void  *Y, const CBLAS_INT incY);
    CBLAS_BACKEND_INIT();
    CBLAS_HOOK_SELECT(zgemv);
    fn(layout,TransA,M,N,alpha,A,lda,X,incX,beta,Y,incY);


}

void flexiblas_chain_cblas_zgemv(const CBLAS_LAYOUT layout,
        const CBLAS_TRANSPOSE TransA, const CBLAS_INT M, const CBLAS_INT N,
        const void *alpha, const void  *A, const CBLAS_INT lda,
        const void  *X, const CBLAS_INT incX, const void *beta,
        void  *Y, const CBLAS_INT incY)
{
    void (*fn)
        (const CBLAS_LAYOUT layout,
         const CBLAS_TRANSPOSE TransA, const CBLAS_INT M, const CBLAS_INT N,
         const void *alpha, const void  *A, const CBLAS_INT lda,
         const void  *X, const CBLAS_INT incX, const void *beta,
         void  *Y, const CBLAS_INT incY);
    CBLAS_HOOK_ADVANCE(zgemv);
    fn(layout,TransA,M,N,alpha,A,lda,X,incX,beta,Y,incY);


}

void flexiblas_real_cblas_zgemv(const CBLAS_LAYOUT layout,
        const CBLAS_TRANSPOSE TransA, const CBLAS_INT M, const CBLAS_INT N,
        const void *alpha, const void  *A, const CBLAS_INT lda,
        const void  *X, const CBLAS_INT incX, const void *beta,
        void  *Y, const CBLAS_INT incY)
{
    char TA;
#define F77_TA &TA
#ifdef F77_INT
    F77_INT F77_M=M, F77_N=N, F77_lda=lda, F77_incX=incX, F77_incY=incY;
#else
#define F77_M M
#define F77_N N
#define F77_lda lda
#define F77_incX incx
#define F77_incY incY
#endif

    if ( current_backend->blas.zgemv.cblas_function != NULL ) {

        void (*fn)
            (const CBLAS_LAYOUT layout,
             const CBLAS_TRANSPOSE TransA, const CBLAS_INT M, const CBLAS_INT N,
             const void *alpha, const void  *A, const CBLAS_INT lda,
             const void  *X, const CBLAS_INT incX, const void *beta,
             void  *Y, const CBLAS_INT incY)
            = current_backend->blas.zgemv.cblas_function;
        fn(layout,TransA,M,N,alpha,A,lda,X,incX,beta,Y,incY);
    } else {
        CBLAS_INT n=0, i=0, incx=incX;
        double *xx;;
        double ALPHA[2],BETA[2];
        CBLAS_INT tincY, tincx;
        double *x = NULL, *y=(double *)Y, *st=0, *tx=0;
        const double *stx = x;
        extern int CBLAS_CallFromC;
        extern int RowMajorStrg;
        RowMajorStrg = 0;

        COPY_CONST_PTR(xx,X);
        COPY_CONST_PTR(x,X);

        CBLAS_CallFromC = 1;

        if (layout == CblasColMajor)
        {
            if (TransA == CblasNoTrans) TA = 'N';
            else if (TransA == CblasTrans) TA = 'T';
            else if (TransA == CblasConjTrans) TA = 'C';
            else
            {
                cblas_xerbla(2, "cblas_zgemv","Illegal TransA setting, %d\n", TransA);
                CBLAS_CallFromC = 0;
                RowMajorStrg = 0;
                return;
            }
#ifdef F77_CHAR
            F77_TA = C2F_CHAR(&TA);
#endif
            FC_GLOBAL(zgemv,ZGEMV)(F77_TA, &F77_M, &F77_N, alpha, A, &F77_lda, X, &F77_incX,
                    beta, Y, &F77_incY);
        }
        else if (layout == CblasRowMajor)
        {
            RowMajorStrg = 1;
            if (TransA == CblasNoTrans) TA = 'T';
            else if (TransA == CblasTrans) TA = 'N';
            else if (TransA == CblasConjTrans)
            {
                ALPHA[0]=    *( (const double *)  alpha    );
                ALPHA[1]= -( *( (const double *)  alpha+1) );
                BETA[0]=     *( (const double *)  beta     );
                BETA[1]= -(  *( (const double *)  beta+1 ) );
                TA = 'N';
                if (M > 0)
                {
                    n = M << 1;
                    x = malloc(n*sizeof(double));
                    tx = x;
                    if( incX > 0 ) {
                        i = incX << 1 ;
                        tincx = 2;
                        st= x+n;
                    } else {
                        i = incX *(-2);
                        tincx = -2;
                        st = x-2;
                        x +=(n-2);
                    }

                    do
                    {
                        *x = *xx;
                        x[1] = -xx[1];
                        x += tincx ;
                        xx += i;
                    }
                    while (x != st);
                    x=tx;

                    F77_incX = 1;

                    if(incY > 0)
                        tincY = incY;
                    else
                        tincY = -incY;

                    y++;

                    if (N > 0)
                    {
                        i = tincY << 1;
                        n = i * N ;
                        st = y + n;
                        do {
                            *y = -(*y);
                            y += i;
                        } while(y != st);
                        y -= n;
                    }
                    stx = x;
                }
                else stx = (const double *)X;
            }
            else
            {
                cblas_xerbla(2, "cblas_zgemv","Illegal TransA setting, %d\n", TransA);
                CBLAS_CallFromC = 0;
                RowMajorStrg = 0;
                return;
            }
#ifdef F77_CHAR
            F77_TA = C2F_CHAR(&TA);
#endif
            if (TransA == CblasConjTrans)
                FC_GLOBAL(zgemv,ZGEMV)(F77_TA, &F77_N, &F77_M, ALPHA, A, &F77_lda, stx,
                        &F77_incX, BETA, Y, &F77_incY);
            else
                FC_GLOBAL(zgemv,ZGEMV)(F77_TA, &F77_N, &F77_M, alpha, A, &F77_lda, x,
                        &F77_incX, beta, Y, &F77_incY);

            if (TransA == CblasConjTrans)
            {
                if (x != (const double *)X) free(x);
                if (N > 0)
                {
                    do
                    {
                        *y = -(*y);
                        y += i;
                    }
                    while (y != st);
                }
            }
        }
        else cblas_xerbla(1, "cblas_zgemv", "Illegal layout setting, %d\n", layout);
        CBLAS_CallFromC = 0;
        RowMajorStrg = 0;

    }
    return;
}
