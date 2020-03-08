#ifndef TUNITS_HH
#define TUNITS_HH

#include <cmath>

// units
namespace Unit
{
  // length
  static const double m  = 1.;
  static const double dm = 0.1;
  static const double cm = 0.01;
  static const double mm = 0.001;
  static const double um = 1e-6;

  // magnetic field
  static const double Tesla  = 1.;
  static const double Gauss  = 1e-4;
  static const double mTesla = 1e-3;

  // current
  static const double Ampere  = 1.;
  static const double mAmpere = 1e-3;

};


// physics constants
namespace Constant
{
  static const double pi  = M_PI;
  static const double mu0 = 4.*pi*1e-7;
};


#endif
