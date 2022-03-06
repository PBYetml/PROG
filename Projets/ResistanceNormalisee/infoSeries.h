//-----------------------------------------------------------------------------------//
// Nom du projet 		: Approximation r�sistance
// Nom du fichier 		: infoSeries.h
// Date de cr�ation 	: 04.03.2022
// Date de modification : 05.03.2022
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : d�finition et prototype li� aux s�rie de r�sistance 
//
//
// Remarques :          : 
//----------------------------------------------------------------------------------//
#ifndef INFO_SERIE
#define INFO_SERIE 

//-- librairies utilis�es --//
#include <stdint.h>
#include "infoUser.h"

//-- d�claration des constantes ou de d�finition --// 
#define LIMITE_R_MIN 1.00
#define LIMITE_R_MAX 10.00
#define LIMITE_POID_PUISSANCE_MIN 0
#define LIMITE_POID_PUISSANCE_MAX 6

//-- d�claration �num�ration --// 
typedef enum
{
	E6 = 6, E12 = 12, E24 = 24
}e_valuerSerie;

typedef enum
{
	CONST_K = 3, CONST_M = 6
}e_poidPuissance;


//-- d�claration de structeur --// 
typedef struct 
{
	uint8_t choixSerieR;			// choix de la s�rie 
	uint8_t rangResistance; 		// rang ou position de la valeur normalis�e 
	float *pt_tbApproximation;		// tableau d'approximation unitaire
	float resistanceBrute;			// valeur brute de la r�sistance 
	float resistanceNormalisee;		// valeur normalis�e de la r�sistance
} s_serieRX;

//-- d�claration de prototype --// 
e_validation ControleChoixSerie(uint8_t valUser);						// controle de la s�rie E6, E12, E24... 
e_validation ControleChoixResistance(float valUser);					// contr�le de la valeur unitaire de la r�sistance 
e_validation ControlePuissanceResistance(uint8_t valUser);				// contr�le du puissance de puissance en base 10
float CalculResistanceUser(float valR, uint8_t valP);					// calcule la r�sistance brute de l'utilsateur
void AfficherValeurResistance(float valRBrute, uint8_t poidPuissance);	// affichage de la valeur de r�sistance avec suffixe -, k, M

#endif // !INFO_SERIE


