//-----------------------------------------------------------------------------------//
// Nom du projet 		: Approximation résistance
// Nom du fichier 		: infoResistance.c
// Date de création 	: 04.03.2022
// Date de modification : 05.03.2022
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : main lié au test 1 semestre 2 PROG (voir données)
//
//
// Remarques :          : 
//----------------------------------------------------------------------------------//
//-- directive préprocesseur pour supprimer certains warining --//
#pragma warning(disable : 4996)		//-- warning concernant les scanf

//-- librairires standards --// 
#include <stdint.h>		// normalisation des types entiers
#include <stdio.h>		// flux d'entrée/sortie 
#include <math.h>

//-- librairies personnelles --// 
#include "infoSeries.h"
#include "infoUser.h"

//----------------------------------------------------------------------------------//
// Nom de la fonction		: ControleChoixSerie
// Entrée / Sortie / I/O    : valUser / flagOK / - 
// Description				: test si la valeur entrée par l'utilisateur est correcte
//							  renvoie un OK, et renvoi un NOT_OK si incorrecte 
// Date modfification		: le 05.03.2022
// Remarque					: -
//----------------------------------------------------------------------------------//
e_validation ControleChoixSerie(uint8_t valUser)
{
	//-- déclaration de variable --//
	e_validation flagOK; 

	switch (valUser)
	{
		case E6 :
			flagOK = OK; 
			break; 

		case E12:
			flagOK = OK;
			break;

		case E24:
			flagOK = OK;
			break;

		default:
			flagOK = NOT_OK;
			//-- message user --// 
			printf("!! la serie choisie n'est pas valide !!\n"); 
			break; 
	}

	return(flagOK);
}


//----------------------------------------------------------------------------------//
// Nom de la fonction		: ControleChoixResistance
// Entrée / Sortie / I/O    : valUser / flagOK / - 
// Description				: test si la valeur entrée par l'utilisateur est correcte
//							  renvoie OK, et renvoi un NOT_OK si incorrecte 
// Date modfification		: le 05.03.2022
// Remarque					: -
//----------------------------------------------------------------------------------//
e_validation ControleChoixResistance(float valUser)
{
	//-- déclaration de variable --// 
	e_validation flagOk; 

	//-- test si la valeur utilisateur est dans les limites demandées --//
	if ((valUser >= LIMITE_R_MIN) && (valUser < LIMITE_R_MAX))
		flagOk = OK;
	else
	{
		flagOk = NOT_OK; 
		printf("!! la valeur saisie n'est pas correcte !!\n"); 
	}
	return(flagOk); 
}

//----------------------------------------------------------------------------------//
// Nom de la fonction		: ControlePuissanceResistance
// Entrée / Sortie / I/O    : valUser / flagOK / - 
// Description				: test si la valeur entrée par l'utilisateur est correcte
//							  renvoie OK, et renvoi un NOT_OK si incorrecte 
// Date modfification		: le 05.03.2022
// Remarque					: -
//----------------------------------------------------------------------------------//
e_validation ControlePuissanceResistance(uint8_t valUser)
{
	//-- déclaration de variable --// 
	e_validation flagOk;

	//-- test si la valeur utilisateur est dans les limites demandées --//
	if ((valUser >= LIMITE_POID_PUISSANCE_MIN) && (valUser <= LIMITE_POID_PUISSANCE_MAX))
		flagOk = OK;
	else
	{
		flagOk = NOT_OK;
		printf("!! la valeur saisie n'est pas correcte !!\n");
	}
	return(flagOk);
}


//----------------------------------------------------------------------------------//
// Nom de la fonction		: CalculResistanceUser
// Entrée / Sortie / I/O    : valR, valP / R_ohm / - 
// Description				: calcul la valeur brute de la résistance en ohm 
// Date modfification		: le 05.03.2022
// Remarque					: -
//----------------------------------------------------------------------------------//
float CalculResistanceUser(float valR, uint8_t valP)
{
	//-- déclaration des variables --// 
	float R_ohm; 

	//-- calcul de la résistance (ex : 3.14 * 10^2 = 314 ohm)--// 
	R_ohm = valR * pow(10, valP); 

	return (R_ohm); 
}

//----------------------------------------------------------------------------------//
// Nom de la fonction		: AfficherValeurResistance
// Entrée / Sortie / I/O    : - / - / - 
// Description				: calcul la valeur brute de la résistance en ohm 
// Date modfification		: le 06.03.2022
// Remarque					: -
//----------------------------------------------------------------------------------//
void AfficherValeurResistance(float valRBrute, uint8_t poidPuissance)
{
	//-- déclaration de variable --//
	char displaySuffixe = 0; 
	float displayValeurR; 
	
	//-- test en fct du poid de puissance --//
	if (poidPuissance < CONST_K)
	{
		displaySuffixe = ' ';
		displayValeurR = valRBrute; 
	}
	else if (poidPuissance < CONST_M)
	{
		displaySuffixe = 'k';
		displayValeurR = valRBrute / pow(10, CONST_K); 
	}
	else
	{
		displaySuffixe = 'M';
		displayValeurR = valRBrute / pow(10, CONST_M);
	}

	//-- affichage du message --// 
	printf("la valeur est de %3.3f %cohm", displayValeurR, displaySuffixe);
}


