/* 
 *  This file is part of the Chronus Quantum (ChronusQ) software package
 *  
 *  Copyright (C) 2014-2017 Li Research Group (University of Washington)
 *  
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *  
 *  Contact the Developers:
 *    E-Mail: xsli@uw.edu
 *  
 */
#ifndef __INCLUDED_CQLINALG_SVD_HPP__
#define __INCLUDED_CQLINALG_SVD_HPP__

#include <cqlinalg/cqlinalg_config.hpp>

namespace ChronusQ {

  template <typename _F>
  int SVD(char JOBU, char JOBVT, int M, int N, _F *A, int LDA, double *S,
    _F *U, int LDU, _F *VT, int LDVT, CQMemManager &mem);

}; // namespace ChronusQ

#endif
