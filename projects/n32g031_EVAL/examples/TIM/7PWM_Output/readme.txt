1、功能说明
    1、TIM1和TIM8输出3路互补波形和一路CH4波形
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置:
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM1 CLK=48M,TIM8 CLK=48M
        2、端口配置：
                    PA8选择为TIM1 CH1输出
                    PA9选择为TIM1 CH2输出
                    PA10选择为TIM1 CH3输出
                    PB13选择为TIM1 CH1N输出
                    PB14选择为TIM1 CH2N输出
                    PB15选择为TIM1 CH3N输出
                    PA11选择为TIM1 CH4输出
                    PA0选择为TIM8 CH1输出
                    PA1选择为TIM8 CH2输出
                    PA2选择为TIM8 CH3输出
                    PB6选择为TIM8 CH1N输出
                    PB7选择为TIM8 CH2N输出
                    PB5选择为TIM8 CH3N输出
                    PA3选择为TIM8 CH4输出
        3、TIM：
                    TIM1 6路互补输出,CH4输出
                    TIM8 6路互补输出,CH4输出
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察TIM1 TIM8的输出波形
        2、输出波形TIM1 3路互补加一路CH4，TIM8 3路互补加一路CH4
4、注意事项
       开发板默认PA9、PA10跳帽接到NSLINK的虚拟串口，若工程中PA9、PA10不作串口，用作其他用途，须拔掉串口跳帽。

1. Function description
    1. TIM1 and TIM8 output 3 complementary waveforms and 1 CH4 waveform
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G031C8L7-STB V1.0
3. Instructions for Use
    System configuration;
        1. Clock source:
            HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, TIM1 CLK=48M, TIM8 CLK=48M
        2. Port configuration:
                    PA8 is selected as TIM1 CH1 output
                    PA9 is selected as TIM1 CH2 output
                    PA10 is selected as TIM1 CH3 output
                    PB13 is selected as TIM1 CH1N output
                    PB14 is selected as TIM1 CH2N output
                    PB15 is selected as TIM1 CH3N output
                    PA11 is selected as TIM1 CH4 output
                    PA0 is selected as TIM8 CH1 output
                    PA1 is selected as TIM8 CH2 output
                    PA2 is selected as TIM8 CH3 output
                    PB6 is selected as TIM8 CH1N output
                    PB7 is selected as TIM8 CH2N output
                    PB5 is selected as TIM8 CH3N output
                    PA3 is selected as TIM8 CH4 output
        3. TIM:
            TIM1 6 complementary outputs, CH4 output
            TIM8 6 complementary outputs, CH4 output
    Instructions:
        1. Open debugging mode after compilation and use an oscilloscope or logic analyzer to observe the output waveform of TIM1 TIM8
        2. Output waveform TIM1 3-way complementary plus one CH4, TIM8 3-way complementary plus one CH4
4. Matters needing attention
       By default, the PA9 and PA10 jumper caps of the development board are connected to the virtual serial port of NSLINK. If PA9 and PA10 are not used as serial ports in the project, and are used for other purposes, the serial port jumper caps must be unplugged.
