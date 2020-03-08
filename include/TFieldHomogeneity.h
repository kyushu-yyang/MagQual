#ifndef TFIELDHOMOGENEITY_HH
#define TFIELDHOMOGENEITY_HH

/// the base class to calculate the field homogeneity
///
/// @file  : TFieldHomogeneity
/// @author: Y.Yang
/// @date  : 2020.03.07


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
  kSVMS
};


// class
class MagQual::TFieldHomogeneity
{
  public:


  private:


};


#endif
