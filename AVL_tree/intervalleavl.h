/* 
 * Squelette minimal pour classe générique IntervalleAVL<T> du TP2.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#ifndef __INTERVALLEAVL_H__
#define __INTERVALLEAVL_H__

#include <assert.h>
#include "intervalle.h"
#include "pile.h"

template <class T>
class IntervalleAVL {
	/**************** Interface publique ****************
	* Vous ne devez pas ajouter de nouvelles fonctions 
	* publiques ni modifier les fonctions déjà présentes.
	*****************************************************/
	public:
		IntervalleAVL();
		IntervalleAVL(const IntervalleAVL<T> & a);
		~IntervalleAVL();

		// Vide l'arbre AVL d'intervalles en libérant la mémoire allouée
		// pour chaque noeud de l'arbre AVL courant.
		void vider();

		// Retourne la taille de l'arbre AVL courant, c'est-à-dire le 
		// nombre de noeuds/intervalles de l'arbre.
		int taille() const;

		// Retourne la hauteur de l'arbre AVL courant.
		int hauteur() const;

		// Retourne "true" si l'abrbre AVL courant contient un noeud dont
		// l'intervalle est égal à "i" et "maximum" égal à "m". Retourne 
		// "false" si non.
		// 
		// Complexité exigée : O(log n) où n est la taille de l'arbre AVL
		// courant. 
		bool contient(const Intervalle<T> & i, T m) const;

		// Retourne le nombre d'intervalles dans l'arbre AVL courant qui 
		// inclus la valeur "e".
		int couvert(T e) const;

		// Insère un nouvel intervalle "i" dans l'arbre AVL courant, si
		// l'arbre AVL courant ne contient pas l'intervalle "i". Ne fait
		// rien si l'intervalle "i" est déjà présent dans l'arbre AVL.
		// Après l'insertion,
		// 	- L'attribut "equilibre" doit être mis à jour pour que l'arbre 
		// 	courant respecte la structure d'un arbre AVL à la fin de cette
		// 	fonction.
		// 	- L'attribut "maximum" doit également être mis à jour, de tel 
		// 	sorte	que dans chaque noeud "n" de l'arbre AVL courant on a
		// 		"n->maximum = max(n->contenu.fin,
		// 				n->gauche->maximum,
		// 				n->droite->maximum)"
		//	- L'arbre courant doit respecté la structure d'un arbre AVL à
		//	la fin de cette fonction.
		//
		// Complexité exigée : O(log n) où "n" est la taille de l'arbre AVL
		// courant.
		void inserer(const Intervalle<T> & i);
		
		// Enlève l'intervalle "i" s'il est contenu dans l'arbre AVL courant, 
		// Ne fait rien si l'intervalle "i" n'est pas présent dans l'arbre AVL.
		// Lors de l'enlèvement, si la valeur à supprimer est dans un noeud avec 
		// deux enfants, il faudra emprunter le max à gauche.
		// Après l'enlèvement,
		// 	- L'attribut "equilibre" doit être mis à jour pour que l'arbre 
		// 	courant respecte la structure d'un arbre AVL à la fin de cette
		// 	fonction.
		// 	- L'attribut "maximum" doit également être mis à jour, de tel 
		// 	sorte	que dans chaque noeud "n" de l'arbre AVL courant on a
		// 		"n->maximum = max(n->contenu.fin,
		// 				n->gauche->maximum,
		// 				n->droite->maximum)"
		//	- L'arbre courant doit respecté la structure d'un arbre AVL à
		//	la fin de cette fonction.
		//
		// Complexité exigée : O(log n) où "n" est la taille de l'arbre AVL
		// courant.
		void enlever(const Intervalle<T> & i);
    
		IntervalleAVL<T> & operator = (const IntervalleAVL<T> & autre);
		
		// Retourne "true" si les arbres AVl ont exactement les mêmes éléments 
		// peu importe l'ordre d'apparition dans les deux arbres. Si non, 
		// retourne "false".
		//
		// Complexité exigée : O(min(n,n)) où "n" est la taille de l'arbre AVL
		// courant et "m" est la taille de l'arbre "autre".
 		bool operator == (const IntervalleAVL<T> & autre) const;
	
		// Cet itérateur est basé sur un parcours inordre de l'arbre courant.
		class Iterateur;
		Iterateur debut() const;
		Intervalle<T> & operator[] (const Iterateur &);
		const Intervalle<T> & operator[] (const Iterateur &) const;
	
	/**************** Représentation **********************
	* Représentation interne de la classe IntervalleAVL<T>,
	* vous n'avez pas le droit de la modifier ni d'y 
	* ajouter des variables/attributs/relations friend.
	*******************************************************/
	private:
		struct Noeud {
			// Construit un objet de type "Noeud" dans le tas, avec les 
			// affectations par défaut suivantes, 
			// 	- "contenu = i"
			// 	- "maximum = i.fin"
			// 	- "equilibre = 0"
			// 	- "gauche = nullptr"
			// 	- "droite = nullptr"
			Noeud(const Intervalle<T> & i);

			Intervalle<T> contenu;
			T maximum;
			int equilibre;
			Noeud * gauche;
			Noeud * droite;
		};
		Noeud * racine;

		/************************ Interface privée ***************************
		* Vous pouvez ajouter toutes les fonctions privées que vous estimez 
		* nécessaire.
		* N'oubliez pas de bien commenter vos fonctions, de bien utilisez le 
		* mot-clé const et de prendre en considération les bonnes pratiques.
		**********************************************************************/
		int hauteur(Noeud * n) const;

	public:
		class Iterateur {
			/**************** Interface publique ****************
			* Vous ne devez pas ajouter de nouvelles fonctions 
			* publiques ni modifier les fonctions déjà présentes.
			*****************************************************/
			public:
				Iterateur(const Iterateur &);
				Iterateur(const IntervalleAVL &);
				operator bool() const;
				Iterateur operator++(int);
				Iterateur & operator++();
			/**************** Représentation **********************
			* Représentation interne de la classe Iterateur, vous 
			* n'avez pas le droit de la modifier ni d'y ajouter des 
			* fonctions/variables/attributs/relations friend.
			*******************************************************/
			private:
				Noeud * courant;
				const IntervalleAVL & arbre_associe;
				Pile<Noeud *> chemin;
				friend class IntervalleAVL;
		};

	/*********************** Fonctions de test *********************************
	* Ces fonctions sont implémentées à des fins de test et de diagnostique.
	* Vous ne devez pas les utiliser dans vos implémentations, ni les modifier!
	* À noter qu'elles nécessitent l'implémentation de la fonction privée
	* 	int hauteur(Noeud * n) const; 
	* qui est également requise pour la fonction publique 
	*	int hauteur() const;
	****************************************************************************/
		int equilibre(const Intervalle<T> &) const;
		int get_equilibre(const Intervalle<T> &) const;
		T max(const Intervalle<T> &) const;
		T get_max(const Intervalle<T> &) const;
	private:
		T max(const Noeud *) const;
		
};



