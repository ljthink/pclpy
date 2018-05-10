
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pcl/point_types.h>

namespace py = pybind11;
using namespace pybind11::literals;

PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
#include "../make_opaque_vectors.hpp"

#include "surface/marching_cubes.hpp"
#include "surface/marching_cubes_hoppe.hpp"
#include "surface/marching_cubes_rbf.hpp"
#include "surface/organized_fast_mesh.hpp"
#include "surface/poisson.hpp"
#include "surface/simplification_remove_unused_vertices.hpp"
#include "surface/surfel_smoothing.hpp"
#include "surface/texture_mapping.hpp"


void defineSurfaceClasses1(py::module &m) {
    py::module m_surface = m.def_submodule("surface", "Submodule surface");
    defineSurfaceMarchingCubesClasses(m_surface);
    defineSurfaceMarchingCubesHoppeClasses(m_surface);
    defineSurfaceMarchingCubesRbfClasses(m_surface);
    defineSurfaceOrganizedFastMeshClasses(m_surface);
    defineSurfacePoissonClasses(m_surface);
    defineSurfaceSimplificationRemoveUnusedVerticesClasses(m_surface);
    defineSurfaceSurfelSmoothingClasses(m_surface);
    defineSurfaceTextureMappingClasses(m_surface);
}