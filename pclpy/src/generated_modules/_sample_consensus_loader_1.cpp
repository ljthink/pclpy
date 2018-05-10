
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pcl/point_types.h>

namespace py = pybind11;
using namespace pybind11::literals;

PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
#include "../make_opaque_vectors.hpp"

#include "sample_consensus/lmeds.hpp"
#include "sample_consensus/mlesac.hpp"
#include "sample_consensus/msac.hpp"
#include "sample_consensus/prosac.hpp"


void defineSampleConsensusClasses(py::module &m) {
    py::module m_sample_consensus = m.def_submodule("sample_consensus", "Submodule sample_consensus");
    defineSampleConsensusLmedsClasses(m_sample_consensus);
    defineSampleConsensusMlesacClasses(m_sample_consensus);
    defineSampleConsensusMsacClasses(m_sample_consensus);
    defineSampleConsensusProsacClasses(m_sample_consensus);
}