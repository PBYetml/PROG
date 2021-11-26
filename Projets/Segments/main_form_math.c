//-----------------------------------------------------------------------------------//
// Nom du projet 		: Formulaire mathematique 
// Nom du fichier 		: main_form_math.c
// Date de création 	: 25.09.2017
// Date de modification : 23.10.2020
//
// Auteur 				: Philou (Ph. Bovey)
//
// Version				: 0.2 
//
// Description          : Solution test1 -> voir donnée
//
// Remarques			:            
//----------------------------------------------------------------------------------//
//-- directive préprocesseur pour supprimer certains warining --//
#pragma warning(disable : 4996)		//-- warning concernant les scanf

//--- librairie standart ---//    
#include <stdio.h>		// entrée - sortie
#include <stdlib.h>		// lib système 	
#include <stdint.h>		// type normalisé 
#include <math.h>		// pour les opérations mathématiques 

//-- déclaration de constantes --// 
#define VOTRE_NOM			"Solus de Philou"
#define LIMITE_MAX_AXE_X	100
#define LIMITE_MIN_AXE_X	-100
#define LIMITE_MAX_AXE_Y	50
#define LIMITE_MIN_AXE_Y	-50

//-- programme principal --// 
int main(void)
{
	//-- déclaration de variable locale --//
	double distanceSegmentA_B; 
	double milieuSegmentAxe_X, milieuSegmentAxe_Y;
	double pente; 

	int pointA_axeX, pointA_axeY;		// définissant le point A  
	int pointB_axeX, pointB_axeY;		// définissant le point B 
	int8_t testValXa = 0, testValYa = 0, test_valeur = 0;
	int8_t testValXb = 0, testValYb = 0; 

	//-- message utilisateur --//
	printf("-- TEST LOGA n1 Semestre1 %s -- \n\n", VOTRE_NOM); 

	//-- boucle pour test si valeur comprise entre les limites --//
	do
	{
		//-- Demande utilisateur pour récuperation de valeurs --// 
		//-- test sur la valeur abscisse A --//
		if(!testValXa)
		{ 
			//-- message utilisateur --//
			printf("Entrez valeur abscisse pour point A !\n");
			scanf("%d", &pointA_axeX);


			//-- test si les points se trouve dans les bonnes limites --//
			//-- test 1 -> point A -> X --//
			if ((pointA_axeX < LIMITE_MAX_AXE_X) || (pointA_axeX > LIMITE_MIN_AXE_X))
				testValXa = 1;
		}

		//-- test sur la valeur ordonnee A --//
		else if ((testValXa == 1) && (testValYa == 0))
		{
			//-- message utilisateur --//
			printf("Entrez valeur ordonnee pour point A !\n");
			scanf("%d", &pointA_axeY);

			//-- test si les points se trouve dans les bonnes limites --//
			//-- test 2 --> point A -> Y --//
			if ((pointA_axeY < LIMITE_MAX_AXE_Y) || (pointA_axeY > LIMITE_MIN_AXE_Y))
				testValYa = 1;
		}

		//-- test sur la valeur abscisse B --//
		else if ((testValYa == 1) && (testValXb == 0))
		{
			//-- message utilisateur --//
			printf("Entrez valeur abscisse pour point B !\n");
			scanf("%d", &pointB_axeX);

			//-- test si les points se trouve dans les bonnes limites --//
			//-- test 3 -> point B -> X --//
			if ((pointB_axeX < LIMITE_MAX_AXE_Y) || (pointB_axeX > LIMITE_MIN_AXE_Y))
				testValXb = 1;
		}

		//-- test sur la valeur ordonnee B --//
		else if ((testValXb == 1) && (testValYb == 0))
		{
			//-- message utilisateur --//
			printf("Entrez valeur ordonnee pour point B !\n");
			scanf("%d", &pointB_axeY);
			
			//-- test si les points se trouve dans les bonnes limites --//
			//-- test 4 -> point B -> Y --//
			if ((pointB_axeY < LIMITE_MAX_AXE_Y) || (pointB_axeY > LIMITE_MIN_AXE_Y))
				testValYb = 1;
		}
		else
		{
			printf("Erreur !!! \n"); 
		}

	//-- fin de boucle de test --// 
	} while (!((testValXa != 0) && (testValYa != 0) && (testValXb != 0) && (testValYb != 0)));

	//-- partie calcul --//
	//-- calcul de la distance : d = sqrt (Xb - Xa)^2 + (Yb - Ya)^2
	//distanceSegmentA_B = sqrt(((pointB_axeX - pointA_axeX)*(pointB_axeX - pointA_axeX)) + ((pointB_axeY - pointA_axeY)*(pointB_axeY - pointA_axeY)));
	distanceSegmentA_B = sqrt(pow((pointB_axeX - pointA_axeX), 2) + pow(pointB_axeY - pointA_axeY, 2)); 

	//-- calcul coordonéé milieu d'un segment: M_X = (Xa + Xb)/2 et M_Y = (Ya + Yb)/2
	milieuSegmentAxe_X = (pointA_axeX + pointB_axeX) / 2; 
	milieuSegmentAxe_Y = (pointA_axeY + pointB_axeY) / 2;

	//-- calcul de la pente : m = (Yb - Ya) / (Xb - Xa)
	pente = (float)(pointB_axeY - pointA_axeY) / (float)(pointB_axeX - pointA_axeX); 

	//-- affichage des différents calculs --// 
	printf("la distance du segment A - B est de : %.3f \n", distanceSegmentA_B); 
	printf("le milieu du segment A - B est pour l'abssice de : %.3f \n", milieuSegmentAxe_X);
	printf("le milieu du segment A - B est pour l'ordonnee : %.3f \n", milieuSegmentAxe_Y); 
	printf("la pente vaut : %.3f \n", pente); 

	//-- mettre en pause le programme --// 
	system("pause");

	//-- fin de programme --// 
	return (0); 

}
