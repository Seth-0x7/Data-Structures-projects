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
		std::cerr << "ECHEC - I" << std::endl;
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
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	tree.enlever(t);
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
    std::cerr << "ECHEC - III" << std::endl;
    erreur++;
  }
  if(!tree.contient(i, 27) ||
      !tree.contient(j, 26) ||
      !tree.contient(k, 27) ||
      !tree.contient(l, 9.5) ||
      !tree.contient(m, 15) ||
      !tree.contient(n, 23) ||
      !tree.contient(o, 26) ||
      !tree.contient(p, 23) ||
      !tree.contient(q, 26) ||
      !tree.contient(r, 27)) {
    std::cerr << "ECHEC - IV" << std::endl;
    erreur++;
  }
	tree.enlever(r);
  if(tree.equilibre(i) != tree.get_equilibre(i) ||
      tree.equilibre(j) != tree.get_equilibre(j) ||
      tree.equilibre(k) != tree.get_equilibre(k) ||
      tree.equilibre(l) != tree.get_equilibre(l) ||
      tree.equilibre(m) != tree.get_equilibre(m) ||
      tree.equilibre(n) != tree.get_equilibre(n) ||
      tree.equilibre(o) != tree.get_equilibre(o) ||
      tree.equilibre(p) != tree.get_equilibre(p) ||
      tree.equilibre(q) != tree.get_equilibre(q)) {
    std::cerr << "ECHEC - VI" << std::endl;
    erreur++;
  }
  if(!tree.contient(i, 26) ||
      !tree.contient(j, 26) ||
      !tree.contient(k, 12) ||
      !tree.contient(l, 9.5) ||
      !tree.contient(m, 15) ||
      !tree.contient(n, 23) ||
      !tree.contient(o, 26) ||
      !tree.contient(p, 23) ||
      !tree.contient(q, 26)) {
    std::cerr << "ECHEC - VII" << std::endl;
    erreur++;
  }
	tree.enlever(k);
  if(tree.equilibre(i) != tree.get_equilibre(i) ||
      tree.equilibre(j) != tree.get_equilibre(j) ||
      tree.equilibre(l) != tree.get_equilibre(l) ||
      tree.equilibre(m) != tree.get_equilibre(m) ||
      tree.equilibre(n) != tree.get_equilibre(n) ||
      tree.equilibre(o) != tree.get_equilibre(o) ||
      tree.equilibre(p) != tree.get_equilibre(p) ||
      tree.equilibre(q) != tree.get_equilibre(q)) {
    std::cerr << "ECHEC - VIII" << std::endl;
    erreur++;
  }
  if(!tree.contient(i, 26) ||
      !tree.contient(j, 26) ||
      !tree.contient(l, 9.5) ||
      !tree.contient(m, 15) ||
      !tree.contient(n, 23) ||
      !tree.contient(o, 26) ||
      !tree.contient(p, 23) ||
      !tree.contient(q, 26)) {
    std::cerr << "ECHEC - IX" << std::endl;
    erreur++;
  }
	tree.enlever(m);
  if(tree.equilibre(i) != tree.get_equilibre(i) ||
      tree.equilibre(j) != tree.get_equilibre(j) ||
      tree.equilibre(l) != tree.get_equilibre(l) ||
      tree.equilibre(n) != tree.get_equilibre(n) ||
      tree.equilibre(o) != tree.get_equilibre(o) ||
      tree.equilibre(p) != tree.get_equilibre(p) ||
      tree.equilibre(q) != tree.get_equilibre(q)) {
    std::cerr << "ECHEC - XI" << std::endl;
    erreur++;
  }
  if(!tree.contient(i, 26) ||
      !tree.contient(j, 26) ||
      !tree.contient(l, 9.5) ||
      !tree.contient(n, 23) ||
      !tree.contient(o, 26) ||
      !tree.contient(p, 23) ||
      !tree.contient(q, 26)) {
    std::cerr << "ECHEC - XII" << std::endl;
    erreur++;
  }
	tree.enlever(l);
  if(tree.equilibre(i) != tree.get_equilibre(i) ||
      tree.equilibre(j) != tree.get_equilibre(j) ||
      tree.equilibre(n) != tree.get_equilibre(n) ||
      tree.equilibre(o) != tree.get_equilibre(o) ||
      tree.equilibre(p) != tree.get_equilibre(p) ||
      tree.equilibre(q) != tree.get_equilibre(q)) {
    std::cerr << "ECHEC - XIII" << std::endl;
    erreur++;
  }
  if(!tree.contient(i, 13) ||
      !tree.contient(j, 26) ||
      !tree.contient(n, 23) ||
      !tree.contient(o, 25) ||
      !tree.contient(p, 23) ||
      !tree.contient(q, 26)) {
    std::cerr << "ECHEC - XIV" << std::endl;
    erreur++;
  }
	tree.enlever(j);
  if(tree.equilibre(i) != tree.get_equilibre(i) ||
      tree.equilibre(n) != tree.get_equilibre(n) ||
      tree.equilibre(o) != tree.get_equilibre(o) ||
      tree.equilibre(p) != tree.get_equilibre(p) ||
      tree.equilibre(q) != tree.get_equilibre(q)) {
    std::cerr << "ECHEC - XV" << std::endl;
    erreur++;
  }
  if(!tree.contient(i, 13) ||
      !tree.contient(n, 23) ||
      !tree.contient(o, 26) ||
      !tree.contient(p, 23) ||
      !tree.contient(q, 26)) {
    std::cerr << "ECHEC - XVI" << std::endl;
    erreur++;
  }
	tree.enlever(o);
  if(tree.equilibre(i) != tree.get_equilibre(i) ||
      tree.equilibre(n) != tree.get_equilibre(n) ||
      tree.equilibre(p) != tree.get_equilibre(p) ||
      tree.equilibre(q) != tree.get_equilibre(q)) {
    std::cerr << "ECHEC - XVII" << std::endl;
    erreur++;
  }
  if(!tree.contient(i, 13) ||
      !tree.contient(n, 23) ||
      !tree.contient(p, 23) ||
      !tree.contient(q, 26)) {
    std::cerr << "ECHEC - XVIII" << std::endl;
    erreur++;
  }
	tree.enlever(q);
  if(tree.equilibre(i) != tree.get_equilibre(i) ||
      tree.equilibre(n) != tree.get_equilibre(n) ||
      tree.equilibre(p) != tree.get_equilibre(p)) {
    std::cerr << "ECHEC - XIX" << std::endl;
    erreur++;
  }
  if(!tree.contient(i, 13) ||
      !tree.contient(n, 23) ||
      !tree.contient(p, 20)) {
    std::cerr << "ECHEC - XX" << std::endl;
    erreur++;
  }
	tree.enlever(n);
  if(tree.equilibre(i) != tree.get_equilibre(i) ||
      tree.equilibre(p) != tree.get_equilibre(p)) {
    std::cerr << "ECHEC - XXI" << std::endl;
    erreur++;
  }
  if(!tree.contient(i, 20) ||
      !tree.contient(p, 20)) {
    std::cerr << "ECHEC - XXII" << std::endl;
    erreur++;
	} 
	tree.enlever(i);
  if(tree.equilibre(p) != tree.get_equilibre(p)) {
    std::cerr << "ECHEC - XXIII" << std::endl;
    erreur++;
  }
  if(!tree.contient(p, 20)) {
    std::cerr << "ECHEC - XXIV" << std::endl;
    erreur++;
	} 
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

