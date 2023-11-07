1、功能说明
    1、通过设定唤醒时间触发中断。
    2、通过唤醒标志位来配置IO输出


2、使用环境

    /* 软件开发环境：当前工程使用的软件工具名称及版本号 */
    IDE工具：KEIL MDK-ARM 5.21.1.0
      
    /* 硬件环境：工程对应的开发硬件平台 */
    开发板：N32G031C8L7-STB V1.0     



3、使用说明

    系统配置；
        1、周期性唤醒时钟源：RTCCLK（1HZ）
        2、串口配置：
                    - 串口为USART1（TX：PA9  RX：PA10）:
                    - 数据位：8
                    - 停止位：1
                    - 奇偶校验：无
                    - 波特率： 115200 


    使用方法：
        1、在KEIL下编译后烧录到评估板，上电后，串口每隔4s会打印I am in rtc_wkup。
            
4、注意事项
    无


1. Function description
    1. Trigger the interrupt by setting the wake-up time.
    2. Configure the IO output through the wake-up flag bit


2. Use environment

    /* Software development environment: the name and version number of the software tool used in the current project */
    IDE tool: KEIL MDK-ARM 5.21.1.0
      
    /* Hardware environment: the development hardware platform corresponding to the project */
    Development board: N32G031C8L7-STB V1.0



3. Instructions for use

    System Configuration;
        1. Periodic wake-up clock source: RTCCLK (1HZ)
        2. Serial port configuration:
                    - Serial port is USART1 (TX: PA9 RX: PA10):
                    - Data bits: 8
                    - Stop bit: 1
                    - Parity: none
                    - Baud rate: 115200


    Instructions:
        1. After compiling under KEIL, burn it to the evaluation board. After power-on, the serial port will print I am in rtc_wkup every 4s.
            
4. Matters needing attention
    none