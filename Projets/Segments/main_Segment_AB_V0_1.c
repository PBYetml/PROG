//-----------------------------------------------------------------------------------//
// Nom du projet 		: Formulaire mathematique 
// Nom du fichier 		: main_form_math.c
// Date de création 	: 25.09.2017
// Date de modification : 26.09.2017
//
// Auteur 				: Philou (Ph. Bovey)
//
// Version				: 0.1 
//
// Description          : Solution test1 -> voir donnée
//
//
// Remarques			:            
//----------------------------------------------------------------------------------//

//--- librairie standart ---//
#include <stdio.h>		// entrée - sortie
#include <stdint.h>		// type normalisé 
#include <math.h>		// pour les opérations mathématiques 

//-- déclaration de constantes --// 
#define VOTRE_NOM			"VOTRE NOM"
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
	int test_valeur = 0; 

	//-- message utilisateur --//
	printf("-- TEST LOGA n1 Semestre1 %s -- \n\n", VOTRE_NOM); 

	//-- boucle pour test si valeur comprise entre les limites --//
	do
	{
		//-- Demande utilisateur avec récuperation valeur --// 
		printf("Entrez valeur abscisse pour point A !\n");
		scanf_s("%d%*c", &pointA_axeX);

		printf("Entrez valeur ordonnee pour point A !\n");
		scanf_s("%d%*c", &pointA_axeY);

		printf("Entrez valeur abscisse pour point B !\n");
		scanf_s("%d%*c", &pointB_axeX);

		printf("Entrez valeur ordonnee pour point B !\n");
		scanf_s("%d%*c", &pointB_axeY);

		//-- test si les points se trouve dans les bonnes limites --//
		//-- test 1 -> point A -> X --//
		if ((pointA_axeX > LIMITE_MAX_AXE_X) || (pointA_axeX < LIMITE_MIN_AXE_X))
			test_valeur = 1;
		//-- test 2 --> point A -> Y --//
		else if ((pointA_axeY > LIMITE_MAX_AXE_Y) || (pointA_axeY < LIMITE_MIN_AXE_Y))
			test_valeur = 1; 
		//-- test 3 -> point B -> X --//
		else if ((pointB_axeX > LIMITE_MAX_AXE_Y) || (pointB_axeX < LIMITE_MIN_AXE_Y))
			test_valeur = 1;
		//-- test 4 -> point B -> Y --//
		else if ((pointB_axeY > LIMITE_MAX_AXE_Y) || (pointB_axeY < LIMITE_MIN_AXE_Y))
			test_valeur = 1;
		else
			test_valeur = 0; 

	//-- fin de boucle de test --// 
	} while (test_valeur != 0);

	//-- partie calcul --//
	//-- calcul de la distance : d = sqrt (Xb - Xa)^2 + (Yb - Ya)^2
	//distanceSegmentA_B = sqrt(((pointB_axeX - pointA_axeX)*(pointB_axeX - pointA_axeX)) + ((pointB_axeY - pointA_axeY)*(pointB_axeY - pointA_axeY)));
	distanceSegmentA_B = sqrt(pow((pointB_axeX - pointA_axeX), 2) + pow(pointB_axeY - pointA_axeY, 2)); 

	//-- calcul coordonéé milieu d'un segment: M_X = (Xa + Xb)/2 et M_Y = (Ya + Yb)/2
	milieuSegmentAxe_X = (pointA_axeX + pointB_axeX) / 2; 
	milieuSegmentAxe_Y = (pointA_axeY + pointB_axeY) / 2;

	//-- calcul de la pente : m = (Yb - Ya) / (Xb - Xa)
	pente = (pointB_axeY - pointA_axeY) / (pointB_axeX - pointA_axeX); 

	//-- affichage des différents calculs --// 
	printf("la distance du segment A - B est de : %f \n", distanceSegmentA_B); 
	printf("le milieu du segment A - B est pour l'abssice de : %f \n", milieuSegmentAxe_X);
	printf("le milieu du segment A - B est pour l'ordonnee : %f \n", milieuSegmentAxe_Y); 
	printf("la pente vaut : %f", pente); 

	//-- fin de programme --// 
	return (0); 

}
