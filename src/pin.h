/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */


#ifndef PIN_H   /* Guard against multiple inclusion */
#define PIN_H

#include "config/default/peripheral/gpio/plib_gpio.h"
#define PIN_NUM 12


typedef struct {
    uint32_t mask;
    void *set_output();
    void *reset_output();
}pin_t;

pin_t V1 = {
    0xC0,
    ,
    &VALVE_1_Clear
};



uint8_t set_pin_state(uint32_t pins, uint8_t* pin_order);

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
