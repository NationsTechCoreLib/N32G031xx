1、功能说明
    1、LPTIM 输出PWM信号
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.30.0.0
    硬件环境：      基于N32G031CL-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,LPTIM CLK=LSI
        2、端口配置：
                    PA9选择为LPTIM输出
        3、LPTIM：
                    LPTIM CLK不分频，LPTIM输出PWM信号,频率50HZ（ARR设为600）。
    使用方法：
        1、编译后打开调试模式，可观察到PA9引脚PWM信号
4、注意事项
    无


1. Function description
     1. LPTIM output PWM signal
2. Use environment
     Software development environment: KEIL MDK-ARM V5.30.0.0
     Hardware environment: N32G031CL-STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
            HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,LPTIM CLK=LSI
         2. Port configuration:
            PA9 selected as LPTIM output
         3. LPTIM:
            LPTIM CLK does not divide the frequency,LPTIM outputs PWM signal,the frequency is 50Hz.(ARR: 600)
    Instructions:
         1. Open the debug mode after compiling, and you can observe the PWM signal of the PA9pin
4. Matters needing attention
     none