//LED CONNECTION IS ON
//port:A
//pin:5

#define PERIPH_BASE 			(0x40000000UL)
#define AHB2PERIPH_OFFSET   	(0x08000000UL)
#define AHB2PERIPH_BASE     	(PERIPH_BASE + AHB2PERIPH_OFFSET)
#define GPIOA_OFFSET 			(0X0000UL)  //0X 0000 0000


#define GPIOA_BASE 				(AHB2PERIPH_BASE + GPIOA_OFFSET)


#define AHB1PERIPH_OFFSET 		(0x00020000UL)
#define AHB1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET) //RCC IS ON AHB1 (You have to enable the bus first)


#define RCC_OFFSET 				(0x00001000UL)
#define RCC_BASE 	 	 		(AHB1PERIPH_BASE + RCC_OFFSET)


#define AHB2EN_R_OFFSET			(0x4CUL)
#define AHB2EN_R_BASE 			(*(volatile unsigned int *)(RCC_BASE + AHB2EN_R_OFFSET))


#define MODE_R_OFFSET			(0x00UL)
#define GPIOA_MODE_R  			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))


#define OD_R_OFFSET    			(0x14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))


#define GPIOAEN					(1U<<0)


#define PIN5					(1U<<5)
#define LED_PIN					(PIN5)



typedef struct{

}GPIO_TypeDef;


int main(void)
{
	/*1. Enable clock access to GPIOA */
	AHB2EN_R_BASE |= GPIOAEN;

	/*2. set PA5 as output pin*/
	GPIOA_MODE_R |= (1U<<10);
	GPIOA_MODE_R &=~(1U<<11);

	while(1){
		/*set PA5 high*/
		//GPIOA_OD_R |= LED_PIN;

		/*toggle led*/
		GPIOA_OD_R ^= LED_PIN;

		for(int i=0; i<100000;i++);
	}



}




