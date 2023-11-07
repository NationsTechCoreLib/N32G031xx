1、功能说明
    1、TIM1输出3路互补波形
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置:
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM1 CLK=48M
        2、端口配置：
                    PA8选择为TIM1 CH1输出
                    PA9选择为TIM1 CH2输出
                    PA10选择为TIM1 CH3输出
                    PB13选择为TIM1 CH1N输出
                    PB14选择为TIM1 CH2N输出
                    PB15选择为TIM1 CH3N输出
                    PB12选择为TIM1 Breakin输入
        3、TIM：
                    TIM1 6路互补带死区，带IOM刹车
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察TIM1的波形
        2、可观察到3路互补波形，PB12引脚为高可关闭输出
4、注意事项
       开发板默认PA9,PA10跳帽接到NSLINK的虚拟串口，若工程中PA9，PA10不作串口，用作其他用途，须拔掉串口跳帽。

1. Function description
    1. TIM1 output 3 complementary waveforms
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G031C8L7-STB V1.0
3. Instructions for use
    System configuration:
        1. Clock source:
            HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, TIM1 CLK=48M
        2. Port configuration:
                     PA8 is selected as TIM1 CH1 output
                     PA9 is selected as TIM1 CH2 output
                     PA10 is selected as TIM1 CH3 output
                     PB13 is selected as TIM1 CH1N output
                     PB14 is selected as TIM1 CH2N output
                     PB15 is selected as TIM1 CH3N output
                     PB12 is selected as TIM1 Breakin input
        3. TIM:
            TIM1 6 Complementary with dead-time, with IOM Brake
    Instructions:
        1. Open debugging mode after compilation and observe TIM1 waveform with oscilloscope or logic analyzer
        2. 3 complementary waveforms can be observed, and the output of PB12 pin can be turned off when the pin is high
4. Matters needing attention
    By default, the PA9 and PA10 jumper caps of the development board are connected to the virtual serial port of NSLINK. If PA9 and PA10 are not used as serial ports in the project, and are used for other purposes, the serial port jumper caps must be unplugged.
