1、功能说明
    通过PC13来检测入侵。



2、使用环境

    /* 软件开发环境：当前工程使用的软件工具名称及版本号 */
    IDE工具：KEIL MDK-ARM 5.21.1.0
      
    /* 硬件环境：工程对应的开发硬件平台 */
    开发板：N32G031C8L7-STB V1.0     



3、使用说明

    系统配置；
        1、时钟：LSI
        2、检测口：PC13
        3、串口配置：
                    - 串口为USART1（TX：PA9  RX：PA10）:
                    - 数据位：8
                    - 停止位：1
                    - 奇偶校验：无
                    - 波特率： 115200 


    使用方法：
        1、在KEIL下编译后烧录到评估板，上电后，给PC13外接上拉，PC13接GND，串口打印输出Tamper interrupt。
                
                

4、注意事项
    无



1. Function description
    Intrusion is detected by PC13.



2. Use environment

    /* Software development environment: the name and version number of the software tool used in the current project */
    IDE tool: KEIL MDK-ARM 5.21.1.0
      
    /* Hardware environment: the development hardware platform corresponding to the project */
    Development board: N32G031C8L7-STB V1.0



3. Instructions for use

    System Configuration;
        1. Clock: LSI
        2. Detection port: PC13
        3. Serial port configuration:
                    - Serial port is USART1 (TX: PA9 RX: PA10):
                    - Data bits: 8
                    - Stop bit: 1
                    - Parity: none
                    - Baud rate: 115200


    Instructions:
        1. After compiling under KEIL, burn it to the evaluation board. After power-on, connect an external pull-up to PC13, connect PC13 to GND, and the serial port will print out Tamper interrupt.
                               

4. Matters needing attention
    none