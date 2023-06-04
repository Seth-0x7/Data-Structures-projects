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
	Intervalle<double> uqac(2, 3), uqam(2, 4), udem(1, 2), udes(3, 5);
	if(udem.longueur() != 1 || 
			udes.longueur() != 2 ||
			uqam.longueur() != 2 ||
			uqac.longueur() != 1) {
    std::cerr << "ECHEC - I" << std::endl;
    erreur++;
  }
	if(udem.fusion(udes).longueur() != 0 || udes.fusion(udem).longueur() != 0) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	Intervalle<double> univ(2, 4);
	if(!(univ == uqac.fusion(uqam)) || !(univ == uqam.fusion(uqac))) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	Intervalle<double> vinu(2, 5);
	if(!(vinu == udes.fusion(uqam)) || !(vinu == uqam.fusion(udes))) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(udem.inter(udes).longueur() != 0 || udes.inter(udem).longueur() != 0) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(!(uqac == uqac.inter(uqam)) || !(uqac == uqam.inter(uqac))) {
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	Intervalle<double> inuv(2, 2);
	if(!(inuv == uqac.inter(udem)) || !(inuv == udem.inter(uqac))) {
		std::cerr << "ECHEC - VII" << std::endl;
		erreur++;
	}
	Intervalle<double> ssd(2.5, 2.75), hdd(6, 7);
	if(uqam.distance(udem) != 0 ||
			udem.distance(uqam) != 0 ||
			uqac.distance(uqam) != 0 ||
			uqam.distance(uqac) != 0 ||
			udes.distance(uqam) != 0 ||
			uqam.distance(udes) != 0 ||
			ssd.distance(uqac) != 0 ||
			uqac.distance(ssd) != 0) {
		std::cerr << "ECHEC - VIII" << std::endl;
		erreur++;
	}
	if(udes.distance(udem) != 1 ||
			udem.distance(udes) != 1 ||
			ssd.distance(udem) != 0.5 ||
			udem.distance(ssd) != 0.5 ||
			ssd.distance(hdd) != 3.25 ||
			hdd.distance(ssd) != 3.25) {
		std::cerr << "ECHEC - IX" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