/************ Fonctions publiques ************/ 

template <class T>
IntervalleAVL<T>::Noeud::Noeud(const Intervalle<T> & c) {
	// À compléter
}

template <class T>
IntervalleAVL<T>::IntervalleAVL() {
	// À compléter
}

template <class T>
IntervalleAVL<T>::IntervalleAVL(const IntervalleAVL<T> & autre) {
	// À compléter
}

template <class T>
IntervalleAVL<T>::~IntervalleAVL() {
	// À compléter
}

template <class T>
void IntervalleAVL<T>::vider() {
	// À compléter
}

template <class T>
int IntervalleAVL<T>::taille() const {
	// À compléter
}

template <class T>
int IntervalleAVL<T>::hauteur() const {
	return hauteur(r);
}

template <class T>
bool IntervalleAVL<T>::contient(const Intervalle<T> & i, T max) const {
	// À compléter
}

template <class T>
int IntervalleAVL<T>::couvert(T e) const {
	// À compléter
}

template <class T>
void IntervalleAVL<T>::inserer(const Intervalle<T> & i) {
	// À compléter
}

template <class T>
void IntervalleAVL<T>::enlever(const Intervalle<T> & i) {
	// À compléter
}
 
template <class T>
IntervalleAVL<T> & IntervalleAVL<T>::operator = (const IntervalleAVL & autre) {
	// À compléter
}

