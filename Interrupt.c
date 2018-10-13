/**
 * Daniel Vera Gilliard
 * TGJ 2/2
 * 12.10.18
 * Interrupt 0 erhöht Anzeige auf einer 7-Segmentanzeige an Port 0
 * *****ACHTUNG***** 7-Seg reagiert auf HIGH Pegel(1)
 */

#include <reg51.h>

// Pointer für die Tabelle
data int i;

// Pointer auf erste Stelle in Tabelle
int i = 0;

// Tabelle mit 7-Seg werten(binär encoded)
code unsigned char tabelle[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

// Interrupt 0 & ISR 0
void ex0_isr(void) interrupt 0
{
	// Erhöhe pointer in Tabelle
	i = i + 1;
	// Check ob ende Tabelle angekommen
	if (i > 9)
	{
		i = 0;
	}
}

void main()
{
	// Interrupt setup
	EX0 = 1;
	IT0 = 1;
	EA = 1;

	// Endlosschleife
	while (1)
	{
		// 7-seg mit Muster an stelle des Pointers anzeigen
		P0 = tabelle[i];
	}
}
