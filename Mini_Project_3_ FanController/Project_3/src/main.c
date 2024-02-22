/*
 * main.c
 *	Description: Main file for the Project
 *  Created on: Feb 16, 2024
 *      Author: abdalla
 */
#include "adc.h" 			/* For ADC_init Function */
#include "dc_motor.h"
#include "lcd.h"
#include "lm35_sensor.h"

/* Enumeration for fan states */
typedef enum
{
	OFF, /* Fan is off */
	ON   /* Fan is on */
}STATE;

int main(void)
{
	/* Variables to store temperature and fan speed */
	uint8 temperature, fan_speed_percentage;
	STATE fan_state; /* Variable to store the state of the fan */

	/* ADC configuration structure */
	ADC_ConfigType ADC = {INTERNAL_2V,F_CPU_DIV_8};

	LCD_init(); 		/* initialize LCD driver */
	ADC_init(&ADC); 	/* initialize ADC driver */
	DcMotor_init(); 	/* initialize DcMotor driver */

	/* Display initial fan state and temperature on LCD */
	LCD_displaySringRowColumn("FAN is ", 0, 4);
	LCD_displaySringRowColumn("Temp =   C", 1, 4);

    while(1)
    {
    	/* Read ADC channe2 where the LM35 is connected */
    	temperature = LM35_getTemperature();

    	/* Determine fan state and speed based on temperature */
    	if (temperature < 30)
    	{
    		fan_state = OFF;			/* Fan off if temperature is below 30 */
    		fan_speed_percentage = 0;	/* Fan speed 0% Motor off*/
    	}
    	else if (temperature >= 30 && temperature < 60)
    	{
    		fan_state = ON;				/* Fan on if temperature is between 30 and 60 */
    		fan_speed_percentage = 25;	/* Fan speed 25% */
    	}
    	else if (temperature >= 60 && temperature < 90)
    	{
    		fan_state = ON;				/* Fan on if temperature is between 60 and 90 */
    		fan_speed_percentage = 50;	/* Fan speed 50% */
    	}
    	else if (temperature >= 90 && temperature < 120)
    	{
    		fan_state = ON;				/* Fan on if temperature is between 90 and 120 */
    		fan_speed_percentage = 75;	/* Fan speed 75% */
    	}
    	else
    	{
    		fan_state = ON;				/* Fan on if temperature is greater than 120 */
    		fan_speed_percentage = 100;	/* Fan speed 100% Max speed */
    	}

    	/* Update temperature display on LCD */
		LCD_moveCursor(1,10);

		/* Display temperature if 100 or above */
		if(temperature >= 100)
		{
			LCD_intgerToString(temperature);
		}

		/* Display temperature if below 100 */
		else
		{
			LCD_intgerToString(temperature);
			/* Clear next digit place if temperature is less than 3 digits */
			LCD_displayCharacter(' ');
		}

		/* Set fan rotation based on state and speed */
    	DcMotor_rotate(fan_state,fan_speed_percentage);


		/* Display the Fan state every time at same position */
		LCD_moveCursor(0,11);
		if(fan_state == ON)
		{
			LCD_displayString("ON");	/* Display 'ON' if fan is on */
			LCD_displayCharacter(' ');	/* Clear next character place */
		}
		else
		{
			LCD_displayString("OFF");	/* Display 'OFF' if fan is off */
		}
    }
}
