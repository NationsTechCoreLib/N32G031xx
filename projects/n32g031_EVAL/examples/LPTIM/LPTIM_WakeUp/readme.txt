1、功能说明
    1、LPTIM 定时产生EXTI23，唤醒CPU进行IO翻转
2、使用环境
    软件开发环境：  KEIL MDK-ARM V5.30.0.0
    硬件环境：      基于N32G031CL-STB V1.0开发
3、使用说明
    系统配置；
        1、时钟源：
                    HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,LPTIM CLK=LSI
        2、中断：
                    LPTIM周期触发EXTI23中断，唤醒CPU
        3、端口配置：
                    PB7选择为IO输出
        4、LPTIM：
                    LPTIM连续定时模式
    使用方法：
        1、编译后打开调试模式，可观察到PB7引脚出产生周期翻转，且CPU不断进入低功耗模式
4、注意事项
    无


1. Function description
     1. LPTIM generates EXTI23 regularly, wakes up the CPU for IO flipping
2. Use environment
     Software development environment: KEIL MDK-ARM V5.30.0.0
     Hardware environment: N32G031CL-STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
             HSE=8M,PLL=48M,AHB=48M,APB1=48M,APB2=48M,LPTIM CLK=LSI
         2. Interrupt:
             LPTIM cycle triggers EXTI23 interrupt, wakes up CPU
         3. Port configuration:
             PB7 is selected as IO output
         4. LPTIM:
             LPTIM Continuous Timing Mode
    Instructions:
         1. Turn on the debug mode after compiling, and it can be observed that the PB7 pin has a cycle flip, and the CPU continues to enter the low-power mode
4. Matters needing attention
     none   