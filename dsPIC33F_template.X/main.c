/*
 * Template dsPIC33F
 * Compiler : Microchip xC16
 * �C : 33FJ64MC802
 * Juillet 2012
 *    ____________      _           _
 *   |___  /| ___ \    | |         | |
 *      / / | |_/ /___ | |__   ___ | |_
 *     / /  |    // _ \| '_ \ / _ \| __|
 *    / /   | |\ \ (_) | |_) | (_) | |_
 *   /_/    |_| \_\___/|____/ \___/'\__|
 *			      7robot.fr
 */

#include <p33Fxxxx.h>      /* Includes device header file                     */
#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include "header.h"        /* Function / Parameters                           */
#include <libpic30.h>
#include "ax12.h"
#include <uart.h>
#include <delay.h>
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */


/******************************************************************************/
/* Configuartion                                                              */
/******************************************************************************/

// Select Oscillator and switching.
_FOSCSEL(FNOSC_FRCPLL & IESO_OFF);
// Select clock.
_FOSC(POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_OFF & FCKSM_CSDCMD);
// Watchdog Timer.
_FWDT(FWDTEN_OFF);
// Select debug channel.
_FICD(ICS_PGD1 & JTAGEN_OFF);


/******************************************************************************/
/* Main Program                                                               */

/******************************************************************************/

int16_t main(void) {
    // Initialize IO ports and peripherals.
    ConfigureOscillator();
    InitApp();
    responseReadyAX = 0;
    // time
    int t1 = 100;
    int t2 = 25;

    while (1) {
        //  PutAX(AX_BROADCAST, AX_LED, 1);
        //  PutAX(AX_BROADCAST, AX_GOAL_POSITION, 100);
        //  PutAX(AX_BROADCAST, AX_BAUD_RATE, 34);
        //  PutAX(AX_BROADCAST, AX_ID, 42);

        //  PutAX(AX_BROADCAST, AX_TORQUE_LIMIT, 500);
        // PutAX(12, AX_GOAL_POSITION, 400);
        // __delay_ms(t1)
        init_bras(1);
        init_bras(2);
        __delay_ms(1000);

        catch_bras(2);
        
        stock_bras(2);
        face1(2);

        
        led1 = !led1;
        __delay_ms(1000);




    }
}

