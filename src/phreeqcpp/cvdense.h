#ifndef _INC_CVDENSE_H
#define _INC_CVDENSE_H
/**************************************************************************
 *                                                                        *
 * File          : cvdense.h                                              *
 * Programmers   : Scott D. Cohen, Alan C. Hindmarsh, and                 *
 *                 Radu Serban @ LLNL                                     *
 * Version of    : 26 June 2002                                           *
 *------------------------------------------------------------------------*
 * Copyright (c) 2002, The Regents of the University of California        *
 * Produced at the Lawrence Livermore National Laboratory                 *
 * All rights reserved                                                    *
 * For details, see LICENSE below                                         *
 *------------------------------------------------------------------------*
 * This is the header file for the CVODE dense linear solver,             *
 * CVDENSE.                                                               *
 *                                                                        *
 * Note: The type integertype must be large enough to store the           *
 * value of the linear system size N.                                     *
 *                                                                        *
 *------------------------------------------------------------------------*
 * LICENSE                                                                *
 *------------------------------------------------------------------------*
 * Copyright (c) 2002, The Regents of the University of California.       *
 * Produced at the Lawrence Livermore National Laboratory.                *
 * Written by S.D. Cohen, A.C. Hindmarsh, R. Serban,                      *
 *            D. Shumaker, and A.G. Taylor.                               *
 * UCRL-CODE-155951    (CVODE)                                            *
 * UCRL-CODE-155950    (CVODES)                                           *
 * UCRL-CODE-155952    (IDA)                                              *
 * UCRL-CODE-237203    (IDAS)                                             *
 * UCRL-CODE-155953    (KINSOL)                                           *
 * All rights reserved.                                                   *
 *                                                                        *
 * This file is part of SUNDIALS.                                         *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions     *
 * are met:                                                               *
 *                                                                        *
 * 1. Redistributions of source code must retain the above copyright      *
 * notice, this list of conditions and the disclaimer below.              *
 *                                                                        *
 * 2. Redistributions in binary form must reproduce the above copyright   *
 * notice, this list of conditions and the disclaimer (as noted below)    *
 * in the documentation and/or other materials provided with the          *
 * distribution.                                                          *
 *                                                                        *
 * 3. Neither the name of the UC/LLNL nor the names of its contributors   *
 * may be used to endorse or promote products derived from this software  *
 * without specific prior written permission.                             *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * REGENTS OF THE UNIVERSITY OF CALIFORNIA, THE U.S. DEPARTMENT OF ENERGY *
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,        *
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       *
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   *
 **************************************************************************/

#ifndef _cvdense_h
#define _cvdense_h


#include <stdio.h>
#include "cvode.h"
#include "sundialstypes.h"
#include "dense.h"
#include "nvector.h"


/******************************************************************
 *                                                                *
 * CVDENSE solver statistics indices                              *
 *----------------------------------------------------------------*
 * The following enumeration gives a symbolic name to each        *
 * CVDENSE statistic. The symbolic names are used as indices into *
 * the iopt and ropt arrays passed to CVodeMalloc.                *
 * The CVDENSE statistics are:                                    *
 *                                                                *
 * iopt[DENSE_NJE] : number of Jacobian evaluations, i.e. of      *
 *                   calls made to the dense Jacobian routine     *
 *                   (default or user-supplied).                  *
 *                                                                *
 * iopt[DENSE_LRW] : size (in realtype words) of real workspace   *
 *                   matrices and vectors used by this solver.    *
 *                                                                *
 * iopt[DENSE_LIW] : size (in integertype words) of integer       *
 *                   workspace vectors used by this solver.       *
 *                                                                *
 ******************************************************************/

	enum
	{ DENSE_NJE = CVODE_IOPT_SIZE, DENSE_LRW, DENSE_LIW };


/******************************************************************
 *                                                                *
 * CVDENSE solver constants                                       *
 *----------------------------------------------------------------*
 * CVD_MSBJ  : maximum number of steps between dense Jacobian     *
 *             evaluations                                        *
 *                                                                *
 * CVD_DGMAX : maximum change in gamma between dense Jacobian     *
 *             evaluations                                        *
 *                                                                *
 ******************************************************************/

#define CVD_MSBJ  50

#define CVD_DGMAX RCONST(0.2)


