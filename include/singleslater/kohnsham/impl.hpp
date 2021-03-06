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
#ifndef __INCLUDED_SINGLESLATER_KOHNSHAM_IMPL_HPP__
#define __INCLUDED_SINGLESLATER_KOHNSHAM_IMPL_HPP__

#include <singleslater/kohnsham.hpp>
#include <util/preprocessor.hpp>
#include <quantum/preprocessor.hpp>

#define KOHNSHAM_COLLECTIVE_OP(OP_MEMBER,OP_VEC_OP) \
  OP_MEMBER(this,other,isGGA_)\
  OP_MEMBER(this,other,functionals)\
  OP_MEMBER(this,other,intParam)\
  OP_MEMBER(this,other,XCEnergy)\
  OP_VEC_OP(double,this,other,this->memManager,VXC);

namespace ChronusQ {

  template <typename T>
  template <typename U>
  KohnSham<T>::KohnSham(const KohnSham<U> &other, int dummy) :
    SingleSlater<T>(dynamic_cast<const SingleSlater<U>&>(other),dummy),
    QuantumBase(dynamic_cast<const QuantumBase&>(other)),
    WaveFunctionBase(dynamic_cast<const WaveFunctionBase&>(other))
    { 
      KOHNSHAM_COLLECTIVE_OP(COPY_OTHER_MEMBER,COPY_OTHER_MEMBER_VEC_OP);
    };

  template <typename T>
  template <typename U>
  KohnSham<T>::KohnSham(KohnSham<U> &&other, int dummy) :
    SingleSlater<T>(dynamic_cast<SingleSlater<U>&&>(std::move(other)),dummy),
    QuantumBase(dynamic_cast<QuantumBase&&>(std::move(other))),
    WaveFunctionBase(dynamic_cast<WaveFunctionBase&&>(std::move(other)))
    { 
      KOHNSHAM_COLLECTIVE_OP(MOVE_OTHER_MEMBER,MOVE_OTHER_MEMBER_VEC_OP);
    };

  template <typename T>
  KohnSham<T>::KohnSham(const KohnSham<T> &other) :
    KohnSham(other,0) { }

  template <typename T>
  KohnSham<T>::KohnSham(KohnSham<T> &&other) :
    KohnSham(std::move(other),0) { }



}; // namespace ChronusQ

#include <singleslater/kohnsham/vxc.hpp> // VXC build

#endif
