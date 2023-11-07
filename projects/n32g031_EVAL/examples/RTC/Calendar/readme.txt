1、功能说明
    1、通过EXTI线来触发日历打印输出。


2、使用环境

    /* 软件开发环境：当前工程使用的软件工具名称及版本号 */
    IDE工具：KEIL MDK-ARM 5.21.1.0
      
    /* 硬件环境：工程对应的开发硬件平台 */
    开发板：N32G031C8L7-STB V1.0     



3、使用说明

    系统配置；
        1、RTC时钟源：LSI
                2、中断线：EXTI_LINE7
        3、串口配置：
                    - 串口为USART1（TX：PA9  RX：PA10）:
                    - 数据位：8
                    - 停止位：1
                    - 奇偶校验：无
                    - 波特率： 115200 


    使用方法：
        在KEIL下编译后烧录到评估板，PC13连接到PA7口，上电后，串口每隔1S会打印一次对应日历时间


4、注意事项
    无



1. Function description
    1. Trigger the calendar printout through the EXTI line.


2. Use environment

    /* Software development environment: the name and version number of the software tool used in the current project */
    IDE tool: KEIL MDK-ARM 5.21.1.0
      
    /* Hardware environment: the development hardware platform corresponding to the project */
    Development board: N32G031C8L7-STB V1.0



3. Instructions for use

    System Configuration;
        1. RTC clock source: LSI
                2. Interrupt line: EXTI_LINE7
        3. Serial port configuration:
                    - Serial port is USART1 (TX: PA9 RX: PA10):
                    - Data bits: 8
                    - Stop bit: 1
                    - Parity: none
                    - Baud rate: 115200


    Instructions:
        After compiling under KEIL and burning to the evaluation board, PC13 is connected to the PA7 port. After power-on, the serial port will print the corresponding calendar time every 1S.


4. Matters needing attention
    none