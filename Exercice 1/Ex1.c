//-----------------------------------------------------------------------------------//
// Nom du projet 		: Exercice 1 - Chapitre 1
// Nom du fichier 		: Ex1.c
// Date de création 	: 16.11.2021
// Date de modification : xx.xx.202x
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : Programme calculant la moyenne des notes à disposition
//
// Remarques :            
//----------------------------------------------------------------------------------//
//-- librairies standart --// 
#include <stdio.h>	// entree - sortie 				

//-- librairie personnelle --// 

//-- déclaration de prototype --//
int CalculMoyenne(float n1, float n2, float n3); 

//-- programme principale --// 
int main(void)
{
	//-- déclaration de variables --//
	float note1 = 6.0, note2 = 3.5, note3 = 4.5; 

	int resultat; 

	//-- appel de fonction : CalculMoyenne
	resultat = CalculMoyenne(note1, note2, note3);

	printf("la moyenne des notes (%0.1f, %0.1f, %0.1f) vaut : %d \n", note1, note2, note3, resultat); 

	return (0); 
}

//----------------------------------------------------------------------------------//
// Nom de la fonction   : CalculMoyenne
// Entrée / Sortie      : note1, note2, note3 / moyenne /
// Description          : calcul la moyenne de 3 notes et renvoie la valeur
// Date modfification   : le 16.11.2021
// Remarque             : -
//----------------------------------------------------------------------------------//
int CalculMoyenne(float n1, float n2, float n3)
{
	return ((n1 + n2 + n3) / 3);
}


