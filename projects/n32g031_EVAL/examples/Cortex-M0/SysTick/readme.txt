1、功能说明

	/* 简单描述工程功能 */
        这个例程配置并演示如何使用SysTick


2、使用环境

	/* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32G031C8L7-STB V1.0


3、使用说明
	
	/* 描述相关模块配置方法；例如:时钟，I/O等 */
        SystemClock：48MHz
        USART：TX - PA9，RX - PA10，波特率115200
		SysTick：1s中断

	/* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.SysTick中断被触发后开始计数，计数为偶数时打印信息；


4、注意事项


1. Function description

	/* Briefly describe the project function */
         This routine configures and demonstrates how to use SysTick


2. Use environment

	/* Hardware environment: the development hardware platform corresponding to the project */
         Development board: N32G031C8L7-STB V1.0


3. Instructions for use

	/* Describe related module configuration methods; for example: clock, I/O, etc. */
         SystemClock: 48MHz
         USART: TX - PA9, RX - PA10, baud rate 115200
SysTick: 1s interrupt

	/* Describe the test steps and phenomena of the Demo */
         1. After compiling, download the program to reset and run;
         2. Start counting after the SysTick interrupt is triggered, and print information when the count is even;


4. Matters needing attention
