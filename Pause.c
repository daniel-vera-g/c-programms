/**
 * Daniel Vera Gilliard
 * TGJ 2/2
 * 12.10.18
 * Ein Lauflicht auf Port 0, das mindestens eine Pause benötigt -> Erweitert von Aufgabe 1
 */

#include <reg51.h>

// Position an der sich Lauflicht befindet
data int index;
// Counter für richtung
data int richtung;

// Werte initialisieren
void init()
{
	// anfang von Lauflicht
	index = 1;
}

// lauflicht links rum
void linksRum()
{
	// Lauflicht anzeigen
	P0 = index;
	// Lauflicht um eins nach Links verschieben
	index = index << 1;
}

// lauflicht rechts rum
void rechtsRum()
{
	// Lauflicht anzeigen
	P0 = index;
	// Lauflicht um eins nach rechts verschieben
	index = index >> 1;
}

// Schaut ob Schalter gedrückt oder nicht -> Return 1 || 0
int abfrage()
{
	if (P1 == 1)
	{
		// Gedrückt = Rechts rum
		return 1;
	}
	else
	{
		// Nicht gedrückt = Links rum
		return 0;
	}
}

// Schaut ob Lauflicht am ende angekommen je nach dem ob Links oder Rechts rum
// @param Richtung ob links oder rechts
void checkEnde(richt)
{

	if (richt == 1 && index == 0)
	{
		index = 128;
	}
	else if (richt == 0 && index > 128)
	{
		index = 1;
	}
}

/**
 * Pause die eine Warteschleife von:
 * 255 * 255 * 8MZ(int) = 520200µs = 0,5202s
 */
void pause()
{
	// Zählvariablen
	unsigned int i, y;
	for (i = 0; i < 255; i++)
	{

		for (y = 0; y < 255; y++)
		{
			/* code */
		}
	}
}

main()
{
	init();

	// endlosschleife
	while (1)
	{
		//Schalter abfragen(Polling) ob rechts oder links rrm
		int richtung = abfrage();

		// Rechts oder Linksrum aufrufen
		if (richtung == 1)
		{
			rechtsRum();
		}
		else
		{
			linksRum();
		}

		// Schaue ob ende erreicht
		checkEnde(richtung);
		pause();
	}
}