/******************************************************************
 *                                                                *
 * Type : CVDenseJacFn                                            *
 *----------------------------------------------------------------*
 * A dense Jacobian approximation function Jac must have the      *
 * prototype given below. Its parameters are:                     *
 *                                                                *
 * N is the length of all vector arguments.                       *
 *                                                                *
 * J is the dense matrix (of type DenseMat) that will be loaded   *
 * by a CVDenseJacFn with an approximation to the Jacobian matrix *
 * J = (df_i/dy_j) at the point (t,y).                            *
 * J is preset to zero, so only the nonzero elements need to be   *
 * loaded. Two efficient ways to load J are:                      *
 *                                                                *
 * (1) (with macros - no explicit data structure references)      *
 *     for (j=0; j < N; j++) {                                    *
 *       col_j = DENSE_COL(J,j);                                  *
 *       for (i=0; i < N; i++) {                                  *
 *         generate J_ij = the (i,j)th Jacobian element           *
 *         col_j[i] = J_ij;                                       *
 *       }                                                        *
 *     }                                                          *
 *                                                                *
 * (2) (without macros - explicit data structure references)      *
 *     for (j=0; j < N; j++) {                                    *
 *       col_j = (J->data)[j];                                    *
 *       for (i=0; i < N; i++) {                                  *
 *         generate J_ij = the (i,j)th Jacobian element           *
 *         col_j[i] = J_ij;                                       *
 *       }                                                        *
 *     }                                                          *
 *                                                                *
 * The DENSE_ELEM(A,i,j) macro is appropriate for use in small    *
 * problems in which efficiency of access is NOT a major concern. *
 *                                                                *
 * f is the right hand side function for the ODE problem.         *
 *                                                                *
 * f_data is a pointer to user data to be passed to f, the same   *
 *        as the F_data parameter passed to CVodeMalloc.          *
 *                                                                *
 * t is the current value of the independent variable.            *
 *                                                                *
 * y is the current value of the dependent variable vector,       *
 *      namely the predicted value of y(t).                       *
 *                                                                *
 * fy is the vector f(t,y).                                       *
 *                                                                *
 * ewt is the error weight vector.                                *
 *                                                                *
 * h is a tentative step size in t.                               *
 *                                                                *
 * uround is the machine unit roundoff.                           *
 *                                                                *
 * jac_data is a pointer to user data - the same as the jac_data  *
 *          parameter passed to CVDense.                          *
 *                                                                *
 * nfePtr is a pointer to the memory location containing the      *
 * CVODE problem data nfe = number of calls to f. The Jacobian    *
 * routine should update this counter by adding on the number     *
 * of f calls made in order to approximate the Jacobian, if any.  *
 * For example, if the routine calls f a total of N times, then   *
 * the update is *nfePtr += N.                                    *
 *                                                                *
 * vtemp1, vtemp2, and vtemp3 are pointers to memory allocated    *
 * for vectors of length N which can be used by a CVDenseJacFn    *
 * as temporary storage or work space.                            *
 *                                                                *
 ******************************************************************/

	typedef void (*CVDenseJacFn) (integertype N, DenseMat J, RhsFn f,
								  void *f_data, realtype t, N_Vector y,
								  N_Vector fy, N_Vector ewt, realtype h,
								  realtype uround, void *jac_data,
								  long int *nfePtr, N_Vector vtemp1,
								  N_Vector vtemp2, N_Vector vtemp3);


/******************************************************************
 *                                                                *
 * Function : CVDense                                             *
 *----------------------------------------------------------------*
 * A call to the CVDense function links the main CVODE integrator *
 * with the CVDENSE linear solver.                                *
 *                                                                *
 * cvode_mem is the pointer to CVODE memory returned by           *
 *              CVodeMalloc.                                      *
 *                                                                *
 * djac is the dense Jacobian approximation routine to be used.   *
 *         A user-supplied djac routine must be of type           *
 *         CVDenseJacFn. Pass NULL for djac to use the default    *
 *         difference quotient routine CVDenseDQJac supplied      *
 *         with this solver.                                      *
 *                                                                *
 * jac_data is a pointer to user data which is passed to the      *
 *         djac routine every time it is called.                  *
 *                                                                *
 * The return values of CVDense are:                              *
 *    SUCCESS   = 0  if successful                                *
 *    LMEM_FAIL = -1 if there was a memory allocation failure     *
 *                                                                *
 * NOTE: The dense linear solver assumes a serial implementation  *
 *       of the NVECTOR package. Therefore, CVDense will first    *
 *       test for a compatible N_Vector internal representation   *
 *       by checking (1) the machine environment ID tag and       *
 *       (2) that the functions N_VMake, N_VDispose, N_VGetData,  *
 *       and N_VSetData are implemented.                          *
 *                                                                *
 ******************************************************************/

	int CVDense(void *cvode_mem, CVDenseJacFn djac, void *jac_data);


/******************************************************************
 *                                                                *
 * Function : CVReInitDense                                       *
 *----------------------------------------------------------------*
 * A call to the CVReInitDense function resets the link between   *
 * the main CVODE integrator and the CVDENSE linear solver.       *
 * After solving one problem using CVDENSE, call CVReInit and then*
 * CVReInitDense to solve another problem of the same size, if    *
 * there is a change in the CVDense parameters djac or jac_data.  *
 * If there is no change in parameters, it is not necessary to    *
 * call either CVReInitDense or CVDense for the new problem.      *
 *                                                                *
 * All arguments to CVReInitDense have the same names and meanings*
 * as those of CVDense.  The cvode_mem argument must be identical *
 * to its value in the previous CVDense call.                     *
 *                                                                *
 * The return values of CVReInitDense are:                        *
 *   SUCCESS   = 0      if successful, or                         *
 *   LMEM_FAIL = -1     if the cvode_mem argument is NULL         *
 *                                                                *
 * NOTE: CVReInitDense performs the same compatibility tests as   *
 *       CVDense.                                                 *
 *                                                                *
 ******************************************************************/

	int CVReInitDense(void *cvode_mem, CVDenseJacFn djac, void *jac_data);


#endif
/*
#ifdef __cplusplus
}
#endif
*/
#endif /* _INC_CVDENSE_H */
