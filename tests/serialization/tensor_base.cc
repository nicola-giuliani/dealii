// ---------------------------------------------------------------------
//
// Copyright (C) 2010 - 2017 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE.md at
// the top level directory of deal.II.
//
// ---------------------------------------------------------------------


// check serialization for Tensor<1,dim>

#include <deal.II/base/tensor.h>

#include "serialization.h"


void
test()
{
  const unsigned int dim = 3;

  double         a1[3] = {1, 2, 3};
  Tensor<1, dim> t1(a1);

  double         a2[3] = {3, 6, 9};
  Tensor<1, dim> t2(a2);

  verify(t1, t2);
}


int
main()
{
  std::ofstream logfile("output");
  deallog << std::setprecision(3);
  deallog.attach(logfile);

  test();

  deallog << "OK" << std::endl;
}
