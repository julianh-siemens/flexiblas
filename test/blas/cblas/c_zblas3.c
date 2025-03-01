/*
 *     Written by D.P. Manley, Digital Equipment Corporation.
 *     Prefixed "C_" to BLAS routines and their declarations.
 *
 *     Modified by T. H. Do, 4/15/98, SGI/CRAY Research.
 */
#include <stdlib.h>
#include <stdio.h>
#include "cblas.h"
#include "cblas_test.h"
#define  TEST_COL_MJR	0
#define  TEST_ROW_MJR	1
#define  UNDEFINED     -1

void F77_zgemm(F77_INT *layout, char *transpa, char *transpb, F77_INT *m, F77_INT *n,
     F77_INT *k, CBLAS_TEST_ZOMPLEX *alpha, CBLAS_TEST_ZOMPLEX *a, F77_INT *lda,
     CBLAS_TEST_ZOMPLEX *b, F77_INT *ldb, CBLAS_TEST_ZOMPLEX *beta,
     CBLAS_TEST_ZOMPLEX *c, F77_INT *ldc
#ifdef BLAS_FORTRAN_STRLEN_END
  , FORTRAN_STRLEN transpa_len, FORTRAN_STRLEN transpb_len
#endif
) {

  CBLAS_TEST_ZOMPLEX *A, *B, *C;
  F77_INT i,j,LDA, LDB, LDC;
  CBLAS_TRANSPOSE transa, transb;

  get_transpose_type(transpa, &transa);
  get_transpose_type(transpb, &transb);

  if (*layout == TEST_ROW_MJR) {
     if (transa == CblasNoTrans) {
        LDA = *k+1;
        A=(CBLAS_TEST_ZOMPLEX*)malloc((*m)*LDA*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*m; i++ )
           for( j=0; j<*k; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     else {
        LDA = *m+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc(LDA*(*k)*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*k; i++ )
           for( j=0; j<*m; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }

     if (transb == CblasNoTrans) {
        LDB = *n+1;
        B=(CBLAS_TEST_ZOMPLEX* )malloc((*k)*LDB*sizeof(CBLAS_TEST_ZOMPLEX) );
        for( i=0; i<*k; i++ )
           for( j=0; j<*n; j++ ) {
              B[i*LDB+j].real=b[j*(*ldb)+i].real;
              B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
           }
     }
     else {
        LDB = *k+1;
        B=(CBLAS_TEST_ZOMPLEX* )malloc(LDB*(*n)*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*n; i++ )
           for( j=0; j<*k; j++ ) {
              B[i*LDB+j].real=b[j*(*ldb)+i].real;
              B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
           }
     }

     LDC = *n+1;
     C=(CBLAS_TEST_ZOMPLEX* )malloc((*m)*LDC*sizeof(CBLAS_TEST_ZOMPLEX));
     for( j=0; j<*n; j++ )
        for( i=0; i<*m; i++ ) {
           C[i*LDC+j].real=c[j*(*ldc)+i].real;
           C[i*LDC+j].imag=c[j*(*ldc)+i].imag;
        }
     cblas_zgemm( CblasRowMajor, transa, transb, *m, *n, *k, alpha, A, LDA,
                  B, LDB, beta, C, LDC );
     for( j=0; j<*n; j++ )
        for( i=0; i<*m; i++ ) {
           c[j*(*ldc)+i].real=C[i*LDC+j].real;
           c[j*(*ldc)+i].imag=C[i*LDC+j].imag;
        }
     free(A);
     free(B);
     free(C);
  }
  else if (*layout == TEST_COL_MJR)
     cblas_zgemm( CblasColMajor, transa, transb, *m, *n, *k, alpha, a, *lda,
                  b, *ldb, beta, c, *ldc );
  else
     cblas_zgemm( UNDEFINED, transa, transb, *m, *n, *k, alpha, a, *lda,
                  b, *ldb, beta, c, *ldc );
}


void F77_zgemmtr(F77_INT *layout, char *uplop, char *transpa, char *transpb, F77_INT *n,
     F77_INT *k, CBLAS_TEST_ZOMPLEX *alpha, CBLAS_TEST_ZOMPLEX *a, F77_INT *lda,
     CBLAS_TEST_ZOMPLEX *b, F77_INT *ldb, CBLAS_TEST_ZOMPLEX *beta,
     CBLAS_TEST_ZOMPLEX *c, F77_INT *ldc, FORTRAN_STRLEN len_1, FORTRAN_STRLEN len_2, FORTRAN_STRLEN len_3 ) {

  CBLAS_TEST_ZOMPLEX *A, *B, *C;
  F77_INT i,j,LDA, LDB, LDC;
  CBLAS_TRANSPOSE transa, transb;
  CBLAS_UPLO uplo;

  get_transpose_type(transpa, &transa);
  get_transpose_type(transpb, &transb);
  get_uplo_type(uplop, &uplo);

  if (*layout == TEST_ROW_MJR) {
      if (transa == CblasNoTrans) {
          LDA = *k+1;
          A=(CBLAS_TEST_ZOMPLEX*)malloc((*n)*LDA*sizeof(CBLAS_TEST_ZOMPLEX));
          for( i=0; i<*n; i++ )
              for( j=0; j<*k; j++ ) {
                  A[i*LDA+j].real=a[j*(*lda)+i].real;
                  A[i*LDA+j].imag=a[j*(*lda)+i].imag;
              }
      }
      else {
          LDA = *n+1;
          A=(CBLAS_TEST_ZOMPLEX* )malloc(LDA*(*k)*sizeof(CBLAS_TEST_ZOMPLEX));
          for( i=0; i<*k; i++ )
              for( j=0; j<*n; j++ ) {
                  A[i*LDA+j].real=a[j*(*lda)+i].real;
                  A[i*LDA+j].imag=a[j*(*lda)+i].imag;
              }
      }

      if (transb == CblasNoTrans) {
          LDB = *n+1;
          B=(CBLAS_TEST_ZOMPLEX* )malloc((*k)*LDB*sizeof(CBLAS_TEST_ZOMPLEX) );
          for( i=0; i<*k; i++ )
              for( j=0; j<*n; j++ ) {
                  B[i*LDB+j].real=b[j*(*ldb)+i].real;
                  B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
              }
      }
      else {
          LDB = *k+1;
          B=(CBLAS_TEST_ZOMPLEX* )malloc(LDB*(*n)*sizeof(CBLAS_TEST_ZOMPLEX));
          for( i=0; i<*n; i++ )
              for( j=0; j<*k; j++ ) {
                  B[i*LDB+j].real=b[j*(*ldb)+i].real;
                  B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
              }
      }

      LDC = *n+1;
      C=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDC*sizeof(CBLAS_TEST_ZOMPLEX));
      for( j=0; j<*n; j++ )
          for( i=0; i<*n; i++ ) {
              C[i*LDC+j].real=c[j*(*ldc)+i].real;
              C[i*LDC+j].imag=c[j*(*ldc)+i].imag;
          }
      cblas_zgemmtr( CblasRowMajor, uplo, transa, transb, *n, *k, alpha, A, LDA,
              B, LDB, beta, C, LDC );
      for( j=0; j<*n; j++ )
          for( i=0; i<*n; i++ ) {
              c[j*(*ldc)+i].real=C[i*LDC+j].real;
              c[j*(*ldc)+i].imag=C[i*LDC+j].imag;
          }
      free(A);
      free(B);
      free(C);
  }
  else if (*layout == TEST_COL_MJR)
      cblas_zgemmtr( CblasColMajor, uplo, transa, transb, *n, *k, alpha, a, *lda,
              b, *ldb, beta, c, *ldc );
  else
      cblas_zgemmtr( UNDEFINED, uplo, transa, transb, *n, *k, alpha, a, *lda,
              b, *ldb, beta, c, *ldc );
}


void F77_zhemm(F77_INT *layout, char *rtlf, char *uplow, F77_INT *m, F77_INT *n,
        CBLAS_TEST_ZOMPLEX *alpha, CBLAS_TEST_ZOMPLEX *a, F77_INT *lda,
	CBLAS_TEST_ZOMPLEX *b, F77_INT *ldb, CBLAS_TEST_ZOMPLEX *beta,
        CBLAS_TEST_ZOMPLEX *c, F77_INT *ldc
#ifdef BLAS_FORTRAN_STRLEN_END
  , FORTRAN_STRLEN rtlf_len, FORTRAN_STRLEN uplow_len
#endif
) {

  CBLAS_TEST_ZOMPLEX *A, *B, *C;
  F77_INT i,j,LDA, LDB, LDC;
  CBLAS_UPLO uplo;
  CBLAS_SIDE side;

  get_uplo_type(uplow,&uplo);
  get_side_type(rtlf,&side);

  if (*layout == TEST_ROW_MJR) {
     if (side == CblasLeft) {
        LDA = *m+1;
        A= (CBLAS_TEST_ZOMPLEX* )malloc((*m)*LDA*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*m; i++ )
           for( j=0; j<*m; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     else{
        LDA = *n+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDA*sizeof(CBLAS_TEST_ZOMPLEX ) );
        for( i=0; i<*n; i++ )
           for( j=0; j<*n; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     LDB = *n+1;
     B=(CBLAS_TEST_ZOMPLEX* )malloc( (*m)*LDB*sizeof(CBLAS_TEST_ZOMPLEX ) );
     for( i=0; i<*m; i++ )
        for( j=0; j<*n; j++ ) {
           B[i*LDB+j].real=b[j*(*ldb)+i].real;
           B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
        }
     LDC = *n+1;
     C=(CBLAS_TEST_ZOMPLEX* )malloc((*m)*LDC*sizeof(CBLAS_TEST_ZOMPLEX ) );
     for( j=0; j<*n; j++ )
        for( i=0; i<*m; i++ ) {
           C[i*LDC+j].real=c[j*(*ldc)+i].real;
           C[i*LDC+j].imag=c[j*(*ldc)+i].imag;
        }
     cblas_zhemm( CblasRowMajor, side, uplo, *m, *n, alpha, A, LDA, B, LDB,
                  beta, C, LDC );
     for( j=0; j<*n; j++ )
        for( i=0; i<*m; i++ ) {
           c[j*(*ldc)+i].real=C[i*LDC+j].real;
           c[j*(*ldc)+i].imag=C[i*LDC+j].imag;
        }
     free(A);
     free(B);
     free(C);
  }
  else if (*layout == TEST_COL_MJR)
     cblas_zhemm( CblasColMajor, side, uplo, *m, *n, alpha, a, *lda, b, *ldb,
                  beta, c, *ldc );
  else
     cblas_zhemm( UNDEFINED, side, uplo, *m, *n, alpha, a, *lda, b, *ldb,
                  beta, c, *ldc );
}
void F77_zsymm(F77_INT *layout, char *rtlf, char *uplow, F77_INT *m, F77_INT *n,
          CBLAS_TEST_ZOMPLEX *alpha, CBLAS_TEST_ZOMPLEX *a, F77_INT *lda,
	  CBLAS_TEST_ZOMPLEX *b, F77_INT *ldb, CBLAS_TEST_ZOMPLEX *beta,
          CBLAS_TEST_ZOMPLEX *c, F77_INT *ldc
#ifdef BLAS_FORTRAN_STRLEN_END
  , FORTRAN_STRLEN rtlf_len, FORTRAN_STRLEN uplow_len
#endif
) {

  CBLAS_TEST_ZOMPLEX *A, *B, *C;
  F77_INT i,j,LDA, LDB, LDC;
  CBLAS_UPLO uplo;
  CBLAS_SIDE side;

  get_uplo_type(uplow,&uplo);
  get_side_type(rtlf,&side);

  if (*layout == TEST_ROW_MJR) {
     if (side == CblasLeft) {
        LDA = *m+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*m)*LDA*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*m; i++ )
           for( j=0; j<*m; j++ )
              A[i*LDA+j]=a[j*(*lda)+i];
     }
     else{
        LDA = *n+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDA*sizeof(CBLAS_TEST_ZOMPLEX ) );
        for( i=0; i<*n; i++ )
           for( j=0; j<*n; j++ )
              A[i*LDA+j]=a[j*(*lda)+i];
     }
     LDB = *n+1;
     B=(CBLAS_TEST_ZOMPLEX* )malloc((*m)*LDB*sizeof(CBLAS_TEST_ZOMPLEX ));
     for( i=0; i<*m; i++ )
        for( j=0; j<*n; j++ )
           B[i*LDB+j]=b[j*(*ldb)+i];
     LDC = *n+1;
     C=(CBLAS_TEST_ZOMPLEX* )malloc((*m)*LDC*sizeof(CBLAS_TEST_ZOMPLEX));
     for( j=0; j<*n; j++ )
        for( i=0; i<*m; i++ )
           C[i*LDC+j]=c[j*(*ldc)+i];
     cblas_zsymm( CblasRowMajor, side, uplo, *m, *n, alpha, A, LDA, B, LDB,
                  beta, C, LDC );
     for( j=0; j<*n; j++ )
        for( i=0; i<*m; i++ )
           c[j*(*ldc)+i]=C[i*LDC+j];
     free(A);
     free(B);
     free(C);
  }
  else if (*layout == TEST_COL_MJR)
     cblas_zsymm( CblasColMajor, side, uplo, *m, *n, alpha, a, *lda, b, *ldb,
                  beta, c, *ldc );
  else
     cblas_zsymm( UNDEFINED, side, uplo, *m, *n, alpha, a, *lda, b, *ldb,
                  beta, c, *ldc );
}

void F77_zherk(F77_INT *layout, char *uplow, char *transp, F77_INT *n, F77_INT *k,
     double *alpha, CBLAS_TEST_ZOMPLEX *a, F77_INT *lda,
     double *beta, CBLAS_TEST_ZOMPLEX *c, F77_INT *ldc
#ifdef BLAS_FORTRAN_STRLEN_END
  , FORTRAN_STRLEN uplow_len, FORTRAN_STRLEN transp_len
#endif
) {

  F77_INT i,j,LDA,LDC;
  CBLAS_TEST_ZOMPLEX *A, *C;
  CBLAS_UPLO uplo;
  CBLAS_TRANSPOSE trans;

  get_uplo_type(uplow,&uplo);
  get_transpose_type(transp,&trans);

  if (*layout == TEST_ROW_MJR) {
     if (trans == CblasNoTrans) {
        LDA = *k+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDA*sizeof(CBLAS_TEST_ZOMPLEX ) );
        for( i=0; i<*n; i++ )
           for( j=0; j<*k; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     else{
        LDA = *n+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*k)*LDA*sizeof(CBLAS_TEST_ZOMPLEX ) );
        for( i=0; i<*k; i++ )
           for( j=0; j<*n; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     LDC = *n+1;
     C=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDC*sizeof(CBLAS_TEST_ZOMPLEX ) );
     for( i=0; i<*n; i++ )
        for( j=0; j<*n; j++ ) {
           C[i*LDC+j].real=c[j*(*ldc)+i].real;
           C[i*LDC+j].imag=c[j*(*ldc)+i].imag;
        }
     cblas_zherk(CblasRowMajor, uplo, trans, *n, *k, *alpha, A, LDA, *beta,
	         C, LDC );
     for( j=0; j<*n; j++ )
        for( i=0; i<*n; i++ ) {
           c[j*(*ldc)+i].real=C[i*LDC+j].real;
           c[j*(*ldc)+i].imag=C[i*LDC+j].imag;
        }
     free(A);
     free(C);
  }
  else if (*layout == TEST_COL_MJR)
     cblas_zherk(CblasColMajor, uplo, trans, *n, *k, *alpha, a, *lda, *beta,
	         c, *ldc );
  else
     cblas_zherk(UNDEFINED, uplo, trans, *n, *k, *alpha, a, *lda, *beta,
	         c, *ldc );
}

void F77_zsyrk(F77_INT *layout, char *uplow, char *transp, F77_INT *n, F77_INT *k,
     CBLAS_TEST_ZOMPLEX *alpha, CBLAS_TEST_ZOMPLEX *a, F77_INT *lda,
     CBLAS_TEST_ZOMPLEX *beta, CBLAS_TEST_ZOMPLEX *c, F77_INT *ldc
#ifdef BLAS_FORTRAN_STRLEN_END
  , FORTRAN_STRLEN uplow_len, FORTRAN_STRLEN transp_len
#endif
) {

  F77_INT i,j,LDA,LDC;
  CBLAS_TEST_ZOMPLEX *A, *C;
  CBLAS_UPLO uplo;
  CBLAS_TRANSPOSE trans;

  get_uplo_type(uplow,&uplo);
  get_transpose_type(transp,&trans);

  if (*layout == TEST_ROW_MJR) {
     if (trans == CblasNoTrans) {
        LDA = *k+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDA*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*n; i++ )
           for( j=0; j<*k; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     else{
        LDA = *n+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*k)*LDA*sizeof(CBLAS_TEST_ZOMPLEX ) );
        for( i=0; i<*k; i++ )
           for( j=0; j<*n; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     LDC = *n+1;
     C=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDC*sizeof(CBLAS_TEST_ZOMPLEX ) );
     for( i=0; i<*n; i++ )
        for( j=0; j<*n; j++ ) {
           C[i*LDC+j].real=c[j*(*ldc)+i].real;
           C[i*LDC+j].imag=c[j*(*ldc)+i].imag;
        }
     cblas_zsyrk(CblasRowMajor, uplo, trans, *n, *k, alpha, A, LDA, beta,
	         C, LDC );
     for( j=0; j<*n; j++ )
        for( i=0; i<*n; i++ ) {
           c[j*(*ldc)+i].real=C[i*LDC+j].real;
           c[j*(*ldc)+i].imag=C[i*LDC+j].imag;
        }
     free(A);
     free(C);
  }
  else if (*layout == TEST_COL_MJR)
     cblas_zsyrk(CblasColMajor, uplo, trans, *n, *k, alpha, a, *lda, beta,
	         c, *ldc );
  else
     cblas_zsyrk(UNDEFINED, uplo, trans, *n, *k, alpha, a, *lda, beta,
	         c, *ldc );
}
void F77_zher2k(F77_INT *layout, char *uplow, char *transp, F77_INT *n, F77_INT *k,
        CBLAS_TEST_ZOMPLEX *alpha, CBLAS_TEST_ZOMPLEX *a, F77_INT *lda,
	CBLAS_TEST_ZOMPLEX *b, F77_INT *ldb, double *beta,
        CBLAS_TEST_ZOMPLEX *c, F77_INT *ldc
#ifdef BLAS_FORTRAN_STRLEN_END
  , FORTRAN_STRLEN uplow_len, FORTRAN_STRLEN transp_len
#endif
) {
  F77_INT i,j,LDA,LDB,LDC;
  CBLAS_TEST_ZOMPLEX *A, *B, *C;
  CBLAS_UPLO uplo;
  CBLAS_TRANSPOSE trans;

  get_uplo_type(uplow,&uplo);
  get_transpose_type(transp,&trans);

  if (*layout == TEST_ROW_MJR) {
     if (trans == CblasNoTrans) {
        LDA = *k+1;
        LDB = *k+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDA*sizeof(CBLAS_TEST_ZOMPLEX ));
        B=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDB*sizeof(CBLAS_TEST_ZOMPLEX ));
        for( i=0; i<*n; i++ )
           for( j=0; j<*k; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
              B[i*LDB+j].real=b[j*(*ldb)+i].real;
              B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
           }
     }
     else {
        LDA = *n+1;
        LDB = *n+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc( LDA*(*k)*sizeof(CBLAS_TEST_ZOMPLEX ) );
        B=(CBLAS_TEST_ZOMPLEX* )malloc( LDB*(*k)*sizeof(CBLAS_TEST_ZOMPLEX ) );
        for( i=0; i<*k; i++ )
           for( j=0; j<*n; j++ ){
	      A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
              B[i*LDB+j].real=b[j*(*ldb)+i].real;
              B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
           }
     }
     LDC = *n+1;
     C=(CBLAS_TEST_ZOMPLEX* )malloc( (*n)*LDC*sizeof(CBLAS_TEST_ZOMPLEX ) );
     for( i=0; i<*n; i++ )
        for( j=0; j<*n; j++ ) {
           C[i*LDC+j].real=c[j*(*ldc)+i].real;
           C[i*LDC+j].imag=c[j*(*ldc)+i].imag;
        }
     cblas_zher2k(CblasRowMajor, uplo, trans, *n, *k, alpha, A, LDA,
		  B, LDB, *beta, C, LDC );
     for( j=0; j<*n; j++ )
        for( i=0; i<*n; i++ ) {
           c[j*(*ldc)+i].real=C[i*LDC+j].real;
           c[j*(*ldc)+i].imag=C[i*LDC+j].imag;
        }
     free(A);
     free(B);
     free(C);
  }
  else if (*layout == TEST_COL_MJR)
     cblas_zher2k(CblasColMajor, uplo, trans, *n, *k, alpha, a, *lda,
		   b, *ldb, *beta, c, *ldc );
  else
     cblas_zher2k(UNDEFINED, uplo, trans, *n, *k, alpha, a, *lda,
		   b, *ldb, *beta, c, *ldc );
}
void F77_zsyr2k(F77_INT *layout, char *uplow, char *transp, F77_INT *n, F77_INT *k,
         CBLAS_TEST_ZOMPLEX *alpha, CBLAS_TEST_ZOMPLEX *a, F77_INT *lda,
	 CBLAS_TEST_ZOMPLEX *b, F77_INT *ldb, CBLAS_TEST_ZOMPLEX *beta,
         CBLAS_TEST_ZOMPLEX *c, F77_INT *ldc
#ifdef BLAS_FORTRAN_STRLEN_END
  , FORTRAN_STRLEN uplow_len, FORTRAN_STRLEN transp_len
#endif
) {
  F77_INT i,j,LDA,LDB,LDC;
  CBLAS_TEST_ZOMPLEX *A, *B, *C;
  CBLAS_UPLO uplo;
  CBLAS_TRANSPOSE trans;

  get_uplo_type(uplow,&uplo);
  get_transpose_type(transp,&trans);

  if (*layout == TEST_ROW_MJR) {
     if (trans == CblasNoTrans) {
        LDA = *k+1;
        LDB = *k+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDA*sizeof(CBLAS_TEST_ZOMPLEX));
        B=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDB*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*n; i++ )
           for( j=0; j<*k; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
              B[i*LDB+j].real=b[j*(*ldb)+i].real;
              B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
           }
     }
     else {
        LDA = *n+1;
        LDB = *n+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc(LDA*(*k)*sizeof(CBLAS_TEST_ZOMPLEX));
        B=(CBLAS_TEST_ZOMPLEX* )malloc(LDB*(*k)*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*k; i++ )
           for( j=0; j<*n; j++ ){
	      A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
              B[i*LDB+j].real=b[j*(*ldb)+i].real;
              B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
           }
     }
     LDC = *n+1;
     C=(CBLAS_TEST_ZOMPLEX* )malloc( (*n)*LDC*sizeof(CBLAS_TEST_ZOMPLEX));
     for( i=0; i<*n; i++ )
        for( j=0; j<*n; j++ ) {
           C[i*LDC+j].real=c[j*(*ldc)+i].real;
           C[i*LDC+j].imag=c[j*(*ldc)+i].imag;
        }
     cblas_zsyr2k(CblasRowMajor, uplo, trans, *n, *k, alpha, A, LDA,
		  B, LDB, beta, C, LDC );
     for( j=0; j<*n; j++ )
        for( i=0; i<*n; i++ ) {
           c[j*(*ldc)+i].real=C[i*LDC+j].real;
           c[j*(*ldc)+i].imag=C[i*LDC+j].imag;
        }
     free(A);
     free(B);
     free(C);
  }
  else if (*layout == TEST_COL_MJR)
     cblas_zsyr2k(CblasColMajor, uplo, trans, *n, *k, alpha, a, *lda,
		   b, *ldb, beta, c, *ldc );
  else
     cblas_zsyr2k(UNDEFINED, uplo, trans, *n, *k, alpha, a, *lda,
		   b, *ldb, beta, c, *ldc );
}
void F77_ztrmm(F77_INT *layout, char *rtlf, char *uplow, char *transp, char *diagn,
       F77_INT *m, F77_INT *n, CBLAS_TEST_ZOMPLEX *alpha, CBLAS_TEST_ZOMPLEX *a,
       F77_INT *lda, CBLAS_TEST_ZOMPLEX *b, F77_INT *ldb
#ifdef BLAS_FORTRAN_STRLEN_END
  , FORTRAN_STRLEN rtlf_len, FORTRAN_STRLEN uplow_len, FORTRAN_STRLEN transp_len, FORTRAN_STRLEN diagn_len
#endif
) {
  F77_INT i,j,LDA,LDB;
  CBLAS_TEST_ZOMPLEX *A, *B;
  CBLAS_SIDE side;
  CBLAS_DIAG diag;
  CBLAS_UPLO uplo;
  CBLAS_TRANSPOSE trans;

  get_uplo_type(uplow,&uplo);
  get_transpose_type(transp,&trans);
  get_diag_type(diagn,&diag);
  get_side_type(rtlf,&side);

  if (*layout == TEST_ROW_MJR) {
     if (side == CblasLeft) {
        LDA = *m+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*m)*LDA*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*m; i++ )
           for( j=0; j<*m; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     else{
        LDA = *n+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDA*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*n; i++ )
           for( j=0; j<*n; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     LDB = *n+1;
     B=(CBLAS_TEST_ZOMPLEX* )malloc((*m)*LDB*sizeof(CBLAS_TEST_ZOMPLEX));
     for( i=0; i<*m; i++ )
        for( j=0; j<*n; j++ ) {
           B[i*LDB+j].real=b[j*(*ldb)+i].real;
           B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
        }
     cblas_ztrmm(CblasRowMajor, side, uplo, trans, diag, *m, *n, alpha,
		 A, LDA, B, LDB );
     for( j=0; j<*n; j++ )
        for( i=0; i<*m; i++ ) {
           b[j*(*ldb)+i].real=B[i*LDB+j].real;
           b[j*(*ldb)+i].imag=B[i*LDB+j].imag;
        }
     free(A);
     free(B);
  }
  else if (*layout == TEST_COL_MJR)
     cblas_ztrmm(CblasColMajor, side, uplo, trans, diag, *m, *n, alpha,
		   a, *lda, b, *ldb);
  else
     cblas_ztrmm(UNDEFINED, side, uplo, trans, diag, *m, *n, alpha,
		   a, *lda, b, *ldb);
}

void F77_ztrsm(F77_INT *layout, char *rtlf, char *uplow, char *transp, char *diagn,
         F77_INT *m, F77_INT *n, CBLAS_TEST_ZOMPLEX *alpha, CBLAS_TEST_ZOMPLEX *a,
         F77_INT *lda, CBLAS_TEST_ZOMPLEX *b, F77_INT *ldb
#ifdef BLAS_FORTRAN_STRLEN_END
  , FORTRAN_STRLEN rtlf_len, FORTRAN_STRLEN uplow_len, FORTRAN_STRLEN transp_len, FORTRAN_STRLEN diagn_len
#endif
) {
  F77_INT i,j,LDA,LDB;
  CBLAS_TEST_ZOMPLEX *A, *B;
  CBLAS_SIDE side;
  CBLAS_DIAG diag;
  CBLAS_UPLO uplo;
  CBLAS_TRANSPOSE trans;

  get_uplo_type(uplow,&uplo);
  get_transpose_type(transp,&trans);
  get_diag_type(diagn,&diag);
  get_side_type(rtlf,&side);

  if (*layout == TEST_ROW_MJR) {
     if (side == CblasLeft) {
        LDA = *m+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc( (*m)*LDA*sizeof(CBLAS_TEST_ZOMPLEX ) );
        for( i=0; i<*m; i++ )
           for( j=0; j<*m; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     else{
        LDA = *n+1;
        A=(CBLAS_TEST_ZOMPLEX* )malloc((*n)*LDA*sizeof(CBLAS_TEST_ZOMPLEX));
        for( i=0; i<*n; i++ )
           for( j=0; j<*n; j++ ) {
              A[i*LDA+j].real=a[j*(*lda)+i].real;
              A[i*LDA+j].imag=a[j*(*lda)+i].imag;
           }
     }
     LDB = *n+1;
     B=(CBLAS_TEST_ZOMPLEX* )malloc((*m)*LDB*sizeof(CBLAS_TEST_ZOMPLEX));
     for( i=0; i<*m; i++ )
        for( j=0; j<*n; j++ ) {
           B[i*LDB+j].real=b[j*(*ldb)+i].real;
           B[i*LDB+j].imag=b[j*(*ldb)+i].imag;
        }
     cblas_ztrsm(CblasRowMajor, side, uplo, trans, diag, *m, *n, alpha,
		 A, LDA, B, LDB );
     for( j=0; j<*n; j++ )
        for( i=0; i<*m; i++ ) {
           b[j*(*ldb)+i].real=B[i*LDB+j].real;
           b[j*(*ldb)+i].imag=B[i*LDB+j].imag;
        }
     free(A);
     free(B);
  }
  else if (*layout == TEST_COL_MJR)
     cblas_ztrsm(CblasColMajor, side, uplo, trans, diag, *m, *n, alpha,
		   a, *lda, b, *ldb);
  else
     cblas_ztrsm(UNDEFINED, side, uplo, trans, diag, *m, *n, alpha,
		   a, *lda, b, *ldb);
}
