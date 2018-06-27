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

// get/set SDA aliases
#define SDA_TRIS                 TRISBbits.TRISB4
#define SDA_LAT                  LATBbits.LATB4
#define SDA_PORT                 PORTBbits.RB4
#define SDA_WPU                  WPUBbits.WPUB4
#define SDA_OD                   ODCONBbits.ODB4
#define SDA_ANS                  ANSELBbits.ANSB4
#define SDA_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDA_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDA_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDA_GetValue()           PORTBbits.RB4
#define SDA_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDA_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SDA_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SDA_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define SDA_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define SDA_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SDA_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SCL aliases
#define SCL_TRIS                 TRISBbits.TRISB6
#define SCL_LAT                  LATBbits.LATB6
#define SCL_PORT                 PORTBbits.RB6
#define SCL_WPU                  WPUBbits.WPUB6
#define SCL_OD                   ODCONBbits.ODB6
#define SCL_ANS                  ANSELBbits.ANSB6
#define SCL_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCL_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCL_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCL_GetValue()           PORTBbits.RB6
#define SCL_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCL_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCL_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCL_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define SCL_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define SCL_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SCL_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set Button3 aliases
#define Button3_TRIS                 TRISCbits.TRISC3
#define Button3_LAT                  LATCbits.LATC3
#define Button3_PORT                 PORTCbits.RC3
#define Button3_WPU                  WPUCbits.WPUC3
#define Button3_OD                   ODCONCbits.ODC3
#define Button3_ANS                  ANSELCbits.ANSC3
#define Button3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define Button3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define Button3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define Button3_GetValue()           PORTCbits.RC3
#define Button3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define Button3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define Button3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define Button3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define Button3_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define Button3_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define Button3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define Button3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set Button2 aliases
#define Button2_TRIS                 TRISCbits.TRISC4
#define Button2_LAT                  LATCbits.LATC4
#define Button2_PORT                 PORTCbits.RC4
#define Button2_WPU                  WPUCbits.WPUC4
#define Button2_OD                   ODCONCbits.ODC4
#define Button2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define Button2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define Button2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define Button2_GetValue()           PORTCbits.RC4
#define Button2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define Button2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define Button2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define Button2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define Button2_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define Button2_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set Button1 aliases
#define Button1_TRIS                 TRISCbits.TRISC5
#define Button1_LAT                  LATCbits.LATC5
#define Button1_PORT                 PORTCbits.RC5
#define Button1_WPU                  WPUCbits.WPUC5
#define Button1_OD                   ODCONCbits.ODC5
#define Button1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define Button1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define Button1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define Button1_GetValue()           PORTCbits.RC5
#define Button1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define Button1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define Button1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define Button1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define Button1_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define Button1_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)

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