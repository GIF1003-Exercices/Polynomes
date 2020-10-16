/*
 * Polynome.cpp
 *
 *  Created on: Oct 15, 2020
 *      Author: etudiant
 */

#include "Polynome.h"
#include <cassert>

namespace lab7 {

/**
 * Retourne true si l'entier p_degre est entre 0 et DEGRE_MAXIMAL
 * (donc pourrait être un des termes  du polynôme)
 */
bool Polynome::degreEstValide(const int p_degre)
{
	return (p_degre >= 0) and (p_degre < DEGRE_MAXIMAL);
}

/**
 * Constructeur par défaut: retourne un polynôme identiquement nul
 */

Polynome::Polynome()
{
	for (int i= 0; i < DEGRE_MAXIMAL; ++i)
	{
		m_coefficients[i] = 0;
	}
}

/**
 * Constructeur <a partir d'une liste ordonnées de coefficients.
 *
 * \param[in] p_coefficients Liste ordonnée des coefficients
 */

Polynome::Polynome(const double p_coefficients[DEGRE_MAXIMAL])
{
	for (int i = 0; i < DEGRE_MAXIMAL; ++i)
	{
		m_coefficients[i] = p_coefficients[i];
	}
}

/**
 * Permet de modifier un des coefficients
 *
 * \param[in] p_coefficient la nouvelle valeur souhaitée
 * \param[in] p_degre le terme auquel assigner le nouveau coefficient
 * \pre 0 <= p_degre <= DEGRE_MAXIMAL
 */
void Polynome::asgCoefficient(const double p_coefficient, const int p_degre)
{
	assert(degreEstValide(p_degre));
	m_coefficients[p_degre] = p_coefficient;
}

/**
 * Retourne la valeur du coefficient de degré p_degré
 */

double Polynome::reqCoefficient(const int p_degre) const
{
    assert(degreEstValide(p_degre));
	return m_coefficients[p_degre];
}

/**
 * Retourne le degré du polynôme soit:
 * Le degré du terme non-nul ayant l'exposnat maximal
 */
int Polynome::reqDegre() const
{
	int degre;

	for (degre = DEGRE_MAXIMAL - 1; (m_coefficients[degre] == 0) and (degre > 0); --degre);
	return degre;
}

/**
 * Retourne la valeur numérique du polynôme au point p_x
 */

double Polynome::eval(const double p_x) const
{
	int degre = reqDegre();
	double termeCourant;
	double termeInitial = m_coefficients[degre];

	for (int i = degre-1; i >= 0; --i)
	{
		termeCourant = p_x * termeInitial + m_coefficients[i];
		termeInitial = termeCourant;
	}
	return termeInitial;

}


} /* namespace lab7 */
