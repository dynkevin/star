#define GPIOB_CLK (*(volatile unsigned int *)(0x40021000 + 0x18))
#define GPIOB_CRL (*(volatile unsigned int *)(0X40010C00 + 0x00))
#define GPIOB_OPR (*(volatile unsigned int *)(0X40010C00 + 0x0c))

int main(void)
{
//1.ʹ��GPIOB������ʱ��
	GPIOB_CLK |= (1<<3);
//2.GPIOB��������ģʽ
	GPIOB_CRL &= ~(0xf<<(4*0));//�����4Ϊ�Ĵ���
	GPIOB_CRL |= (2<<0);
	
	GPIOB_OPR &= ~(0x1<<(1*0));//�����1Ϊ�Ĵ���
	GPIOB_OPR |= (2<<0);
}
