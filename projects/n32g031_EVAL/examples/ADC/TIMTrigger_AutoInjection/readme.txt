1、功能说明
    1、ADC规则采样PA5、自动注入采样PA4引脚的模拟电压，在TIM1 CC2事件下触发采样
    2、其中规则转换结果通过DMA_CH1通道读取到变量ADC_RegularConvertedValueTab[32]数组
           注入转换结果通过转换结束中断读取到变量ADC_InjectedConvertedValueTab[32]数组
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.30.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,ADC CLK=48M/16,ADC 1M CLK=HSI/8,DMA CLK=48M
        2、中断：
                    ADC注入转换结果完成中断打开, 断优先级0
                    中断函数中将注入结果读取到ADC_InjectedConvertedValueTab[32]数组，并翻转PA6电平
        3、端口配置：
                    PA4选择为模拟功能ADC转换通道
                    PA5选择为模拟功能ADC转换通道
                    PA6选择为通用IO输出
                    PA9选择为TIM1 CH2 PWM输出
        4、DMA：
                    DMA_CH1通道循环模式搬运32个半字的ADC1转换结果到ADC_RegularConvertedValueTab[32]数组
        5、ADC：
                    ADC TIM1 CC2触发、12位数据右对齐，规则转换通道PA5，自动注入转换通道PA4的模拟电压数据
        6、TIM：
                    TIM1开启CH2输出，CH2用作触发ADC转换        
    使用方法：
        1、编译后打开调试模式，将变量ADC_RegularConvertedValueTab[32],ADC_InjectedConvertedValueTab[32]添加到watch窗口观察
        2、通过改变PA4 PA5引脚的电压，在每个CC2事件发生时转换一次规则和注入通道，变量储存在对应数组中。同时在PA9 可以看到TIM1 CH2的 PWM 波形
4、注意事项
    当系统采用HSE时钟时（一般HSI也是打开的），RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8)可以配置为HSE或者HSI
    当系统采样HSI时钟时（一般HSE是关闭的），RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8)只能配置为HSI


1. Function description
    1. The ADC regularly samples PA5, automatically injects and samples the analog voltage of the PA4 pin, and triggers sampling under the TIM1 CC2 event
    2. The regular conversion result is read into the variable ADC_RegularConvertedValueTab[32] array through the DMA_CH1 channel
           The result of the injection conversion is read into the variable ADC_InjectedConvertedValueTab[32] array through the conversion end interrupt

2. Use environment
    Software development environment: KEIL MDK-ARM V5.30.0.0
    Hardware environment: Developed based on the development board N32G031C8L7-STB V1.0

3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, ADC CLK=48M/16, ADC 1M CLK=HSI/8, DMA CLK=48M
        2. Interrupt:
                    ADC injection conversion result complete interrupt is turned on, interrupt priority is 0
                    In the interrupt function, the injection result is read into the ADC_InjectedConvertedValueTab[32] array, and the PA6 level is flipped
        3. Port configuration:
                    PA4 is selected as the analog function, ADC conversion channel
                    PA5 is selected as the analog function, ADC conversion channel
                    PA6 is selected as general IO output
                    PA9 is selected as TIM1 CH2 PWM output
        4. DMA:
                    DMA1_CH1 channel is configuered as circular mode,carries 32 half-word ADC1 conversion results to ADC_RegularConvertedValueTab[32] array
        5. ADC:
                    ADC configuration: TIM1 CC2 trigger, 12-bit data right-aligned, regular conversion channel PA5, automatic injection of analog voltage data of conversion channel PA4
        6. TIM:
                    TIM1 turns on CH2 output, and CH2 is used to trigger ADC conversion
    Instructions:
        1. Open the debug mode after compiling and add the variables ADC_RegularConvertedValueTab[32], ADC_InjectedConvertedValueTab[32] to the watch window for observation
        2. By changing the voltage of the PA4 PA5 pin, the rule and injection channel are converted once every CC2 event occurs, and the variables are stored in the corresponding array. At the same time, you can see the PWM waveform of TIM1 CH2 on PA9

4. Matters needing attention
    When the system uses the HSE clock (HSI is generally enabled), ), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8) can be configured as HSE or HSI
    When the system uses the HSI clock(HSE is generally disabled), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8) can only be configured as HSI