# NeoPlay
* DPTP System - NeoPlay -> Object oriented code for STM32
* title:		main program, VGM Player (Neo Geo)
* autor:		DPTP System - Tóth Péter
* pcb created:	2020.07.07.
* date:			2024.02.01.
* email:		don_peter[kukac]freemail[pont]hu
* device:		Special adapter and develop device
* platform:		STM32CubeMX, STM32CubeIDE, C Code
* MCU:			STM32F407ZET6
* spec.:		RAM：192K
*				FLASH：512K
*				Frequence：168MHz
* spec. ICs:	YM2610, YM3016D, RC4558D, LM4880D, JRC2066D or NJM2066D

# Leírás
Egy már évek óta dédelgetett álom, amelynek már többedjére fogok neki, de sajnos az időhiány és más projektek priorítása késlelteti a kivitelezést. Az eszköz illetve egy prototíps
PCB már 2020-ban elkészült, amely arra vár, hogy a fejlesztőpanel segítségével feléledjen. Az eszköz, ha elkészül és nem becsültem alá az erőforásokat, akkor a 90'-es évekből 
amolyan retro játékzenéket lejátszó eszköz lesz, amelyhez hasonlót már korábban bemutattam, annyi külömbséggel, hogy a mostani hardver a Neo Geo eredeti hangproceszorát foglya megszólaltatni.
Nem kis feladat lesz a megfelelő fejlesztés, de remélem a korábbi tapasztalatok, amelyeket a hasonló SEGA-s projekteknél hazsnáltam segítenek, hogy sikerrel járjak.

# Folyamat
A projekt lassan halladva fog felépülni, elsőnek csak egy alap programot készítek el, amely hibamentesen fordúl és készen álnak a szükséges perifériák felkonfigurálva.
Ezt követően készítem el a szükséges drivereket, amelyek már majd a speciális IC-ket kezelik, majd ezek után írom meg a VGM zene lejátszáshoz szükséges feldolgozó struktúrát.
Reményeim szerint talán még ebben az évben megszólalhat az eszköz.

# Projekt haladás
* 2024.02.01. - alap dokumentációk összekészítése (újra)

# Cél
Neo Geo arcade vagy másként játéktermi játék zenéinek eredeti, de speciális egyedi hardveren történő lejátszása.
További célok, hogy a következő komponesek, perifériák elérhetőek legyenk: USB, SPI memória, SD kártya, I2C, OLED kijelzés
