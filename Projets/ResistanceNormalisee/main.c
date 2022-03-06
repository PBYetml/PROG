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
	//-- enumaration --// 
	e_validation validationSerie = NOT_OK;			// NOT_OK valeur non validée => OK valeur validée
	e_validation validationResistance = NOT_OK;		// NOT_OK valeur non validée => OK valeur validée
	e_validation validadationPuissanceR = NOT_OK;	// NOT_OK valeur non validée => OK valeur validée

	//-- floattant --// 
	float choixUserValResistance; 
	float tbDecadeE6[E6] = { 0 }, tbDecadeE12[E12] = { 0 }, tbDecadeE24[E24] = { 0 }; 

	//-- entier --// 
	int choixUserSerie, choixPuissanceR; 

	//-- strcuture --//
	s_serieRX Resistances;  //ResistanceE12, ResistanceE24; 


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

			//-- appel de fonction => test si série valide --//
			validationSerie = ControleChoixSerie(choixUserSerie);
		}

		//-- test sur le choix de la valeur de résistance --// 
		if (validationResistance == NOT_OK)
		{
			//-- information / demande à l'utilisateur 
			printf("\nVeuillez inserer une valeur unitaire de resistance entre 1.00 à 9.99 (ex : 3.14) : "); 

			//-- récupération de info utilisateur --// 
			scanf("%f", &choixUserValResistance);

			//-- appel de fonction => vider le buffer clavier --//
			ViderBufferClavier();

			//-- appel de fonction => test si valeur résistance unitaire est dans les limites --// 
			validationResistance = ControleChoixResistance(choixUserValResistance);
		}

		//-- test sur le choix de la puissance de 10 que l'utilsateur --// 
		if (validadationPuissanceR == NOT_OK)
		{
			//-- information / demande à l'utilisateur 
			printf("\nVeuillez inserer une valeur de puissance de 10 entre 0 et 6 : 10 ^ ");

			//-- récupération de info utilisateur --// 
			scanf("%d", &choixPuissanceR);

			//-- appel de fonction => vider le buffer clavier --//
			ViderBufferClavier();

			//-- appel de fonction => test si valeur résistance unitaire est dans les limites --// 
			validadationPuissanceR = ControlePuissanceResistance(choixPuissanceR);
		}

	} while ((validationSerie == NOT_OK) || (validationResistance == NOT_OK) || (validadationPuissanceR == NOT_OK));

	//-- appel de fonction => calculer la résistance définit par l'utilisateur
	Resistances.resistanceBrute = CalculResistanceUser(choixUserValResistance, choixPuissanceR);

	//-- appel de fonction => afficher la valeur avec le suffixe de puissance (-, k, M)
	AfficherValeurResistance(Resistances.resistanceBrute, choixPuissanceR);

	//-- sélection de la structure à utiliser en fonction du choix de l'utilisateur --// 
	switch (choixUserSerie)
	{
		case E6: 
			Resistances.choixSerieR = E6; 
			break; 

		case E12: 
			Resistances.choixSerieR = E12;
			break; 

		case E24: 
			Resistances.choixSerieR = E24;
			break; 

		default: 
			printf("!! Aucune structure selectionnee !!"); 
			break; 
	}
}
