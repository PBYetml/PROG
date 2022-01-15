//-----------------------------------------------------------------------------------//
// Nom du projet 		: Formulaire mathematique 
// Nom du fichier 		: infoUser.c
// Date de création 	: 29.11.2021
// Date de modification : xx.xx.2021
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
#include <stdint.h>			//-- type normalisé 
#include <stdio.h>			//-- lib sur les entrées/sortie système 
#include <math.h>			//-- lib pour les fct matématiques

//-- librairie personnelle --// 
#include "segmentAB.h"

//-----------------------------------------------------------------------------------//
// nom fonction				: CalculerDistancePointsA_B
// entrée / sortie / in_out : pointAx, pointAy, pointBx, pointBy / distanceAB / - 
// description				: calcul la distance d'un segment entre deux point 
//							  cartésiens 
// date de modification		: 29.11.2021
// remarque					: formule mathématique : 
//							  d = sqrt(Xb - Xa) ^ 2 + (Yb - Ya) ^ 2
//-----------------------------------------------------------------------------------//
double CalculerDistancePointsA_B(int pointAx, int pointAy, int pointBx, int pointBy)
{
	//-- déclaration de variable --// 
	double distanceAB; 

	//-- calcul de la distance --// 
	/* : d = sqrt(Xb - Xa) ^ 2 + (Yb - Ya) ^ 2
	* Solution écriture sans la fct pow : 
	* distanceSegmentA_B = sqrt(((pointBx - pointAx)*(pointBx - pointAx)) + ((pointBy - pointAy)*(pointBy - pointAy))); */
	distanceAB = sqrt(pow((pointBx - pointAx), 2) + pow(pointBy - pointAy, 2));

	//-- valeur de retour --// 
	return(distanceAB); 
}


//-----------------------------------------------------------------------------------//
// nom fonction				: CalculerCoordonneePointMilieu
// entrée / sortie / in_out : pointA, pointB / pointmilieu /  - 
// description				: calcul le point milieu d'un segment sur le même axe 
//							  les infos des points recus doivent être sur le même axe 
// date de modification		: 29.11.2021
// remarque					: formule mathématique : 
//							  point milieu = (Xa + Ya) / 2 ou (Xb + Yb) / 2
//-----------------------------------------------------------------------------------//
double CalculerCoordonneePointMilieu(int pointA, int pointB)
{
	//-- déclaration de variable --// 
	double pointmilieu; 

	//-- calcul du point milieu (axe indentique) 
	pointmilieu = (pointA + pointB) / 2.0;	// calculer avec cast implicte en float (DOUBLE) 
	
	//-- valeur de retour --// 
	return(pointmilieu); 
}

//-----------------------------------------------------------------------------------//
// nom fonction				: CalculerPenteSegmentA_B
// entrée / sortie / in_out : pointAx, pointAy pointBx, pointBy / pente /  - 
// description				: calcul la pente d'un segment AB par rapport à l'abscisse
//							  (axe X) 
// date de modification		: 29.11.2021
// remarque					: formule mathématique : 
//							  m = (Yb - Ya) / (Xb - Xa)
//-----------------------------------------------------------------------------------//
double CalculerPenteSegmentA_B(int pointAx, int pointAy, int pointBx, int pointBy)
{
	//-- déclaration de variable --//
	double pente; 

	//-- calcul de la pente --//
	//-- m = (Yb - Ya) / (Xb - Xa)
	//-- attention à caster le calcul --// 
	pente = (double)(pointBy - pointAy) / (double)(pointBx - pointAx);

	return (pente); 
}