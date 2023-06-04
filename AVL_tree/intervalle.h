/* 
 * Squelette minimal pour classe générique Intervalle<T> du TP2.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#ifndef __INTERVALLE_H__
#define __INTERVALLE_H__

#include <ostream>
#include <istream>
#include <assert.h>

template <class T>
class Intervalle {
	/**************** Interface publique ****************
	* Vous ne devez pas ajouter de nouvelles fonctions 
	* publiques ni modifier les fonctions déjà présentes.
	*****************************************************/
	public:
		// Constructeurs et destructeur d'un intervalle. Conditions :
		// 	- "debut" <= "fin"
		// 	- Constructeur sans argument : initialisez les attributs 
		// 	avec la valeur par défaut du paramètre T
		Intervalle();
		Intervalle(T d, T f);
		Intervalle(const Intervalle & i);
		~Intervalle();

		// Retourne "true" si la valeur "x" est incluse dans l'intervalle
		// courant (incluant les valeurs "debut" et "fin"). Retourne 
		// "false" si non.
		bool inclut(const T & x) const;

		// Retourne "true" si l'intervalle "i" a plusieurs valeurs en 
		// commun (> 1) ) avec l'intervalle courant. Retourne "false" si non.
		bool chevauchement(const Intervalle & i) const;

		// Si l'intervalle "i" partage au moins une valeur commune avec 
		// l'instervalle courant, cette fonction retourne un nouvel intervalle 
		// qui contient toutes les valeurs dans l'intervalle "i" et 
		// l'intervalle courant. 
		// Si les intervalles courant et "i" ne partagent aucune valeur, cette
		// fonction retourne un intervalle de longeur 0. C'est-à-dire un
		// intervalle avec "debut == fin". Initialisez "debut" et "fin" avec 
		// la valeur par défaut du paramètre T.
		Intervalle<T> fusion(const Intervalle & i) const;

		// Si l'intervalle "i" partage au moins une valeur commune avec 
		// l'instervalle courant, cette fonction retourne un nouvel intervalle 
		// qui contient toutes les valeurs communes entre l'intervalle "i" et 
		// l'intervalle courant. 
		// Si les intervalles courant et "i" ne partagent aucune valeur, cette
		// fonction retourne un intervalle de longeur 0. C'est-à-dire un
		// intervalle avec "debut == fin". Initialisez "debut" et "fin"
		// avec la valeur par défaut du paramètre T.
		Intervalle<T> inter(const Intervalle & i) const;
	
		// Retourne la longueur de l'intervalle courant "fin - debut". 
		// Attention, cette fonction impose l'existence ou la surcharge de 
		// l'opérateur "-" pour le paramètre T.
		T longueur() const;

		// Retourne la distance de l'intervalle courant et l'intervalle "i". 
		// Attention, cette fonction impose l'existence ou la surcharge de 
		// l'opérateur "-" pour le paramètre T.
		T distance(const Intervalle<T> & i) const;
	
		// Retourne "true" si l'intervalle courant et l'intervalle "i" ont 
		// le même "debut" et la même "fin". Retourne "false" si non.
		bool operator == (const Intervalle<T> & i) const;

		// Les deux opérateurs suivants sont basés sur comparaison de la
		// valeur "debut" des deux intervalles courant et "i".
		bool operator < (const Intervalle<T> & i) const;
		bool operator > (const Intervalle<T> & i) const;

		// Cet opérateur affecte les valeurs "debut" et "fin".
		Intervalle<T> & operator = (const Intervalle<T> & i);

		// Les deux opérateurs servent à afficher et lire un intervalle.
		// Le format suivant doit être respecté pour l'affichage et la 
		// lecture :
		// 	- un intervalle commence par le caractère '['
		// 	- suivi d'une première valeur de type T
		// 	- suivi du caractère ','
		// 	- suivi d'une deuxième valeur de type T
		// 	- et se termine par le caractère ']'
		template <typename U>
		friend std::ostream & operator << (std::ostream & os, const Intervalle<U> &);
		template <typename U>
		friend std::istream & operator >> (std::istream & is, Intervalle<U> &);
		
	/**************** Représentation ********************
	* Représentation interne de la classe Intervalle<T>,
	* vous n'avez pas le droit de la modifier ni d'y 
	* ajouter des variables.
	*****************************************************/
	private:
		T debut, fin;

		// Vous devez déclarer une relation d'amitié avec la classe IntervalleAVL
		// Attention c'est le seul ajout autorisé, aucune fonction privée n'est 
		// autorisée (ni nécessaire!).
		
		friend class intervalleavl;
};

template <class T>
Intervalle<T>::Intervalle() {
	// À compléter
}

template <class T>
Intervalle<T>::Intervalle(T d, T f) {
	assert(d<=f);
	
}

template <class T>
Intervalle<T>::Intervalle(const Intervalle & i) {
	// À compléter
}

template <class T>
Intervalle<T>::~Intervalle() {
	// À compléter
}

template <class T>
bool Intervalle<T>::inclut(const T & x) const {
	return (x>debut && x<fin);
}

template <class T>
bool Intervalle<T>::chevauchement(const Intervalle & i) const {
	// À compléter
}

template <class T>
Intervalle<T> Intervalle<T>::fusion(const Intervalle<T> & i) const {
	// À compléter
}

template <class T>
Intervalle<T> Intervalle<T>::inter(const Intervalle<T> & i) const {
	// À compléter
}

template <class T>
T Intervalle<T>::longueur() const {
	// À compléter
}

template <class T>
T Intervalle<T>::distance(const Intervalle<T> & i) const {
	// À compléter
}

template <class T>
bool Intervalle<T>::operator == (const Intervalle<T> & i) const {
	// À compléter
}

template <class T>
bool Intervalle<T>::operator < (const Intervalle<T> & i) const {
	// À compléter
}

template <class T>
bool Intervalle<T>::operator > (const Intervalle<T> & i) const {
	// À compléter
}

template <class T>
Intervalle<T> & Intervalle<T>::operator = (const Intervalle<T> & i) {
	// À compléter
}

template <typename U>
std::ostream & operator << (std::ostream & os, const Intervalle<U> & i) {
	// À compléter
}

template <typename U>
std::istream & operator >> (std::istream & is, Intervalle<U> & i) {
	// À compléter
}

#endif
