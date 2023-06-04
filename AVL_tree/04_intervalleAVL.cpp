/**
 * Tests unitaires pour IntervalleAVL<T>.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "intervalleavl.h"
#include <iostream>

int main() {
	int erreur = 0;
	IntervalleAVL<double> tree;
	for(int i = 0; i < 1000; i++) {
		Intervalle<double> t(i, i + 1);
		tree.inserer(t);
	}
	if(tree.taille() != 1000) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(tree.hauteur() != 10) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	for(IntervalleAVL<double>::Iterateur iter = tree.debut(); iter; iter++)
		if(tree.equilibre(tree[iter]) != tree.get_equilibre(tree[iter]))
			erreur++;
	if(old_erreur != erreur) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	old_erreur = erreur;
	for(IntervalleAVL<double>::Iterateur iter = tree.debut(); iter; iter++)
		if(tree.max(tree[iter]) != tree.get_max(tree[iter]))
			erreur++;
	if(old_erreur != erreur) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

