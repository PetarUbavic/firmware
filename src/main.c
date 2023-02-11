/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    can_t msg;
    uint32_t pins;
    msg.length = 0;
    
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    
    uint8_t const pin_mask[8] = {V1, V2, V3, V4, V5, V6,
                                 P1, P2, P3, P4, P5, P6};

    
    while ( true )
    {
        memset(&msg, 0, sizeof(can_t));
        while( !CAN4_MessageReceive(&msg.ID, &msg.length, msg.data, 0, 2, &msg.msgAttr));
        
        pins = msg.data[2]<<16 | msg.data[1]<<8 | msg.data[0];
        
         
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        //SYS_Tasks ( );
        //PUMP_6_Toggle();
        UART6_Write(msg.data, 8);
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

