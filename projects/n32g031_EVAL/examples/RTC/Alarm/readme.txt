1、功能说明
    1、通过设定闹钟时间来触发闹钟中断。
    2、通过闹钟标志位来配置IO输出

2、使用环境

    /* 软件开发环境：当前工程使用的软件工具名称及版本号 */
    IDE工具：KEIL MDK-ARM 5.21.1.0
      
    /* 硬件环境：工程对应的开发硬件平台 */
    开发板：N32G031C8L7-STB V1.0     



3、使用说明

    系统配置；
        1、RTC时钟源：LSI
        2、串口配置：
                    - 串口为USART1（TX：PA9  RX：PA10）:
                    - 数据位：8
                    - 停止位：1
                    - 奇偶校验：无
                    - 波特率： 115200 


    使用方法：
        在KEIL下编译后烧录到评估板，上电，串口按照闹钟设定时间进行打印输出。

4、注意事项
    无


1. Function description
    1. Trigger the alarm interrupt by setting the alarm time.
    2. Configure the IO output through the alarm flag bit

2. Use environment

    /* Software development environment: the name and version number of the software tool used in the current project */
    IDE tool: KEIL MDK-ARM 5.21.1.0
      
    /* Hardware environment: the development hardware platform corresponding to the project */
    Development board: N32G031C8L7-STB V1.0



3. Instructions for use

    System Configuration;
        1. RTC clock source: LSI
        2. Serial port configuration:
                    - Serial port is USART1 (TX: PA9 RX: PA10):
                    - Data bits: 8
                    - Stop bit: 1
                    - Parity: none
                    - Baud rate: 115200


    Instructions:
        After compiling under KEIL, burn it to the evaluation board, power on, and the serial port will print out the time set by the alarm clock.

4. Matters needing attention
    none