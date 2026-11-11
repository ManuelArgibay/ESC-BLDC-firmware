
#include <stdint.h>

//System definitions
#define SYSCTL_RCGCGPIO *((volatile uint32_t *) 0x400FE608) //permite activar /desactivar los modulos GPIO del Run mode
#define SYSCTL_PRGPIO *((volatile uint32_t *) 0x400FEA08) //indica cuando los modulos estaran listos para ser accedidos por el SW
#define SYSCTL_RCC *((volatile uint32_t *) 0x400FE060) //este registro controla el clock cuando estamos en run mode
#define SYSCTL_RCGCPWM *((volatile uint32_t *) 0x400FE640) //registro para activar el clock control para los puertos que tendran PWM
#define SYSCTL_PRPWM *((volatile uint32_t *) 0x400FEA40)  //este registro indica cuando los puertos estaran listos para ser configurados como PWM
#define NVIC_EN0 *((volatile uint32_t *) 0xE000E100)  // habilita interrupciones 0-31 en el NVIC

// PUERTOS

//Port B
#define GPIOB_DIR *((volatile uint32_t *) 0x40005400)   //dirección pines (Puerto B)
#define GPIOB_DATA *((volatile uint32_t *) 0x400053FC)  //registro de datos (Puerto B). Offset 0x3FC: con 0x000 la máscara de dirección es 0 y no se accede a ningún bit
#define GPIOB_AFSEL *((volatile uint32_t *) 0x40005420) //selección de función alternativa (Puerto B)
#define GPIOB_DEN  *((volatile uint32_t *) 0x4000551C) //registro de digital Enable (Puerto B)
#define GPIOB_AMSEL *((volatile uint32_t *) 0x40005528) //registro función analógica (Puerto B)
#define GPIOB_PCTL *((volatile uint32_t *) 0x4000552C)  //registro para seleccionar función PWM (Puerto B)

//Port D
#define GPIOD_DIR *((volatile uint32_t *) 0x40007400)   //dirección pines (Puerto D)
#define GPIOD_DATA *((volatile uint32_t *) 0x400073FC)  //registro de datos (Puerto D). Offset 0x3FC: con 0x000 la máscara de dirección es 0 y no se accede a ningún bit
#define GPIOD_AFSEL *((volatile uint32_t *) 0x40007420) //selección de función alternativa (Puerto D)
#define GPIOD_DEN   *((volatile uint32_t *) 0x4000751C) //registro de digital Enable (Puerto D)
#define GPIOD_AMSEL *((volatile uint32_t *) 0x40007528) //registro función analógica (Puerto D)
#define GPIOD_PCTL *((volatile uint32_t *) 0x4000752C)  //registro para seleccionar función PWM (Puerto D)

//Port E
#define GPIOE_DIR *((volatile uint32_t *) 0x40024400)   //dirección pines (Puerto E)
#define GPIOE_DATA *((volatile uint32_t *) 0x400243FC)  //registro de datos (Puerto E). Offset 0x3FC: con 0x000 la máscara de dirección es 0 y no se accede a ningún bit
#define GPIOE_AFSEL *((volatile uint32_t *) 0x40024420) //selección de función alternativa (Puerto E)
#define GPIOE_DEN   *((volatile uint32_t *) 0x4002451C) //registro de digital Enable (Puerto E)
#define GPIOE_AMSEL *((volatile uint32_t *) 0x40024528) //registro función analógica (Puerto E)
#define GPIOE_PCTL *((volatile uint32_t *) 0x4002452C)  //registro para seleccionar función PWM (Puerto E)

//Port F
#define GPIOF_DIR *((volatile uint32_t *) 0x40025400)   //dirección pines (Puerto F)
#define GPIOF_DATA *((volatile uint32_t *) 0x400253FC)  //registro de datos (Puerto F). Offset 0x3FC: con 0x000 la máscara de dirección es 0 y no se accede a ningún bit
#define GPIOF_AFSEL *((volatile uint32_t *) 0x40025420) //selección de función alternativa (Puerto F)
#define GPIOF_DEN   *((volatile uint32_t *) 0x4002551C) //registro de digital Enable (Puerto F)
#define GPIOF_AMSEL *((volatile uint32_t *) 0x40025528) //registro función analógica (Puerto F)
#define GPIOF_PCTL *((volatile uint32_t *) 0x4002552C)  //registro para seleccionar función PWM (Puerto F)


