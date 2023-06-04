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
	Intervalle<int> uqac(-4, 2), uqam(2, 13), udem(13, 19);
	if(uqac.chevauchement(uqam) || uqam.chevauchement(udem) || uqac.chevauchement(udem)) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	Intervalle<int> uqtr(uqam);
	if(!uqam.chevauchement(uqtr) || !uqtr.chevauchement(uqam)) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	Intervalle<int> udes(0, 15);
	if(!udes.chevauchement(uqam) || !uqam.chevauchement(udes)) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	if(!udes.chevauchement(udem) || !udem.chevauchement(udes)) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(!udes.chevauchement(uqac) || !uqac.chevauchement(udes)) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

