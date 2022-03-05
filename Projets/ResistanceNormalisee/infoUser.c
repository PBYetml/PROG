//-----------------------------------------------------------------------------------//
// Nom du projet 		: Approximation résistance
// Nom du fichier 		: infoUser.c
// Date de création 	: 05.03.2022
// Date de modification : xx.xx.202x
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : définition et prototype lié aux série de résistance 
//
//
// Remarques :          : 
//----------------------------------------------------------------------------------//
//-- directive préprocesseur pour supprimer certains warining --//
#pragma warning(disable : 4996)		//-- warning concernant les scanf

//-- librairires standards --// 
#include <stdio.h>		// flux d'entrée / sortie 
#include <stdint.h>		// normalisation des types entiers 

//-- librairies personnelles --// 
#include "infoUser.h"

//----------------------------------------------------------------------------------//
// Nom de la fonction		: ViderBufferClavier
// Entrée / Sortie / I/O    : - / - / - 
// Description				: vide le buffer (flux d'entrée) => ici clavier 
// Date modfification		: le 05.03.2022
// Remarque					: -
//----------------------------------------------------------------------------------//
void ViderBufferClavier(void)
{
	//-- déclarataion de variable --// 

	//-- itération tant qu'on lit un caractère différents de \n ou EOF, on reste 
	//   dans la boucle
	while ((getchar() != '\n') && (getchar() != EOF));
}
