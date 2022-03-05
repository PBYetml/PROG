//-----------------------------------------------------------------------------------//
// Nom du projet 		: Approximation r�sistance
// Nom du fichier 		: main.c
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
#include <stdio.h>		// flux d'entr�e / sortie 
#include <stdint.h>		// normalisation des types entiers 

//-- librairies personnelles --// 
#include "infoSeries.h"

//-- d�finition ou constante --// 
#define NOM_DEVELOPPEUR "Philou"

//-- programme principales --// 
void main()
{
	//-- d�claration de variables --//
	e_validation validationSerie = NOT_OK;		// NOT_OK valeur non valid�e => OK valeur valid�e
	e_validation validatonResistance = NOT_OK;	// NOT_OK valeur non valid�e => OK valeur valid�e
	float choixUserValResistance; 
	int choixUserSerie; 

	//-- message user --// 
	printf("TEST1 SEMESTRE 2 - ANNEE 2022 - DEVELOPPEUR : %s \n", NOM_DEVELOPPEUR); 
	
	//-- it�ration faire tant que l'utilisateur de donner pas de bonne information  --// 
	do
	{
		//-- test sur le choix de la s�rie --// 
		if (validationSerie == NOT_OK)
		{
			//-- information / demande au user --// 
			printf("\nVeuillez choisir une serie en inscrivant le nombre de celle ci (ex: E6 => 6) : ");

			//-- r�cup�ration de info utilisateur --// 
			scanf("%d", &choixUserSerie);

			//-- appel de fonction => vider le buffer clavier --//
			ViderBufferClavier(); 
		}

		//-- test sur le choix de la valeur de r�sistance --// 
		if (validatonResistance == NOT_OK)
		{
			//-- information / demande � l'utilisateur 
			printf("\nVeuillez inserer une valeur unitaire de resistance entre 1.00 � 9.99 (ex : 3.14) :"); 

			//-- r�cup�ration de info utilisateur --// 
			scanf("%f", &choixUserValResistance);

			//-- appel de fonction => vider le buffer clavier --//
			ViderBufferClavier();
		}

		//-- appel de fonction => test si s�rie valide 
		validationSerie = ControleChoixSerie(choixUserSerie); 

		//-- appel de fonction => test si valeur r�sistance unitaire est dans les limites 
		validatonResistance = ControleChoixResistance(choixUserValResistance); 

	} while (validationSerie == NOT_OK); 




	//-- calcul des valeurs unitaires en fonction de la s�rie choisie (
	

	





}