// PWM

#define RCGC0 *((volatile uint32_t *) 0x400FE100)
#define RCGC2 *((volatile uint32_t *) 0x400FE108)
#define PWMENABLE *((volatile uint32_t *) 0x40028008)

// PWM0 -> PB7 (M0PWM1)
#define PWM0CTL *((volatile uint32_t *) 0x40028040)
#define PWM0LOAD *((volatile uint32_t *) 0x40028050)
#define PWM0GENB *((volatile uint32_t*) 0x40028064)
#define PWM0CMPA *((volatile uint32_t*) 0x40028058)

// PWM1 -> PB5 (M0PWM3)
#define PWM1CTL *((volatile uint32_t *) 0x40028080)
#define PWM1LOAD *((volatile uint32_t *) 0x40028090)
#define PWM1GENB *((volatile uint32_t*) 0x400280A4)
#define PWM1CMPA *((volatile uint32_t*) 0x40028098)

// PWM2 -> PE4 (M0PWM4)
#define PWM2CTL *((volatile uint32_t *) 0x400280C0)
#define PWM2LOAD *((volatile uint32_t *) 0x400280D0)
#define PWM2GENA *((volatile uint32_t*) 0x400280E0)
#define PWM2CMPA *((volatile uint32_t*) 0x400280D8)


//ADC

// ADC init
#define PE0 0x01 //ADC
#define SYSCTL_RCGCADC *(volatile uint32_t*) 0x400FE638  // Enable/disable ADC modules from Run Mode
#define SYSCTL_PRADC *(volatile uint32_t*)   0x400FEA38  // Indica cuando los modulos ADC estan ready para ser leidos por el software
#define ADC0_ACTSS   *(volatile uint32_t*)   0x40038000
#define ADC0_EMUX    *(volatile uint32_t*)    0x40038014
#define ADC0_SSMUX3  *(volatile uint32_t*)    0x400380A0
#define ADC0_SSCTL3  *(volatile uint32_t*)    0x400380A4
#define ADC0_ISC     *(volatile uint32_t*)    0x4003800C //limpia (clear) las instrucciones pendientes	

//ADC conversion
#define ADC0_PSSI    (*(volatile uint32_t *)0x40038028)  //inicio de conversion
#define ADC0_RIS     (*(volatile uint32_t *)0x40038004)  //interrupt status. sirve para indicar cuando ha finalizado la conversión
#define ADC0_SSFIFO3 (*(volatile uint32_t *)0x400380A8)  //guarda el resultado de la conversion


// TIMERS

#define RCGCTIMER *((volatile uint32_t *) 0x400FE604) //permite activar /desactivar los modulos GPIO del Run mode
#define PRTIMER *((volatile uint32_t *) 0x400FEA04) //permite activar /desactivar los modulos GPIO del Run mode

// Timer 0A
#define GPTMCFG0 (*(volatile uint32_t *)0x40030000)
#define GPTMTAMR0 (*(volatile uint32_t *)0x40030004)
#define GPTMCTL0 (*(volatile uint32_t *)0x4003000C)
#define GPTMIMR0 (*(volatile uint32_t *)0x40030018)
#define GPTMRIS0 (*(volatile uint32_t *)0x4003001C)
#define GPTMICR0 (*(volatile uint32_t *)0x40030024)
#define GPTMTAILR0 (*(volatile uint32_t *)0x40030028)

// Timer 1A
#define GPTMCFG1 (*(volatile uint32_t *)0x40031000)
#define GPTMTAMR1 (*(volatile uint32_t *)0x40031004)
#define GPTMCTL1 (*(volatile uint32_t *)0x4003100C)
#define GPTMIMR1 (*(volatile uint32_t *)0x40031018)
#define GPTMRIS1 (*(volatile uint32_t *)0x4003101C)
#define GPTMICR1 (*(volatile uint32_t *)0x40031024)
#define GPTMTAILR1 (*(volatile uint32_t *)0x40031028)


