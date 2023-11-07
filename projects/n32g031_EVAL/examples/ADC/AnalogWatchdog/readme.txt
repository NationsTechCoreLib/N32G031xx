1、功能说明
    1、ADC采样转换PA4引脚的模拟电压，如果超过模拟看门狗定义的阈值范围，则跳入中断程序
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.30.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,ADC CLK=48M/16,ADC 1M CLK=HSI/8
        2、ADC：
                    ADC连续转换、软件触发、12位数据右对齐，转换PA4引脚的模拟电压数据
        3、端口配置：
                    PA4选择为模拟功能ADC转换通道4
        4、中断：
                    ADC模拟看门狗中断打开，优先级0
    使用方法：
        1、编译后打开调试模式，将变量gCntAwdg添加到watch窗口观察
        2、改变PA4引脚电压值，当电压值超出模拟看门狗定义的0x300（即0.6V）到0xB00（即2.26V）范围外，则进入一次中断，变量做累加操作
4、注意事项
    当系统采用HSE时钟时（一般HSI也是打开的），RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8)可以配置为HSE或者HSI
    当系统采样HSI时钟时（一般HSE是关闭的），RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8)只能配置为HSI

1. Function description
    1. ADC samples and converts the analog voltage of the PA4 pin. If it exceeds the threshold range defined by the analog watchdog, then jump into the interrupt program

2. Use environment
    Software development environment: KEIL MDK-ARM V5.30.0.0
    Hardware environment: DDeveloped based on the development board N32G031C8L7-STB V1.0

3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, ADC CLK=48M/16, ADC 1M CLK=HSI/8
        2. ADC:
                    ADC configuration: continuous conversion, software trigger, 12-bit data right-aligned, conversion of analog voltage data of PA4 pin
        3. Port configuration:
                    PA4 is selected as analog function, ADC conversion channel 4
        4. Interrupt:
                    ADC analog watchdog interrupt is turned on, priority 0
    Instructions:
        1. Open the debug mode after compiling and add the variable gCntAwdg to the watch window for observation
        2. Change the voltage value of the PA4 pin. When the voltage value exceeds the range defined by the analog watchdog from 0x300 (ie 0.6V) to 0xB00 (ie 2.26V), an interrupt is entered, and the variable is accumulated

4. Matters needing attention
    When the system uses the HSE clock (HSI is generally enabled), ), RCC_ConfigAdc1mClk (RCC_ADC1MCLK_SRC_HSE, RCC_ADC1MCLK_DIV8) can be configured as HSE or HSI
    When the system uses the HSI clock(HSE is generally disabled), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, RCC_ADC1MCLK_DIV8) can only be configured as HSI