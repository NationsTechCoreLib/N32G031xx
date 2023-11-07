1、功能说明
    1、TIM3 在TIM1周期下计数
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM1 CLK=48M,TIM3 CLK=48M
        2、端口配置：
                    PA6选择为TIM3的CH1输出
                    PA8选择为TIM1的CH1输出
        3、TIM：
                    TIM1 CH1 周期触发TIM3 的门控
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察TIM1 CH1、TIM3 CH1的波形
        2、程序运行后，TIM3的周期值是TIM1的15倍
4、注意事项
    无

1. Function description
     1. TIM3 counts under TIM1 cycle
2. Use environment
     Software development environment: KEIL MDK-ARM V5.34.0.0
     Hardware environment: Developed based on N32G031C8L7_STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM1 CLK=48M,TIM3 CLK=48M
         2. Port configuration:
                     PA6 is selected as the CH1 output of TIM3
                     PA8 is selected as the CH1 output of TIM1
         3. TIM:
                     TIM1 CH1 periodically triggers the gate control of TIM3
     Instructions:
         1. Open the debug mode after compiling, and observe the waveforms of TIM1 CH1, TIM3 CH1,with an oscilloscope or logic analyzer
         2. After the program runs, The period of TIM3 is 15 times that of TIM1
4. Matters needing attention
    None