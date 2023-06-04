/**
 * Tests unitaires pour EnhancedAVL<T>.
 * TP2 -- Arbre AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "intervalleavl.h"
#include <iostream>

int main() {
	int erreur = 0;
	IntervalleAVL<double> tree;
	Intervalle<double> i(12.5, 13); 
	Intervalle<double> j(14.5, 19.5);
	Intervalle<double> k(10, 12);
	Intervalle<double> l(9, 9.5);
	Intervalle<double> m(14, 15);
	Intervalle<double> n(15, 23);
	Intervalle<double> o(13, 25);
	Intervalle<double> p(17, 20);
	Intervalle<double> q(12.75, 26);
	Intervalle<double> r(11, 27);
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
	for(IntervalleAVL<double>::Iterateur iter = tree.debut(); iter; iter++)
		std::cout << tree[iter] << std::endl;
	tree.enlever(q);
	std::cout << std::endl;
	for(IntervalleAVL<double>::Iterateur iter = tree.debut(); iter; iter++)
		std::cout << tree[iter] << std::endl;
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

