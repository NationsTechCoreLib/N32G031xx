1、功能说明
    1、TIM3 利用CH1 CH2 CH3 CH4 CC值产生定时中断，翻转IO电平
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
            HSE=8M,PLL=48M,AHB=48M,APB1=12M,APB2=48M,TIM3 CLK=24M
        2、中断：
            TIM3 比较中断打开，优先级1
        3、端口配置：
                    PA6选择为IO输出
                    PA7选择为IO输出
                    PA8选择为IO输出
                    PA9选择为IO输出
        4、TIM：
                    TIM3输出冻结模式，CH1 CH2 CH3 CH4比较值产生中断
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察PA6、PA7、PA8、PA9的波形
        2、程序运行后，对应通道达到比较值后，比较值累加并翻转对应IO口电平
4、注意事项
   开发板默认PA9,PA10跳帽接到NSLINK的虚拟串口，若工程中PA9，PA10不作串口，用作其他用途，须拔掉串口跳帽。

1. Function description
     1. TIM3 uses the CH1 CH2 CH3 CH4 CC value to generate a timing interrupt and flip the IO level
2. Use environment
     Software development environment: KEIL MDK-ARM V5.34.0.0
     Hardware Environment: Developed based on N32G031C8L7-STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
             HSE=8M, PLL=48M, AHB=48M, APB1=12M, APB2=48M, TIM3 CLK=24M
         2. Interruption:
             TIM3 compare interrupt is turned on, priority level 1
         3. Port configuration:
                     PA6 is selected as IO output
                     PA7 is selected as IO output
                     PA8 is selected as IO output
                     PA9 is selected as IO output
         4. TIM:
                     TIM3 output freeze mode, CH1 CH2 CH3 CH4 compare value interrupt
     Instructions:
         1. Open the debug mode after compiling, and observe the waveform of PA6,PA7,PA8,PA9 with an oscilloscope or logic analyzer
         2. After the program runs, after the corresponding channel reaches the comparison value, the comparison value accumulates and flips the corresponding IO port level
Matters needing attention
     None