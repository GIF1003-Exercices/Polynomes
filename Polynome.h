/*
 * Polynome.h
 *
 *  Created on: Oct 15, 2020
 *      Author: etudiant
 */

#ifndef POLYNOME_H_
#define POLYNOME_H_

namespace lab7 {

const int DEGRE_MAXIMAL = 10;

class Polynome {

private:
	double m_coefficients[DEGRE_MAXIMAL];

public:
	static bool degreEstValide(const int p_degre);

	Polynome();
	Polynome(const double p_coefficients[DEGRE_MAXIMAL]);

	void asgCoefficient(const double p_coefficient, const int p_degre);
	double reqCoefficient(const int p_degre) const;

	int reqDegre() const;
	double eval(const double p_x) const;

};

} /* namespace lab7 */

#endif /* POLYNOME_H_ */