// definimos los pines que mas usaremos
#define PB5 0x20 //High Phase A
#define PE4 0x10 //High Phase B	
#define PB7 0x80 //High Phase C

#define PD0 0x01 //Low Phase A
#define PB3 0x08 //Low Phase B
#define PF2 0x04 //Low Phase C

#define PD2 0x04 //BEMF Phase B
#define PD3 0x08 //BEMF Phase A
#define PD6 0x40 //BEMF Phase C

volatile uint16_t adc_valor = 0;
volatile uint8_t indice_fase = 0;

void initSys(void)
{

	//Activamos el Run Mode para los puertos B, D, E, F (los que tendran el PWM que commutara)
	//Bits: A=0x01, B=0x02, C=0x04, D=0x08, E=0x10, F=0x20 -> B|D|E|F = 0x3A
	SYSCTL_RCGCGPIO |= 0x3A;

	//Para poder proseguir, hay que asegurarnos que los puertos estan armados (Ready) -> se lee PRGPIO, no RCGCGPIO
	while ((SYSCTL_PRGPIO & 0x3A) != 0x3A);

	//Activamos el modulo PWM0 (PB5 = M0PWM3, PB7 = M0PWM1, PE4 = M0PWM4 -> todos en el modulo 0)
	//Bits de RCGCPWM: PWM0 = 0x01, PWM1 = 0x02
	SYSCTL_RCGCPWM |= 0x01;

	//Para poder proseguir, hay que asegurarnos que el modulo PWM0 esta armado (Ready)
	while ((SYSCTL_PRPWM & 0x01) == 0);

}

void initGPIOs(void)
{
	//Seleccionamos si cada pin funciona como GPIO (AFSEL = 0) o lo controla un periférico (AFSEL = 1)
	GPIOD_AFSEL &= ~(PD0);              //GPIO: low-side fase A
	GPIOB_AFSEL &= ~(PB3);              //GPIO: low-side fase B
	GPIOF_AFSEL &= ~(PF2);              //GPIO: low-side fase C
	GPIOD_AFSEL &= ~(PD2 | PD3 | PD6);  //GPIO: entradas BEMF (PD3 = A, PD2 = B, PD6 = C)
	GPIOB_AFSEL |= PB5;                 //Periférico (PWM): high-side fase A
	GPIOE_AFSEL |= PE4;                 //Periférico (PWM): high-side fase B
	GPIOB_AFSEL |= PB7;                 //Periférico (PWM): high-side fase C

	//Desactivamos la función analógica en los pines que usamos como digitales
	GPIOB_AMSEL &= ~(PB5 | PB7 | PB3);  //PB5, PB7 y PB3
	GPIOD_AMSEL &= ~(PD0);              //PD0
	GPIOE_AMSEL &= ~(PE4);              //PE4
	GPIOF_AMSEL &= ~(PF2);              //PF2

	//En el Port Control (PCTL) seleccionamos la función alternativa de los pines de PWM (valor 4 = M0PWMx).
	//Los pines GPIO (PB3, PD0, PF2, PD2, PD3, PD6) se quedan con PCTL = 0, que es su valor de reset
	GPIOB_PCTL = (GPIOB_PCTL & 0xFF0FFFFF) | 0x00400000; //PB5 -> M0PWM3
	GPIOB_PCTL = (GPIOB_PCTL & 0x0FFFFFFF) | 0x40000000; //PB7 -> M0PWM1
	GPIOE_PCTL = (GPIOE_PCTL & 0xFFF0FFFF) | 0x00040000; //PE4 -> M0PWM4

	//Habilitamos la función digital (sin DEN = 1 las salidas no actúan y las entradas siempre leen 0)
	GPIOB_DEN |= (PB5 | PB7 | PB3);
	GPIOD_DEN |= (PD0 | PD2 | PD3 | PD6);
	GPIOE_DEN |= PE4;
	GPIOF_DEN |= PF2;

	//Estado inicial conocido: todas las salidas a nivel bajo antes de configurarlas como salida
	GPIOB_DATA &= ~(PB5 | PB7 | PB3);   //PB5, PB7 y PB3
	GPIOD_DATA &= ~(PD0);               //PD0
	GPIOE_DATA &= ~(PE4);               //PE4
	GPIOF_DATA &= ~(PF2);               //PF2

	//Dirección de los pines (en los pines con AFSEL = 1 la controla el periférico)
	GPIOB_DIR |= (PB5 | PB7 | PB3);     //Salidas: PB5, PB7 y PB3
	GPIOD_DIR |= (PD0);                 //Salida: PD0
	GPIOD_DIR &= ~(PD2 | PD3 | PD6);    //Entradas: PD2, PD3 y PD6 (BEMF)
	GPIOE_DIR |= (PE4);                 //Salida: PE4
	GPIOF_DIR |= (PF2);                 //Salida: PF2
}

