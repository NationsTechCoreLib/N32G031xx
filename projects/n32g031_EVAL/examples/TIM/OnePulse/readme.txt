1、功能说明
    1、TIM3 CH2上升沿触发CH1输出一个单脉冲
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM3 CLK=48M
        2、端口配置：
                    PA4选择为TIM3的CH1输出
                    PA7选择为TIM3的CH2输入
                    PA3选择为IO输出
        3、TIM：
                    TIM3 配置CH2上升沿触发CH1输出一个单脉冲
    使用方法：
        1、编译后打开调试模式，PA3连接PA7，用示波器或者逻辑分析仪观察TIM3 的CH1 的波形
        2、将变量gSendTrigEn添加到watch窗口，默认gSendTrigEn=0，每次手动修改gSendTrigEn=1,将会看到在TIM3 CH1端口输出一个单脉冲
4、注意事项
    无

1. Function description
     1. The rising edge of TIM3 CH2 triggers CH1 to output a single pulse
2. Use environment
     Software development environment: KEIL MDK-ARM V5.34.0.0
     Hardware Environment: Developed based on N32G031C8L7-STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM3 CLK=48M
         2. Port configuration:
                     PA4 is selected as the CH1 output of TIM3
                     PA7 is selected as the CH2 input of TIM3
                     PA3 is selected as IO output
         3. TIM:
                     TIM3 configures CH2 rising edge to trigger CH1 to output a single pulse
     Instructions:
         1. Open the debug mode after compiling, connect PA3 to PA7, and observe the waveform of CH1 of TIM3 with an oscilloscope or logic analyzer
         2. Add the variable gSendTrigEn to the watch window, the default gSendTrigEn=0, every time you manually modify gSendTrigEn=1, you will see a single pulse output on the TIM3 CH1 port
4. Matters needing attention
    None