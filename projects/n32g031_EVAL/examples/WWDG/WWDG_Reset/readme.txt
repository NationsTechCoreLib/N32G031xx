1、功能说明
	1、WWDG复位功能。


2、使用环境

	软件开发环境：KEIL MDK-ARM V5.25

    硬件环境：
		1、基于评估板N32G031CL-STB V1.0开发
		2、MCU：N32G031C8


3、使用说明
	
	系统配置；
		1、WWDG时钟源：PCLK1
		2、窗口值：31.96ms < n <43.52ms
        3、指示灯：PA4(LED1)   PA5(LED2)
             
	测试步骤与现象：
		1、在KEIL下编译后烧录到评估板，上电后，指示灯LED2不停的闪烁。说明窗口值刷新正常，代码正常运行。
        2、当把Delay(38)函数参数改成小于32或者大于44时，整个系统将一直处于复位状态。LED1亮。


4、注意事项
	1、当窗口值很小时，系统处于频繁的复位状态，此时，容易引起程序无法正常下载。本例程中在开启WWDG前加了1秒延时来避免这个现象。当然也可以不用延时，直接将BOOT0引脚拉高即可正常下载。 

	

1. Function description

    WWDG reset function.
    

2. Use environment

    Software development environment:
       IDE tool: KEIL MDK-ARM 5.25
    
    Hardware environment:
       1. Development Board N32G031CL-STB V1.0
	   2. MCU：N32G031C8


3. Instructions for use

    System Configuration:
       1. IWDG clock source: PCLK1
	   2. Window value: 31.96ms < n <43.52ms
       3. light Indicator: PA4(LED1)   PA5(LED2)

    Test steps and phenomenon：
       1. Compile and download the code to reset and run, the indicator LED2 keeps flashing. 
	      It means that the window value is refreshed normally and the code is running normally.
       2. When the parameter of the Delay() function is changed from 38 to less than 32 or greater than 44, 
	      the entire system will always be in the reset state. LED1 is on.

		
4. Matters needing attention
    1. When the window value is very small, the system is in a frequent reset state, and at this time, it is easy to 
	   cause the program to fail to download normally. In this routine, 1s delay is added before WWDG is 
	   turned on to avoid this phenomenon. Of course, without delay, you can directly pull up the BOOT0 pin to download normally.