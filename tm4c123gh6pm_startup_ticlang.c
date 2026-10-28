/******************************************************************************
 * tm4c123gh6pm_startup_ticlang.c - Startup para TM4C123GH6PM (TI Arm Clang)
 *
 * Contiene la tabla de vectores que el Cortex-M4 lee al arrancar:
 *   posición 0 -> valor inicial del stack pointer
 *   posición 1 -> dirección de la rutina de reset
 *   resto      -> rutinas de excepción e interrupciones
 *****************************************************************************/
#include <stdint.h>

void ResetISR(void);
static void NmiSR(void);
static void FaultISR(void);
static void IntDefaultHandler(void);

extern void _c_int00(void);     /* inicialización de C de TI: prepara variables y llama a main() */
extern uint32_t __STACK_END;    /* fin del stack, lo define el linker */

#define NUM_VECTORES 155        /* 16 del núcleo + 139 del TM4C123GH6PM */

__attribute__((section(".intvecs"), used))
void (* const g_pfnVectors[NUM_VECTORES])(void) =
{
    [0]  = (void (*)(void))((uint32_t)&__STACK_END), /* Stack pointer inicial */
    [1]  = ResetISR,            /* Reset */
    [2]  = NmiSR,               /* NMI */
    [3]  = FaultISR,            /* Hard fault */
    [4]  = IntDefaultHandler,   /* MPU fault */
    [5]  = IntDefaultHandler,   /* Bus fault */
    [6]  = IntDefaultHandler,   /* Usage fault */
    [11] = IntDefaultHandler,   /* SVCall */
    [12] = IntDefaultHandler,   /* Debug monitor */
    [14] = IntDefaultHandler,   /* PendSV */
    [15] = IntDefaultHandler,   /* SysTick */
    [16 ... NUM_VECTORES - 1] = IntDefaultHandler  /* Interrupciones de periféricos */
};

void ResetISR(void)
{
    _c_int00();                 /* también habilita la FPU */
}

/* Si al pausar el debugger te encuentras en alguna de estas, el micro ha fallado */
static void NmiSR(void)             { while (1); }
static void FaultISR(void)          { while (1); }
static void IntDefaultHandler(void) { while (1); }
