#ifndef TFIELDHOMOGENEITY_HH
#define TFIELDHOMOGENEITY_HH

/// the base class to calculate the field homogeneity
///
/// @file  : TFieldHomogeneity
/// @author: Y.Yang
/// @date  : 2020.03.07

#include <Eigen/Dense>
#include <boost/math/quadrature/trapezoidal.hpp>

using namespace Eigen;

namespace MagQual
{ class TFieldHomogeneity; }

// @eum define the scored shape of field
enum Shape
{
  kShpere,
  kEllpisoid,
  kCylinder
};

// @eum define the type of homogeneity
enum Homogeneity
{
  kPeakPeak,
  kVRMS,
  kSRMS
};


// class
class MagQual::TFieldHomogeneity
{
  public:
    /// constructor
    TFieldHomogeneity();

    /// deconstructor
    virtual ~TFieldHomogeneity();


  private:
    int fNLegendre;
    MatrixXd fAnm;

};


#endif
