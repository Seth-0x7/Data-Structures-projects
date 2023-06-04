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
	if(tree.couvert(9) != 1) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(tree.couvert(11.5) != 2) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	if(tree.couvert(9.75) != 0) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	if(tree.couvert(13) != 4) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(tree.couvert(16) != 5) {
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	if(tree.couvert(18) != 6) {
		std::cerr << "ECHEC - VII" << std::endl;
		erreur++;
	}
	tree.vider();
	if(tree.taille() != 0) {
		std::cerr << "ECHEC - VIII" << std::endl;
		erreur++;
	}
	if(tree.hauteur() != 0) {
		std::cerr << "ECHEC - IX" << std::endl;
		erreur++;
	}
	for(int i = 0; i < 1000; i++) {
		Intervalle<double> t(i, i + 4);
		tree.inserer(t);
	}
	int old_erreur = erreur;
	for(int i = 4; i < 1000; i++)
		if(tree.couvert(i) != 5)
			erreur++;
	if(old_erreur != erreur) {
		std::cerr << "ECHEC - X" << std::endl;
		erreur++;
	}
	if(tree.couvert(0) != 1 ||
			tree.couvert(1) != 2 ||
			tree.couvert(2) != 3 ||
			tree.couvert(3) != 4 ||
			tree.couvert(1000) != 4 ||
			tree.couvert(1001) != 3 ||
			tree.couvert(1002) != 2 ||
			tree.couvert(1003) != 1) {
		std::cerr << "ECHEC - XI" << std::endl;
		erreur++;
	}
	tree.vider();
	if(tree.taille() != 0) {
		std::cerr << "ECHEC - XII" << std::endl;
		erreur++;
	}
	if(tree.hauteur() != 0) {
		std::cerr << "ECHEC - XIII" << std::endl;
		erreur++;
	}
	old_erreur = erreur;
	for(int i = 0; i < 1004; i++)
		if(tree.couvert(i) != 0)
			erreur++;
	if(old_erreur != erreur) {
		std::cerr << "ECHEC - XIV" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

