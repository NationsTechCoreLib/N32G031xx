1、功能说明

	/* 简单描述工程功能 */
        这个例程配置并演示MCU跑分测试


2、使用环境

	/* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32G031C8L7-STB V1.0
        

3、使用说明
	
	/* 描述相关模块配置方法；例如:时钟，I/O等 */
	SystemClock：48MHz
    USART：TX - PA9，RX - PA10，波特率115200
	SysTick：时钟滴答配置为1MS

	/* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.通过串口打印出跑分结果；


4、注意事项
	此例程的IAR工程为了充分测试芯片性能需要修改堆栈，为避免和其他例程冲突，所以需要选择工程内部的icf文件，更换路径后icf文件会找不到导致编译错误，需要打开工程后选择Options->linker->config->Override default下重新选择工程内部的N32G031x6.icf文件即可，重新编译后就不会报错。



1. Function description

	/* Briefly describe the project function */
         This example configures and demonstrates the MCU benchmark


2. Use environment

	/* Hardware environment: the development hardware platform corresponding to the project */
         Development board: N32G031C8L7-STB V1.0
        

3. Instructions for use

	/* Describe related module configuration methods; for example: clock, I/O, etc. */
	SystemClock: 48MHz
     	USART: TX - PA9, RX - PA10, baud rate 115200
	SysTick: Clock ticks configured as 1MS

	/* Describe the test steps and phenomena of the Demo */
         	1. After compiling, download the program to reset and run;
         	2. Print out the running score results through the serial port;


4. Matters needing attention
	The IAR project of this routine needs to modify the stack in order to fully test the chip performance. In order to avoid conflicts with other routines, it is necessary to select the icf file inside the project. After changing the path, the icf file will not be found, resulting in a compilation error. You need to open the project and select Under Options->linker->config->Override default, re-select the N32G031x6.icf file inside the project, and no error will be reported after recompiling.