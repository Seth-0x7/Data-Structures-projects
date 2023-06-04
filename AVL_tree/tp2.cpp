/** 
 * Programme principal pour utiliser les classes Intervalle et IntervalleAVL.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include <iostream>
#include <sstream>
#include <string>
#include "intervalleavl.h"

using namespace std;

/***********************************************************************
 * Vous pouvez ajouter toutes les fonctions dont vous avez besoin.
 * N'oubliez pas de bien commenter vos fonctions, de bien utilisez 
 * le mot-clé const et de prendre en considération les bonnes pratiques.
 ***********************************************************************/


// Retourne la période d'occupation. Voir l'exemple de l'énoncé pour plus
// détails.
double occupation(const IntervalleAVL<double> & arbre) {
	// À compléter
}

// Retourne la période d'inactivité. Voir l'exemple de l'énoncé pour plus
// détails.
double inactivite(const IntervalleAVL<double> & arbre) {
	// À compléter
}

// Retourne le nombre maximal d'intervalles qui se chevauchent avec l'intervalle "i". 
// Attention, si l'intervalle "i" partage seulement son "debut" ou sa "fin" avec un
// intervalle de "arbre", ce n'est pas considéré comme un chevauchement dans cette 
// fonction.
int chevauchement(const IntervalleAVL<double> & arbre, const Intervalle<double> & i) {
	// À compléter
}

/**
 * La fonction main est le point d'entrée. En principe, vous n'avez pas à modifier.
 * Deux usages possibles :
 * 		-	Calcul de l'activité : ./tp2 -a OCCUPATION INACTIVITE < TACHES 
 * 		-	Calcul de chevauchement : ./tp2 -c INTERVALLE CHEVAUCHEMENT ... < TACHES 
 */
int main(int argc, char * argv[]) {
	int erreur = 0;
	IntervalleAVL<double> arbre;
	std::string line; 
	while(std::getline(std::cin, line) && !line.empty()) {
		Intervalle<double> i;
		std::stringstream ss(line);
    		ss >> i;
		arbre.inserer(i);
	}
	if(std::string(argv[1]) == "-a") {
		double cons, inactif;
		istringstream s_occupation(argv[2]);
		s_occupation >> cons;
		istringstream s_inactivite(argv[3]);
		s_inactivite >> inactif;
		if(occupation(arbre) != cons) {
			std::cerr << "ECHEC - I" << std::endl;
			erreur++;
		}
		if(inactivite(arbre) != inactif) {
			std::cerr << "ECHEC - II" << std::endl;
			erreur++;
		}
	}
	if(std::string(argv[1]) == "-c") {
		for(int i = 2; i < argc; i += 2) {
			Intervalle<double> x;
			int che;
			istringstream s_intervalle(argv[i]);
    			s_intervalle >> x;
    			istringstream s_chevauchement(argv[i + 1]);
    			s_chevauchement >> che;
			if(chevauchement(arbre, x) != che) {
				std::cerr << "ECHEC - " << x << std::endl;
				erreur++;
			}
		}
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
