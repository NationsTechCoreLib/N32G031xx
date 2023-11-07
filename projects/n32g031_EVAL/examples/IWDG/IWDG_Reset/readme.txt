1、功能说明
	IWDG复位功能。


2、使用环境

	软件开发环境：KEIL MDK-ARM V5.25

    硬件环境：
		1、基于评估板N32G031CL-STB V1.0开发
		2、MCU：N32G031C8L7


3、使用说明
	
	系统配置；
		1、IWDG时钟源：LSI/128
	    2、超时时间值：260ms(4.27ms*61)
        3、指示灯：LED1(PA4) LED2(PA5)
            



	测试步骤及现象：
	    1、在KEIL下编译后烧录到评估板，上电后，指示灯LED2不停的闪烁。说明IWDG正常喂狗，代码正常运行。
        2、把Delay(250)函数参数改成261以上，整个系统将一直处于复位状态，LED1亮。


4、注意事项
	1、如果通过烧录器仿真，需要开启DBG_ConfigPeriph(DBG_IWDG_STOP,ENABLE);
	2、260ms是理论计算得到的超时时间值，实际情况下，LSI时钟存在偏差，故延时函数的参数因实际而定。LSI时钟的偏差范围详见数据手册。

1. Function description

    IWDG reset function.
    

2. Use environment

    Software development environment:
       IDE tool: KEIL MDK-ARM 5.25
    
    Hardware environment:
       1. Development Board N32G031CL-STB V1.0
	   2. MCU：N32G031C8L7


3. Instructions for use

    System Configuration:
       1. IWDG clock source: LSI/128
	   2. Timeout value: 260ms (4.27ms*61)
       3. light Indicator: LED1(PA4) LED2(PA5)

    Test steps and phenomenon：
       1. Compile and download the code to reset and run.The indicator LED2 
		  keeps flashing. It means that IWDG feeds the dog normally and the code runs normally.
       2. Change the parameter of the Delay() function from 250 to 261 or more, the whole system
          will always be in the reset state, and LED1 will be on.

		
4. Matters needing attention
    1. If you simulate through the programmer, you need to enable DBG_ConfigPeriph(DBG_IWDG_STOP,ENABLE).
	2. 260ms is the timeout value obtained by theoretical calculation. In practice, the LSI clock has deviation, 
	   so the parameters of the delay function are determined according to the actual situation.The skew range of
	   the LSI clock is detailed in the data sheet.