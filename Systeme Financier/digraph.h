/* 
 * Squelette minimal pour la classe générique Digraph<T> du TP3.
 * TP3 -- Graphes orientés
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */
 

#ifndef __DIGRAPH_H__
#define __DIGRAPH_H__

#include <set>
#include <map>
#include <tuple>
#include <assert.h>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
// #include <multiset>
// #include <multimap>
#include <unordered_set>
#include <unordered_map>
// #include <unordered_multiset>
// #include <unordered_multimap>
#include <stack>
#include <queue>
// #include <priority_queue>
#include <limits>

/*
 * 	Remarque.
 *	Tout parcours des structures de données "map" et "set" doit se faire dans	
 *	l'ordre croissant (pour les valeurs numériques) ou l'ordre lexicographique
 *	(pour les caractères ou chaines de caractères). C'est le parcours implémenté
 *	dans le standard C++11 avec le compilateur g++.
 *	Par conséquent, lors de la recherche de circuits, c'est le premier circuit 
 *	induit par parcours en ordre croissant qui sera considéré dans les différents
 *	tests.
 */

template <class T>
class Digraph {
	// Vous n'avez pas le droit de modifier cette interface. Aucun ajout de fonction
	// publique n'est autorisé. Aucune modification des signatures ou des types de
	// retour des déclarations fonctions publiques n'est autorisé.
	public:
		Digraph();
		Digraph(const Digraph & autre);
		~Digraph();
		Digraph<T> & operator = (const Digraph<T> & autre);
		
		/*********** Fonctions pour les caractéristiques de graphe ***********/
		// Retourne le nombre de sommets dans le graphe.
		int sommets() const;
		// Retourne le nombre d'arcs dans le graphe.
		int arcs() const;
		// Retourne "true" si "u" est un sommet du graphe courant. "false" si 
		// non.
		bool sommet(T u) const;
		// Retourne "true" si "(u,v)" est un arc du graphe courant. "false" si
		// non.
		bool arc(T u, T v) const;

		/*************************** Modificateurs ***************************/
		// Insère le sommet "u" si le graphe ne le contient pas. Ne fait 
		// rien si le graphe contient déjà le sommet "u".
		void inserer(T u);
		// Créé un arc entre les sommets "u" et "v" avec le poids "emprunt", 
		// si le graphe ne contient pas l'arc "(u, v)". Ne fait rien si le
		// graphe contient déjà un arc "(u,v)".
		// Si l'arc doit être créé faut s'assurer que,
		// 	- "u" doit être différent de "v",
		// 	- "emprunt" doit être strictement positif,
		// 		- faut arrêter l'exécution avec la fonction "assert" si les 
		// 		deux conditions plus faut ne sont pas satisfaites,
		// 	- si l'arc "(u,v)" existe déjà, peu importe la valeur de "emprunt",
		//	rien ne	sera fait par la fonction inserer.
		// 	- si l'un ou les deux sommets "u" et "v" n'existent pas dans
		// 	le graphe, ils seront crées.
		void inserer(T u, T v, double emprunt);
		// Supprime le sommet "u" et tous les arcs qui lui sont incidents.
		void supprimer(T u);
		// Supprime l'arc "(u, v)"
		void supprimer(T u, T v);

		/**************************** Sous-graphe ***************************/	
		// Créé un sous-graphe du graphe courant induit par les sommets du 
		// set "S".
		// Un "sous-graphe induit" par les sommets de "S" est un sous-graphe 
		// formé par les sommets de "S" et TOUS les arcs "e=(u,v)" du graphe 
		// courant tel que "u" et "v" sont TOUS deux des sommets de "S".
		//	- Il faut que tous les sommets listés dans "S" soient des
		//	sommets du graphe courant. Faut arrêter l'exécution avec la 
		//	fonction "assert" dans le cas	contraire.
		Digraph<T> cooperative(std::set<T> & S) const;
		