template <class T>
bool IntervalleAVL<T>::operator == (const IntervalleAVL<T> & autre) const {
	// À compléter
}

template <class T>
typename IntervalleAVL<T>::Iterateur IntervalleAVL<T>::debut() const {
	// À compléter
}

template <class T>
Intervalle<T> & IntervalleAVL<T>::operator[](const Iterateur & i) {
	// À compléter
}

template <class T>
const Intervalle<T> & IntervalleAVL<T>::operator[](const Iterateur & i) const {
	// À compléter
}



/************ Fonctions de la classe Iterateur ************/

template <class T>
IntervalleAVL<T>::Iterateur::Iterateur(const IntervalleAVL & a) {
	// À compléter
}

template <class T>
IntervalleAVL<T>::Iterateur::Iterateur(const Iterateur & i) {
	// À compléter
}

template <class T>
typename IntervalleAVL<T>::Iterateur IntervalleAVL<T>::Iterateur::operator++(int) {
	// À compléter
}

template <class T>
typename IntervalleAVL<T>::Iterateur& IntervalleAVL<T>::Iterateur::operator++() {
	// À compléter
}

template <class T>
IntervalleAVL<T>::Iterateur::operator bool() const {
	// À compléter
}



/************ Fonctions privées ************/

template <class T>
int IntervalleAVL<T>::hauteur(Noeud * n) const {
	// À compléter
}



/************ Fonctions de tests ************/

#include <climits>
template <class T>
int IntervalleAVL<T>::equilibre(const Intervalle<T> & i) const {
	int eq = INT_MIN;
	if(contient(racine, i)) {
		Noeud * n = racine;
		while(n != nullptr && !(n->contenu == i))
    			if(n->contenu > i)
      				n = n->gauche;
    			else
      				n = n->droite;
		eq = hauteur(n->gauche) - hauteur(n->droite);
	}
	return eq;
}

template <class T>
int IntervalleAVL<T>::get_equilibre(const Intervalle<T> & i) const {
	int eq = INT_MIN;
	if(contient(racine, i)) {
		Noeud * n = racine;
    		while(n != nullptr && !(n->contenu == i)) 
      			if(n->contenu > i)
        			n = n->gauche;
      			else
        			n = n->droite;
		eq = n->equilibre;
	}
	return eq;
}

template <class T>
T IntervalleAVL<T>::max(const Noeud * n) const {
	T m = n->contenu.fin;
	if(n->gauche != nullptr) {
		T temp = max(n->gauche);
		m = m < temp ? temp : m;
	}
	if(n->droite != nullptr) {
		T temp = max(n->droite);
		m = m < temp ? temp : m;
	}
	return m;
}

template <class T>
T IntervalleAVL<T>::max(const Intervalle<T> & i) const {
	Noeud * n = racine;
	while(n->gauche != nullptr)
		n = n->gauche;
	T m = n->contenu.debut;
	n = racine;
	while(n != nullptr && !(n->contenu == i))
		if(n->contenu > i)
    			n = n->gauche;
		else
      			n = n->droite;
	return max(n);
}

template <class T>
T IntervalleAVL<T>::get_max(const Intervalle<T> & i) const {
	Noeud * n = racine;
	while(n != nullptr && !(n->contenu == i)) 
		if(n->contenu > i)
    			n = n->gauche;
		else
    			n = n->droite;
	return n->maximum;
}

#endif
