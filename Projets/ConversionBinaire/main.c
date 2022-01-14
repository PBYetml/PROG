//-----------------------------------------------------------------------------------//
// Nom du projet 		: CONVERSION_TEMP
// Nom du fichier 		: main.c
// Date de création 	: 01.10.2021
// Date de modification : xx.xx.2021
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : fîchier source contenant le main principal - va demander à 
//						  l'utilisateur de rentrer une valeur représentant une 
//						  température et convertir celle-ci en binaire et hexadécimal 
//						  Simulation de la table du capteur de température DS1822  
//
// Remarques :            
//----------------------------------------------------------------------------------//
//-- librairie standart --// 
#include <stdio.h>				// librairie pour les I/O
#include <stdint.h>				// libraire types entiers normalisée	

//-- librairie personnelle --// 
#include "mesFonctions.h"

//-- definition --// 
#define NOM_PROGRAMMEUR			"Philou"
#define VERSION_PROGRAMME		01
#define TEMPERATURE_MIN_Celuis	-55.0
#define TEMPERATURE_MAX_Celuis	125.0

//-- programme principale --// 
void main()
{
	//-- déclaration de variable interne --// 
	char reponseUser = 'N';
	float temperatureUser = 200; 

	//-- message utilisateur --// 
	printf("-- TEST PROG C - VERSION %0d - Nom : %s", VERSION_PROGRAMME, NOM_PROGRAMMEUR);
	
	//-- boucle faire tant que l'utilisteur ne veut pas quitter le programme --//
	do
	{
		//-- boucle tant que l'utilisateur n'a pas insérer une valeur correcte
		while ((temperatureUser > TEMPERATURE_MAX_Celuis) || (temperatureUser < TEMPERATURE_MIN_Celuis))
		{
			//-- message utilsateur --//
			printf("\n\nInsere une valeur entre %.2f et %.2f : ", TEMPERATURE_MAX_Celuis, TEMPERATURE_MIN_Celuis);
			
			//-- récuperation infromation utilisateur
			#pragma warning(suppress : 4996) // supprime l'erreur lié à la fonction scanf 
			scanf("%f", &temperatureUser); 
		}

		//-- appel de la fonction de conversion --//
		ConvertirTemperatureEnBinaire(temperatureUser); 

		//-- MAJ valeur temperature User --// 
		temperatureUser = 200; 

		//-- vider le buffer lié à la saisie clavier --//
		while ((getchar() != '\n') && (getchar() != EOF));

		//-- message utilsateur --//
		printf("\n\nVoulez-vous sortir du programme [O/N] ? ");
		//-- récuperation infromation utilisateur
		#pragma warning(suppress : 4996) // supprime l'erreur lié à la fonction scanf 
		scanf("%c", &reponseUser); 

	} while (!((reponseUser == 'O') || (reponseUser == 'o')));
}

