/*
 * EXTI_Pins.h
 *
 * Created: 8/8/2025 6:11:24 PM
 *  Author: GAGHL
 */ 

#ifndef GAGHL_AVR_EXTI_Pins_H_
#define GAGHL_AVR_EXTI_Pins_H_

/*
 * Group 1: Small ATmega (INT0, INT1 on PD2, PD3, INT2 on PB2)
 */
#if defined(__AVR_ATmega8__)  || defined(__AVR_ATmega8A__)   || \
    defined(__AVR_ATmega16__) || defined(__AVR_ATmega16A__)  || \
    defined(__AVR_ATmega32__) || defined(__AVR_ATmega32A__)  || \
    defined(__AVR_ATmega48__) || defined(__AVR_ATmega48P__)  || defined(__AVR_ATmega48PA__) || \
    defined(__AVR_ATmega88__) || defined(__AVR_ATmega88P__)  || defined(__AVR_ATmega88PA__) || \
    defined(__AVR_ATmega168__)|| defined(__AVR_ATmega168P__) || defined(__AVR_ATmega168PA__)|| \
    defined(__AVR_ATmega328__)|| defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328PB__)

    #define INT0_PORT   PORTD
    #define INT0_PIN    PIND
    #define INT0_DDR    DDRD
    #define INT0_BIT    PD2

    #define INT1_PORT   PORTD
    #define INT1_PIN    PIND
    #define INT1_DDR    DDRD
    #define INT1_BIT    PD3

    #define INT2_PORT   PORTB
    #define INT2_PIN    PINB
    #define INT2_DDR    DDRB
    #define INT2_BIT    PB2


/*
 * Group 2: Large ATmega (INT0..INT7 on PORTE)
 */
#elif defined(__AVR_ATmega64__)  || defined(__AVR_ATmega64A__)  || \
      defined(__AVR_ATmega128__) || defined(__AVR_ATmega128A__) || \
      defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || \
      defined(__AVR_ATmega1281__)|| defined(__AVR_ATmega2560__) || \
      defined(__AVR_ATmega2561__)|| defined(__AVR_ATmega2564__)

    #define INT0_PORT   PORTE
    #define INT0_PIN    PINE
    #define INT0_DDR    DDRE
    #define INT0_BIT    PE4

    #define INT1_PORT   PORTE
    #define INT1_PIN    PINE
    #define INT1_DDR    DDRE
    #define INT1_BIT    PE5

    #define INT2_PORT   PORTE
    #define INT2_PIN    PINE
    #define INT2_DDR    DDRE
    #define INT2_BIT    PE6

    #define INT3_PORT   PORTE
    #define INT3_PIN    PINE
    #define INT3_DDR    DDRE
    #define INT3_BIT    PE7

    #define INT4_PORT   PORTE
    #define INT4_PIN    PINE
    #define INT4_DDR    DDRE
    #define INT4_BIT    PE3

    #define INT5_PORT   PORTE
    #define INT5_PIN    PINE
    #define INT5_DDR    DDRE
    #define INT5_BIT    PE2

    #define INT6_PORT   PORTE
    #define INT6_PIN    PINE
    #define INT6_DDR    DDRE
    #define INT6_BIT    PE1

    #define INT7_PORT   PORTE
    #define INT7_PIN    PINE
    #define INT7_DDR    DDRE
    #define INT7_BIT    PE0


/*
 * Group 3: ATmega162 example (INT0..INT3 on PORTD)
 */
#elif defined(__AVR_ATmega162__)

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


/*
 * Default (unsupported)
 */
#else
    #error "MCU not supported in EXTI pin mapping header!"
#endif



#endif /* GAGHL_AVR_EXTI_Pins_H_ */