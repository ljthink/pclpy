
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pcl/point_types.h>

namespace py = pybind11;
using namespace pybind11::literals;

PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
#include "../make_opaque_vectors.hpp"

#include "features/intensity_spin.hpp"
#include "features/linear_least_squares_normal.hpp"
#include "features/moment_invariants.hpp"
#include "features/moment_of_inertia_estimation.hpp"
#include "features/multiscale_feature_persistence.hpp"
#include "features/normal_3d.hpp"
#include "features/normal_3d_omp.hpp"
#include "features/normal_based_signature.hpp"


void defineFeaturesClasses2(py::module &m) {
    py::module m_features = m.def_submodule("features", "Submodule features");
    defineFeaturesIntensitySpinClasses(m_features);
    defineFeaturesLinearLeastSquaresNormalClasses(m_features);
    defineFeaturesMomentInvariantsClasses(m_features);
    defineFeaturesMomentOfInertiaEstimationClasses(m_features);
    defineFeaturesMultiscaleFeaturePersistenceClasses(m_features);
    defineFeaturesNormal3dClasses(m_features);
    defineFeaturesNormal3dOmpClasses(m_features);
    defineFeaturesNormalBasedSignatureClasses(m_features);
}