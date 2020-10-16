/*
 * testPolynome.cpp
 *
 *  Created on: 2020-10-11
 *      Author: etudiant
 */

#include <iostream>
#include "Polynome.h"

using namespace std;

int main()
{
	lab7::Polynome poly;

	// On crée explicitement le polynôme de degré 2: x**2 - x - 2
	poly.asgCoefficient(-2, 0);
	poly.asgCoefficient(-1, 1);
	poly.asgCoefficient(1, 2);

	cout << poly.reqDegre() << endl;
	cout << poly.eval(2) << endl;
	cout << poly.eval(-1) << endl;
	cout << poly.eval(0) << endl;

	lab7::Polynome polyp;
	polyp.asgCoefficient(1, 0);

	cout << polyp.reqDegre() << endl;
	cout << polyp.eval(1) << endl;
	cout << polyp.eval(1000.4565) << endl;
	cout << polyp.eval(-125678) << endl;

	double listeGrosPolynome[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	lab7::Polynome polypp(listeGrosPolynome);
	cout << polypp.reqDegre() << endl;
	cout << polypp.eval(0) << endl;
	cout << polypp.eval(1) << endl;
	cout << polypp.eval(-1) << endl;

	return 0;
}



