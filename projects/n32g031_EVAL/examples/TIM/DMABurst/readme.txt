1、功能说明
    1、TIM1 一个周期后同时改变周期和占空比
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置：
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM1 CLK=48M,DMA CLK=48M
        2、端口配置：
                    PA8选择为TIM1 CH1输出
        3、TIM：
                    TIM1 CH1 输出，周期触发DMA burst传输，加载AR,REPCNT,CCDAT1寄存器，改变占空比和周期和重复计数器
        4、DMA：
                    DMA1_CH5通道正常模式搬运3个半字SRC_Buffer[3]变量到TIM1 DMA寄存器
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察TIM1 CH1的波形
        2、TIM1的第一个周期结束后，后面的波形为DMA搬运的改变周期和占空比的波形
4、注意事项
    无

1. Function description
     1. TIM1 changes the period and duty cycle at the same time after one cycle
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G031C8L7-STB V1.0
3. Instructions for use
    System Configuration:
        1. Clock source:
                     HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, TIM1 CLK=48M, DMA CLK=48M
        2. Port configuration:
                     PA8 is selected as TIM1 CH1 output
        3. TIM:
            TIM1 CH1 output, periodically triggered DMA burst transmission, loading AR, REPCNT, CCDAT1 registers, changing duty cycle, period and repeat counter
        4. DMA:
                     The DMA1_CH5 channel in normal mode transfers 3 half-word SRC_Buffer[3] variables to the TIM1 DMA register
    Instructions:
        1. Open debugging mode after compilation and observe TIM1 CH 1 waveform with oscilloscope or logic analyzer
         2. After the first cycle of TIM1 is over, the following waveforms are the waveforms of changing cycle and duty cycle of DMA transport
4. Matters needing attention
    None