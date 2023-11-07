1、功能说明
    1、COMP1的输出刹车TIM1 的互补信号，COMP OUT变低后恢复TIM1 波形
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.30.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,COMP CLK=48M,TIM1 CLK=48M
        2、端口配置：
                    PA1选择为模拟功能COMP INP
                    PA0选择为模拟功能COMP INM
                    PA6选择为模拟功能COMP OUT
                    PA2选择为IO输出
                    PA3选择为IO输出
                    PA8选择为TIM1 CH1输出
                    PA9选择为TIM1 CH2输出
                    PA10选择为TIM1 CH3输出
                    PB13选择为TIM1 CH1N输出
                    PB14选择为TIM1 CH2N输出
                    PB15选择为TIM1 CH3N输出
        3、TIM：
                    TIM1开启CH1 CH2 CH3 CH1N CH2N CH3N输出,COMP作为刹车输入
        4、COMP：
                    COMP1输出触发TIM1 刹车，无输出时恢复TIM1 输出
    使用方法：
        1、编译后打开调试模式，将PA2连接到PA1，PA3连接到PA0，利用示波器或者逻辑分析仪观察TIM1输出波形
        2、当软件输出PA2电平大于PA3时，TIM波形消失，相反时，波形正常输出
4、注意事项
    无



1. Function description
    1. The output of COMP1 brakes the complementary signal of TIM1, and the waveform of TIM1 is restored after COMP OUT goes low.

2. Use environment
    Software development environment: KEIL MDK-ARM V5.30.0.0
    Hardware environment: Developed based on the evaluation board N32G031C8L7-STB V1.0

3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, COMP CLK=48M, TIM1 CLK=48M
        2. Port configuration:
                    PA1 is selected as the analog function, COMP INP
                    PA0 is selected as the analog function, COMP INM
                    PA6 is selected as the analog function, COMP OUT
                    PA2 is selected as IO output
                    PA3 is selected as IO output
                    PA8 is selected as TIM1 CH1 output
                    PA9 is selected as TIM1 CH2 output
                    PA10 is selected as TIM1 CH3 output
                    PB13 is selected as TIM1 CH1N output
                    PB14 is selected as TIM1 CH2N output
                    PB15 is selected as TIM1 CH3N output
        3. TIM:
                    TIM1 turns on CH1 CH2 CH3 CH1N CH2N CH3N output, COMP is used as brake input
        4. COMP:
                    COMP1 output triggers TIM1 brake, and resumes TIM1 output when there is no output
    Instructions:
        1. Open the debug mode after compiling, connect PA2 to PA1 and PA3 to PA0, use an oscilloscope or logic analyzer to observe the output waveform of TIM1
        2. When the software output PA2 level is greater than PA3, the TIM waveform disappears, on the contrary, the waveform is output normally

4. Matters needing attention
   None