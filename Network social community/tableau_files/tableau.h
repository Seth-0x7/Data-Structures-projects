/** 
 * Squelette pour classe générique Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#ifndef __TABLEAU_H___
#define __TABLEAU_H___

#include <assert.h>

/**
* À noter que pour cette implémentation, la capacité du tableau
* dynamique doit doublée (x2) si la taille du tableau atteint la 
* capacité du tableau.
*/

template <class T>
class Tableau {
	/**************** Interface publique ****************
	* 
	* Vous ne devez pas ajouter de nouvelles fonctions 
	* publiques ni modifier les fonctions déjà présentes.
	*
	*****************************************************/
	public:	
		Tableau(int capacite_initiale = 4);
		Tableau(const Tableau & autre);
		~Tableau();

		// Ajoute un élément e à la fin du tableau.
		// Complexité : O(1)
		void ajouter(const T & e);
  
		// Retourne le nombre d'éléments dans le tableau.
		// Complexité : O(1)
		int taille() const;

		// Insère un élément e à la position i du tableau.
		// Complexité : O(n) 
		//	n étant la taille du tableau.
		void inserer(const T & e, int i = 0);
		
		// Enlève un élément à la position i.
		// Complexité : O(n)
		//	n étant la taille du tableau.
		void enlever(int i = 0);

		// Compte le nombre d'occurrence d'un élément e dans le tableau.
		// Complexité : O(n)
		//	n étant la taille du tableau.
		int occurrence(const T & e) const;

		// Vide le tableau sans libérer la mémoire.
		void vider();

		// Surcharge des opérateurs
		//	- d'accès []
		//	- d'accès et de modification []
		//	- d'égalité == 
		//		Deux tableaux sont égaux s'ils ont le même objet
		//		qui les représente, ou s'ils ont la même taille et
		//		leurs éléments sont égaux pour chaque indice.
		//	- d'affectation de tableau =
		const T & operator [] (int index) const;
		T & operator [] (int index);
		bool operator == (const Tableau<T> & autre) const;
		Tableau<T> & operator = (const Tableau<T> & autre);

	/**************** Représentation ********************
	* 
	* Représentation interne de la classe Tableau<T>,
	* vous n'avez pas le droit de la modifier ni d'y 
	* ajouter des variables.
	*
	*****************************************************/
	private:
    		T * elements;
    		int nbElements;
    		int capacite;
			void redimensionner(int nouvCapacite);
    	
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
Tableau<T>::Tableau(int capacite_initiale) {
	capacite = capacite_initiale;
	nbElements = 0;
	elements = new T [capacite];
}

template <class T>
Tableau<T>::Tableau(const Tableau & autre) {
	capacite = autre.capacite;
	nbElements = autre.nbElements;
	elements = new T [capacite]; 
	for (int i = 0; i < nbElements; i++)
	{
		elements[i] = autre.elements[i];
	}
	
	
}

template <class T>
Tableau<T>::~Tableau() {
	delete [] elements;
}

template <class T>
void Tableau<T>::ajouter(const T & element) {
	if(nbElements >= capacite)
		redimensionner(capacite*2);
	elements[nbElements++] = element;
}

template <class T>
int Tableau<T>::taille() const {
	return nbElements;
}

template <class T>
void Tableau<T>::inserer(const T & element, int index) {
	if(nbElements == capacite)
		redimensionner(capacite*2);

	for (int i = nbElements; i > index; --i)
	{
		elements[i] = elements[i-1];
	}
	
	elements[index] = element;
	nbElements++;
	
}

template <class T>
void Tableau<T>::enlever(int index) {
	assert(index<nbElements);
	for (int i = index; i < nbElements; ++i)
	{
		elements[i] = elements[i+1];
	}
	nbElements--;
}

template <class T>
int Tableau<T>::occurrence(const T & element) const {
	int compte = 0;
	for (int i = 0; i < nbElements; i++)
	{
		if(elements[i] == element){
			compte++;
		}
	}
	return compte; 
}

template <class T>
void Tableau<T>::vider() {
	nbElements = 0;
}

template <class T>
const T & Tableau<T>::operator [] (int index) const {
	assert(index<nbElements);
	return elements[index];
}

template <class T>
T & Tableau<T>::operator [] (int index) {
	assert(index<nbElements);
	return elements[index];
}

template <class T>
bool Tableau<T>::operator == (const Tableau<T> & autre) const {

	if(this == &autre)
	{return true;}

	if(nbElements == autre.nbElements)
	{return true;}

	for (int i = 0; i < nbElements; i++)
	{
		if (elements[i] != autre.elements[i])
		{return false;}
		
	}
	return true;
}

template <class T>
Tableau<T> & Tableau<T>::operator = (const Tableau<T> & autre) {
	if(this == &autre){return *this;}

	nbElements = autre.nbElements;

	if(capacite<autre.nbElements){
		delete [] elements;
		capacite = autre.nbElements;
		elements = new T [capacite];
	}

	for (int i = 0; i < nbElements; i++)
	{
		elements[i] = autre.elements[i];
	}
	
	return *this;
}

template <class T> 
void Tableau<T>::redimensionner(int nouvCapacite){
	capacite = nouvCapacite;
	T* temp = new T[capacite];
	for (int i = 0; i < nbElements; i++)
	{
		temp[i] = elements[i];
	}
	delete [] elements;
	elements = temp;
	
}

/***** Fonctions privées *****/

#endif