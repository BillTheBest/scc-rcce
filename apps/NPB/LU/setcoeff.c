// 
// Copyright 2010 Intel Corporation
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
// 
#include <math.h>
#include "applu_share.h"
#include "applu_macros.h"

void setcoeff() {

      dxi   = 1.0 / ( nx0 - 1 );
      deta  = 1.0 / ( ny0 - 1 );
      dzeta = 1.0 / ( nz0 - 1 );

      tx1 = 1.0 / ( dxi * dxi );
      tx2 = 1.0 / ( 2.0 * dxi );
      tx3 = 1.0 / dxi;

      ty1 = 1.0 / ( deta * deta );
      ty2 = 1.0 / ( 2.0 * deta );
      ty3 = 1.0 / deta;

      tz1 = 1.0 / ( dzeta * dzeta );
      tz2 = 1.0 / ( 2.0 * dzeta );
      tz3 = 1.0 / dzeta;

      ii1 = 2;
      ii2 = nx0 - 1;
      ji1 = 2;
      ji2 = ny0 - 2;
      ki1 = 3;
      ki2 = nz0 - 1;

//c---------------------------------------------------------------------
//c   diffusion coefficients
//c---------------------------------------------------------------------
      dx1 = 0.75;
      dx2 = dx1;
      dx3 = dx1;
      dx4 = dx1;
      dx5 = dx1;

      dy1 = 0.75;
      dy2 = dy1;
      dy3 = dy1;
      dy4 = dy1;
      dy5 = dy1;

      dz1 = 1.00;
      dz2 = dz1;
      dz3 = dz1;
      dz4 = dz1;
      dz5 = dz1;

//c---------------------------------------------------------------------
//c   fourth difference dissipation
//c---------------------------------------------------------------------
      dssp = ( fmax (dx1, fmax (dy1, dz1) ) ) / 4.0;

//c---------------------------------------------------------------------
//c   coefficients of the exact solution to the first pde
//c---------------------------------------------------------------------
      ce(1,1) = 2.0;
      ce(1,2) = 0.0;
      ce(1,3) = 0.0;
      ce(1,4) = 4.0;
      ce(1,5) = 5.0;
      ce(1,6) = 3.0;
      ce(1,7) = 5.0e-01;
      ce(1,8) = 2.0e-02;
      ce(1,9) = 1.0e-02;
      ce(1,10) = 3.0e-02;
      ce(1,11) = 5.0e-01;
      ce(1,12) = 4.0e-01;
      ce(1,13) = 3.0e-01;

//c---------------------------------------------------------------------
//c   coefficients of the exact solution to the second pde
//c---------------------------------------------------------------------
      ce(2,1) = 1.0;
      ce(2,2) = 0.0;
      ce(2,3) = 0.0;
      ce(2,4) = 0.0;
      ce(2,5) = 1.0;
      ce(2,6) = 2.0;
      ce(2,7) = 3.0;
      ce(2,8) = 1.0e-02;
      ce(2,9) = 3.0e-02;
      ce(2,10) = 2.0e-02;
      ce(2,11) = 4.0e-01;
      ce(2,12) = 3.0e-01;
      ce(2,13) = 5.0e-01;

//c---------------------------------------------------------------------
//c   coefficients of the exact solution to the third pde
//c---------------------------------------------------------------------
      ce(3,1) = 2.0;
      ce(3,2) = 2.0;
      ce(3,3) = 0.0;
      ce(3,4) = 0.0;
      ce(3,5) = 0.0;
      ce(3,6) = 2.0;
      ce(3,7) = 3.0;
      ce(3,8) = 4.0e-02;
      ce(3,9) = 3.0e-02;
      ce(3,10) = 5.0e-02;
      ce(3,11) = 3.0e-01;
      ce(3,12) = 5.0e-01;
      ce(3,13) = 4.0e-01;

//c---------------------------------------------------------------------
//c   coefficients of the exact solution to the fourth pde
//c---------------------------------------------------------------------
      ce(4,1) = 2.0;
      ce(4,2) = 2.0;
      ce(4,3) = 0.0;
      ce(4,4) = 0.0;
      ce(4,5) = 0.0;
      ce(4,6) = 2.0;
      ce(4,7) = 3.0;
      ce(4,8) = 3.0e-02;
      ce(4,9) = 5.0e-02;
      ce(4,10) = 4.0e-02;
      ce(4,11) = 2.0e-01;
      ce(4,12) = 1.0e-01;
      ce(4,13) = 3.0e-01;

//c---------------------------------------------------------------------
//c   coefficients of the exact solution to the fifth pde
//c---------------------------------------------------------------------
      ce(5,1) = 5.0;
      ce(5,2) = 4.0;
      ce(5,3) = 3.0;
      ce(5,4) = 2.0;
      ce(5,5) = 1.0e-01;
      ce(5,6) = 4.0e-01;
      ce(5,7) = 3.0e-01;
      ce(5,8) = 5.0e-02;
      ce(5,9) = 4.0e-02;
      ce(5,10) = 3.0e-02;
      ce(5,11) = 1.0e-01;
      ce(5,12) = 3.0e-01;
      ce(5,13) = 2.0e-01;

      return;
}



