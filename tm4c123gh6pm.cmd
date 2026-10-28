/******************************************************************************
 * tm4c123gh6pm.cmd - Linker command file para TM4C123GH6PM (TI Arm Clang)
 * Le dice al linker dónde está la flash (256 KB) y la SRAM (32 KB).
 *****************************************************************************/

--retain=g_pfnVectors      /* que el linker no elimine la tabla de vectores */
--stack_size=2048

MEMORY
{
    FLASH (RX)  : origin = 0x00000000, length = 0x00040000
    SRAM  (RWX) : origin = 0x20000000, length = 0x00008000
}

SECTIONS
{
    .intvecs    : > 0x00000000      /* tabla de vectores al principio de la flash */
    .text       : > FLASH
    .rodata     : > FLASH
    .const      : > FLASH
    .cinit      : > FLASH
    .pinit      : > FLASH
    .init_array : > FLASH
    .ARM.exidx  : > FLASH

    .vtable     : > 0x20000000
    .data       : > SRAM
    .bss        : > SRAM
    .sysmem     : > SRAM
    .stack      : > SRAM (HIGH)
}
