# Firmware del ESC sensorless para motor BLDC

Firmware bare-metal en C para la LaunchPad **TI Tiva C TM4C123GXL** (TM4C123GH6PM) que controla la placa ESC de [BLDC-ESC-PCB](https://github.com/ManuelArgibay/BLDC-ESC-PCB): conmutación trifásica de los semipuentes mediante PWM, lectura de los cruces por cero de la BEMF y consigna de velocidad por potenciómetro.

Proyecto de la asignatura *Laboratori de Sistemes Electrònics I* (Grado en Ingeniería Electrónica de Telecomunicación, Universitat de Barcelona). En desarrollo.

## Estado actual

El código accede directamente a los registros del microcontrolador (sin TivaWare) y por ahora incluye la inicialización de relojes y GPIO, el generador PWM0 a 32 kHz para las entradas de lado alto de los drivers y el ADC0 (secuenciador SS3) sobre PE0/AIN3 para el potenciómetro. Falta la secuencia de conmutación de seis pasos y el lazo sensorless.

## Asignación de pines

| Señal | Pin | Uso |
|---|---|---|
| Fase A alto / bajo | PB5 / PD0 | PWM / GPIO hacia el IR2301 A |
| Fase B alto / bajo | PE4 / PB3 | PWM / GPIO hacia el IR2301 B |
| Fase C alto / bajo | PB7 / PF2 | PWM / GPIO hacia el IR2301 C |
| BEMF A / B / C | PD2 / PD3 / PD6 | Entradas desde el LM339 |
| Potenciómetro | PE0 (AIN3) | Consigna de velocidad |

## Cómo abrirlo

Es un proyecto de Code Composer Studio (versión basada en Theia, compilador TI Clang). Importalo con *File → Import Project* apuntando a esta carpeta; la configuración de depuración (`targetConfigs/`) usa el Stellaris In-Circuit Debug Interface de la LaunchPad.

## Autores

Manuel Argibay Molina y Max Pérez Piqué
