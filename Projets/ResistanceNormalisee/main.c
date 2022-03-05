//-----------------------------------------------------------------------------------//
// Nom du projet 		: Approximation résistance
// Nom du fichier 		: main.c
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
#include <stdio.h>		// flux d'entrée / sortie 
#include <stdint.h>		// normalisation des types entiers 

//-- librairies personnelles --// 
#include "infoSeries.h"

//-- définition ou constante --// 
#define NOM_DEVELOPPEUR "Philou"

//-- programme principales --// 
void main()
{
	//-- déclaration de variables --//
	e_validation validationSerie = NOT_OK;		// NOT_OK valeur non validée => OK valeur validée
	e_validation validatonResistance = NOT_OK;	// NOT_OK valeur non validée => OK valeur validée
	float choixUserValResistance; 
	int choixUserSerie; 

	//-- message user --// 
	printf("TEST1 SEMESTRE 2 - ANNEE 2022 - DEVELOPPEUR : %s \n", NOM_DEVELOPPEUR); 
	
	//-- itération faire tant que l'utilisateur de donner pas de bonne information  --// 
	do
	{
		//-- test sur le choix de la série --// 
		if (validationSerie == NOT_OK)
		{
			//-- information / demande au user --// 
			printf("\nVeuillez choisir une serie en inscrivant le nombre de celle ci (ex: E6 => 6) : ");

			//-- récupération de info utilisateur --// 
			scanf("%d", &choixUserSerie);

			//-- appel de fonction => vider le buffer clavier --//
			ViderBufferClavier(); 
		}

		//-- test sur le choix de la valeur de résistance --// 
		if (validatonResistance == NOT_OK)
		{
			//-- information / demande à l'utilisateur 
			printf("\nVeuillez inserer une valeur unitaire de resistance entre 1.00 à 9.99 (ex : 3.14) :"); 

			//-- récupération de info utilisateur --// 
			scanf("%f", &choixUserValResistance);

			//-- appel de fonction => vider le buffer clavier --//
			ViderBufferClavier();
		}

		//-- appel de fonction => test si série valide 
		validationSerie = ControleChoixSerie(choixUserSerie); 

		//-- appel de fonction => test si valeur résistance unitaire est dans les limites 
		validatonResistance = ControleChoixResistance(choixUserValResistance); 

	} while (validationSerie == NOT_OK); 




	//-- calcul des valeurs unitaires en fonction de la série choisie (
	

	





}
