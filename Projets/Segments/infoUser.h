#ifndef infoUser_H
#define infoUser_H 
//-- librairie standart pour les types utilisés dans les protoytpes --// 
#include <stdint.h>

//-- librairie personnelle pour les types utilisés dans les protoytpes--// 
#include "segmentAB.h"

//-- déclararation de prototype --// 
int DemandeValeurPoint(e_point choixPoint); 
int8_t ValiderValUser(int8_t valeurUser, e_point choixPoint); 

#endif // !infoUser

