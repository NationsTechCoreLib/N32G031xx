1、功能说明
    1、TIM1 CH3 CH3N互补信号每6个周期改变一次占空比
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置:
        1、时钟源：
                HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM1 CLK=48M,DMA CLK=48M
        2、端口配置：
                PA10选择为TIM1 CH3输出
                PB15选择为TIM1 CH3N输出
        3、TIM：
                TIM1 CH3 CH3N互补输出，每6个周期触发一次DMA传输
        4、DMA：
                DMA1_CH5通道回环模式搬运3个半字SRC_Buffer[3]变量到TIM1 CCDAT3寄存器
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察TIM1 CH3 CH3N的波形
        2、TIM1的6个周期改变一次CH3 CH3N的占空比，循环改变
4、注意事项
    无

1. Functional description
    1. TIM1 CH3 CH3N complementary signal changes duty cycle every 6 cycles
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G031C8L7-STB V1.0
3. Instructions for Use
    System configuration:
        1. Clock source:
            HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, TIM1 CLK=48M, DMA CLK=48M
        2. Port configuration:
            PA10 selected as TIM1 CH3 Output
            PB15 selected as TIM1 CH3N Output
        3. TIM:
            TIM1 CH3 CH3N complementary output triggers DMA transmission every 6 cycles
        4. DMA:
            DMA1_ CH5 Channel circular mode handling 3 half-Word SRC_ Buffer[3] variable to TIM1 CCDAT3 register
     Instructions:
         1. After compiling, turn on the debug mode, use an oscilloscope or logic analyzer to observe the waveform of TIM1 CH3 CH3N
         2. Change the duty cycle of CH3 and CH3N once in 6 cycles of TIM1, and change cyclically
4. Matters needing attention
    None