/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1619
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED3 aliases
#define LED3_TRIS                 TRISAbits.TRISA1
#define LED3_LAT                  LATAbits.LATA1
#define LED3_PORT                 PORTAbits.RA1
#define LED3_WPU                  WPUAbits.WPUA1
#define LED3_OD                   ODCONAbits.ODA1
#define LED3_ANS                  ANSELAbits.ANSA1
#define LED3_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED3_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED3_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED3_GetValue()           PORTAbits.RA1
#define LED3_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED3_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISAbits.TRISA2
#define LED2_LAT                  LATAbits.LATA2
#define LED2_PORT                 PORTAbits.RA2
#define LED2_WPU                  WPUAbits.WPUA2
#define LED2_OD                   ODCONAbits.ODA2
#define LED2_ANS                  ANSELAbits.ANSA2
#define LED2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED2_GetValue()           PORTAbits.RA2
#define LED2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISAbits.TRISA5
#define LED4_LAT                  LATAbits.LATA5
#define LED4_PORT                 PORTAbits.RA5
#define LED4_WPU                  WPUAbits.WPUA5
#define LED4_OD                   ODCONAbits.ODA5
#define LED4_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED4_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED4_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED4_GetValue()           PORTAbits.RA5
#define LED4_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED4_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()               do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()                do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()                do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()       do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()      do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()               do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()                do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()                do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()       do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()      do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set buton aliases
#define buton_TRIS                 TRISCbits.TRISC4
#define buton_LAT                  LATCbits.LATC4
#define buton_PORT                 PORTCbits.RC4
#define buton_WPU                  WPUCbits.WPUC4
#define buton_OD                   ODCONCbits.ODC4
#define buton_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define buton_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define buton_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define buton_GetValue()           PORTCbits.RC4
#define buton_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define buton_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define buton_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define buton_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define buton_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define buton_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISCbits.TRISC5
#define LED1_LAT                  LATCbits.LATC5
#define LED1_PORT                 PORTCbits.RC5
#define LED1_WPU                  WPUCbits.WPUC5
#define LED1_OD                   ODCONCbits.ODC5
#define LED1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED1_GetValue()           PORTCbits.RC5
#define LED1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/