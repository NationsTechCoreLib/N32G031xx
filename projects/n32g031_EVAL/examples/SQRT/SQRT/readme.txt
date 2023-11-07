1、功能说明
    1、SQRT执行一次开方，在完成中断里面通过串口发送商和余数
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.30.0.0
    硬件环境：      基于N32G031C8L7-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,SQRT CLK=48M
        2、端口配置：
                    PA9选择为串口输出
                    PA10选择为串口输入
        3、HDIV：
                    SQRT中断打开优先级0，计算 123456开方的结果
    使用方法：
        1、编译后打开调试模式，将变量SQRT的寄存器打开
        2、程序执行后，可以看到开方的结果为351，同时串口也会打印相关信息
4、注意事项
    无


1. Function description
     1. SQRT executes a square root, and sends the quotient and remainder through the serial port in the completion interrupt
2. Use environment
     Software development environment: KEIL MDK-ARM V5.30.0.0
     Hardware Environment: Developed based on N32G031C8L7-STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,SQRT CLK=48M
         2. Port configuration:
                     PA9 is selected as serial output
                     PA10 is selected as serial input
         3. HDIV:
                     SQRT interrupt open priority 0, calculate the result of 123456 square root
     Instructions:
         1. Open the debug mode after compiling, and open the register of the variable SQRT
         2. After the program is executed, you can see that the result of the square is 351, and the serial port will also print relevant information
4. Matters needing attention
     none