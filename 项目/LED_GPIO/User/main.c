#define GPIOB_CLK (*(volatile unsigned int *)(0x40021000 + 0x18))
#define GPIOB_CRL (*(volatile unsigned int *)(0X40010C00 + 0x00))
#define GPIOB_OPR (*(volatile unsigned int *)(0X40010C00 + 0x0c))

int main(void)
{
//1.使能GPIOB的外设时钟
	GPIOB_CLK |= (1<<3);
//2.GPIOB配置推挽模式
	GPIOB_CRL &= ~(0xf<<(4*0));//清除低4为寄存器
	GPIOB_CRL |= (2<<0);
	
	GPIOB_OPR &= ~(0x1<<(1*0));//清除低1为寄存器
	GPIOB_OPR |= (2<<0);
}
