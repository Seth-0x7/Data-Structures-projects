/** 
 * Squelette pour classe générique Ensemble<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#ifndef __ENSEMBLE_H__
#define __ENSEMBLE_H__

#include "tableau.h"
#include <ostream> 		

template <class T>
class Ensemble {
	/**************** Interface publique ****************
	* 
	* Vous ne devez pas ajouter de nouvelles fonctions 
	* publiques ni modifier les fonctions déjà présentes.
	*
	*****************************************************/
	public:		
		Ensemble();
		Ensemble(const Ensemble & autre);
		~Ensemble();
  
		// Retourne le nombre d'éléments dans l'ensemble.
		// Complexité : O(1)
		int taille() const;
		
		// Vérifie si l'élément "e" est dans l'ensemble.
		// Complexité : O(log n)
		//	n étant la taille de l'ensemble.
		bool contient(const T & e) const;

		// Insère un élément "e" dans l'ensemble si "e" 
		// n'appartient pas l'ensemble et retourne "true",
		// "false" si l'élément "e" est déjà dans l'ensemble.
		// Complexité : O(n) 
		//	n étant la taille de l'ensemble.
		bool inserer(const T & e);
		
		// Enlève un l'élément "e" de l'ensemble et retourne
		// "true" si l'élément "e" a été supprimé, "false" si 
		// non
		// Complexité : O(n)
		//	n étant la taille de l'ensemble.
		bool enlever(const T & e);

		// Surcharge des opérateurs
		//	- d'égalité == 
		//	Deux ensembles sont égaux s'ils ont 
		//	le même objet qui les représente, ou 
		//	s'ils contiennent exactement les mêmes 
		//	éléments.
		//	Complexité : O(min(n,m))
		//		n étant la taille de l'ensemble courant.
		//		m étant la taille de l'ensemble "autre".
		//	- d'affectation de tableau =
		bool operator == (const Ensemble<T> & autre) const;
		Ensemble<T> & operator = (const Ensemble<T> & autre);
		
		// Retourne un ensemble qui contient les éléments
		// de l'ensemble courant et l'ensemble "autre" donné
		// en paramètre.
		// Complexité : O(n + m)
		//	n étant la taille de l'ensemble courant.
		//	m étant la taille de l'ensemble "autre".
		Ensemble<T> fusion(const Ensemble<T> & autre) const;

		// Retourne un ensemble qui contient les éléments
		// communs entre l'ensemble courant et l'ensemble 
		// "autre" donné en paramètre.
		// Complexité : O(n+m)
		//	n étant la taille de l'ensemble courant.
		//	m étant la taille de l'ensemble "autre".
		Ensemble<T> inter(const Ensemble<T> & autre) const;

		// Retourne un ensemble qui contient les éléments
		// qui sont dans l'ensemble courant mais qui 
		// n'appartiennent à l'ensemble "autre" donné en 
		// paramètre.
		// Complexité : O(n+m)
		//	n étant la taille de l'ensemble courant.
		Ensemble<T> minus(const Ensemble<T> & autre) const;
		
		// Affiche les éléments d'un Ensemble, entre 2 accolades {}
		// et séparés par une virgule. Par exemple, {2,5,7,10}
		template <typename U>
		friend std::ostream& operator << (std::ostream& os, const Ensemble<U> & e);		

	/**************** Représentation ********************
	* 
	* Représentation interne de la classe Ensemble<T>,
	* vous n'avez pas le droit de la modifier ni d'y 
	* ajouter des variables.
	*
	*****************************************************/
	private:
    		Tableau<T> ens;
			int determinerIndice(const T & e);
    		
    	
	/**************** Interface privée ******************
	* 
	* Vous pouvez ajouter toutes les fonctions privées
	* que vous estimez nécessaire.
	* N'oubliez pas de bien commenter vos fonctions, de 
	* bien utilisez le mot-clé const et de prendre en 
	* considération les bonnes pratiques.
	*
	*****************************************************/
};

/***** Fonctions publiques *****/

template <class T>
Ensemble<T>::Ensemble() {
}

template <class T>
Ensemble<T>::Ensemble(const Ensemble & autre) {
	ens = autre.ens;
}

template <class T>
Ensemble<T>::~Ensemble() {
}

template <class T>
bool Ensemble<T>::contient(const T & e) const {
	int a = 0; int b = ens.taille();
	while (a<b)
	{
		int c = (a+b)/2;
		if(e < ens[c]) b = c;
		else if(ens[c]<e) a=c+1;
		else return true;
	}
	return false;
	
}

template <class T>
int Ensemble<T>::taille() const {
	return ens.taille();
}

template <class T>
bool Ensemble<T>::inserer(const T & e) {
	int position = 0;
	if (!contient(e))
	{
		for (int i = 0; i < ens.taille(); i++)
		{
			if (ens[i]<e){
				position++;
			}
			
		}
		ens.inserer(e,position);
		
	}
	return false;
	
	
}

template <class T>
bool Ensemble<T>::enlever(const T & e) {
	int indiceElement;
	if (contient(e) == true)
	{
		indiceElement = determinerIndice(e);
		ens.enlever(indiceElement);
		return true;
	}
	return false;
}

template <class T>
bool Ensemble<T>::operator == (const Ensemble<T> & autre) const {
	return (ens == autre.ens);
}

template <class T>
Ensemble<T> & Ensemble<T>::operator = (const Ensemble<T> & autre) {
		ens = autre.ens;
	return *this;
}

template <class T>
Ensemble<T> Ensemble<T>::fusion(const Ensemble<T> & autre) const {
	Ensemble<T> uneFusion;
	for (int i = 0; i < this->taille(); i++)
		uneFusion.inserer(ens[i]);
			for (int j = 0; j < autre.taille(); j++)
				uneFusion.inserer(autre.ens[j]);
	return uneFusion;
}

template <class T>
Ensemble<T> Ensemble<T>::inter(const Ensemble<T> & autre) const {
	Ensemble<T> uneIntersection;
	for (int i = 0; i < this->taille(); i++)
		for (int j = 0; j < autre.taille(); j++)
			if (ens[i] == autre.ens[j])
				uneIntersection.inserer(ens[i]);
	
	return uneIntersection;
}

template <class T>
Ensemble<T> Ensemble<T>::minus(const Ensemble<T> & autre) const {
	Ensemble<T> unMinus;
	for (int i = 0; i < this->taille(); i++)
	{
		for (int j = 0; j < autre.taille(); j++)
		{
			if (this->contient(ens[i]) && !autre.contient(ens[i]))
			{
				unMinus.inserer(ens[i]);
			}
			
		}
	}
	return unMinus;
}

template <typename U>
std::ostream& operator << (std::ostream& os, const Ensemble<U> & e) {
	os << "{ " ;
	for (int i = 0; i < e.ens.taille(); i++)
	{
		os << e.ens[i] << "," ;
	}
	os << " }";
	
	return os;
}

/***** Fonctions privées *****/
template <class T>
int Ensemble <T>::determinerIndice(const T & e){
	int indice;
	for (indice = 0; indice < ens.taille(); indice++)
		if (ens[indice] == e)
			return indice;
	return -1;
}

#endif
