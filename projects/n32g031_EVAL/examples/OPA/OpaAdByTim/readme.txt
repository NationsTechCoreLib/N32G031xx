1、功能说明
     1、TIM1 CH4触发ADC注入采样OPA的电压数据，并且TIM1输出受COMP1刹车控制
2、使用环境
     软件开发环境：KEIL MDK-ARM V5.30.0.0
     硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
     系统配置；
         1、时钟源：
                    HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, ADC CLK=48M/16, ADC 1M CLK=HSE/8,OPA CLK=48M, COMP CLK=48M, TIM1 CLK=48M, TIM8 CLK=48M
         2、中断：
                    ADC注入中断打开，优先级0
                    读取转换结果
         3、端口配置：
                    PA0选择为模拟功能OPA VP
                    PA6选择为模拟功能OPA OUT
                    PA1选择为模拟功能COMP1 INP
                    PA4选择为模拟功能COMP1 INM
                    PA12选择为模拟功能COMP1 OUT    
                    PA8选择为TIM1 CH1输出
                    PA9选择为TIM1 CH2输出
                    PA10选择为TIM1 CH3输出
                    PB13选择为TIM1 CH1N输出
                    PB14选择为TIM1 CH2N输出
                    PB15选择为TIM1 CH3N输出
                    PA6选择为ADC_CH6通道输入
        4、OPA：
                    OPA电压跟随器功能，VM无引脚
        5、ADC：
                    ADC注入模式、扫描转换、TIM1 CC4触发、12位数据右对齐，注入转换OPA输出模拟电压数据
        6、COMP：
                    COMP1 INP选择PA1，INM选择PA4，输出触发TIM1和TIM8刹车
        7、TIM：
                    TIM1 6路互补打开，刹车使能且打开中断，CH4触发输出
    使用方法：
        1、编译后打开调试模式，用示波器或者逻辑分析仪观察TIM1的输出波形和ADC读取的采集数据
        2、改变COMP1 的输出状态可以刹车TIM1，改变OPA的输入电压可以改变ADC读取的数据
4、注意事项
    无


1. Function description
    1. TIM1 CH4 triggers ADC to inject the voltage data of sampled OPA, and TIM1 output is controlled by COMP1 brake
2. Use environment
    Software development environment: KEIL MDK-ARM V5.30.0.0
    Hardware Environment: Developed based on the development board N32G031C8L7-STB V1.0
3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, ADC CLK=48M/16, ADC 1M CLK=HSE/8,
                    OPA CLK=48M, COMP CLK=48M, TIM1 CLK=48M, TIM8 CLK=48M
        2. Interrupt:
                     Enable the ADC injection interrupt, priority 0
                     Read conversion result
        3. Port configuration:
                    PA0 is selected as analog function, OPA VP
                    PA6 is selected as analog function, OPA OUT
                    PA1 is selected as analog function, COMP1 INP
                    PA4 is selected as analog function, COMP1 INM
                    PA12 is selected as analog function, COMP1 OUT
                    PA8 is selected as TIM1 CH1 output
                    PA9 is selected as TIM1 CH2 output
                    PA10 is selected as TIM1 CH3 output
                    PB13 is selected as TIM1 CH1 output
                    PB14 is selected as TIM1 CH2 output
                    PB15 is selected as TIM1 CH3 output
                    PA6 is selected as ADC_CH6 channel input
        4. OPA:
                    OPA voltage follower function, VM no pins
        5. ADC:
                    ADC injection mode, scan conversion, TIM1 CC4 trigger, 12-bit data right-justified, injection conversion OPA output analog voltage data
        6. TIM:
                    TIM1 6-channel complementary open, brake enable and open interrupt, CH4 trigger output
    Instructions:
        1. After compiling, open the debug mode, and use an oscilloscope or logic analyzer to observe the output waveform of TIM1 and the acquired data read by the ADC
        2. Changing the output state of COMP1 can brake TIM1, and changing the input voltage of OPA can change the data read by ADC
4. Matters needing attention
   None