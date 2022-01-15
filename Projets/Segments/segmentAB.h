#ifndef segmentAB_H
#define segmentAB_H

//-- définition --// 
#define LIMITE_MAX_AXE_X	100
#define LIMITE_MIN_AXE_X	-100
#define LIMITE_MAX_AXE_Y	50
#define LIMITE_MIN_AXE_Y	-50

//-- type énumération --// 
typedef enum { abscisse_A, abscisse_B, ordonnee_A, ordonnee_B } e_point; 

//-- prototype --// 
double CalculerDistancePointsA_B(int pointAx, int pointAy, int pointBx, int pointBy); 
double CalculerCoordonneePointMilieu(int pointA, int pointB); 
double CalculerPenteSegmentA_B(int pointAx, int pointAy, int pointBx, int pointBy);


#endif // !segmentAB_H
