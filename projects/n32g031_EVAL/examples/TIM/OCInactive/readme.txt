1、功能说明
    1、TIM3 CH1 CH2 CH3 CH4 达到CC值后，对应拉低PA6 PA7 PA8 PA9的IO电平
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM3 CLK=48M
        2、中断：
                    TIM3 比较中断打开,优先级1
        3、端口配置：
                    PA6选择为IO 输出
                    PA7选择为IO 输出
                    PA8选择为IO 输出
                    PA9选择为IO 输出
        4、TIM：
                    TIM3 配置好CH1 CH2 CH3 CH4的比较值，并打开比较中断
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察PA6 PA7 PA8 PA9的波形
        2、定时器运进入CC1 CC2 CC3 CC4中断后,对应拉低PA6 PA7 PA8 PA9的IO
4、注意事项
       开发板默认PA9,PA10跳帽接到NSLINK的虚拟串口，若工程中PA9，PA10不作串口，用作其他用途，须拔掉串口跳帽。

Function Description
     1. After TIM3 CH1 CH2 CH3 CH4 reaches the CC value, pull down the IO level of PA6 PA7 PA8 PA9 correspondingly.
2. Use environment
     Software development environment: KEIL MDK-ARM V5.34.0.0
     Hardware Environment: Developed based on N32G031C8L7_STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM3 CLK=48M
         2. Interruption:
                    TIM3 compare interrupt is turned on, subpriority 1
         3. Port configuration:
                     PA6 is selected as IO output
                     PA7 is selected as IO output
                     PA8 is selected as IO output
                     PA9 is selected as IO output
         4. TIM:
                    TIM3 configures the comparison value of CH1, CH2, CH3, CH4, and turns on the comparison interrupt
     Instructions:
         1. Open the debug mode after compiling, and observe the waveforms of PA6 PA7 PA8 PA9 with an oscilloscope or logic analyzer
         2. After the timer runs to CC1 CC2 CC3 CC4, pull down the IO level of PA6 PA7 PA8 PA9 correspondingly
4. Matters needing attention
    By default, the PA9 and PA10 jumper caps of the development board are connected to the virtual serial port of NSLINK. If PA9 and PA10 are not used as serial ports in the project, and are used for other purposes, the serial port jumper caps must be unplugged.
