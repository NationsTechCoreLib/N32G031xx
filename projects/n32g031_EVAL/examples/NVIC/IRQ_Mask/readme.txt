1、功能说明

	/* 简单描述工程功能 */
        这个例程配置并演示使用EXIT外部中断及TIM定时器中断


2、使用环境

	/* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32G031C8L7-STB V1.0
        

3、使用说明
	
	/* 描述相关模块配置方法；例如:时钟，I/O等 */
        SystemClock：48MHz
        USART：TX - PA9，波特率115200
	    EXIT：PA0为浮空输入模式，外部中断线 - EXIT_LINE0，开启外部中断
	    TIM：预分频系数 - （SystemClock/1200-1），周期 - （1200-1），开启定时器中断

	/* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.查看串口打印信息，定时器中断信息每1S打印一次，按下按键打印停止，再次按下则继续打印，表明程序运行正常；


4、注意事项


1. Function description

	/* Briefly describe the project function */
         This routine configures and demonstrates the use of EXIT external interrupt and TIM timer interrupt


2. Use environment

	/* Hardware environment: the development hardware platform corresponding to the project */
         Development board: N32G031C8L7-STB V1.0
        

3. Instructions for use

	/* Describe related module configuration methods; for example: clock, I/O, etc. */
         	SystemClock: 48MHz
         	USART: TX - PA9, baud rate 115200
	EXIT: PA0 is floating input mode, external interrupt line - EXIT_LINE0, open external interrupt
	TIM: prescale factor - (SystemClock/1200-1), period - (1200-1), enable timer interrupt

	/* Describe the test steps and phenomena of the Demo */
         1. After compiling, download the program to reset and run;
         2. Check the serial port printing information, the timer interrupt information is printed every 1S, press the button to stop printing, press it again to continue printing, indicating that the program is running normally;


4. Matters needing attention