// Inicialización del timer 0 -> Delays
void initTimer0(void)
{
	RCGCTIMER |= 0x00000001; // Habilito el reloj en el timer 0

	//Para poder proseguir, hay que asegurarnos que los puertos estan armados (Ready) -> se lee PRGPIO, no RCGCGPIO
	while ((PRTIMER & 0x01) != 0x01);

	GPTMCTL0 &= ~(0x00000001); // Deshabilito el timer para configurarlo (requerimiento de fabricante)
	GPTMCFG0 &= 0xFFFFFFF8; // Timer de 32 bits
	GPTMTAMR0 = (GPTMTAMR0 & 0xFFFFFFFC) | 0x00000002; // Modo de timer periódico
	GPTMTAILR0 = 0x00000010; // LOAD = 16 -> Clock de 16MHz a 16 cuentas => delayMicro(microsegundos) 
	GPTMIMR0 |= 0x00000001; // Habilito interrupciones
	NVIC_EN0 = (1 << 19); // Habilito la interrupción 19 (Timer 0A) en el NVIC
	// Probablemente sea mejor activarlo en la funcion delay(), por lo que ahora solo realizo la inicialización
	// GPTMCTL0 |= 0x00000001; // Habilito el timer
}

// Inicialización del timer 1 -> Open-loop del BLDC
void initTimer1(void)
{
	RCGCTIMER |= 0x00000002; // Habilito el reloj en el timer 1

	//Para poder proseguir, hay que asegurarnos que los puertos estan armados (Ready) -> se lee PRGPIO, no RCGCGPIO
	while ((PRTIMER & 0x02) != 0x02);

	GPTMCTL1 &= ~(0x00000001); // Deshabilito el timer para configurarlo (requerimiento de fabricante)
	GPTMCFG1 &= 0xFFFFFFF8; // Timer de 32 bits
	GPTMTAMR1 = (GPTMTAMR1 & 0xFFFFFFFC) | 0x00000002; // Modo de timer periódico
	GPTMTAILR1 = 0x000019C8; // 6600 clocks, es decir velocidad al 50% (suponiendo velocidad máxima de 200Hz, y como son 6 ciclos es 1200Hz, que serían unos 13200 clocks a 16MHz) 
	GPTMIMR1 |= 0x00000001; // Habilito interrupciones
	NVIC_EN0 = (1 << 21); // Habilito la interrupción 21 (Timer 1A) en el NVIC
	GPTMCTL1 |= 0x00000001; // Habilito el timer
}


void initPWM(void)
{
	/*RCGC0 |= 0x00100000;
	RCGC2 |= 0x00000012;*/

	//PWM0 -> PB7(PWM0 GENB)
	PWM0CTL &= 0xFFFFFFFD; // Modo Count-Down
	PWM0GENB |= 0x0000008C; //PWM1 utiliza el generador B
	PWM0LOAD = (PWM0LOAD & 0xFFFF0000) | 0x000001F3; // Definido un LOAD de 499 para un PWM de 32kHz -> 16MHz / 32kHz - 1 = 499
	PWM0CTL |= 0x00000001;  // Comienza a funcionar el PWM0

	// PWM1 PB5(PWM1 GENB)
	PWM1CTL &= 0xFFFFFFFD; // Modo Count-Down
	PWM1GENB |= 0x0000008C; //PWM3 utiliza el generador B
	PWM1LOAD = (PWM1LOAD & 0xFFFF0000) | 0x000001F3; // Definido un LOAD de 499 para un PWM de 32kHz -> 16MHz / 32kHz - 1 = 499
	PWM1CTL |= 0x00000001;  // Comienza a funcionar el PWM1
	
	// PWM2 -> PE4(PWM2 GENA)
	PWM2CTL &= 0xFFFFFFFD; // Modo Count-Down
	PWM2GENA |= 0x0000008C; //PWM4 utiliza el generador A
	PWM2LOAD = (PWM2LOAD & 0xFFFF0000) | 0x000001F3; // Definido un LOAD de 499 para un PWM de 32kHz -> 16MHz / 32kHz - 1 = 499
	PWM2CTL |= 0x00000001;  // Comienza a funcionar el PWM2
}

