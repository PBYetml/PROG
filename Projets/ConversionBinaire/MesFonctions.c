//-----------------------------------------------------------------------------------//
// Nom du projet 		: CONVERSION_TEMP
// Nom du fichier 		: mesFonction.c
// Date de cr�ation 	: 04.10.2021
// Date de modification : xx.xx.2021
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : fichier comportant diff�rentes fonctions permettant de faire 
//						  des convertions
//----------------------------------------------------------------------------------//
//-- librairie standart --// 
#include <stdio.h>				// librairie pour les I/O
#include <stdint.h>				// libraire types entiers normalis�e
#include <math.h>

//-- librairie personnelle --// 
#include "mesFonctions.h"

//----------------------------------------------------------------------------------//
// Nom de la fonction   : ConvertirTemperatureEnBinaire
// Entr�e / Sortie      : temperature_Celuis / - /
// Description          : recoit une valeur correspondant � une temperature en �C et 
//						  la converti en valeur binaire -> simulation du capteur 
//						  DS1822
// Date modfification   : le 04.10.2021
// Remarque             : datasheet capteur DS 1822
//						  https://www.mouser.ch/datasheet/2/256/DS1822-369473.pdf
//----------------------------------------------------------------------------------//
void ConvertirTemperatureEnBinaire(float temperature_Celuis) 
{
	//-- d�claration de variable --//
	int8_t tbValeurBinaire[RESOLUTION_BINAIRE] = {0};		// tableau ayant comme valeur initiales 0 pour toutes les cases  
	int8_t iteration = RESOLUTION_BINAIRE - 2, valeurEntiere = 0, valeurDecimal = 0;
	float temperatureFractionnee_Celuis; 
	int32_t temperatureEntiere_Celuis;

	//-- scinder en deux partie :  r�el et partie enti�re 
	temperatureEntiere_Celuis = temperature_Celuis; 
	temperatureFractionnee_Celuis = temperature_Celuis - temperatureEntiere_Celuis; 

	//-- d�terminer si le nombre est n�gatif --// 
	if (temperatureEntiere_Celuis < 0)
		//-- compl�ments � deux pour la partie enti�re -> vision math�matique --// 
		temperatureEntiere_Celuis = pow(2, 8) + temperatureEntiere_Celuis; 

	if (temperatureFractionnee_Celuis < 0)
		//-- compl�ments � deux pour la partie enti�re -> vision math�matique --// 
		temperatureFractionnee_Celuis = 1 + temperatureFractionnee_Celuis; 
		
	//-- Converison binaire partie enti�re --//
	while (temperatureEntiere_Celuis != 0)
	{
		//-- conversion binaire -> r�cup�ration du reste  --// 
		tbValeurBinaire[iteration - 1] = temperatureEntiere_Celuis % 2;

		//-- MAJ de la temperature enti�re --//
		temperatureEntiere_Celuis >>= 1; 

		//-- MAJ de l'it�ration 
		iteration -= 1; 
	}

	//-- MAJ de la valeur it�ration --// 
	iteration = 0; 

	//-- conversion binaire partie r�el --//
	while (iteration < 2)
	{
		//-- enregistrement de la valeur binaire fractionn�e sur deux digits --// 
		tbValeurBinaire[8 + iteration] = (temperatureFractionnee_Celuis * 2.0); 

		//-- MAJ de la valeur fractionnee --//
		if ((temperatureFractionnee_Celuis * 2.0) >= 1.0)
			temperatureFractionnee_Celuis = (temperatureFractionnee_Celuis * 2.0) - 1;
		else
			temperatureFractionnee_Celuis *= 2; 

		//-- MAJ de l'�teration --// 
		iteration += 1; 
	}

	//-- message utilisateur => affichage de la valeur binaire --//
	printf("\nLa valeur binaire est 0b"); 
	for (iteration = 0; iteration < RESOLUTION_BINAIRE; iteration++)
	{
		//-- message utilisateur => valeur binaire compl�te --//
		printf("%d", tbValeurBinaire[iteration]);
		
		//-- test pour calculer la valeur enti�re --// 
		if (iteration < RESOLUTION_BINAIRE - 2)
			//-- calcul de la valeur en d�cimal pour obtenir la valeur en hexa => utile pour la valeur n�gatif (compl�emnt � deux) 
			valeurEntiere += tbValeurBinaire[iteration] * (pow(2, (RESOLUTION_BINAIRE - 2) - (iteration + 1)));
		else
			valeurDecimal += tbValeurBinaire[iteration] * pow(2, (RESOLUTION_BINAIRE - iteration)+1); 
	}

	//-- message utilisateur => affichage de la valeur en hexa --//
	printf(" et la valeur en hexa est 0x%2x%1x", (uint8_t)valeurEntiere, (uint8_t)valeurDecimal);
}
