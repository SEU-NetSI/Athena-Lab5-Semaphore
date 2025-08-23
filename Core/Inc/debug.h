#include <stdint.h> 
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <usart.h>

typedef int (*putc_t)(int c);

int evprintf(putc_t putcf, const char * fmt, va_list ap);
int eprintf(putc_t putcf, const char * fmt, ...);
int uartPutchar(int ch);

uint8_t UART1_Receive();
void UART1_Transmit(uint8_t *data, uint32_t length);
#define DEBUG_PRINTF(fmt, ...) consolePrintf(fmt, ##__VA_ARGS__)
#define consolePrintf(FMT, ...) eprintf(uartPutchar, FMT, ## __VA_ARGS__)