		/********************** Fonctions financières **********************/
		// Retourne le montant total que doit rembourser le sommet "u".
		double dette(T u) const;
		// De même, retourne le montant total que doivent rembourser tous 
		// les sommets du sous-graphe "SG" envers les autres sommets dans 
		// le reste du graphe courant. Attention, on ne comptabilise pas 
		// les dettes internes à "SG", on comptabilise que les dettes d'un 
		// sommet externe à "SG" vers un sommet interne de "SG".
		double dette(const Digraph<T> & SG) const;
		// Retourne le montant total des remboursements que doit recevoir 
		// le sommet "u".
		double pret(T u) const;
		// De même, retourne le montant total des remboursements que doivent
		// recevoir tous les sommets du sous-graphe "SG" de la part des 
		// autres sommets dans le reste du graphe courant. Attention, on ne 
		// comptabilise pas les remboursements internes à "SG", on 
		// comptabilise que les remboursements d'un sommet interne de "SG" 
		// vers un sommet externe à "SG".
		double pret(const Digraph<T> & SG) const;
		// Réduit les dettes circulaires du sommet "s". Voir des explications
		// et un exemple de l'énoncé.
		void reduire(T s);
		// De même, réduit les dettes circulaires d'un sous-graphe "SG". Voir
		// des explications et un exemple dans l'énoncé.
		void reduire(const Digraph<T> & SG);
	
	// Vous n'avez pas le droit de modifier l'attribut "graphe".
	// Vous n'avez pas le droit d'ajouter d'autres attributs privés.		
	private:
		
		// Par défaut, le "map" et le "set" sont parcourus en ordre croissant, 
		// ils sont ordonnés (standard C++11).
		std::map<T,std::set<std::tuple<T,double>>> graphe;
		
		// Vous pouvez ajouter toutes les fonctions privées que vous estimez
		// nécessaire.
};

template <class T>
Digraph<T>::Digraph(){

}

template <class T>
Digraph<T>::Digraph(const Digraph & autre){
	graphe = autre.graphe;
}

template <class T>
Digraph<T>::~Digraph(){
	
}

template <class T>
int Digraph<T>::sommets() const {
	return graphe.size();
}

template <class T>
int Digraph<T>::arcs() const {
	int nbreArcs = 0;
		auto it = graphe.begin();
		while (it != graphe.end()) {
			nbreArcs += it->second.size();
			++it;
		}
	return nbreArcs;
}

template <class T>
bool Digraph<T>::sommet(T u) const{
	return graphe.find(u) != graphe.end();
}

template <class T>
bool Digraph<T>::arc(T u, T v) const{
	if (!sommet(u) || !sommet(v)) {
        return false;
    }

    const auto& a = graphe.at(u);
    for (auto& voisin : a) {
        if (std::get<0>(voisin)==v) {
            return true;
        }
    }
    return false;
}

template <class T>
void Digraph<T>::inserer(T u){
	if(!sommet(u)){
		graphe[u] = std::set<std::tuple<T,double>>();
	}
}

template <class T>
void Digraph<T>::inserer(T u, T v, double emprunt){
	 assert(u != v && emprunt > 0);
    if (!arc(u,v)) {
		inserer(u);
    	inserer(v);
        graphe[u].insert(std::make_tuple(v,emprunt));
    }
}

template <class T>
void Digraph<T>::supprimer(T u){
	graphe.erase(u);
auto iterer = graphe.begin();
while (iterer != graphe.end())
{
    auto& proche = iterer->second;
    auto it = proche.begin();
    while (it != proche.end())
    {
        if (std::get<0>(*it) == u) {
            it = proche.erase(it);
        } else {
            ++it;
        }
    }
    ++iterer;
}

}

template <class T>
void Digraph<T>::supprimer(T u, T v){
	auto iterer = graphe.find(u);
if(iterer != graphe.end()){
    auto &proche = iterer->second;
    auto iterer_v = proche.begin();
    while (iterer_v != proche.end()) {
        if(std::get<0>(*iterer_v) == v){
            iterer_v = proche.erase(iterer_v);
            return;
        } else {
            ++iterer_v;
        }
    }
}

	

}

template <class T>
Digraph<T> Digraph<T>::cooperative(std::set<T> & S) const{
auto iterer = S.begin();
while(iterer != S.end())
{
    assert(graphe.find(*iterer) != graphe.end());
    ++iterer;
}
Digraph<T> sousGraphe;
for (auto &s : S)
{
    sousGraphe.inserer(s);
}

for (auto iterer = graphe.begin(); iterer != graphe.end(); ++iterer)
{
    T s = iterer->first;
    if (S.find(s) == S.end()) continue;

    for (auto &voisin : iterer->second)
    {
        T v = std::get<0>(voisin);
        double poid = std::get<1>(voisin);
        if (S.find(v) != S.end())
        {
            sousGraphe.inserer(s,v,poid);
        }
    }
}
return sousGraphe;


}

