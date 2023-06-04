/**
 * Tests unitaires pour Intervalle<T>.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "intervalle.h"
#include <iostream>

int main() {
	int erreur = 0, infinf = 0, inf = 2, mid = 7, sup = 13,  supsup = 17;
	Intervalle<int> uqam(2, 13);
	if(uqam.inclut(infinf) || uqam.inclut(supsup)) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(!uqam.inclut(mid) || !uqam.inclut(inf) || !uqam.inclut(sup)) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

