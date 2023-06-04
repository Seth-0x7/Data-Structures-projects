/** 
 * Programme principal pour utiliser les classe Tableau et Ensemble.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "tableau_files/tableau.h"
#include "ensemble_files/ensemble.h"
#include <iostream>

using namespace std;

/***********************************************************************
 * Vous pouvez ajouter toutes les fonctions dont vous avez abesoin.
 * N'oubliez pas de bien commenter vos fonctions, de bien utilisez le 
 * mot-clé const, &, * et de prendre en considération les bonnes 
 * pratiques.
 ***********************************************************************/


// Creer des sous ensembles en lisant la sortie standard
	
Ensemble<int> creerEnsemble(int a, int b);

// Determine les ensembles qui ont une intersection
	
bool determinerIntersection (const Tableau<Ensemble<int>> &e);

//	Determine la taille des communautes
Tableau<int> tailleCommunautes(const Tableau<Ensemble<int>> &e);

/**
 * Cette fonction lit son entrée standard pour construire le réseau.
 * Par la suite, elle calcule le nombre de communautés et leur tailles
 * et retourne un tableau de type Tableau<int> contenant les tailles de 
 * toutes les communautés présentes dans le réseau lu.
 */
Tableau<int> communautes() {

	Tableau <int> r;
	// int tailleCommunaute ;
	// // lecture entree standard
	// Tableau<Ensemble<int>> tabEnsemble;
	// int nb, nb2, nb3;
	// int i = 0;
	// cin >> nb;

	// while (cin >> nb2 >> nb3){
	// 	Ensemble<int> tabEns;
	// 	tabEns = creerEnsemble(nb2, nb3);
	// 	tabEnsemble.ajouter(tabEns);
	// }
	// int z = 0;
	// while (z < 2)
	// {
	// 	for (int i = 0; i < tabEnsemble.taille(); i++)
	// {
		
	// 	for (int j = 1; j < tabEnsemble.taille(); j++)
	// 	{
				
	// 			if (tabEnsemble[i].inter(tabEnsemble[j]).taille()>0)
	// 			{
					
	// 				tabEnsemble[i]= tabEnsemble[i].fusion(tabEnsemble[j]);
					
	// 				tabEnsemble.enlever(j);
	// 			}
				
			
	// 	}
		
	// }
	// z++;
	// }


	// bool existe = false;
	// for (int i = 0; i < nb; i++)
	// {
		
	// 	existe = false;
	// 	for (int j = 0; j < tabEnsemble.taille(); j++)
	// 	{

	// 		if (tabEnsemble[j].contient(i))
	// 		{
				
				
	// 			existe = true;

	// 		}
			
	// 	}
	// 	if(existe == false){
			
	// 		Ensemble<int> t;
	// 		t.inserer(i);
	// 		tabEnsemble.ajouter(t);
	// 	}
		
	// }
	

	// for (int i = 0; i < tabEnsemble.taille(); i++)
	// {
	// 	r.ajouter(tabEnsemble[i].taille());
	// }
	
	
	// for (int i = 0; i < tabEnsemble.taille(); i++)
	// {
	// 	cout<<tabEnsemble[i]<<endl;
	// }

	return r;
}



bool determinerIntersection (const Tableau<Ensemble<int>> &e){

	for (int i = 0; i < e.taille(); i++)
	{
		for (int j = i+1; i < e.taille(); j++)
		{
			e[i].inter(e[j]);
			return true;
		}
		
	}
	return false;
	
}



Ensemble<int> creerEnsemble(int a, int b){
	Ensemble<int> tableEns;
	tableEns.inserer(a);
	tableEns.inserer(b);
	return tableEns;
}

/**
 * La fonction main est le point d'entrée. En principe, vous n'avez pas à modifier.
 */
int main() {
	int erreur = 0;
	Tableau<int> tab = communautes();
	if(tab.taille() != 5) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(tab.occurrence(1) != 1 &&
		tab.occurrence(6) != 2 &&
		tab.occurrence(13) != 1 &&
		tab.occurrence(15) != 1) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
