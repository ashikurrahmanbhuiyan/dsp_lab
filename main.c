
	#define RCC_BASE         0x40021000
	#define GPIOC_BASE       0x40011000
	#define SysTick_BASE     0xE000E010
	#define RCC_APB2ENR      (*((volatile unsigned long *) (RCC_BASE + 0x18)))
	#define GPIOC_CRH        (*((volatile unsigned long *) (GPIOC_BASE + 0x04)))
	#define GPIOC_ODR        (*((volatile unsigned long *) (GPIOC_BASE + 0x0C)))
	#define SysTick_CTRL     (*((volatile unsigned long *) (SysTick_BASE + 0x00)))
	#define SysTick_LOAD     (*((volatile unsigned long *) (SysTick_BASE + 0x04)))
	#define SysTick_VAL      (*((volatile unsigned long *) (SysTick_BASE + 0x08)))


	void systik_init();
	void DelayMili();
	void delays (int time);

	int main() {
		RCC_APB2ENR |= 0x10;
		GPIOC_CRH &= 0x0FFFFF;
		GPIOC_CRH |= 0x300000;
		systik_init();
			while (1){
				GPIOC_ODR ^= 0x2000;
				delays (1000);
			}
	}

	void systik_init(){
		SysTick_CTRL = 0;
		SysTick_CTRL |=5;
	}

	void DelayMili() {
		SysTick_LOAD = 8000-1;
		SysTick_VAL = 0;
		while ((SysTick_CTRL & 0x10000) == 0);
	}

	void delays (int time){
		for(int i = 0;i<time;i++){
			DelayMili();
		}
	}














