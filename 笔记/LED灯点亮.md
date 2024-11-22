# LED灯点亮

## 一、新建KEIL工程模版

1. 新建main.c
2. 写int main函数（void）
3. 导入CMSIS-code和Devise-start up

## 二、通过寄存器编写GPIO的驱动程序

1. 了解总线矩阵

![image-20241122210118393](C:\Users\dynke\AppData\Roaming\Typora\typora-user-images\image-20241122210118393.png)

​		GPIO通过APB2与Cortex-M3相连

2. 时钟 的概念：控制外设的使能与否就是控制外设的时钟

3. 软件开发步骤：

​		(1) 使能GPIOB的外设时钟

​				外设基地址2.3（RCC）：0x4002 1000     偏移6.3.7：0x18    APB2 外设时钟使能寄存器

​				7.3.7

​		(2) 配置推挽模式：

​				8.1GPIO功能：推挽输出

![](C:\Users\dynke\AppData\Roaming\Typora\typora-user-images\image-20241122212028050.png)

​				配置好各寄存器即设置好模式：8.2.1、8.2.4

​						配置：高电平（1），清除：低电平（2）

​				外设基地址2.3（GPIOB）：0X4001 0C00     CRL偏移8.2.1：0x00    ODR偏移8.2.4：0x0C

## Code

``` c
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
```

