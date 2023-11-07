1、功能说明
    1、OPA PGA模式，放大输入电压2倍
2、使用环境
     软件开发环境：KEIL MDK-ARM V5.30.0.0
     硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
     系统配置；
         1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,OPA CLK=48M
         2、端口配置：
                    PA1选择为模拟功能OPA VP
                    PA6选择为模拟功能OPA OUT
         3、OPA：
                    OPA PGA功能，放大倍数2倍
      使用方法：
         1、编译后打开调试模式，用示波器观察OPA的输入和输出
         2、OPA输出=2*OPA输入
4、注意事项
     无


1. Function description
    1. OPA PGA mode, amplifies the input voltage by 2 times
2. Use environment
    Software development environment: KEIL MDK-ARM V5.30.0.0
    Hardware Environment: Developed based on the development board N32G031C8L7-STB V1.0
3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,OPA CLK=48M
        2. Port configuration:
                    PA1 is selected as analog function, OPA VP
                    PA6 is selected as analog function, OPA OUT
        3. OPA:
                    OPA PGA function, 2x magnification
    Instructions:
        1. Open the debug mode after compiling, and observe the input and output of the OPA with an oscilloscope
        2. OPA output = 2*OPA input
4. Matters needing attention
   None