void setPWMLoad(uint32_t adc)
{
	
	if (adc >= 4000) 
	{
		adc = 4000; // Damos un poco de rango para no llegar a duty de 100% y descargar capacidad de bootstrap (duty_max ≈ 98%)
	} else if(adc <= 100)
	{
		adc = 0;  // Damos un par de rango para no llegar a duty de 0% y descargar capacidad de bootstrap (duty_max ≈ 2.5%)
	}
	
	uint32_t duty = (adc * 100) >> 12;

	if(duty != 0){
		uint32_t comparador = 499 - 499 * duty / 100; // Este es el valor del comparador
		PWM0CMPA = (PWM0CMPA & 0xFFFF0000) | comparador; // duty = 0.5 en PB7
		PWM1CMPA = (PWM1CMPA & 0xFFFF0000) | comparador; // duty = 0.5 en PB5
		PWM2CMPA = (PWM2CMPA & 0xFFFF0000) | comparador; // duty = 0.5 en PE4
	}

}


void highA(void)
{	
	PWMENABLE &= ~(0x0000001A); // Desactivo todos los PWM -> PE4 = M0PWM4 = 0x00000010, PB5 = M0PWM3 = 0x00000008, PB7 = M0PWM1 = 0x00000002.
	PWMENABLE |= 0x00000008; // PB5 = M0PWM3 = 0x00000008
}

void highB(void)
{	
	PWMENABLE &= ~(0x0000001A); // Desactivo todos los PWM -> PE4 = M0PWM4 = 0x00000010, PB5 = M0PWM3 = 0x00000008, PB7 = M0PWM1 = 0x00000002.
	PWMENABLE |= 0x00000010; // PE4 = M0PWM4 = 0x00000010
}

void highC(void)
{	
	PWMENABLE &= ~(0x0000001A); // Desactivo todos los PWM -> PE4 = M0PWM4 = 0x00000010, PB5 = M0PWM3 = 0x00000008, PB7 = M0PWM1 = 0x00000002.
	PWMENABLE |= 0x00000002; // PB7 = M0PWM1 = 0x00000002.
}

void lowA(void)
{
	GPIOB_DATA &= ~(PB3);   // Desactivo Fase B (PB3)
	GPIOF_DATA &= ~(PF2);   // Desactivo Fase C (PF2)
	GPIOD_DATA |= PD0;      // Activo Fase A (PD0)
}

void lowB(void)
{
	GPIOF_DATA &= ~(PF2);   // Desactivo Fase C (PF2)
	GPIOD_DATA &= ~(PD0);   // Desactivo Fase A (PD0)
	GPIOB_DATA |= PB3;      // Activo Fase B (PB3)
}

void lowC(void)
{
	GPIOB_DATA &= ~(PB3);   // Desactivo Fase B (PB3)
	GPIOD_DATA &= ~(PD0);   // Desactivo Fase A (PD0)
	GPIOF_DATA |= PF2;      // Activo Fase C (PF2)
}

void allOff(void){
	GPIOD_DATA &= ~(PD0);   // Desactivo Fase A (PD0)
	GPIOB_DATA &= ~(PB3);   // Desactivo Fase B (PB3)
	GPIOF_DATA &= ~(PF2);   // Desactivo Fase C (PF2)
	PWMENABLE &= ~(0x0000001A); // Desactivo todos los PWM -> PE4 = M0PWM4 = 0x00000010, PB5 = M0PWM3 = 0x00000008, PB7 = M0PWM1 = 0x00000002.
}



