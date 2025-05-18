
#ifndef UART_H
#define UART_H

// estrucutra que define a los distintos uarts
typedef struct
{

	volatile uint8_t UCSRA;
	volatile uint8_t UCSRB;
	volatile uint8_t UCSRC;
	volatile uint8_t resb;
	volatile uint16_t UBRR;
	volatile uint8_t UDR;

} UART_reg_t;

/*
para poder acceder a ;ps registros

*/

extern uint8_t *UART_offset[];

// Prototypes
// Initialization

UART_Ini(uint8_t com, uint32_t baudrate, uint8_t size, uint8_t parity, uint8_t stop);

uint16_t set_UBRR(uint32_t baudrate);

// Send
void UART_puts(uint8_t com, char *str);
void UART_putchar(uint8_t com, char data);

// Received*/
uint8_t UART_available(uint8_t com);
char UART_getchar(uint8_t com);
void UART_gets(uint8_t com, char *str);

// Escape sequences
UART_clrscr(uint8_t com);
UART_setColor(uint8_t com, uint8_t color);
UART_gotoxy(uint8_t com, uint8_t x, uint8_t y);

#define YELLOW 33 // Fixme
#define GREEN 32  // Fixme
#define BLUE 34	  // Fixme

// Utils
void itoa(uint16_t number, char *str, uint8_t base);
uint16_t atoi(char *str);

void UART_putnum(uint8_t com, uint8_t num);

#endif
