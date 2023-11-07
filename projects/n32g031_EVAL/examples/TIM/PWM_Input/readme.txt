1、功能说明
    1、TIM3 CH2捕获引脚通过CH1下降沿和CH2上升沿计算占空比和频率
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.34.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM3 CLK=48M
        2、中断：
                    TIM3 CC2比较中断打开，优先级1
        3、端口配置：
                    PA7选择为TIM3的CH2输入
                    PA3选择为IO输出
        4、TIM：
                    TIM3 CH1捕获CH2信号的下降沿。TIM3 CH2捕获CH2信号的上升沿
    使用方法：
        1、编译后打开调试模式，连接PA3和PA7，将Frequency、DutyCycle、gOnePulsEn添加到watch窗口
        2、程序运行后，默认gOnePulsEn=0，每次手动给gOnePulsEn=1，此时可以看到被捕获到的占空比和频率的值分别存储在DutyCycle和Frequency变量
4、注意事项
    无

1. Function description
    1. TIM3 CH2 capture pin calculates the duty cycle and frequency through the falling edge of CH1 and the rising edge of CH2
2. Use environment
     Software development environment: KEIL MDK-ARM V5.34.0.0
     Hardware environment: Developed based on N32G031C8L7_STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,TIM3 CLK=48M
         2. Interrupt:
                    TIM3 CC2 compare interrupt is turned on, priority level 1
         3. Port configuration:
                    PA7 is selected as the CH2 input of TIM3
                    PA3 is selected as IO output
         4. TIM:
                    TIM3 CH1 captures the falling edge of CH2 signals.TIM3 CH2 captures the rising edge of CH2. 
     Instructions:
         1. Open the debug mode after compiling, connect PA3 and PA7, and add the variables TIM3Freq and gOnePulsEn to the watch window
         2. The default gOnePulsEn=0, manually give gOnePulsEn=1 each time, then you can see that the values of the duty cycle and frequency captured are stored in the DutyCycle and Frequency variables.
4. Matters needing attention
    None