1、功能说明

	1、此例程展示 IO 电平快速翻转


2、使用环境

	/* 软件开发环境：当前工程使用的软件工具名称及版本号 */
        IDE工具：KEIL MDK-ARM 5.21.1.0

        /* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32G031CL-STB V1.0

3、使用说明
	
	/* 描述相关模块配置方法；例如:时钟，I/O等 */
         1、 SystemClock：48MHz
         2、 GPIO：PA0 引脚电平快速翻转


	/* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.用示波器看 PA0 引脚电平快速翻转


4、注意事项
     无


1. Function description
    1. This routine shows IO level flipping quickly
2. Use environment
    /* Software development environment: the name and version number of the software tool used in the current project */
    Software development environment: 
    	KEIL MDK-ARM 5.21.1.0
    /* Hardware environment: the development hardware platform corresponding to the project */
    Hardware Environment: 
    	Developed based on N32G031CL-STB V1.0
3. Instructions for use
    System Configuration;
        1. SystemClock: 48MHz
        2. GPIO: the level of the PA0 pin flips quickly

    Instructions:
        1. After compiling, download the program to reset and run
        2. Use an oscilloscope to see the PA0 pin level flips quickly
4. Matters needing attention
    No