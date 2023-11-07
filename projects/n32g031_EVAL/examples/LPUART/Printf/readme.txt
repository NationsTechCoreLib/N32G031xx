1、功能说明

    该测例演示了LPUART与PC间通过查询检测标识实现的基础通信。
    重定向printf函数至LPUART，并使用printf函数输出消息至终端。


2、使用环境

     软件开发环境：KEIL MDK-ARM Professional Version 5.26.2.0

     硬件环境：最小系统板N32G031C8L7-STB V1.0


3、使用说明
	
    系统时钟配置如下：
    - 时钟源 = HSI + PLL
    - 系统时钟 = 48MHz
    
    LPUART配置如下：
    - 波特率 = 115200 baud
    - 字长 = 8数据位（固定）
    - 1停止位（固定）
    - 校验控制禁用
    - 硬件流控制禁用（RTS和CTS信号）
    - 接收器和发送器使能
    
    LPUART引脚连接如下：
    - LPUART_Tx.PA1 
    
    测试步骤与现象：
    - Demo在KEIL环境下编译后，下载至MCU
    - 复位运行，查看串口打印信息


4、注意事项

1. Function description

     This test example demonstrates the basic communication between LPUART and PC by querying the detection mark.
     Redirect the printf function to LPUART, and use the printf function to output messages to the terminal.


2. Use environment

      Software development environment: KEIL MDK-ARM Professional Version 5.26.2.0

      Hardware environment: minimum system board N32G031C8L7-STB V1.0


3. Instructions for use

     The system clock configuration is as follows:
     -Clock source = HSI + PLL
     -System clock = 48MHz
    
     The LPUART configuration is as follows:
     -Baud rate = 115200 baud
     -Word length = 8 data bits (fixed)
     -1 stop bit (fixed)
     -Verification control disabled
     -Hardware flow control disabled (RTS and CTS signals)
     -Receiver and transmitter enable
    
     The LPUART pin connections are as follows:
     -LPUART_Tx.PA1
    
     Test steps and phenomena:
     -After the Demo is compiled in the KEIL environment, download it to the MCU
     -Reset operation, view serial port print information


4. Matters needing attention