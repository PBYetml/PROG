#ifndef infoUser_H
#define infoUser_H 
//-- librairie standart pour les types utilis�s dans les protoytpes --// 
#include <stdint.h>

//-- librairie personnelle pour les types utilis�s dans les protoytpes--// 
#include "segmentAB.h"

//-- d�clararation de prototype --// 
int DemandeValeurPoint(e_point choixPoint); 
int8_t ValiderValUser(int8_t valeurUser, e_point choixPoint); 

#endif // !infoUser

