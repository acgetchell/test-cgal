#include <CGAL/Delaunay_triangulation_3.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_cell_base_with_info_3.h>
#include <CGAL/Triangulation_vertex_base_with_info_3.h>
#include <iostream>

using Kernel = CGAL::Exact_predicates_inexact_constructions_kernel;
using Triangulation3 = CGAL::Triangulation_3<Kernel>;
using Vertex_base = CGAL::Triangulation_vertex_base_with_info_3<int, Kernel>;
using Cell_base = CGAL::Triangulation_cell_base_with_info_3<int, Kernel>;
using Tds = CGAL::Triangulation_data_structure_3<Vertex_base, Cell_base,
                                                 CGAL::Parallel_tag>;
using Delaunay3 = CGAL::Delaunay_triangulation_3<Kernel, Tds>;
using Vertex_handle = Delaunay3::Vertex_handle;

int main(int argc, char const *argv[]) {
  Delaunay3 dt;
  std::cout << "Default construction of Delaunay3 ...\n";

  auto vertices = dt.tds().vertices();
  auto vertex = static_cast<Vertex_handle>(vertices.begin());

  std::cout << std::boolalpha
            << "There is only one vertex: " << (vertices.size() == 1) << "\n";

  std::cout << std::boolalpha
            << "The item from tds().vertices().begin() is a vertex: "
            << dt.is_vertex(vertex) << "\n";

  std::cout << std::boolalpha
            << "The item is the infinite vertex: " << dt.is_infinite(vertex)
            << "\n";

  return 0;
}
