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
	Intervalle<double> i(12.5, 13), j(14.5, 19.5), k(10, 12),
		l(9, 9.5), m(14, 15), n(15, 23),
		o(13, 25), p(17, 20), q(12.75, 26),
		r(11, 27), t(28, 30);
	tree.inserer(i);
	tree.inserer(j);
	tree.inserer(k);
	tree.inserer(l);
	tree.inserer(m);
	tree.inserer(n);
	tree.inserer(o);
	tree.inserer(p);
	tree.inserer(q);
	tree.inserer(r);
	tree.inserer(t);
	IntervalleAVL<double> arbre(tree);
	if(!(tree == arbre) || !(arbre == tree)) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	IntervalleAVL<double> baum = arbre;
	if(!(tree == baum) || !(baum == arbre) || !(baum == baum)) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	tree.vider();
	if(tree == arbre || arbre == tree || baum == tree) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	arbre.vider();
	if(!(tree == arbre) || arbre == baum || baum == tree) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	for(int i = 0; i < 1000; i++) {
		Intervalle<double> t(i, i + 4);
		tree.inserer(t);
	}
	baum = tree;
	if(!(tree == baum) || !(baum == tree)) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	for(int i = 999; i >= 0; i--) {
		Intervalle<double> t(i, i + 4);
		arbre.inserer(t);
	}
	if(!(arbre == baum) || 
			!(baum == arbre) ||
			!(tree == arbre) ||
			!(arbre == tree)) {
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