void initADC(void)
{
	SYSCTL_RCGCADC	|=	 0x01; //habilitamos el reloj del puerto E, donde esta el pin PE0 (Run mode)
	SYSCTL_RCGCGPIO |=   0x10; //habilitamos el reloj del ADC (Run mode)

    while ((SYSCTL_PRGPIO & 0x10) == 0);  //Esperamos a que el reloj del ADC este ready
    while ((SYSCTL_PRADC  & 0x01	) == 0);  //Esperamos a que el reloj del puerto E este ready

	//Inicializamos GPIO para el ADC
	GPIOE_DIR &= ~(PE0);
    GPIOE_AFSEL |=  PE0;
    GPIOE_DEN &= ~PE0;
    GPIOE_AMSEL |=  PE0;

	// Configurar el sample sequencer (SS3)

    ADC0_ACTSS &= ~0x08;       // Desactivamos el SS3. Para programar el ADC, debe estar desactivado. Esto previene ejecucion erronea durante configuracion
    ADC0_EMUX  &= ~0xF000;     // trigger event para el SS3
    ADC0_SSMUX3 = 0x03;        // configuramos el input de nuestro ADC (en nuestro caso, es el PE0, que corresponde al AIN3)
    ADC0_SSCTL3 = 0x06;        // configuramos los bits the nibble correspondientes a la muesta
    ADC0_ISC = 0x08;            // Limpiamos las flags que pueden haber pendientes
    ADC0_ACTSS |= 0x08;        // Una vez configurado, podemos habilitar SS3
	
}

uint32_t leerADC(void)
{
	ADC0_PSSI = 0x08;			//iniciamos la conversion

    while ((ADC0_RIS & 0x08) == 0);	//esperamos a que termine la conversion

    volatile uint32_t valor = ADC0_SSFIFO3 & 0xFFF;	//guardamos el valor de 12 bits guardado en el registro SS3

    ADC0_ISC = 0x08;	

    return valor;
}

void setTimerLoad(uint32_t adc)
{	
	// Como el valor de clocks tiene que ser inversamente proporcional al valor del ADC, establecemos la ecuación CLKS = K / ADC,
	// y para calcular el valor de K establecemos la condición que conocemos -> a velocidad máxima
	// A velocidad máxima (cuando el ADC vale 4095) el motor gira alrededor de 200Hz, por lo que los ciclos irían a 1200Hz
	// A partir de un clock de 16MHz, para tener una frecuencia de 1200Hz se necesita
	// K = ADC * CLKS = 16000000 * 4095 / 1200 = 54600000
	if(adc >= 4000)
	{
		adc = 4000;
	}
	else if(adc <= 100)
	{
		adc = 0;
	}

	if(adc == 0)
	{
		GPTMTAILR1 = 0x00F42400; // Vuelve a revisar cada un segundo si se arranca el motor
	} else
	{
		uint32_t clocks = 54600000 / adc; 
		GPTMTAILR1 = clocks;
	}
	
}

int main(void)
{

	initSys();
	initGPIOs();
	initPWM();
	initADC();
	initTimer0();
	initTimer1();

	while(1)
	{
		adc_valor = leerADC();
		setPWMLoad(adc_valor);
		
	}
	
	return 0;
}


// INTERRUPCIONES

void Timer0AHandler (void){

}

void Timer1AHandler (void){

	setTimerLoad(adc_valor);
	
	if(adc_valor <= 100)
	{
		allOff();
	} else
	{
		switch (indice_fase) 
		{
			case 0:
				highA();
				lowB();
				indice_fase += 1;
				break;

			case 1:
				highA();
				lowC();
				indice_fase += 1;
				break;

			case 2:
				highB();
				lowC();
				indice_fase += 1;
				break;

			case 3:
				highB();
				lowA();
				indice_fase += 1;
				break;

			case 4:
				highC();
				lowA();
				indice_fase += 1;
				break;

			case 5:
				highC();
				lowB();
				indice_fase = 0;
				break;

			default:
				highC();
				lowB();
				indice_fase = 0;
				break;
		}
	}

	GPTMICR1 = 0x00000001;

}