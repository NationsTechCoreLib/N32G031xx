1、功能说明

	/* 简单描述工程功能 */
        这个例程配置并演示如何修改线程模式特权访问及堆栈


2、使用环境

	/* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32G031C8L7-STB V1.0


3、使用说明
	
	/* 描述相关模块配置方法；例如:时钟，I/O等 */
        SystemClock：48MHz
        USART：TX - PA9，RX - PA10，波特率115200

	/* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.可使用编译器的“Cortex寄存器”窗口查看线程模式下，使用的堆栈及代码的访问级别（特权级/非特权级）；


4、注意事项



1. Function description

	/* Briefly describe the project function */
         This routine configures and demonstrates how to modify thread mode privileged access and stack


2. Use environment

	/* Hardware environment: the development hardware platform corresponding to the project */
         Development board: N32G031C8L7-STB V1.0


3. Instructions for use

	/* Describe related module configuration methods; for example: clock, I/O, etc. */
         SystemClock: 48MHz
         USART: TX - PA9, RX - PA10, baud rate 115200

	/* Describe the test steps and phenomena of the Demo */
         1. After compiling, download the program to reset and run;
         2. You can use the "Cortex Register" window of the compiler to view the stack used in thread mode and the access level of the code (privileged level/unprivileged level);


4. Matters needing attention