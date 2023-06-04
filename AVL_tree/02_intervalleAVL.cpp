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
	Intervalle<double> i(12.5, 13); 
	tree.inserer(i);
	if(tree.equilibre(i) != tree.get_equilibre(i)) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 13)) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	Intervalle<double> j(14.5, 19.5);
	tree.inserer(j);
	if(tree.equilibre(i) != tree.get_equilibre(i) ||
			tree.equilibre(j) != tree.get_equilibre(j)) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 19.5) ||
			!tree.contient(j, 19.5)) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	Intervalle<double> k(10, 12);
	tree.inserer(k);
	if(tree.equilibre(i) != tree.get_equilibre(i) ||
			tree.equilibre(j) != tree.get_equilibre(j) ||
			tree.equilibre(k) != tree.get_equilibre(k)) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 19.5) ||
			!tree.contient(j, 19.5) ||
			!tree.contient(k, 12)) {
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	Intervalle<double> l(9, 9.5);
	tree.inserer(l);
	if(tree.equilibre(i) != tree.get_equilibre(i) ||
			tree.equilibre(j) != tree.get_equilibre(j) ||
			tree.equilibre(k) != tree.get_equilibre(k) ||
			tree.equilibre(l) != tree.get_equilibre(l)) {
		std::cerr << "ECHEC - VII" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 19.5) ||
			!tree.contient(j, 19.5) ||
			!tree.contient(k, 12) ||
			!tree.contient(l, 9.5)) {
		std::cerr << "ECHEC - VIII" << std::endl;
		erreur++;
	}
	Intervalle<double> m(14, 15);
	tree.inserer(m);
	if(tree.equilibre(i) != tree.get_equilibre(i) ||
			tree.equilibre(j) != tree.get_equilibre(j) ||
			tree.equilibre(k) != tree.get_equilibre(k) ||
			tree.equilibre(l) != tree.get_equilibre(l) ||
			tree.equilibre(m) != tree.get_equilibre(m)) {
		std::cerr << "ECHEC - VII" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 19.5) ||
			!tree.contient(j, 19.5) ||
			!tree.contient(k, 12) ||
			!tree.contient(l, 9.5) ||
			!tree.contient(m, 15)) {
		std::cerr << "ECHEC - VIII" << std::endl;
		erreur++;
	}
	Intervalle<double> n(15, 23);
	tree.inserer(n);
	if(tree.equilibre(i) != tree.get_equilibre(i) ||
			tree.equilibre(j) != tree.get_equilibre(j) ||
			tree.equilibre(k) != tree.get_equilibre(k) ||
			tree.equilibre(l) != tree.get_equilibre(l) ||
			tree.equilibre(m) != tree.get_equilibre(m) ||
			tree.equilibre(n) != tree.get_equilibre(n)) {
		std::cerr << "ECHEC - IX" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 23) ||
			!tree.contient(j, 23) ||
			!tree.contient(k, 12) ||
			!tree.contient(l, 9.5) ||
			!tree.contient(m, 15) ||
			!tree.contient(n, 23)) {
		std::cerr << "ECHEC - X" << std::endl;
		erreur++;
	}
	Intervalle<double> o(13, 25);
	tree.inserer(o);
	if(tree.equilibre(i) != tree.get_equilibre(i) ||
			tree.equilibre(j) != tree.get_equilibre(j) ||
			tree.equilibre(k) != tree.get_equilibre(k) ||
			tree.equilibre(l) != tree.get_equilibre(l) ||
			tree.equilibre(m) != tree.get_equilibre(m) ||
			tree.equilibre(n) != tree.get_equilibre(n) ||
			tree.equilibre(o) != tree.get_equilibre(o)) {
		std::cerr << "ECHEC - XI" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 25) ||
			!tree.contient(j, 25) ||
			!tree.contient(k, 12) ||
			!tree.contient(l, 9.5) ||
			!tree.contient(m, 25) ||
			!tree.contient(n, 23) ||
			!tree.contient(o, 25)) {
		std::cerr << "ECHEC - XII" << std::endl;
		erreur++;
	}
	Intervalle<double> p(17, 20);
	tree.inserer(p);
	if(tree.equilibre(i) != tree.get_equilibre(i) ||
			tree.equilibre(j) != tree.get_equilibre(j) ||
			tree.equilibre(k) != tree.get_equilibre(k) ||
			tree.equilibre(l) != tree.get_equilibre(l) ||
			tree.equilibre(m) != tree.get_equilibre(m) ||
			tree.equilibre(n) != tree.get_equilibre(n) ||
			tree.equilibre(o) != tree.get_equilibre(o) ||
			tree.equilibre(p) != tree.get_equilibre(p)) {
		std::cerr << "ECHEC - XIII" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 25) ||
			!tree.contient(j, 25) ||
			!tree.contient(k, 12) ||
			!tree.contient(l, 9.5) ||
			!tree.contient(m, 25) ||
			!tree.contient(n, 23) ||
			!tree.contient(o, 25) ||
			!tree.contient(p, 20)) {
		std::cerr << "ECHEC - XIV" << std::endl;
		erreur++;
	}
	Intervalle<double> q(12.75, 26);
	tree.inserer(q);
	if(tree.equilibre(i) != tree.get_equilibre(i) ||
			tree.equilibre(j) != tree.get_equilibre(j) ||
			tree.equilibre(k) != tree.get_equilibre(k) ||
			tree.equilibre(l) != tree.get_equilibre(l) ||
			tree.equilibre(m) != tree.get_equilibre(m) ||
			tree.equilibre(n) != tree.get_equilibre(n) ||
			tree.equilibre(o) != tree.get_equilibre(o) ||
			tree.equilibre(p) != tree.get_equilibre(p) ||
			tree.equilibre(q) != tree.get_equilibre(q)) {
		std::cerr << "ECHEC - XV" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 26) ||
			!tree.contient(j, 26) ||
			!tree.contient(k, 12) ||
			!tree.contient(l, 9.5) ||
			!tree.contient(m, 15) ||
			!tree.contient(n, 23) ||
			!tree.contient(o, 26) ||
			!tree.contient(p, 20) ||
			!tree.contient(q, 26)) {
		std::cerr << "ECHEC - XVI" << std::endl;
		erreur++;
	}
	Intervalle<double> r(11, 27);
	tree.inserer(r);
	if(tree.equilibre(i) != tree.get_equilibre(i) ||
			tree.equilibre(j) != tree.get_equilibre(j) ||
			tree.equilibre(k) != tree.get_equilibre(k) ||
			tree.equilibre(l) != tree.get_equilibre(l) ||
			tree.equilibre(m) != tree.get_equilibre(m) ||
			tree.equilibre(n) != tree.get_equilibre(n) ||
			tree.equilibre(o) != tree.get_equilibre(o) ||
			tree.equilibre(p) != tree.get_equilibre(p) ||
			tree.equilibre(q) != tree.get_equilibre(q) ||
			tree.equilibre(r) != tree.get_equilibre(r)) {
		std::cerr << "ECHEC - XVII" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 27) ||
			!tree.contient(j, 26) ||
			!tree.contient(k, 27) ||
			!tree.contient(l, 9.5) ||
			!tree.contient(m, 15) ||
			!tree.contient(n, 23) ||
			!tree.contient(o, 26) ||
			!tree.contient(p, 20) ||
			!tree.contient(q, 26) ||
			!tree.contient(r, 27)) {
		std::cerr << "ECHEC - XVIII" << std::endl;
		erreur++;
	}
	Intervalle<double> t(28, 30);
	tree.inserer(t);
	if(tree.equilibre(i) != tree.get_equilibre(i) ||
			tree.equilibre(j) != tree.get_equilibre(j) ||
			tree.equilibre(k) != tree.get_equilibre(k) ||
			tree.equilibre(l) != tree.get_equilibre(l) ||
			tree.equilibre(m) != tree.get_equilibre(m) ||
			tree.equilibre(n) != tree.get_equilibre(n) ||
			tree.equilibre(o) != tree.get_equilibre(o) ||
			tree.equilibre(p) != tree.get_equilibre(p) ||
			tree.equilibre(q) != tree.get_equilibre(q) ||
			tree.equilibre(r) != tree.get_equilibre(r) ||
			tree.equilibre(t) != tree.get_equilibre(t)) {
		std::cerr << "ECHEC - XVII" << std::endl;
		erreur++;
	}
	if(!tree.contient(i, 30) ||
			!tree.contient(j, 30) ||
			!tree.contient(k, 27) ||
			!tree.contient(l, 9.5) ||
			!tree.contient(m, 15) ||
			!tree.contient(n, 23) ||
			!tree.contient(o, 26) ||
			!tree.contient(p, 30) ||
			!tree.contient(q, 26) ||
			!tree.contient(r, 27) ||
			!tree.contient(t, 30)) {
		std::cerr << "ECHEC - XVIII" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

