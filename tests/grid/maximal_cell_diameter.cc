// ---------------------------------------------------------------------
//
// Copyright (C) 2001 - 2018 by the deal.II authors
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



#include <deal.II/grid/grid_generator.h>
#include <deal.II/grid/grid_out.h>
#include <deal.II/grid/grid_tools.h>
#include <deal.II/grid/tria.h>

#include "../tests.h"



std::ofstream logfile("output");



template <int dim>
void
test1()
{
  // test 1: hypercube
  if (true)
    {
      Triangulation<dim> tria;
      GridGenerator::hyper_cube(tria);

      for (unsigned int i = 0; i < 2; ++i)
        {
          tria.refine_global(2);
          deallog << dim << "d, "
                  << "max diameter: " << GridTools::maximal_cell_diameter(tria)
                  << std::endl;
          Assert(GridTools::maximal_cell_diameter(tria) >=
                   GridTools::minimal_cell_diameter(tria),
                 ExcInternalError());
        };
    };

  // test 2: hyperball
  if (dim >= 2)
    {
      Triangulation<dim> tria;
      GridGenerator::hyper_ball(tria, Point<dim>(), 1);
      tria.reset_manifold(0);

      for (unsigned int i = 0; i < 2; ++i)
        {
          tria.refine_global(2);
          deallog << dim << "d, "
                  << "max diameter: " << GridTools::maximal_cell_diameter(tria)
                  << std::endl;
          Assert(GridTools::maximal_cell_diameter(tria) >=
                   GridTools::minimal_cell_diameter(tria),
                 ExcInternalError());
        };
    };
}


int
main()
{
  deallog << std::setprecision(4);
  deallog.attach(logfile);

  test1<1>();
  test1<2>();
  test1<3>();

  return 0;
}
