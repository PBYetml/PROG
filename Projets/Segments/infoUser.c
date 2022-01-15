//-----------------------------------------------------------------------------------//
// Nom du projet 		: Formulaire mathematique 
// Nom du fichier 		: infoUser.c
// Date de création 	: 27.11.2021
// Date de modification : 29.11.2021
//
// Auteur 				: Philou (Ph. Bovey)
//
// Version				: 0.1
//
// Description          : Solution test2 -> voir donnée
//
// Remarques			:            
//----------------------------------------------------------------------------------//
//-- directive préprocesseur pour supprimer certains warining --//
#pragma warning(disable : 4996)		//-- warning concernant les scanf
//-- librairie standart --// 
#include <stdint.h>
#include <stdio.h>

//-- librairie personnelle --// 
#include "segmentAB.h"

//-----------------------------------------------------------------------------------//
// nom fonction				: DemandeValeurPoint
// entrée / sortie / in_out : choixPoint / valeurPoint / - 
// description				: selon le choix du point, msg différents puis entrer une 
//							  valeur
// date de modification		: 27.11.2021
//-----------------------------------------------------------------------------------//
int DemandeValeurPoint(e_point choixPoint)
{
	//-- déclaration de variables --// 
	int valeurPoint; 

	//-- message utilisateur --//
	//-- demande valeur à l'utilisateur selon son option --// 
	if(choixPoint == abscisse_A)
		printf("Entrez valeur abscisse pour point A ! : ");
	else if (choixPoint == abscisse_B)
		printf("Entrez valeur abscisse pour point B ! : ");
	else if (choixPoint == ordonnee_A)
		printf("Entrez valeur ordonnee pour point A ! : ");
	else 
		printf("Entrez valeur ordonnee pour point B ! : ");

	scanf("%d", &valeurPoint);
	
	return(valeurPoint); 
}

//-----------------------------------------------------------------------------------//
// nom fonction				: ValiderValUser
// entrée / sortie / in_out : valeurUser, choixPoint / status / - 
// description				: selon la valeur et le choix du point, controler si celle
//							  -ci est dans les limites 
// date de modification		: 29.11.2021
//-----------------------------------------------------------------------------------//
int8_t ValiderValUser(int8_t valeurUser, e_point choixPoint)
{
	//-- déclaration de variables --// 
	int8_t status = 0; 

	
	/* Test pour savoir quelles valeurs a été choisi et si elle se trouve dans les 
	*  les limites imposée --*/
	switch (choixPoint)
	{
		case abscisse_A :
			if ((valeurUser <= LIMITE_MAX_AXE_X) && (valeurUser >= LIMITE_MIN_AXE_X))
				status = 1;
			else
				status = 0; 
		break;

		case abscisse_B : 
			if ((valeurUser <= LIMITE_MAX_AXE_X) && (valeurUser >= LIMITE_MIN_AXE_X))
				status = 1;
			else
				status = 0;
			break; 
		
		case ordonnee_A : 
			if ((valeurUser <= LIMITE_MAX_AXE_Y) && (valeurUser >= LIMITE_MIN_AXE_Y))
				status = 1;
			else
				status = 0;
			break; 

		case ordonnee_B : 
			if ((valeurUser <= LIMITE_MAX_AXE_Y) && (valeurUser >= LIMITE_MIN_AXE_Y))
				status = 1;
			else
				status = 0;
			break; 

		default : 
			status = -1;	//-- correspond à un code erreur !!! 
			break; 
	}

	return(status); 
}