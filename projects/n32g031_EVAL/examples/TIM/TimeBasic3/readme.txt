1、功能说明
    1、TIM3 利用更新中断，产生定时翻转IO
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=12M,APB2=48M,TIM3 CLK=24M
        2、中断：
                    TIM3 更新中断打开，优先级1
        3、端口配置：
                    PA6选择为IO输出
                    PA7选择为IO输出
                    PA8选择为IO输出
                    PA9选择为IO输出
        4、TIM：
                    TIM3使能周期中断
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察PA6的波形
        2、程序运行后，TIM3的周期中断来临翻转PA6电平
4、注意事项
    无

1. Function description
     1. TIM3 uses the update interrupt to generate timing rollover IO
2. Use environment
     Software development environment: KEIL MDK-ARM V5.34.0.0
     Hardware environment: Developed based on the evaluation board N32G031C8L7-STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M, PLL=48M, AHB=48M, APB1=12M, APB2=48M, TIM3 CLK=24M
         2. Interruption:
                     TIM3 update interrupt is turned on, priority level 1
         3. Port configuration:
                     PA6 is selected as IO output
                     PA7 is selected as IO output
                     PA8 is selected as IO output
                     PA9 is selected as IO output
         4. TIM:
                     TIM3 enables periodic interrupts
     Instructions:
         1. After compiling, turn on the debug mode, and use an oscilloscope or logic analyzer to observe the PA6 waveform
         2. After the program is running, the periodic interrupt of TIM3 comes to reverse the level of PA6
4. Matters needing attention
    None