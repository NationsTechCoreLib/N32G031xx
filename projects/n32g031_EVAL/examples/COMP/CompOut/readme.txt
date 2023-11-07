1、功能说明
    1、COMP1的输出PA6受输入INP PA1和INM PA0的影响
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.30.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,COMP CLK=48M
        2、端口配置：
                    PA1选择为模拟功能COMP INP
                    PA0选择为模拟功能COMP INM
                    PA6选择为模拟功能COMP OUT
                    PA2选择为IO输出
                    PA3选择为IO输出
        3、COMP：
                    COMP1输入PA1，PA0，输出PA6
    使用方法：
        1、编译后打开调试模式，将PA2连接到PA1，PA3连接到PA0，利用示波器或者逻辑分析仪观察PA6输出波形
        2、当软件输出PA2电平大于PA3时，PA6输出高电平，相反时，输出低电平
4、注意事项
    无


1. Function description
     1. The output PA6 of COMP1 is affected by the input INP PA1 and INM PA0

2. Use environment
     Software development environment: KEIL MDK-ARM V5.30.0.0
     Hardware environment: Developed based on the development board N32G031C8L7-STB V1.0

3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M, PLL=48M, AHB=48M, APB1=48M, APB2=48M, COMP CLK=48M
         2. Port configuration:
                     PA1 is selected as the analog function, COMP INP
                     PA0 is selected as the analog function, COMP INM
                     PA6 is selected as the analog function, COMP OUT
                     PA2 is selected as IO output
                     PA3 is selected as IO output
         3. COMP:
                     COMP1 input PA1, PA0, output PA6
     Instructions:
         1. After compiling, turn on the debug mode, connect PA2 to PA1, and PA3 to PA0, use an oscilloscope or logic analyzer to observe the output waveform of PA6
         2. When the software output PA2 level is greater than PA3, PA6 output high level, on the contrary, output low level

4. Matters needing attention
   None