template <class T>
double Digraph<T>::dette(T u) const{
double total = 0;
auto it = graphe.begin();
while (it != graphe.end()) {
    if (it->first == u) {
        ++it;
        continue;
    }
    auto q_it = it->second.begin();
    while (q_it != it->second.end()) {
        if (std::get<0>(*q_it) == u){
            total += std::get<1>(*q_it);
            break;
        }
        ++q_it;
    }
    ++it;
}
return total;

}

template <class T>
double Digraph<T>::dette(const Digraph<T> & SG) const{
	double total = 0;
auto it1 = graphe.begin();
while (it1 != graphe.end()) {
    const T& sommet = it1->first;
    if (SG.sommet(sommet)) {
        ++it1;
        continue;
    }
    const auto& voisins = it1->second;
    auto it2 = voisins.begin();
    while (it2 != voisins.end()) {
        const T& voisin = std::get<0>(*it2);
        if (SG.sommet(voisin)) {
            total += std::get<1>(*it2);
        }
        ++it2;
    }
    ++it1;
}
return total;

}

template <class T>
double Digraph<T>::pret(T u) const{
double total = 0;
auto iter = graphe.find(u);
if(iter == graphe.end())
    return total;
for(auto arcIter = iter->second.begin(); arcIter != iter->second.end(); ++arcIter)
    total += std::get<1>(*arcIter);
return total;

}

template <class T>
double Digraph<T>::pret(const Digraph<T> & SG) const{
	double total = 0;
for (const auto& [sommet, voisins] : graphe) {
    if (SG.sommet(sommet)) {
        for (const auto& [voisin, poids] : voisins) {
            if (!SG.sommet(voisin)) {
                total += poids;
            }
        }
    }
}
return total;

}

// template <class T>
// void Digraph<T>::reduire(T s){
// 	std::unordered_set<T> visited;
//     std::queue<T> queue;
    
//     // Ajouter le sommet s à la liste des sommets visités et l'ajouter à la file d'attente
//     visited.insert(s);
//     queue.push(s);
    
//     // Parcourir tous les sommets accessibles depuis s et les marquer comme visités
//     while (!queue.empty()) {
//         T v = queue.front();
//         queue.pop();
        
//         for (const auto& w : adj_[v]) {
//             if (visited.find(w) == visited.end()) {
//                 visited.insert(w);
//                 queue.push(w);
//             }
//         }
//     }
    
//     // Supprimer les arcs qui ne mènent pas à un sommet visité depuis s
// 	auto& adj = iterer->second;
//     for (auto& [v, adj] : adj_) {
//         std::vector<T> new_adj;
//         for (const auto& w : adj) {
//             if (visited.find(w) != visited.end()) {
//                 new_adj.push_back(w);
//             }
//         }
//         adj = new_adj;
//     }
// }

// template<typename T>
// void Digraph<T>::reduire(const Digraph<T> & SG) {
//     // Copie de la structure du graphe initial
//     Digraph<T> G(*this);
    
//     // Parcours de tous les sommets du sous-graphe
//     for (const auto & v : SG.vertices()) {
//         // Suppression du sommet du graphe initial
//         G.remove_vertex(v);
//     }
    
//     // Récupération du sous-graphe induit par les sommets restants
//     std::vector<T> remaining_vertices;
//     for (const auto & v : G.vertices()) {
//         if (SG.contains_vertex(v)) {
//             remaining_vertices.push_back(v);
//         }
//     }
//     Digraph<T> subgraph = G.subgraph(remaining_vertices);
    
//     // Réduction du sous-graphe induit par les sommets restants
//     subgraph.reduire(SG);
    
//     // Suppression des arcs qui sortent du sous-graphe réduit
//     for (const auto & v : SG.vertices()) {
//         for (const auto & w : SG.adjacent_vertices(v)) {
//             if (!subgraph.contains_vertex(w)) {
//                 remove_edge(v, w);
//             }
//         }
//     }
// }


template <class T>
Digraph<T> & Digraph<T>:: operator = (const Digraph<T> & autre){
	if(this!=&autre){
		graphe = autre.graphe;
		return *this;
	}
}
#endif
