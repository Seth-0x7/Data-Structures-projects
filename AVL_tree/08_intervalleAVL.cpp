/**
 * Tests unitaires pour IntervalleAVL<T>.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "intervalleavl.h"
#include <iostream>

int compteurAcomparaisons = 0;
class A {
  private:
    double x;
  public:
    A(double x_ = 0) : x(x_) {}
    bool operator < (const A & o) const {
			compteurAcomparaisons++;
      return x < o.x;
    }
    bool operator <= (const A & o) const {
      compteurAcomparaisons++;
      return x <= o.x;
    }
    bool operator == (const A & o) const {
      compteurAcomparaisons++;
      return x == o.x;
    }
    bool operator != (const A & o) const {
      compteurAcomparaisons++;
      return x != o.x;
    }
    bool operator >= (const A & o) const {
      compteurAcomparaisons++;
      return x >= o.x;
    }
    bool operator > (const A & o) const {
      compteurAcomparaisons++;
      return x > o.x;
    }
};

int main() {
	int erreur = 0, n = 1000000;
	IntervalleAVL<A> tree, arbre;
	compteurAcomparaisons = 0;
	for(int i = 0; i < n; i++) {
		Intervalle<A> x(i, i + 1);
		tree.inserer(x);
	}
	double avg = compteurAcomparaisons/(double)n;
	int h = tree.hauteur();
	if(avg > 8 * h) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	compteurAcomparaisons = 0;
	for(int i = n - 1; i >= 0; i--) {
		Intervalle<A> x(i, i + 1);
		tree.enlever(x);
	}
	avg = compteurAcomparaisons/(double)n;
	if(avg > 8 * h) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	tree.vider();
	for(int i = 0; i < n; i++) {
		Intervalle<A> x(i, i + 1);
		Intervalle<A> y(n - i - 1, n - i);
		tree.inserer(x);
		arbre.inserer(y);
	}
	compteurAcomparaisons = 0;
	bool egal = tree == arbre;
	if(!egal || compteurAcomparaisons > 2 * n + 2 * h) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}	
	for(int i = n; i < 2 * n; i++) {
		Intervalle<A> x(i, i + 1);
		tree.inserer(x);
	}
	compteurAcomparaisons = 0;
	egal = tree == arbre;
	if(egal || compteurAcomparaisons > 2 * n + 2 * h) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}	
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}

