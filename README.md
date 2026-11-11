# Firmware del ESC sensorless para motor BLDC

Firmware bare-metal en C para la LaunchPad **TI Tiva C TM4C123GXL** (TM4C123GH6PM) que controla la placa ESC de [BLDC-ESC-PCB](https://github.com/ManuelArgibay/BLDC-ESC-PCB): conmutación trifásica de los semipuentes mediante PWM, lectura de los cruces por cero de la BEMF y consigna de velocidad por potenciómetro.

Proyecto de la asignatura *Laboratori de Sistemes Electrònics I* (Grado en Ingeniería Electrónica de Telecomunicación, Universitat de Barcelona). En desarrollo.

## Estado actual

El código accede directamente a los registros del microcontrolador (sin TivaWare) y el micro funciona con el oscilador interno de 16 MHz, sin PLL. Ya funciona el control en lazo abierto: el Timer 1A, en modo periódico y con interrupción, recorre la secuencia de conmutación de seis pasos, y la frecuencia de conmutación y el duty del PWM son proporcionales a la lectura del potenciómetro, hasta 200 Hz eléctricos. Por debajo de un umbral del ADC el motor se considera parado y se apagan todas las salidas.

Los periféricos usados son el generador PWM0 a 32 kHz para las entradas de lado alto de los drivers, GPIO para las de lado bajo y el ADC0 (secuenciador SS3) sobre PE0/AIN3 para el potenciómetro. Faltan la rampa de arranque con alineación del rotor y el lazo cerrado sensorless con detección de los cruces por cero de la BEMF.

## Asignación de pines

| Señal | Pin | Uso |
|---|---|---|
| Fase A alto / bajo | PB5 / PD0 | PWM / GPIO hacia el IR2301 A |
| Fase B alto / bajo | PE4 / PB3 | PWM / GPIO hacia el IR2301 B |
| Fase C alto / bajo | PB7 / PF2 | PWM / GPIO hacia el IR2301 C |
| BEMF A / B / C | PD3 / PD2 / PD6 | Entradas desde el LM339 |
| Potenciómetro | PE0 (AIN3) | Consigna de velocidad |

## Cómo abrirlo

Es un proyecto de Code Composer Studio (versión basada en Theia, compilador TI Clang). Importalo con *File → Import Project* apuntando a esta carpeta; la configuración de depuración (`targetConfigs/`) usa el Stellaris In-Circuit Debug Interface de la LaunchPad.

## Autores

Manuel Argibay Molina y Max Pérez Piqué
