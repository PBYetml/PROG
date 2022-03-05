//-----------------------------------------------------------------------------------//
// Nom du projet 		: Approximation r�sistance
// Nom du fichier 		: infoResistance.c
// Date de cr�ation 	: 04.03.2022
// Date de modification : 05.03.2022
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : main li� au test 1 semestre 2 PROG (voir donn�es)
//
//
// Remarques :          : 
//----------------------------------------------------------------------------------//
//-- directive pr�processeur pour supprimer certains warining --//
#pragma warning(disable : 4996)		//-- warning concernant les scanf

//-- librairires standards --// 
#include <stdint.h>		// normalisation des types entiers
#include <stdio.h>		// flux d'entr�e/sortie 

//-- librairies personnelles --// 
#include "infoSeries.h"
#include "infoUser.h"

//----------------------------------------------------------------------------------//
// Nom de la fonction		: ControleChoixSerie
// Entr�e / Sortie / I/O    : valUser / flagOK / - 
// Description				: test si la valeur entr�e par l'utilisateur est correcte
//							  renvoie un OK, renvoi un NOT_OK
// Date modfification		: le 05.03.2022
// Remarque					: -
//----------------------------------------------------------------------------------//
e_validation ControleChoixSerie(uint8_t valUser)
{
	//-- d�claration de variable --//
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
			printf("!! la serie choisie n'est pas valide !!"); 
			break; 
	}

	return(flagOK);
}


//----------------------------------------------------------------------------------//
// Nom de la fonction		: ControleChoixResistance
// Entr�e / Sortie / I/O    : valUser / flagOK / - 
// Description				: test si la valeur entr�e par l'utilisateur est correcte
//							  renvoie OK, renvoi u NOT_OK
// Date modfification		: le 05.03.2022
// Remarque					: -
//----------------------------------------------------------------------------------//
e_validation ControleChoixResistance(float valUser)
{
	//-- d�claration de variable --// 
	e_validation flagOk; 

	if ((valUser >= LIMITE_R_MIN) && (valUser < LIMITE_R_MAX))
		flagOk = OK;
	else
	{
		flagOk = NOT_OK; 
		printf("!! la valeur saisie n'est pas correcte !!"); 
	}
	return(flagOk); 
}




