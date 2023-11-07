1、功能说明

    该测例演示了LPUART与USARTz间通过DMA（中断）实现的基础通信。
USARTz可以是USART1。
    首先，DMA传输TxBuffer1数据至LPUART发送数据寄存器，传输完成产生
DMA中断，随后数据发送至USARTz。USARTz接收数据，DMA从USARTz接收
数据寄存器搬移数据至RxBuffer2，完成后产生DMA中断。
    同时，DMA传输TxBuffer2数据至USARTz发送数据寄存器，传输完成产生
DMA中断，随后数据发送至LPUART。LPUART接收数据，DMA从LPUART接收
数据寄存器搬移数据至RxBuffer1，完成后产生DMA中断。
    最后，分别比较两组收、发数据，比较结果存入TransferStatus1变量
和TransferStatus2变量。


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
    - DMA发送模式和DMA接收模式使能
    
    LPUART配置如下：
    - 波特率 = 115200 baud
    - 字长 = 8数据位（固定）
    - 1停止位（固定）
    - 校验控制禁用
    - 硬件流控制禁用（RTS和CTS信号）
    - 接收器和发送器使能
    - DMA发送模式和DMA接收模式使能
    
    USART引脚连接如下：
    - LPUART_Tx.PA1   <------->   USART1_Rx.PA10
    - LPUART_Rx.PA0   <------->   USART1_Tx.PA9

    
    测试步骤与现象：
    - Demo在KEIL环境下编译后，下载至MCU
    - 复位运行，依次查看变量TransferStatus1和TransferStatus2，其中，
      PASSED为测试通过，FAILED为测试异常


4、注意事项

    需先将开发板NS-LINK的MCU_TX和MCU_RX跳线帽断开

1. Function description

   This test example demonstrates the basic communication between LPUART and USARTz via DMA (interrupt).
USARTz can be USART1.
     First, DMA transfers the TxBuffer1 data to the LPUART send data register. After the transfer is completed, 
a DMA interrupt is generated, and then the data is sent to USARTz. USARTz receives data, DMA moves data 
from USARTz receive data register to RxBuffer2, and generates DMA interrupt after completion.
     At the same time, DMA transfers TxBuffer2 data to the USARTz send data register, the transfer is completed 
and a DMA interrupt is generated, and then the data is sent to LPUART. LPUART receives data, DMA moves data 
from LPUART receive data register to RxBuffer1, and generates DMA interrupt after completion.
     Finally, compare the two groups of receiving and sending data respectively, and store the comparison results 
in the TransferStatus1 variable and the TransferStatus2 variable.


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
    -DMA transmit mode and DMA receive mode enable
    
    The LPUART configuration is as follows:
    -Baud rate = 115200 baud
    -Word length = 8 data bits (fixed)
    -1 stop bit (fixed)
    -Verification control disabled
    -Hardware flow control disabled (RTS and CTS signals)
    -Receiver and transmitter enable
    -DMA transmit mode and DMA receive mode enable
    
    The USART pin connections are as follows:
    -LPUART_Tx.PA1 <-------> USART1_Rx.PA10
    -LPUART_Rx.PA0 <-------> USART1_Tx.PA9

    
    Test steps and phenomena:
    -After the Demo is compiled in the KEIL environment, download it to the MCU
    -Reset operation, check the variables TransferStatus1 and TransferStatus2 in turn, among them,
      PASSED means the test passed, FAILED means the test is abnormal


4. Matters needing attention

    the MCU_TX and MCU_RX jumper cap of the development board NS-LINK needs to be disconnected first