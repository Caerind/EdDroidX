#include <msp430.h>
#include "utils.h"
#include "chassis.h"
#include "adc.h"
#include "sensorInfrared.h"
#include "movement.h"
#include "stage3.h"


short contour_obstacle()
{
    short ir_hor=0;     //infrarouge horizontale
    short ir_pen=0;     //infrarouge penché
    short resultat;
    rightRobot(0);  //tourne droite

    ir_hor=ir_detect(4);
    ir_pen=ir_detectThreshold(5, 170);

    if ((ir_hor==1) && (ir_pen==0))
	{    
		//trouvé mur  vers mur
        resultat=1;
    }
    else if ((ir_hor==0) && (ir_pen==1))
	{    
		//trou  cas peu possible
        rightRobot(0);   //tourner droite
        rightRobot(0); //tourner droite
        resultat=0;
    }
    else if ((ir_hor==0) && (ir_pen==0))
	{    
		//vide
        move(856,100);   //avancer 15cm
        leftRobot(0); //tourner gauche

		//detecter devant
        ir_hor=ir_detect(4);
		ir_pen=ir_detectThreshold(5, 170);
        if ((ir_hor==0) && (ir_pen==1))
		{    
			//trou devant  cas peu possible
            rightRobot(0);     // tourner droite
            resultat=0;
        }
        else if ((ir_hor==0) && (ir_pen==0))
		{    
			//rien devant  cas obstacle normale
            move(856,100);   //avancer 15cm
            resultat=0;
        }
        else if ((ir_hor==1) && (ir_pen==0))
		{    
			//trouvé mur  vers mur
            resultat=1;
        }
		// TODO : Cas où les deux = 1 ? 
    }
	// TODO : Cas où les deux = 1 ? 
    return resultat;
}


void contour_trou()
{
    //on n'a plus besoin de penché car il y a qu'un seul trou

    rightRobot(0);  //tourne droite

    if(ir_detect(4) == 1) 
	{    
		//obstacle devant
        rightRobot(0);   // tourner droite
    }
    else
	{    //vide devant
        move(685,100);   //avancer 12cm (0.6 diametre)
        rightRobot(0);  //tourner droite
    }
}

void trouvermur()
{
    short ir_hor=0;     //infrarouge horizontale
    short ir_pen=0;     //infrarouge penché
    short etape=0;      //etape==1 --> bien trouvé le mur

    while(etape!=1)
	{
		ir_hor=ir_detect(4);
		ir_pen=ir_detectThreshold(5, 170);

		//logiquement,il y a que 3 cas:
		//trou sans obstacle
		//obstacle sans trou
		//ni trou ni obstacle
		if((ir_hor==1)&&(ir_pen==0))
		{     
			//obstacle devant & sans trou
			move(172,100);    //avancer 3cm
			etape=contour_obstacle();
		}
		else if((ir_hor==0)&&(ir_pen==1))
		{     
			//trou devant & sans obstacle
			move(172,100);    //avancer 3cm
			contour_trou();
		}
		else if((ir_hor==0)&&(ir_pen==0))
		{     //vide devant
			move(343,100);    //avancer 6cm
		}
		// TODO : Cas où les deux = 1 ? 
    }
}


short contour_obstacle()
{
	short ir_hor=0;     //infrarouge horizontale

	//        short ir_pen=0;     //infrarouge penché

	short resultat=0;
	rightRobot(0); //tourne droite

	//ir_hor=obstacle();    //detecter devant
	////ir_pen=trou();    sans a cote???
	//if((ir_hor==1) && (ir_pen==0)){    //obstacle
	//    ???;  //droite

	move(856,100);   //avancer 15cm
	leftRobot(0);   //gauche
	ir_hor=obstacle();
	if(ir_hor==1)
	{       
		//corner
		rightRobot(0); //droite
		resultat=0;
	}
	else
	{
		move(856,100);   //avancer 15cm
		leftRobot(0);  //gauche
		move(856,100);   //avancer 15cm
		ir_hor=obstacle();    //detecter devant
		if(ir_hor==0)
		{      
			//trouver sortie
			resultat=1;
		}
		else
		{
			rightRobot(0);  //droite
		}
	}
	return resultat;
}


void contour_trou()
{
	//on n'a plus besoin de penché car il y a qu'un seul trou

	rightRobot(0); //tourner droite
	move(1026,100);   //avancer 18cm
	leftRobot(0); //tourner gauche
	move(1026,100);   //avancer 18cm
	leftRobot(0); //tourner gauche
	move(1026,100);   //avancer 18cm
	rightRobot(0); //tourner droite
}


short vide()
{
	short ir_gau=0;     //infrarouge penché
	short resultat=0;
	move(172,100);    //avancer 3cm
	ir_gau=sortie();
	if(ir_gau==1)
	{
		resultat=1;
	}
	return resultat;
}

void trouversortie()
{
	short ir_hor=0;     //infrarouge horizontale
	short ir_pen=0;     //infrarouge penché

	short trouve=0;      //trouve==1 --> bien trouvé la sortie

	rightRobot(0);  //tourner droite car l'etape precedant vers mur
	while(trouve!=1)
	{
		ir_hor=obstacle();
		ir_pen=trou();

		//logiquement,il y a que 3 cas:
		//trou sans obstacle
		//obstacle sans trou
		//ni trou ni obstacle
		if((ir_hor==1)&&(ir_pen==0))
		{     
			//obstacle devant & sans trou
			trouve=contour_obstacle();
		}

		if((ir_hor==0)&&(ir_pen==1))
		{     
			//trou devant & sans obstacle
			contour_trou();
		}

		if((ir_hor==0)&&(ir_pen==0))
		{     
			//vide devant
			vide();
		}
	}
	leftRobot(0);    // gauche
	move(1141,100);   //avancer 20cm pour sortir
}


void stage3()
{
	ut_initInput(1, 3); // Button S2
	while((P1IN & BIT3) == BIT3); // Wait for Button S2
	
    ut_init();
    ch_init();
    adc_init();
	ir_init(3); // Left
	ir_init(4); // Horizontal
	ir_init(5); // Inclined

    trouvermur();
    trouversortie();
	
	/*
	int endFound = 0;
	while (endFound != 1)
	{
		if ((ir_detect(4) == 1) || (ir_detectThreshold(5, 170) == 0)) // Obstacle or hole
		{
			
		}
		else // No obstacle and no hole
		{
			
		}
	}
	*/
}
