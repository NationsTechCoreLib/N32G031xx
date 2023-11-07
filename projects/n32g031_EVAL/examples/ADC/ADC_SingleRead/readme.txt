1、功能说明
    1、ADC1采样转换PA0 PA1引脚的模拟电压
    2、采用软件触发一次，采集一次的方式
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.30.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,ADC CLK=48M/16,ADC 1M CLK=HSI/8
        2、端口配置：
                    PA0选择为模拟功能ADC转换通道0
                    PA1选择为模拟功能ADC转换通道1
        3、ADC：
                    ADC软件触发转换、12位数据右对齐，转换PA0 PA1的模拟电压数据
    使用方法：
        1、编译后打开调试模式，将变量ADCConvertedValue添加到watch窗口观察
        2、通过改变PA0 PA1引脚的电压，可以看到转换结果变量同步改变
4、注意事项
    当系统采用HSE时钟时（一般HSI也是打开的），RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8)可以配置为HSE或者HSI
    当系统采样HSI时钟时（一般HSE是关闭的），RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8)只能配置为HSI


1. Function description
    1. ADC1 samples and converts the analog voltage of PA0 PA1 pin
    2. Use software to trigger once and collect once

2. Use environment
    Software development environment: KEIL MDK-ARM V5.30.0.0
    Hardware environment: Developed based on the development board N32G031C8L7-STB V1.0 

3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, ADC CLK=48M/16, ADC 1M CLK=HSI/8
        2. Port configuration:
                    PA0 is selected as analog function, ADC conversion channel 0
                    PA1 is selected as analog function, ADC conversion channel 1
        3. ADC:
                    ADC configuration: software trigger, 12-bit data is right-aligned, and converts the analog voltage data of PA0 PA1
    Instructions:
        1. Open the debug mode after compiling and add the variable ADCConvertedValue to the watch window for observation
        2. By changing the voltage of the PA0 PA1 pin, you can see that the conversion result variable changes synchronously

4. Matters needing attention
    When the system uses the HSE clock (HSI is generally enabled), ), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8) can be configured as HSE or HSI
    When the system uses the HSI clock(HSE is generally disabled), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8) can only be configured as HSI