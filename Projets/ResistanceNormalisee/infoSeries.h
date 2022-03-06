//-----------------------------------------------------------------------------------//
// Nom du projet 		: Approximation résistance
// Nom du fichier 		: infoSeries.h
// Date de création 	: 04.03.2022
// Date de modification : 05.03.2022
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : définition et prototype lié aux série de résistance 
//
//
// Remarques :          : 
//----------------------------------------------------------------------------------//
#ifndef INFO_SERIE
#define INFO_SERIE 

//-- librairies utilisées --//
#include <stdint.h>
#include "infoUser.h"

//-- déclaration des constantes ou de définition --// 
#define LIMITE_R_MIN 1.00
#define LIMITE_R_MAX 10.00
#define LIMITE_POID_PUISSANCE_MIN 0
#define LIMITE_POID_PUISSANCE_MAX 6

//-- déclaration énumération --// 
typedef enum
{
	E6 = 6, E12 = 12, E24 = 24
}e_valuerSerie;

typedef enum
{
	CONST_K = 3, CONST_M = 6
}e_poidPuissance;


//-- déclaration de structeur --// 
typedef struct 
{
	uint8_t choixSerieR;			// choix de la série 
	uint8_t rangResistance; 		// rang ou position de la valeur normalisée 
	float *pt_tbApproximation;		// tableau d'approximation unitaire
	float resistanceBrute;			// valeur brute de la résistance 
	float resistanceNormalisee;		// valeur normalisée de la résistance
} s_serieRX;

//-- déclaration de prototype --// 
e_validation ControleChoixSerie(uint8_t valUser);						// controle de la série E6, E12, E24... 
e_validation ControleChoixResistance(float valUser);					// contrôle de la valeur unitaire de la résistance 
e_validation ControlePuissanceResistance(uint8_t valUser);				// contrôle du puissance de puissance en base 10
float CalculResistanceUser(float valR, uint8_t valP);					// calcule la résistance brute de l'utilsateur
void AfficherValeurResistance(float valRBrute, uint8_t poidPuissance);	// affichage de la valeur de résistance avec suffixe -, k, M

#endif // !INFO_SERIE


