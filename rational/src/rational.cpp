#include "rational.h"
#include "gcd.h"

#include <stdexcept>
#include <ostream>
#include <iostream>
#include <cmath>

// Implement this
const Rational Rational::inverse() const {
  /* Return the Rational number 1 / current rational */
  return Rational{_den, _num};
}

// Implement this
Rational::sign_type Rational::sign() const {
  /* Return, as a sign_type, the sign of the Rational */
  if (_num < 0) {
    return Rational::NEGATIVE;
  } else {
    return Rational::POSITIVE;
  }
}

/* Print the value num/den to the supplied output stream, or 0 if 
 * the Rational happens to be identically zero.
 */
std::ostream& operator<<( std::ostream &os, const Rational &ratio ) {
  if( ratio == 0 ) {
    os << "0";
  } else {
    if( ratio.sign() == Rational::NEGATIVE ) {
      os << "-";
    }
    os << std::abs( ratio.num() ) << "/" << std::abs( ratio.den() );
  }
  return os;
}

/* This function will be called whenever the 
 * Rational is constructed from integers that
 * are supplied as numerator and denominator.
 * It should reduce the fraction to lowest terms;
 * for example, when we try to construct a
 * Rational{ 4, -8 }, this is the function that
 * will cause the number to be exactly the same
 * as Rational{ -1, 2 }. Numerators should be
 * the only value potentially negative after
 * the call to ::normalize().
 * Throw bad_rational if there is an attempt
 * to set one with a zero denominator.
 */
void Rational::normalize() {
  // You should implement
  intmax_t divide_by = gcd(std::abs(_num), std::abs(_den));
  _num /= divide_by;
  _den /= divide_by;
  if (_den < 0 && _num < 0) {
    _num = std::abs(_num);
    _den = std::abs(_den);
  } else if (_den < 0) {
    _num *= -1;
    _den = std::abs(_den);
  }
}

// Return the float precision number corresponding to the Rational
float Rational::to_float() const {
  return (float) to_double();
}

// Return the double precision number corresponding to the Rational
double Rational::to_double() const {
  return ((double) _num) / ((double) _den);
}
