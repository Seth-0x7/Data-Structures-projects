/**
 * Tests unitaires pour Intervalle<T>.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "intervalle.h"
#include <iostream>

int main() {
	int erreur = 0;
	Intervalle<int> uqac(2, 7), uqam(2, 13);
	if(uqac == uqam || uqam == uqac) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	Intervalle<int> udem(5, 11);
	if(uqac > udem || udem < uqac || uqam > udem || udem < uqam) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	Intervalle<int> udes(0, 15);
	if(uqac < udes || udes > uqac || uqam < udes || udes > uqam) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	Intervalle<int> uqtr(uqam);
	if(!(uqam == uqtr) || !(uqtr == uqam)) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	uqac = uqam;
	if(!(uqam == uqac) || !(uqac == uqam)) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

