
#include <xc.h>
#include "main.h"
#include "clock.h"
#include "gpio.h"
#include "adc.h"

void main(void) {
    
    /* System Clock Initialization */
	CLOCK_Initialize();
    
    /* Config PortA */
    PortA_Initialize();
    
    /* Config PortB */
    PortB_Initialize();

    /* Config PortC */
    PortC_Initialize();
    
    /* Config PortD */
    PortD_Initialize();
    
    /* Config PortE */
    PortE_Initialize();
    
    /* Config PortF */
    PortF_Initialize();
    
    /* Config ADC */
    ADC_Initialize();
    
    /* infinite loop */
    while(1)
    {
     /* Start ADC conversion */
     ADC_Start();
        
     /* Wait for Go = 0 */
	while (ADC_conversionNotComplete)
        
         ;

     /* Write ADC result (low) to RD7:RD6 */
	 LATC = ADRESL;

	 /* Write ADC result (high) to RC7:RC0 */
	 LATD = ADRESH;
         
     } /* while */
            
    return;
} /* main*/
