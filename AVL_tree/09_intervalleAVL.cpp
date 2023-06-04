/**
 * Tests unitaires pour IntervalleAVL<T>.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include <iostream>
#include "intervalleavl.h"

struct Memoire {
	uint64_t allocation = 0;
	uint64_t desallocation = 0;
};

Memoire mem;

void * operator new(std::size_t size) {
	mem.allocation++;
	return std::malloc(size);
}

void operator delete(void * memory) {
	mem.desallocation++;
	std::free(memory);
}

int main() {
	int erreur = 0, n = 100000;
	// Insertion et suppression (enlèvement non simplifié)
	{	
		IntervalleAVL<double> tree;
		for(int i = 0; i < n; i++) {
    	Intervalle<double> x(i, i + 1);
    	tree.inserer(x);
		}
		if(mem.allocation < n) {
			std::cerr << "ECHEC - I" << std::endl;
			erreur++;
		}
		for(int i = 0; i < n; i++) {
    	Intervalle<double> x(i, i + 1);
    	tree.enlever(x);
		}
		if(mem.allocation != mem.desallocation) {
			std::cerr << "ECHEC - II" << std::endl;
			erreur++;
		}
  }
	mem.allocation = 0;
	mem.desallocation = 0;
	// Destructeur
	{	
		IntervalleAVL<double> tree;
		for(int i = 0; i < n; i++) {
    	Intervalle<double> x(i, i + 1);
    	tree.inserer(x);
		}
	}
	if(mem.allocation != mem.desallocation) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	mem.allocation = 0;
	mem.desallocation = 0;
	// Constructeur par copie
	uint64_t alloc;
	{	
		IntervalleAVL<double> tree;
		for(int i = 0; i < n; i++) {
    	Intervalle<double> x(i, i + 1);
    	tree.inserer(x);
		}
		alloc = mem.allocation;
		IntervalleAVL<double> arbre(tree);
		if(mem.allocation - alloc != n) {
			std::cerr << "ECHEC - IV" << std::endl;
			erreur++;
		}
	}
	if(alloc + n != mem.desallocation) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	mem.allocation = 0;
	mem.desallocation = 0;
	// Opérateur d'affectation
	{	
		IntervalleAVL<double> tree;
		for(int i = 0; i < n; i++) {
    	Intervalle<double> x(i, i + 1);
    	tree.inserer(x);
		}
		alloc = mem.allocation;
		IntervalleAVL<double> arbre = tree;
		if(mem.allocation - alloc != n) {
			std::cerr << "ECHEC - VI" << std::endl;
			erreur++;
		}
	}
	if(alloc + n != mem.desallocation) {
		std::cerr << "ECHEC - VII" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

