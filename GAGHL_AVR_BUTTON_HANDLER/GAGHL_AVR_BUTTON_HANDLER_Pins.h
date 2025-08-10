/*
 * GAGHL_AVR_BUTTON_HANDLER_Pins.h
 *
 * Created: 8/8/2025 6:11:24 PM
 *  Author: GAGHL
 */ 

#ifndef GAGHL_AVR_BUTTON_HANDLER_Pins_H_
#define GAGHL_AVR_BUTTON_HANDLER_Pins_H_


#if defined(__AVR_ATmega8__)   || defined(__AVR_ATmega8A__)   || \
	defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)

    #define INT0_PORT   PORTD
    #define INT0_PIN    PIND
    #define INT0_DDR    DDRD
    #define INT0_BIT    PD2

    #define INT1_PORT   PORTD
    #define INT1_PIN    PIND
    #define INT1_DDR    DDRD
    #define INT1_BIT    PD3

#elif defined(__AVR_ATmega16__) || defined(__AVR_ATmega16A__) || \
	  defined(__AVR_ATmega32__) || defined(__AVR_ATmega32A__)

    #define INT0_PORT   PORTD
    #define INT0_PIN    PIND
    #define INT0_DDR    DDRD
    #define INT0_BIT    PD2

    #define INT1_PORT   PORTD
    #define INT1_PIN    PIND
    #define INT1_DDR    DDRD
    #define INT1_BIT    PD3

/*
    #define INT2_PORT   PORTB
    #define INT2_PIN    PINB
    #define INT2_DDR    DDRB
    #define INT2_BIT    PB2
*/	
	
#elif defined(__AVR_ATmega64__)  || defined(__AVR_ATmega64A__)  || \
      defined(__AVR_ATmega128__) || defined(__AVR_ATmega128A__)
	
	/*
    #define INT0_PORT   PORTD
    #define INT0_PIN    PIND
    #define INT0_DDR    DDRD
    #define INT0_BIT    PD0

    #define INT1_PORT   PORTD
    #define INT1_PIN    PIND
    #define INT1_DDR    DDRD
    #define INT1_BIT    PD1

    #define INT2_PORT   PORTD
    #define INT2_PIN    PIND
    #define INT2_DDR    DDRD
    #define INT2_BIT    PD2

    #define INT3_PORT   PORTD
    #define INT3_PIN    PIND
    #define INT3_DDR    DDRD
    #define INT3_BIT    PD3
	*/

    #define INT4_PORT   PORTE
    #define INT4_PIN    PINE
    #define INT4_DDR    DDRE
    #define INT4_BIT    PE4

    #define INT5_PORT   PORTE
    #define INT5_PIN    PINE
    #define INT5_DDR    DDRE
    #define INT5_BIT    PE5

    #define INT6_PORT   PORTE
    #define INT6_PIN    PINE
    #define INT6_DDR    DDRE
    #define INT6_BIT    PE6

    #define INT7_PORT   PORTE
    #define INT7_PIN    PINE
    #define INT7_DDR    DDRE
    #define INT7_BIT    PE7


#elif defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)

    #define INT0_PORT   PORTD
    #define INT0_PIN    PIND
    #define INT0_DDR    DDRD
    #define INT0_BIT    PD0

    #define INT1_PORT   PORTD
    #define INT1_PIN    PIND
    #define INT1_DDR    DDRD
    #define INT1_BIT    PD1

    #define INT2_PORT   PORTD
    #define INT2_PIN    PIND
    #define INT2_DDR    DDRD
    #define INT2_BIT    PD2

    #define INT3_PORT   PORTD
    #define INT3_PIN    PIND
    #define INT3_DDR    DDRD
    #define INT3_BIT    PD3

    #define INT4_PORT   PORTE
    #define INT4_PIN    PINE
    #define INT4_DDR    DDRE
    #define INT4_BIT    PE4

    #define INT5_PORT   PORTE
    #define INT5_PIN    PINE
    #define INT5_DDR    DDRE
    #define INT5_BIT    PE5

    #define INT6_PORT   PORTE
    #define INT6_PIN    PINE
    #define INT6_DDR    DDRE
    #define INT6_BIT    PE6

    #define INT7_PORT   PORTE
    #define INT7_PIN    PINE
    #define INT7_DDR    DDRE
    #define INT7_BIT    PE7

/*
	Unsupported
*/
#else
    #error "MCU not supported in EXTI pin mapping header!"
#endif



#endif /* GAGHL_AVR_BUTTON_HANDLER_Pins_H_ */