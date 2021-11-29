//-----------------------------------------------------------------------------------//
// Nom du projet 		: Formulaire mathematique 
// Nom du fichier 		: main_form_math_V03.c
// Date de création 	: 25.09.2017
// Date de modification : 29.11.2021
//
// Auteur 				: Philou (Ph. Bovey)
//
// Version				: 0.3
//
// Description          : Solution test2 -> voir donnée
//
// Remarques			:            
//----------------------------------------------------------------------------------//
//-- directive préprocesseur pour supprimer certains warining --//
#pragma warning(disable : 4996)		//-- warning concernant les scanf

//-- librairie standart --//    
#include <stdio.h>		// entrée - sortie
#include <stdlib.h>		// lib système 	
#include <stdint.h>		// type normalisé 
#include <math.h>		// pour les opérations mathématiques 

//-- librairie personnelle --// 
#include "infoUser.h"
#include "segmentAB.h"

//-- déclaration de constantes --// 
#define VOTRE_NOM			"Solus de Philou"

//-- programme principal --// 
int main(void)
{
	//-- déclaration de variable locale --//
	double distanceSegmentA_B = 0; 
	double milieuSegmentAxe_X = 0, milieuSegmentAxe_Y = 0;
	double pente = 0; 

	int pointA_axeX, pointA_axeY;		// définissant le point A  
	int pointB_axeX, pointB_axeY;		// définissant le point B 
	
	int8_t testValXa = 0, testValYa = 0, test_valeur = 0;
	int8_t testValXb = 0, testValYb = 0;

	//-- message utilisateur --//
	printf("-- TEST PROG n2 Semestre1 - Auteur : %s -- \n\n", VOTRE_NOM); 

	//-- boucle de controle - valeurs limites --//
	do
	{
		//-- appel de fct : valeur de point de segment --//
		//-- avec test si la valeur est dans les limites ou non --// 
		if (testValXa == 0)
		{
			pointA_axeX = DemandeValeurPoint(abscisse_A);
			testValXa = ValiderValUser(pointA_axeX, abscisse_A); 
		}

		if (testValYa == 0)
		{ 
			pointA_axeY = DemandeValeurPoint(ordonnee_A);
			testValYa = ValiderValUser(pointA_axeY, ordonnee_A); 
		}

		if (testValXb == 0)
		{
			pointB_axeX = DemandeValeurPoint(abscisse_B);
			testValXb = ValiderValUser(pointB_axeX, abscisse_B);
		}

		if (testValYb == 0)
		{
			pointB_axeY = DemandeValeurPoint(ordonnee_B);
			testValYb = ValiderValUser(pointB_axeY, ordonnee_B);
		}

		//-- erreur système --// 
		if ((testValXa < 0) || (testValXb < 0) || (testValYa < 0) || (testValYb < 0))
			printf("!! erreur systeme !!"); 

	//-- fin de boucle de test --// 
	} while (!((testValXa != 0) && (testValYa != 0) && (testValXb != 0) && (testValYb != 0)));

	//-- appel de fonction pour calculer la distance entre deux points --// 
	distanceSegmentA_B = CalculerDistancePointsA_B(pointA_axeX, pointA_axeY, pointB_axeX, pointB_axeY);

	//-- appel de fonction pour calculer le milieu d'un segment AB --//
	//-- double appel de la même fonction --// 
	//-- abscisse --//  
	milieuSegmentAxe_X = CalculerCoordonneePointMilieu(pointA_axeX, pointB_axeX);
	//-- ordonnee --// 
	milieuSegmentAxe_Y = CalculerCoordonneePointMilieu(pointA_axeY, pointB_axeY);

	//-- appel de fonction pour la caluler la pente du segment par rapport à l'axe X (abscisse) 
	pente = CalculerPenteSegmentA_B(pointA_axeX, pointA_axeY, pointB_axeX, pointB_axeY); 

	//-- affichage des différents calculs --// 
	printf("la distance du segment A - B est de : %.3f \n", distanceSegmentA_B); 
	printf("le milieu du segment A - B est pour l'abscisse de : %.3f \n", milieuSegmentAxe_X);
	printf("le milieu du segment A - B est pour l'ordonnee : %.3f \n", milieuSegmentAxe_Y); 
	printf("la pente vaut : %.3f \n", pente); 

	//-- mettre en pause le programme --// 
	system("pause");

	//-- fin de programme --// 
	return (0); 

}
