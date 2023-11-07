1、功能说明
    1、TIM1 周期门控TIM3
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置:
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM1 CLK=48M,TIM3 CLK=48M
        2、端口配置：
                    PA8选择为TIM1的CH1输出
                    PA4选择为TIM3的CH1输出
        3、TIM：
                    TIM1 周期触发门控TIM3 的CH1,即TIM3为10倍周期TIM1
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察TIM1 CH1、TIM3 CH1的波形
        2、TIM3周期10倍于TIM1
4、注意事项
    无

/*** For English users   ***/
1. Function description
    1. TIM1 cycle gated TIM3
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G031C8L7-STB V1.0
3. Instructions for use
    System configuration:
        1. Clock source:
            HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, TIM1 CLK=48M, TIM3 CLK=48M
        2. Port configuration:
            PA8 is selected as CH1 output of TIM1
            PA4 is selected as CH1 output of TIM3
        3. TIM:
            TIM1 cycle triggers CH1 of gated TIM3, i.e. TIM3 is 10 times cycle in TIM1
Usage method:
    1. Open debugging mode after compilation and observe TIM1 CH1, TIM3 CH1 waveforms with oscilloscope or logic analyzer
         2. The cycle of TIM3 is 10 times that of TIM1
4. Matters needing attention
    None